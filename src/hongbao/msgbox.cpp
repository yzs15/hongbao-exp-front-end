#include "msgbox.h"
#include "ui_msgbox.h"
#include <QDebug>
#include <iostream>
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
    if (author.size() == 0) author = QString("%1.%2").arg(CID(send_id)).arg(SID(send_id));
    ui->authorLabel->setText(author);

    ui->msgLabel->setText(this->obj->content);
    if (send_id == SENDER) {
        ui->msgLabel->setStyleSheet("QLabel { background-color: #efa; border-radius: 5; }");
    } else {
        ui->msgLabel->setStyleSheet("QLabel { background-color: #aaa; border-radius: 5; }");
    }

}

MsgBox::~MsgBox()
{
    delete ui;
    delete this->obj;
}

QString MsgBox::getAuthor() const {
    return QString::number(this->obj->sender);
}

void MsgBox::mousePressEvent(QMouseEvent* event) {
    // emit clicked(NULL);
}
