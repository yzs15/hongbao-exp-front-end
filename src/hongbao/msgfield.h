#ifndef MSGFIELD_H
#define MSGFIELD_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QList>
#include "msgbox.h"
#include "public.h"

class MsgField : public QWidget
{
     Q_OBJECT
public:
    MsgField();

    void addMsg(MsgObj *obj);
    void setThingHidden(bool hidden);
    void clear();

signals:
    void msgSelected(MsgDetailObj* obj);

private:
    QList<MsgBox*> msgBoxs;
    QLayout *msgFieldLayout;

private slots:
    void onMsgBoxClicked(MsgDetailObj* obj);
};

#endif // MSGFIELD_H
