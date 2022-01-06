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
    json["SendTime"] = qlonglong(param->sendTime);

    return json;
}

typedef struct zsock_cache_s {
    zsock_t* sock;
    bool in_use;
} zsock_cache_t;
pthread_mutex_t utils_zsock_cache_mutex = PTHREAD_MUTEX_INITIALIZER;
vector<zsock_cache_t> zsock_cache;

bool try_use_sock(zsock_cache_t* zsock_cache_vlaue){
    bool ok = __sync_bool_compare_and_swap(&(zsock_cache_vlaue->in_use), false, true);
    return ok;
}

int getZsock() {
    for (int i = 0; i < zsock_cache.size(); i++) {
        if (zsock_cache[i].in_use) continue;
        if (try_use_sock(&zsock_cache[i])) {
            return i;
        }
    }

    zsock_cache_t tmp;
    tmp.sock = zsock_new_push(ZMQ_SERVER[curEnv]);
    tmp.in_use = true;
    pthread_mutex_lock(&utils_zsock_cache_mutex);
    zsock_cache.push_back(tmp);
    int i = zsock_cache.size() - 1;
    pthread_mutex_unlock(&utils_zsock_cache_mutex);
    return i;
}

time_t zmqSend(char* endpoint, MsgObj *obj) {
    int zi = getZsock();
    zsock_t *sock = zsock_cache[zi].sock;
    zmsg_t *msg = zmsg_new();

    QJsonObject json = makeMsgJson(obj);
    QJsonDocument doc(json);
    QString payload = doc.toJson(QJsonDocument::Compact);

    zmsg_addstr(msg, payload.toStdString().c_str());

    time_t sendTime = get_current_ns_timestamp();
    int ok = zmsg_send(&msg, sock);
    if (ok != 0) {
        qDebug() << "zmq send message failed, " << ok;
    }

    zmsg_destroy(&msg);

    qDebug() << "zmq send a message: " << payload <<  " to " << endpoint << " at " << sendTime;

    zsock_cache[zi].in_use = false;
    return sendTime;
}
