#include "msgsummary.h"
#include "ui_msgsummary.h"

MsgSummary::MsgSummary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MsgSummary)
{
    ui->setupUi(this);
}

MsgSummary::~MsgSummary()
{
    delete ui;
}
