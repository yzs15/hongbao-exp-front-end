#include "mainwindow.h"
#include "ui_mainwindow.h"

time_t combineTime(QDateTime date, QDateTime time, int ms, int us);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->dateIn, &QDateEdit::dateTimeChanged, this, &MainWindow::onDateChanged);
    connect(ui->timeIn, &QTimeEdit::dateTimeChanged, this, &MainWindow::onTimeChanged);
    connect(ui->msIn, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onMsChanged);
    connect(ui->usIn, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onUsChanged);
    connect(ui->netStartBtn, &QPushButton::released, this, &MainWindow::onNetBtnClicked);
    connect(ui->spbStartBtn, &QPushButton::released, this, &MainWindow::onSpbBtnClicked);
    connect(ui->subBtn, &QPushButton::released, this, &MainWindow::onSubBtnClicked);

    this->sendDate = ui->dateIn->dateTime();
    this->sendTime = ui->timeIn->dateTime();
    this->sendMs = ui->msIn->value();
    this->sendUs = ui->usIn->value();

    this->msgField = new MsgField();
    connect(this->msgField, &MsgField::msgSelected, this, &MainWindow::onMsgSelected);
    ui->msgFieldArea->setWidget(this->msgField);

    this->msgSumArea = new MsgSummary();
    this->msgSumArea->tabWidget()->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //this->msgSumArea->tabWidget()->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    //this->msgSumArea->tabWidget()->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
    ui->summaryArea->setWidget(this->msgSumArea);

    this->socket = Q_NULLPTR;

    ui->nameLabel->setText(QString("%1，您好！").arg(NAME));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createSocket() {
    if (this->socket != Q_NULLPTR) {
        this->socket->close();
        delete this->socket;
    }

    this->socket = new QWebSocket();
    qDebug()<<"create websocket to " << WS_SERVER[curEnv];
    connect(this->socket, &QWebSocket::disconnected, this, &MainWindow::onDisConnected);
    connect(this->socket, &QWebSocket::textMessageReceived, this, &MainWindow::onTextReceived);
    connect(this->socket, &QWebSocket::binaryMessageReceived, this, &MainWindow::onBinaryReceived);
    connect(this->socket, &QWebSocket::connected, this, &MainWindow::onConnected);

    QUrl url = QUrl(WS_SERVER[curEnv]);
    url.setQuery(QString("mac=") + QString(MAC_ADDR));
    this->socket->open(url);
}


void MainWindow::onConnected(){
    qDebug() << "websocket is already connect";
    qDebug() << "address:" << this->socket->peerAddress();
}

void MainWindow::onDisConnected(){
    qDebug()<<"websocket is disconnected";
}

void MainWindow::onBinaryReceived(QByteArray msgRaw) {
    time_t receivedTime = get_current_ns_timestamp();

    MsgObj *obj = char2msg(msgRaw.constData(), msgRaw.size());
    this->handleMessage(obj, receivedTime);
}

void MainWindow::onTextReceived(QString msgRaw){
    time_t receivedTime = get_current_ns_timestamp();

    qDebug() << "Hello";

    // FIXME if there are more than one message?
    MsgObj *obj = char2msg(msgRaw.toStdString().c_str(), msgRaw.toStdString().size());
    this->handleMessage(obj, receivedTime);

    // QStringList msgs = msgRaw.split("}\n{");
    // for (QStringList::iterator it = msgs.begin(); it != msgs.end(); it ++) {
    //    QString msg = *it;
    //    if (it != msgs.begin()) msg = "{" + msg;
    //    if (it + 1 != msgs.end()) msg = msg + "}";
    //    qDebug() << "receive a message: " << msg;
    //    this->handleMessage(json, receivedTime);
    // }
}

void MainWindow::handleMessage(MsgObj *obj, time_t receivedTime) {
    qDebug() << "receive a message" << obj->toString();

    switch (obj->type) {
    case NAME_MSG:
        SENDER = obj->receiver;
        MSG_SVR_ID = obj->sender;
        MY_ID = SENDER>>30;
        obj->content = QString("Your ID is %1").arg(MY_ID);
        break;
    case TEXT_MSG:
        MsgObj callback;
        callback.id = obj->id;
        callback.sender = SENDER;
        callback.receiver = MSG_SVR_ID;
        callback.type = LOG_MSG;
        callback.content = "";
        callback.sendTime = receivedTime;
        zmqSend(ZMQ_SERVER[curEnv], &callback);
    }
    this->msgField->addMsg(obj);

    logStore.add(curEnv, obj->id, receivedTime, "ReceiverReceived");
}

void MainWindow::onDateChanged(const QDateTime &newDate) {
    this->sendDate = newDate;
}

void MainWindow::onTimeChanged(const QDateTime &newTime) {
    this->sendTime = newTime;
}

void MainWindow::onMsChanged(const int newVal) {
    this->sendMs = newVal;
}

void MainWindow::onUsChanged(const int newVal) {
    this->sendUs = newVal;
}

void MainWindow::onNetBtnClicked() {
    curEnv = INTERNET;
    this->msgField->clear();
    this->createSocket();
}

void MainWindow::onSpbBtnClicked() {
    curEnv = SUPERBAHN;
    this->msgField->clear();
    this->createSocket();
}

void MainWindow::onSubBtnClicked() {
    time_t timestamp = combineTime(this->sendDate, this->sendTime, this->sendMs, this->sendUs);

    time_t cur_time = get_current_ns_timestamp();
    if (false && cur_time >= timestamp) {
        QLabel *label = new QLabel("设定时间已过，请重新设定。");
        label->show();
        return;
    }

    QString content = ui->msgIn->toPlainText();
    if (false && content.size() == 0) {
        QLabel *label = new QLabel("请输入要发送的内容");
        label->show();
        return;
    }

    int receiver = ui->receiverSlc->currentIndex();
    uint64_t receiverId = RECEIVER_ID[receiver];

    MsgObj *obj = new MsgObj();
    obj->id = get_current_ns_timestamp();
    obj->receiver = receiverId;
    obj->type = TEXT_MSG;
    obj->content = content;
    qDebug() << obj->toString();

    timestamp = get_current_ns_timestamp() + uint64_t(1) * 1000000000;
    this->alarm = new Alarm(this, timestamp, obj);
    connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
    this->alarm->start();

    Countdown *countdown = new Countdown(this, timestamp, ui->countDownLabel);
    countdown->start();
}

void MainWindow::onMsgSended(Alarm *alarm) {
    this->msgField->addMsg(alarm->msgObj);
}

void MainWindow::onThingHideChanged() {
    // bool hidden = ui->thingHidden->checkState() != Qt::Unchecked;
    // this->msgField->setThingHidden(hidden);
}

void MainWindow::onMsgSelected(MsgDetailObj* msg) {
    if (msg->serverReceived != -1) {
        return;
    }

    MsgSendObj obj;
    obj.id = msg->id;
    obj.type = "DETAIL_MSG";
    // sendMsg(this->socket, &obj);
}

time_t combineTime(QDateTime date, QDateTime time, int ms, int us) {
    time_t timestamp = time_t(date.toTime_t() - 8 * 60 * 60) * 1000 * 1000 * 1000;
    timestamp += time_t(time.time().msecsSinceStartOfDay()) * 1000 * 1000;
    timestamp += ms * 1000 * 1000;
    timestamp += us * 100;
    return timestamp;
}
