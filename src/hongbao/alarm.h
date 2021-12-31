#ifndef MSGSENDER_H
#define MSGSENDER_H

#include <QtWebSockets/QtWebSockets>
#include <QObject>
#include "public.h"
#include "commutils.h"
#include "apiutils.h"
#include <czmq.h>

class Alarm : public QThread
{
    Q_OBJECT
public:
    Alarm(QObject* parent=0, time_t sendTime = 0, MsgObj* obj = 0);
    ~Alarm();

    time_t reqSendTime;
    MsgObj *msgObj;

signals:
    void timeOut(Alarm* alarm);

protected:
    void run();
};

#endif // MSGSENDER_H
