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


QTableWidget* MsgSummary::tabWidget() {
    return ui->tableWidget;
}

void MsgSummary::update() {
    MsgSumObj &sumObj = this->sumObjs[curEnv];

    if (sumObj.t_endTime != 0) {
        sumObj.t_totalTime = sumObj.t_endTime - sumObj.t_startTime;
    } else {
        sumObj.t_totalTime = get_current_ns_timestamp() - sumObj.t_startTime;
    }

    // ui->tableWidget->setItem(0, curEnv, QString::number(sumObj.t_totalTime));
}
