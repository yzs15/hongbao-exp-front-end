#include "apiutils.h"
#include <QDebug>


/* ZMQ */
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
    zsock_t *socket = zsock_cache[zi].sock;

    obj->sender = SENDER;
    char *raw = Q_NULLPTR;
    int len = obj->toBytes(&raw);

    zframe_t *frame = zframe_new(raw, len);
    time_t sendTime = get_current_ns_timestamp();
    int ok = zframe_send(&frame, socket, 0);
    if (ok != 0) {
        qDebug() << "zmq send message failed, " << ok;
    }

    zframe_destroy(&frame);
    zsock_cache[zi].in_use = false;

    // qDebug() << time_t2str(sendTime) << "util send a message, size:" << len;
    return sendTime;
}
