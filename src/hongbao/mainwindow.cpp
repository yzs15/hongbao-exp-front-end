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
    connect(this->socket, &QWebSocket::connected, this, &MainWindow::onConnected);
    this->socket->open(QUrl(WS_SERVER[curEnv]));
}


void MainWindow::onConnected(){
    qDebug() << "websocket is already connect";
    qDebug() << "address:" << this->socket->peerAddress();
}

void MainWindow::onDisConnected(){
    qDebug()<<"websocket is disconnected";
}

void MainWindow::onTextReceived(QString msgRaw){
    time_t receivedTime = get_current_ns_timestamp();

    QStringList msgs = msgRaw.split("}\n{");
    for (QStringList::iterator it = msgs.begin(); it != msgs.end(); it ++) {
        QString msg = *it;
        if (it != msgs.begin()) msg = "{" + msg;
        if (it + 1 != msgs.end()) msg = msg + "}";
        qDebug() << "receive a message: " << msg;

        QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8());
        QJsonObject json = doc.object();
        this->handleMessage(json, receivedTime);
    }
}

void MainWindow::handleMessage(QJsonObject &json, time_t receivedTime) {
    MsgObj *obj = new MsgObj();
    obj->id = json["ID"].toVariant().toLongLong();
    obj->sender = json["Sender"].toVariant().toLongLong();
    obj->good = json["Good"].toBool();
    obj->content = json["Content"].toString();

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
    this->start();
}

void MainWindow::onSpbBtnClicked() {
    curEnv = SUPERBAHN;
    this->start();
}

void MainWindow::start() {
    this->msgField->clear();
    this->createSocket();

    time_t timestamp = combineTime(this->sendDate, this->sendTime, this->sendMs, this->sendUs);

    time_t cur_time = get_current_ns_timestamp();
    if (cur_time >= timestamp) {
        QLabel *label = new QLabel("设定时间已过，请重新设定。");
        label->show();
        return;
    }

    MsgObj *obj = new MsgObj();
    obj->id = MID(1);
    obj->content = "信息高铁开通了！";

    Alarm *alarm = new Alarm(this, timestamp, obj);
    alarm->start();

    Countdown *countdown = new Countdown(this, timestamp, ui->countDownLabel);
    countdown->start();
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
