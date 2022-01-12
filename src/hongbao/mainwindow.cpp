#include "mainwindow.h"
#include "ui_mainwindow.h"

uint8_t full = uint8_t((1<<8)-1);

time_t combineTime(QDateTime date, QDateTime time, int ms, int us);
void add2field(MsgField* field, MsgObj* obj);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->dateIn, &QDateEdit::dateTimeChanged, this, &MainWindow::onDateChanged);
    // connect(ui->timeIn, &QTimeEdit::dateTimeChanged, this, &MainWindow::onTimeChanged);
    // connect(ui->msIn, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onMsChanged);
    // connect(ui->usIn, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onUsChanged);
    connect(ui->netStartBtn, &QPushButton::released, this, &MainWindow::onNetBtnClicked);
    connect(ui->spbStartBtn, &QPushButton::released, this, &MainWindow::onSpbBtnClicked);
    connect(ui->subBtn, &QPushButton::released, this, &MainWindow::onSubBtnClicked);
    connect(ui->redBtn, &QPushButton::released, this, &MainWindow::onRedirectBtnClicked);

    //this->sendDate = ui->dateIn->dateTime();
    //this->sendTime = ui->timeIn->dateTime();
    //this->sendMs = ui->msIn->value();
    //this->sendUs = ui->usIn->value();

    this->msgField = new MsgField();
    connect(this->msgField, &MsgField::msgSelected, this, &MainWindow::onMsgSelected);
    ui->msgFieldArea->setWidget(this->msgField);

    //this->msgSumArea = new MsgSummary();
    //this->msgSumArea->tabWidget()->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //this->msgSumArea->tabWidget()->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    //this->msgSumArea->tabWidget()->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
    //ui->summaryArea->setWidget(this->msgSumArea);

    this->socket = Q_NULLPTR;

    ui->nameLabel->setText(QString("%1，您好！").arg(NAMES[WHOAMI]));;

    if (WHOAMI != WANG) { // Sun Li
        ui->redLabel->hide();
        ui->redLi->hide();
        ui->redSun->hide();
        ui->redBtn->hide();

        ui->netStartBtn->setText("连接计算平台 (互联网版)");
        ui->spbStartBtn->setText("连接计算平台 (信息高铁版)");

        ui->teachWang->setChecked(true);
        ui->subBtn->setText("确认祝贺语");

        ui->countDownLabel->setText("收到凭证后开始计时");

        ui->hbWidget;
        for (int i = 1; i < 10; i++) {
            QRadioButton* hb = new QRadioButton(ui->hbWidget);
            hb->setText("");
            hb->setIcon(QIcon(QString("../pic/nums/%1.png").arg(i)));
            ui->hbWidget->layout()->addWidget(hb);
            this->hbRadios[i-1] = hb;
        }
        this->hbRadios[8]->setChecked(true);

    } else { // Wang
        ui->teachLi->setChecked(true);
        ui->teachSun->setChecked(true);

        ui->subBtn->setText("确认开通通知");

        ui->hbWidget->hide();

        ui->countDownLabel->setText("确认转发后开始计时");
    }

    ui->proofLabel->setScaledContents(true);
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
    url.setQuery(QString("mac=") + QString(MAC_ADDRS[WHOAMI]));
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

    // FIXME if there are more than one message?
    MsgObj *obj = char2msg(msgRaw.toStdString().c_str(), msgRaw.toStdString().size());
    this->handleMessage(obj, receivedTime);
}

void MainWindow::handleMessage(MsgObj *obj, time_t receivedTime) {
    qDebug() << "receive a message" << obj->toString();

    switch (obj->type) {
    case NAME_MSG:
        SENDER = obj->receiver;
        obj->content = QString("Your ID is %1").arg(CID(SENDER)).toUtf8();
        add2field(this->msgField, obj);
        if (WHOAMI == WANG) this->testAndBuildProof();
        break;

    case TEXT_MSG:
        if (obj->sender == SENDER) break;

        MsgObj callback;
        callback.id = obj->id;
        callback.sender = SENDER;
        callback.receiver = SID(SENDER);
        callback.type = LOG_MSG;
        callback.content = "";
        callback.sendTime = receivedTime;
        zmqSend(ZMQ_SERVER[curEnv], &callback);

        uint8_t flag = obj->content.at(0);
        if (flag == full) {
            this->handleProof(obj, receivedTime);
        } else if (flag == full-1) {
            this->handleNotice(obj, receivedTime);
        } else {
            this->handleText(obj, receivedTime);
        }
    }
}

void MainWindow::handleProof(MsgObj *obj, time_t receivedTime) {
    QSaveFile file("../pic/proof.jpg");
    file.open(QIODevice::WriteOnly);
    file.write(obj->content.remove(0, 1));
    file.commit();
    obj->content.insert(0, (1<<8)-1);

    QPixmap pix("../pic/proof.jpg");
    ui->proofLabel->setPixmap(pix);

    this->proofMsg = obj;

    if (WHOAMI == WANG) {

    } else {
        time_t startTime = this->proofMsg->sendTime + uint64_t(PREPARE_TIME) * 60 * 1000000000 - uint64_t(5) * 1000000000;
        Countdown *countdown = new Countdown(this, startTime, ui->countDownLabel, "请于 %1 秒内确认祝贺语");
        countdown->start();

        ui->msgIn->setPlainText("恭喜信息高铁开通！");
    }
}

int getCheckedHb(QRadioButton* hbRadios[]) {
    for (int i = 1; i < 10; i++) {
        if (hbRadios[i-1]->isChecked()) return i;
    }
}

void MainWindow::handleNotice(MsgObj *recvObj, time_t receivedTime) {
    recvObj->content.remove(0, 1);
    add2field(this->msgField, recvObj);

    int hbIdx = getCheckedHb(this->hbRadios);
    QFile fi(QString("../pic/nums/%1.png").arg(hbIdx));
    fi.open(QIODevice::ReadOnly);
    QByteArray imgRaw = fi.readAll();
    fi.close();

    QString content = ui->msgIn->toPlainText();
    QByteArray contentRaw = content.toUtf8();
    uint32_t contentLen = contentRaw.size();

    uint8_t svsID = 7;
    QByteArray taskBody;
    taskBody.append(reinterpret_cast<const char *>(&svsID), 1)
            .append(reinterpret_cast<const char *>(&contentLen), 4)
            .append(contentRaw)
            .append(imgRaw);

    bool chosedMan[3];
    chosedMan[0] = ui->teachWang->isChecked();
    chosedMan[1] = ui->teachLi->isChecked();
    chosedMan[2] = ui->teachSun->isChecked();

    for (int i = 0; i < 3; i++) {
        if (!chosedMan[i]) continue;

        MsgObj* obj = new MsgObj();
        obj->id = MID(SENDER, this->mid++);
        obj->sender = SENDER;
        obj->receiver = RECEIVER_ID[i];
        obj->type = TASK_MSG;
        obj->content = taskBody;
        obj->sendTime = get_current_ns_timestamp();

        if (WHOAMI == SUN) {
            time_t sendTime = recvObj->sendTime + uint64_t(WAIT_TIME) * 100000;
            this->alarm = new Alarm(this, sendTime, obj);
            connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
            this->alarm->start();

        } else {
            zmqSend(ZMQ_SERVER[curEnv], obj);
            add2field(this->msgField, obj);
        }
    }
}

void MainWindow::handleText(MsgObj *obj, time_t receivedTime) {
    add2field(this->msgField, obj);

    logStore.add(curEnv, obj->id, receivedTime, "ReceiverReceived");
}

void MainWindow::onNetBtnClicked() {
    ui->netStartBtn->setEnabled(false);
    ui->redBtn->setEnabled(true);
    ui->subBtn->setEnabled(true);
    this->msgField->clear();
    ui->proofLabel->clear();
    ui->proofLabel->setText("暂无凭证");
    this->proofMsg = Q_NULLPTR;

    curEnv = INTERNET;
    this->createSocket();
}

void MainWindow::onSpbBtnClicked() {
    ui->spbStartBtn->setEnabled(false);
    ui->redBtn->setEnabled(true);
    ui->subBtn->setEnabled(true);
    this->msgField->clear();
    ui->proofLabel->clear();
    ui->proofLabel->setText("暂无凭证");
    this->proofMsg = Q_NULLPTR;

    curEnv = SUPERBAHN;
    this->createSocket();
}

void MainWindow::testAndBuildProof() {
    MsgObj* obj = new MsgObj();
    obj->sender = SENDER;
    obj->type = TEXT_MSG;
    obj->content = "开始测试";
    obj->sendTime = get_current_ns_timestamp();

    for (int i = 0; i < THING_NUM; i++) {
        obj->receiver = THING_IDS[i];
        obj->id = MID(SENDER, this->mid++);
        zmqSend(ZMQ_SERVER[curEnv], obj);
        add2field(this->msgField, obj);
    }

    obj->id = MID(SENDER, this->mid++);
    obj->receiver = LOG_ANALYZER_ID;
    obj->content = "开始分析";
    obj->sendTime = obj->sendTime + uint64_t(PROOF_TIME) * 60 * 1000000000;
    this->alarm = new Alarm(this, obj->sendTime, obj);
    connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
    this->alarm->start();
}

void MainWindow::onSubBtnClicked() {
    if (this->proofMsg == Q_NULLPTR) {
        QLabel *label = new QLabel("请点击“测试并生成凭证”，然后等待10分钟");
        label->show();
        return;
    }

    if (WHOAMI == WANG && this->proofMsg->sender != SENDER) {
        QLabel *label = new QLabel("请先确认并转发至其他老师，再确认通知消息");
        label->show();
        return;
    }

    QString content = ui->msgIn->toPlainText();
    if (content.size() == 0) {
        QLabel *label = new QLabel("请输入要发送的内容");
        label->show();
        return;
    }
    ui->subBtn->setEnabled(false);

    if (WHOAMI == WANG) {
        MsgObj* obj = new MsgObj();
        obj->id = MID(SENDER, this->mid++);
        obj->sender = SENDER;
        obj->receiver = BROADCASE_ID;
        obj->type = TEXT_MSG;
        QByteArray body;
        uint8_t flag = full-1;
        body.append(reinterpret_cast<const char *>(&flag), 1).append(content.toUtf8());
        obj->content = body;

        time_t sendTime = this->proofMsg->sendTime + uint64_t(PREPARE_TIME) * 60 * 1000000000;
        this->alarm = new Alarm(this, sendTime, obj);
        connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
        this->alarm->start();

        this->countdown->temp = "将于 %1 秒后发送通知";
    }
}


void MainWindow::onRedirectBtnClicked() {
    ui->redBtn->setEnabled(false);

    bool redLi = ui->redLi->isChecked();
    bool redSun = ui->redSun->isChecked();

    this->proofMsg->sender = SENDER;
    this->proofMsg->sendTime = get_current_ns_timestamp();
    if (redLi) {
        this->proofMsg->id = MID(SENDER, this->mid++);
        this->proofMsg->receiver = RECEIVER_ID[LI];
        zmqSend(ZMQ_SERVER[curEnv], this->proofMsg);
    }

    if (redSun) {
        this->proofMsg->id = MID(SENDER, this->mid++);
        this->proofMsg->receiver = RECEIVER_ID[SUN];
        zmqSend(ZMQ_SERVER[curEnv], this->proofMsg);
    }

    time_t startTime = this->proofMsg->sendTime + uint64_t(PREPARE_TIME) * 60 * 1000000000;
    this->countdown = new Countdown(this, startTime, ui->countDownLabel, "请于 %1 秒内确认开通通知");
    this->countdown->start();

    ui->msgIn->setPlainText("信息高铁开通了！");
}

void MainWindow::onMsgSended(Alarm *alarm) {
    add2field(this->msgField, alarm->msgObj);
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

QByteArray getPart(const QByteArray& raw, int start, int len) {
   QByteArray s;
   for (int i = start; i < start + len; i++) {
       s.append(raw[i]);
   }
   return s;
}

void add2field(MsgField* field, MsgObj* obj) {
    uint8_t flag = obj->content.at(0);
    if (flag == full - 1) {
        obj->content.remove(0, 1);
    }

    if (obj->type == TASK_MSG) {
        QByteArray lenRaw = getPart(obj->content, 1, 4);
        uint32_t len = ((static_cast<uint32_t>(lenRaw[3]) & 0xFF) << 24)
                | ((static_cast<uint32_t>(lenRaw[2]) & 0xFF) << 16)
                | ((static_cast<uint32_t>(lenRaw[1]) & 0xFF) << 8)
                | (static_cast<uint32_t>(lenRaw[0]) & 0xFF);
        QByteArray content = getPart(obj->content, 5, len);
        obj->content = content;
    }

    field->addMsg(obj);
}
