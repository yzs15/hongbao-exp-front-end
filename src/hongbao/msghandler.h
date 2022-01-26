#ifndef MSGHANDLER_H
#define MSGHANDLER_H

#include <QObject>
#include "message.h"
#include "public.h"
#include "apiutils.h"

class MsgHandler: public QObject, public QRunnable
{
    Q_OBJECT
public:
    MsgHandler(MsgObj* msg = Q_NULLPTR, time_t received_time = 0);

    MsgObj* msg;
    time_t received_time;

protected:
    void run();

signals:
    void processed(MsgObj* msg);
};

#endif // MSGHANDLER_H
