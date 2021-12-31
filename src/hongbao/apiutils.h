#ifndef APIUTILS_H
#define APIUTILS_H

#include <QtWebSockets/QtWebSockets>
#include "public.h"
#include "commutils.h"

class MsgSendObj {
public:
    QString id  ="";
    QString author = "";
    QString type = "";
    QString content = "";
    time_t sendTimestamp = -1;

    time_t endBefore = -1;
    time_t reqTimestamp = -1;
    QString reqSender = "";
    QString reqContent = "";
};

QJsonObject makeMsgJson(MsgObj* param);

// 通过 WebSocket 发送消息，并返回发送时间
time_t sendMsg(QWebSocket *ws, MsgSendObj* param);

#endif // APIUTILS_H
