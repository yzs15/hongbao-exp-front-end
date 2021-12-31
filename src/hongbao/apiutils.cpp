#include "apiutils.h"
#include <QDebug>

time_t sendMsg(QWebSocket *ws, MsgObj* param) {
    QJsonObject json = makeMsgJson(param);
    QJsonDocument doc(json);
    QString payload = doc.toJson(QJsonDocument::Compact);

    time_t sendTime = get_current_ns_timestamp();
    ws->sendTextMessage(payload);
    qDebug() << "websocket send a message: " << payload;

    return sendTime;
}

QJsonObject makeMsgJson(MsgObj* param) {
    QJsonObject json;

    json["ID"] = qlonglong(param->id);
    json["Sender"] = qlonglong(param->sender);
    json["Good"] = param->good;
    json["Content"] = param->content;

    return json;
}
