#include "msgdetail.h"
#include "ui_msgdetail.h"

MsgDetail::MsgDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MsgDetail)
{
    ui->setupUi(this);
}

MsgDetail::~MsgDetail()
{
    delete ui;
}

void MsgDetail::setObj(MsgDetailObj* obj) {
    this->obj.id = obj->id;
    this->obj.sender = obj->sender;
    this->obj.content = obj->content;
    this->obj.endBefore = obj->endBefore;
    this->obj.senderSended = obj->senderSended;
    this->obj.serverReceived = obj->serverReceived;
    this->obj.serverResponsed = obj->serverResponsed;
    this->obj.receiverReceived = obj->receiverReceived;

    this->rerender();
}

void MsgDetail::rerender() {
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(this->obj.id, QTableWidgetItem::Type));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(this->obj.sender, QTableWidgetItem::Type));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(this->obj.content, QTableWidgetItem::Type));
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem(time_t2str(this->obj.endBefore), QTableWidgetItem::Type));
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem(time_t2str(this->obj.senderSended), QTableWidgetItem::Type));
    ui->tableWidget->setItem(5, 0, new QTableWidgetItem(time_t2str(this->obj.serverReceived), QTableWidgetItem::Type));
    ui->tableWidget->setItem(6, 0, new QTableWidgetItem(time_t2str(this->obj.serverResponsed), QTableWidgetItem::Type));
    ui->tableWidget->setItem(7, 0, new QTableWidgetItem(time_t2str(this->obj.receiverReceived), QTableWidgetItem::Type));

    this->update();
}
