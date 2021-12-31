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

    ui->authorLabel->setText(QString::number(this->obj->sender));

    ui->msgLabel->setText(this->obj->content);
    ui->msgLabel->setStyleSheet("QLabel { background-color: #aaa; border-radius: 5; }");
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
    emit clicked(NULL);
}
