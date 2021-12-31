#ifndef MSGDETAIL_H
#define MSGDETAIL_H

#include <QWidget>
#include "public.h"
#include "commutils.h"

namespace Ui {
class MsgDetail;
}

class MsgDetail : public QWidget
{
    Q_OBJECT

public:
    explicit MsgDetail(QWidget *parent = 0);
    ~MsgDetail();

    void setObj(MsgDetailObj* obj);
    void rerender();

private:
    Ui::MsgDetail *ui;

    MsgDetailObj obj;
};

#endif // MSGDETAIL_H
