#include "msgbox.h"
#include "ui_msgbox.h"
#include <QDebug>
#include <iostream>

char* LOCS[] = {"北京", "南京"};
char* DEVICES[] = {"摄像头", "加湿器", "冰箱", "电视", "空调", "热水器"};
int N_DEVICE = 6;

MsgBox::MsgBox(QWidget *parent, MsgObj* origin) :
    QWidget(parent),
    ui(new Ui::MsgBox)
{
    ui->setupUi(this);
    this->obj = origin;

    uint64_t send_id = this->obj->sender;
    QString author;
    for (int i = 0; i < 3; i++) {
        if (send_id == RECEIVER_ID[i]) author = NAMES[i];
    }
    if (author.size() == 0) {
        if (CID(send_id) == 0) {
            author = QString("%1接入点").arg(LOCS[SID(send_id)-1]);
        } else {
            author = QString("%1.%2").arg(LOCS[SID(send_id)-1]).arg(DEVICES[CID(send_id) % N_DEVICE]);
        }
    }
    ui->authorLabel->setText(author);
    ui->authorLabel2->setText(author);

    uint8_t flag = this->obj->content.at(0);
    if (flag == full - 2) {
        handleHB();

    } else {
        ui->msgLabel->setText(this->obj->content);
        if (send_id == SENDER) {
            ui->msgLabel->setStyleSheet("QLabel { background-color: #a9e87a; border-radius: 5; }");
        } else {
            ui->msgLabel->setStyleSheet("QLabel { background-color: #fff; border-radius: 5; }");
        }
    }

    if (send_id == SENDER) {
        ui->authorLabel->hide();
    } else {
        ui->authorLabel2->hide();
    }
}

void MsgBox::handleHB() {
    this->isHongbao = true;
    ui->msgLabel->setFixedWidth(300);
    ui->msgLabel->setFixedHeight(100);
    ui->msgLabel->setMargin(0);

    QPixmap bgImage;

    if (curEnv == INTERNET) {
        bgImage = QPixmap("../pic/message-net.png").scaled(ui->msgLabel->size());
    } else {
        if (CID(this->obj->sender) < 4)
            bgImage = QPixmap("../pic/message-spb.png").scaled(ui->msgLabel->size());
        else if (SID(this->obj->sender) == 1)
            bgImage = QPixmap("../pic/message-b.png").scaled(ui->msgLabel->size());
        else
            bgImage = QPixmap("../pic/message-g.png").scaled(ui->msgLabel->size());
    }

    ui->msgLabel->setAutoFillBackground(true);
    QPalette palette (ui->msgLabel->palette());
    palette .setBrush(QPalette::Background, QBrush(bgImage));
    ui->msgLabel->setPalette(palette);

    int len = this->obj->content.size();
    QByteArray con = getPart(this->obj->content, 2, len-2);

    ui->msgLabel->setText(con);
    ui->msgLabel->setStyleSheet("QLabel { padding: 0px 10px 0px 80px; }");

    QByteArray args;
    args.append(this->obj->content);
    this->obj->content = args;
}

MsgBox::~MsgBox()
{
    delete ui;
    // delete this->obj;
}

QString MsgBox::getAuthor() const {
    return ui->authorLabel->text();
}

QString MsgBox::getContent() const {
    return ui->msgLabel->text();
}

void MsgBox::mousePressEvent(QMouseEvent* event) {
    emit clicked(this);
}
