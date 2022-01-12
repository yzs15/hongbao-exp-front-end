void deleteFunc() {
    time_t timestamp = combineTime(this->sendDate, this->sendTime, this->sendMs, this->sendUs);
    bool needHongbao = false;

    time_t cur_time = get_current_ns_timestamp();
    if (false && cur_time >= timestamp) {
        QLabel *label = new QLabel("设定时间已过，请重新设定。");
        label->show();
        return;
    }

    QString content = ui->msgIn->toPlainText();
    if (content.size() == 0) {
        QLabel *label = new QLabel("请输入要发送的内容");
        label->show();
        return;
    }

    //bool toWang = ui->teachWang->isChecked();
    //bool toLi = ui->teachLi->isChecked();
    //bool toSun = ui->teachSun->isChecked();

    // int receiver = ui->receiverSlc->currentIndex();
    // uint64_t receiverId = RECEIVER_ID[receiver];

    MsgObj *obj = new MsgObj();
    obj->id = get_current_ns_timestamp();
    obj->receiver = 0;

    obj->type = TEXT_MSG;
    obj->content = content.toUtf8();

    if (needHongbao) {
        obj->type = TASK_MSG;
        uint8_t svsID = 1;
        uint8_t* png = PNGS[0];
        QByteArray data;
        data.append(reinterpret_cast<const char *>(&svsID), 1).append(reinterpret_cast<const char *>(png), PNG_SIZE[0]);
        obj->content = data;
    }

    timestamp = get_current_ns_timestamp() + uint64_t(1) * 100000000;
    this->alarm = new Alarm(this, timestamp, obj);
    //connect(this->alarm, &Alarm::timeOut, this, &MainWindow::onMsgSended);
    this->alarm->start();

    Countdown *countdown = new Countdown(this, timestamp, ui->countDownLabel);
    countdown->start();
}
