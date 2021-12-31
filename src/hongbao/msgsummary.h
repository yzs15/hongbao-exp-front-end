#ifndef MSGSUMMARY_H
#define MSGSUMMARY_H

#include <QWidget>

namespace Ui {
class MsgSummary;
}

class MsgSummary : public QWidget
{
    Q_OBJECT

public:
    explicit MsgSummary(QWidget *parent = 0);
    ~MsgSummary();

private:
    Ui::MsgSummary *ui;
};

#endif // MSGSUMMARY_H
