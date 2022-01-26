#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    this->pool.setMaxThreadCount(500);

    ui->nameLabel->setText(QString("%1，您好！").arg(NAMES[WHOAMI]));;

    ui->redLabel->hide();
    ui->redLi->hide();
    ui->redSun->hide();
    ui->redBtn->hide();

    ui->teachLi->hide();
    ui->teachWang->hide();
    ui->teachSun->hide();

    if (WHOAMI != WANG) { // Sun Li
        ui->countDownLabel->setText("请点击 连接计算平台");

        ui->netStartBtn->setText("连接计算平台 (互联网版)");
        ui->spbStartBtn->setText("连接计算平台 (信息高铁版)");

        ui->teachWang->setChecked(true);
        ui->subBtn->setText("确认祝贺语");

        //ui->hbWidget;
        //for (int i = 1; i < 10; i++) {
        //    QRadioButton* hb = new QRadioButton(ui->hbWidget);
        //    hb->setText("");
        //    hb->setIcon(QIcon(QString("../pic/nums/%1.png").arg(i)));
        //    ui->hbWidget->layout()->addWidget(hb);
        //    this->hbRadios[i-1] = hb;
        //}
        //this->hbRadios[8]->setChecked(true);

    } else { // Wang
        ui->countDownLabel->setText("请点击 测试并生成凭证");

        ui->teachLi->setChecked(true);
        ui->teachSun->setChecked(true);

        ui->subBtn->setText("确认开通通知");

        //ui->hbWidget->hide();
    }

    ui->proofLabel->setScaledContents(true);

    // MsgObj *obj = new MsgObj();
    // obj->sender = SENDER;

    // uint8_t flag = full - 2;
    // QByteArray taskBody;
    // taskBody.append(reinterpret_cast<const char *>(&flag), 1)
    //         .append("3")
    //         .append("Hello");
    // obj->content = taskBody;
    // add2field(this->msgField, obj);
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
    connect(this->socket, &QWebSocket::disconnected, this, &MainWindow::onDisConnected);
    connect(this->socket, &QWebSocket::textMessageReceived, this, &MainWindow::onTextReceived);
    connect(this->socket, &QWebSocket::binaryMessageReceived, this, &MainWindow::onBinaryReceived);
    connect(this->socket, &QWebSocket::connected, this, &MainWindow::onConnected);

    QUrl url = QUrl(WS_SERVER[curEnv]);
    QUrlQuery query;
    query.addQueryItem("mac", MAC_ADDRS[WHOAMI]);
    query.addQueryItem("expid", QString::number(CID(RECEIVER_ID[WHOAMI])));
    url.setQuery(query);

    qDebug()<< "create websocket to " << url.toString();
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
    time_t receivedTime = get_current_ptp_timestamp();
    // time_t receivedTime = get_current_ns_timestamp();

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
    switch (obj->type) {
    case NAME_MSG:
        SENDER = obj->receiver;
        obj->content = QString("Your ID is %1.%2").arg(CID(SENDER)).arg(SID(SENDER)).toUtf8();
        add2field(this->msgField, obj);
        if (WHOAMI == WANG) this->testAndBuildProof();
        break;

    case TEXT_MSG:
        if (obj->sender == SENDER) break;

        uint8_t flag = obj->content.at(0);
        if (flag == full) {
            this->handleProof(obj, receivedTime);

        } else if (flag == full-1) {
            this->handleNotice(obj, receivedTime);

        } else if (flag == full-3) {
            this->handleTest(obj, receivedTime);

        } else {
            //MsgHandler* hdl = new MsgHandler(obj, receivedTime);
            //connect(hdl, &MsgHandler::processed, this, &MainWindow::onMsgProcessed, Qt::QueuedConnection);
            //this->pool.start(hdl);
            this->handleText(obj, receivedTime);
        }

        if (true || flag >= full-3) {
            MsgObj callback;
            callback.id = obj->id;
            callback.sender = SENDER;
            callback.receiver = SID(SENDER);
            callback.type = LOG_MSG;
            callback.content = "";
            callback.sendTime = receivedTime;
            zmqSend(ZMQ_SERVER[curEnv], &callback);
        }
    }
    // qDebug() << time_t2str(receivedTime) << "receive a message" << obj->toString();
}

void MainWindow::handleProof(MsgObj *obj, time_t receivedTime) {
    this->hidden = false;
    bool hasProof = this->proofMsg != Q_NULLPTR;
    if (hasProof) return;  // 第二张凭证不需要转发

    QString envName;
    if (curEnv == SUPERBAHN) envName = "spb";
    else envName = "net";

    QString typName;
    if (this->proofMsg == Q_NULLPTR) typName = "proof";
    else typName = "hongbao";

    QString title = QString("%1-%2").arg(typName).arg(envName);
    QString picName = QString("../pic/%1.jpg").arg(title);

    QSaveFile file(picName);
    file.open(QIODevice::WriteOnly);
    file.write(obj->content.remove(0, 1));
    file.commit();
    obj->content.insert(0, (1<<8)-1);

    QPixmap pix(picName);
    ui->proofLabel->setPixmap(pix);

    QPixmap labPix(picName);
    labPix.scaled(ui->label->size(), Qt::KeepAspectRatio);

    QLabel *lab = new QLabel();
    lab->setWindowTitle(title);
    lab->setMinimumSize(500, 500);
    lab->setMaximumSize(600, 600);
    lab->setScaledContents(true);
    lab->setPixmap(labPix);
    lab->setWindowState(Qt::WindowMinimized);
    lab->show();

    //bool hasProof = this->proofMsg != Q_NULLPTR;
    this->proofMsg = obj;
    //if (hasProof) return;  // 第二张凭证不需要转发

    if (this->countdown) this->countdown->stop = true;
    if (WHOAMI == WANG) {
        this->onRedirectBtnClicked();

    } else {
        time_t startTime = this->proofMsg->sendTime + uint64_t(PREPARE_TIME) * 1000000000 - uint64_t(5) * 1000000000;
        this->countdown = new Countdown(this, startTime, ui->countDownLabel, "已收到凭证，请于 %1 秒内确认祝贺语");
        this->countdown->start();

        if (curEnv == SUPERBAHN) {
            if (ui->msgIn->toPlainText().size() == 0) ui->msgIn->setPlainText("恭喜信息高铁开通！");
        } else {
            if (ui->msgIn->toPlainText().size() == 0) ui->msgIn->setPlainText("哦，知道了");
        }
    }
}

void MainWindow::handleTest(MsgObj *obj, time_t receivedTime) {
    time_t startTime = obj->sendTime + uint64_t(PROOF_TIME) * 1000000000 + uint64_t(ANALYSIS_TIME) * 1000000000;
    this->countdown = new Countdown(this, startTime, ui->countDownLabel, "正在进行测试，剩余时间约 %1 秒");
    this->countdown->start();

    add2field(this->msgField, obj);
}

int getCheckedHb(QRadioButton* hbRadios[]) {
    for (int i = 1; i < 10; i++) {
        if (hbRadios[i-1]->isChecked()) return i;
    }
}

void MainWindow::handleNotice(MsgObj *recvObj, time_t receivedTime) {
    recvObj->content.remove(0, 1);
    add2field(this->msgField, recvObj);

    //int hbIdx = getCheckedHb(this->hbRadios);
    QFile fi(QString("../pic/nums/%1.png").arg(9));
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

        if (WHOAMI == LI) {
            time_t sendTime = recvObj->sendTime + uint64_t(WAIT_TIME) * 1000000;
            qDebug() << recvObj->sendTime << receivedTime << get_current_ns_timestamp() << sendTime << "LI";
            qDebug() << receivedTime - recvObj->sendTime;
            this->alarm = new Alarm(this, sendTime, obj);
            connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
            this->alarm->start();

        } else {
            time_t sendTime = recvObj->sendTime + uint64_t(B_WAIT_TIME) * 1000000;
            qDebug() << recvObj->sendTime << receivedTime << get_current_ns_timestamp() << sendTime << "SUN";
            qDebug() << receivedTime - recvObj->sendTime;
            this->alarm = new Alarm(this, sendTime, obj);
            connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
            this->alarm->start();

            // zmqSend(ZMQ_SERVER[curEnv], obj);
            // add2field(this->msgField, obj);
        }
    }
}

void MainWindow::handleText(MsgObj *obj, time_t receivedTime) {
    if (!hidden) add2field(this->msgField, obj);
}

void MainWindow::onMsgProcessed(MsgObj *obj) {
    if (!hidden) add2field(this->msgField, obj);
}

void MainWindow::onNetBtnClicked() {
    ui->netStartBtn->setEnabled(false);
    ui->spbStartBtn->setEnabled(true);
    // ui->redBtn->setEnabled(true);
    ui->subBtn->setEnabled(true);
    this->msgField->clear();
    ui->proofLabel->clear();
    ui->proofLabel->setText("暂无凭证");
    this->proofMsg = Q_NULLPTR;
    if (WHOAMI == WANG) this->hidden = true;
    else ui->countDownLabel->setText("请等待开发团队的测试通知");
    zsock_cache.clear();
    this->recvMsgNum = 0;
    this->recvHbAmount = 0;
    ui->msgIn->clear();

    curEnv = INTERNET;
    this->createSocket();
}

void MainWindow::onSpbBtnClicked() {
    ui->netStartBtn->setEnabled(true);
    ui->spbStartBtn->setEnabled(false);
    // ui->redBtn->setEnabled(true);
    ui->subBtn->setEnabled(true);
    this->msgField->clear();
    ui->proofLabel->clear();
    ui->proofLabel->setText("暂无凭证");
    this->proofMsg = Q_NULLPTR;
    if (WHOAMI == WANG) this->hidden = true;
    else ui->countDownLabel->setText("请等待开发团队的测试通知");
    zsock_cache.clear();
    this->recvMsgNum = 0;
    this->recvHbAmount = 0;
    ui->msgIn->clear();

    curEnv = SUPERBAHN;
    this->createSocket();
}

void MainWindow::testAndBuildProof() {
    MsgObj* obj = new MsgObj();
    obj->id = MID(SENDER, this->mid++);
    obj->sender = SENDER;
    obj->receiver = BROADCASE_ID;
    obj->type = TEXT_MSG;

    QByteArray args;
    uint8_t flag = full - 3;
    args.append(reinterpret_cast<const char *>(&flag), 1).append("开始测试");

    obj->content = args;
    obj->sendTime = get_current_ns_timestamp();
    zmqSend(ZMQ_SERVER[curEnv], obj);
    add2field(this->msgField, obj);

    //for (int i = 0; i < THING_NUM; i++) {
    //    obj->receiver = THING_IDS[i];
    //    obj->id = MID(SENDER, this->mid++);
    //    zmqSend(ZMQ_SERVER[curEnv], obj);
    //    add2field(this->msgField, obj);
    //}

    obj->id = MID(SENDER, this->mid++);
    obj->receiver = LOG_ANALYZER_ID;
    obj->content = "开始分析测试任务运行情况";
    obj->sendTime = obj->sendTime + uint64_t(PROOF_TIME) * 1000000000;
    this->alarm = new Alarm(this, obj->sendTime, obj);
    connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
    this->alarm->start();

    this->countdown = new Countdown(this, obj->sendTime + uint64_t(ANALYSIS_TIME) * 1000000000, ui->countDownLabel, "正在进行测试，剩余时间约 %1 秒");
    this->countdown->start();
}

void MainWindow::onSubBtnClicked() {
    if (this->proofMsg == Q_NULLPTR) {
        QLabel *label = new QLabel("请在收到凭证后再进行确认");
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

        obj->sendTime = this->proofMsg->sendTime + uint64_t(PREPARE_TIME) * 1000000000;
        this->alarm = new Alarm(this, obj->sendTime, obj);
        connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
        this->alarm->start();

        this->countdown->temp = "将于 %1 秒后发送通知";

    } else {
        this->countdown->temp = "将于 %1 秒后发送祝贺语";
    }
}


void MainWindow::onRedirectBtnClicked() {
    ui->redBtn->setEnabled(false);

    //bool redLi = ui->redLi->isChecked();
    //bool redSun = ui->redSun->isChecked();

    bool redLi = true;
    bool redSun = true;

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

    time_t startTime = this->proofMsg->sendTime + uint64_t(PREPARE_TIME) * 1000000000;
    this->countdown = new Countdown(this, startTime, ui->countDownLabel, "凭证已转发，请于 %1 秒内确认开通通知");
    this->countdown->start();

    if (curEnv == SUPERBAHN) {
        if (ui->msgIn->toPlainText().size() == 0) ui->msgIn->setPlainText("信息高铁开通了！");
    } else {
        if (ui->msgIn->toPlainText().size() == 0) ui->msgIn->setPlainText("信息高速公路开通了？");
    }
}

void MainWindow::onMsgSended(Alarm *alarm) {
    uint8_t flag = alarm->msgObj->content.at(0);
    if (flag == full - 1 && WHOAMI == WANG) {  // 等一段时间，发送第二次分析通知
        MsgObj *obj = new MsgObj();
        obj->id = MID(SENDER, this->mid++);
        obj->receiver = LOG_ANALYZER_ID;
        obj->type = TEXT_MSG;
        obj->content = "开始分析红包任务运行情况";
        obj->sendTime = alarm->msgObj->sendTime + uint64_t(HONGBAO_TIME) * 1000000000;
        //qDebug() << alarm->msgObj->sendTime;
        //qDebug() << obj->sendTime;
        //qDebug() << get_current_ns_timestamp();
        this->alarm = new Alarm(this, obj->sendTime, obj);
        connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
        this->alarm->start();
    }

    add2field(this->msgField, alarm->msgObj);
}

void MainWindow::onThingHideChanged() {
    // bool hidden = ui->thingHidden->checkState() != Qt::Unchecked;
    // this->msgField->setThingHidden(hidden);
}

void MainWindow::onMsgSelected(MsgBox* msg) {
    if (!msg->isHongbao) return;

    QString author = msg->getAuthor();
    QString content = msg->getContent();
    QString money = QString::fromUtf8(getPart(msg->obj->content, 1, 1));

    if (this->hbOpened) this->hbOpened->hide();
    this->hbOpened = new HBOpened(this, author, money, content);
    this->hbOpened->show();
}

time_t combineTime(QDateTime date, QDateTime time, int ms, int us) {
    time_t timestamp = time_t(date.toTime_t() - 8 * 60 * 60) * 1000 * 1000 * 1000;
    timestamp += time_t(time.time().msecsSinceStartOfDay()) * 1000 * 1000;
    timestamp += ms * 1000 * 1000;
    timestamp += us * 100;
    return timestamp;
}

void MainWindow::add2field(MsgField* field, MsgObj* obj) {
    uint8_t flag = obj->content.at(0);
    if (flag == full - 1 || flag == full - 3) {
        obj->content.remove(0, 1);
    }

    if (obj->type == TASK_MSG) {
        QByteArray lenRaw = getPart(obj->content, 1, 4);
        uint32_t len = ((static_cast<uint32_t>(lenRaw[3]) & 0xFF) << 24)
                | ((static_cast<uint32_t>(lenRaw[2]) & 0xFF) << 16)
                | ((static_cast<uint32_t>(lenRaw[1]) & 0xFF) << 8)
                | (static_cast<uint32_t>(lenRaw[0]) & 0xFF);

        QByteArray args;
        uint8_t flag = full - 2;
        args.append(reinterpret_cast<const char *>(&flag), 1)
                .append("9")
                .append(getPart(obj->content, 5, len));
        obj->content = args;

        ui->countDownLabel->setText("测试结束");
    }

    field->addMsg(obj);

    if (flag == full - 2 && WHOAMI == WANG) {
        while (!__sync_bool_compare_and_swap(&this->recvMsgNum, this->recvMsgNum, this->recvMsgNum+1)) ;

        char c = getPart(obj->content, 1, 1).at(0);
        int money = c - '0';
        while (!__sync_bool_compare_and_swap(&this->recvHbAmount, this->recvHbAmount, this->recvHbAmount+money)) ;

        ui->countDownLabel->setText(QString("累计收到 %1 个红包，共计 %2 元").arg(this->recvMsgNum).arg(this->recvHbAmount));
    }
}
