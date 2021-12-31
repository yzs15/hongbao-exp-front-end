#include "alarm.h"

Alarm::Alarm(QObject* parent, time_t sendTime, MsgObj* obj) :
    QThread(parent)
{
    this->reqSendTime = sendTime;
    this->msgObj = obj;
}

Alarm::~Alarm() {
    delete this->msgObj;
}

void Alarm::run() {
    zsock_t *socket = zsock_new_push(ZMQ_SERVER[curEnv]);
    zmsg_t *msg = zmsg_new();
    QJsonObject json = makeMsgJson(this->msgObj);

    ns_sleep_until(this->reqSendTime, SLEEP_THRESHOLD_NS);

    QJsonDocument doc(json);
    QString payload = doc.toJson(QJsonDocument::Compact);

    zmsg_addstr(msg, payload.toStdString().c_str());

    time_t sendTime = get_current_ns_timestamp();
    int ok = zmsg_send(&msg, socket);
    if (ok != 0) {
        qDebug() << "zmq send message failel, " << ok;
    }

    zmsg_destroy(&msg);
    zsock_destroy(&socket);
    qDebug() << "zmq send a message: " << payload << " at " << sendTime;
    logStore.add(curEnv, this->msgObj->id, sendTime, "SenderSended");
}
