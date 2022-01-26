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
    int zi = getZsock();
    zsock_t *socket = zsock_cache[zi].sock;
    this->msgObj->sender = SENDER;

    char *raw = Q_NULLPTR;
    int len = this->msgObj->toBytes(&raw);

    ns_sleep_until(this->reqSendTime, SLEEP_THRESHOLD_NS);

    time_t now = get_current_ptp_timestamp();
    // time_t now = get_current_ns_timestamp();
    memcpy(raw+len-8, &now, 8);

    zframe_t *frame = zframe_new(raw, len);
    int ok = zframe_send(&frame, socket, 0);
    if (ok != 0) {
        qDebug() << "zmq send message failel, " << ok;
    }

    zframe_destroy(&frame);
    zsock_cache[zi].in_use = false;

    MsgObj* newObj = char2msg(raw, len);
    time_t sendTime = newObj->sendTime;
    delete newObj;
    delete raw;

    qDebug() << time_t2str(sendTime) << "util send a message, size:" << len;
    logStore.add(curEnv, this->msgObj->id, sendTime, "SenderSended");

    emit this->timeOut(this);
}
