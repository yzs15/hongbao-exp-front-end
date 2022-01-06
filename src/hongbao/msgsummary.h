#ifndef MSGSUMMARY_H
#define MSGSUMMARY_H

#include <QWidget>
#include <QTableWidget>
#include "public.h"
#include "commutils.h"

namespace Ui {
class MsgSummary;
}

class MsgSumObj {
public:
    time_t t_startTime = 0;
    time_t t_endTime = 0;
    time_t t_totalTime = 0;
    double t_latency = 0;

    int n_totalTask = 0;
    double p_throughput = 0;
    double p_concurrent = 0;

    int n_goodTask = 0;
    double p_yeild = 0;
    double p_goodput = 0;
};

class MsgSummary : public QWidget
{
    Q_OBJECT

public:
    explicit MsgSummary(QWidget *parent = 0);
    ~MsgSummary();

    QTableWidget* tabWidget();

    MsgSumObj sumObjs[2];

    void update();

private:
    Ui::MsgSummary *ui;
};

#endif // MSGSUMMARY_H
