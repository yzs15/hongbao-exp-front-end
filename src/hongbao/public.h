#ifndef PUBLIC_H
#define PUBLIC_H

#define ENV_NAME "信息高速公路"

#define INTERNET 0
#define SUPERBAHN 1

#define SENDER 1
#define MID(id) (((uint64_t)(SENDER) << 32) | id)

#define JOIN_MSG "join"
#define INSTANT_MSG "now"
#define DETAIL_MSG "detail"
#define TASK_MSG "task"

#define SLEEP_THRESHOLD_NS 120000
#define SLEEP_DURATION_NS 100000

#define MSG_ID_LEN 8

#include <QString>
#include "logstore.h"

extern char* WS_SERVER[];
extern char* ZMQ_SERVER[];

extern int curEnv;

extern LogStore logStore;

class MsgObj {
public:
    uint64_t id = 0;
    uint32_t sender = SENDER;
    bool good = true;
    QString content = "";
};

class MsgDetailObj {
public:
    QString id = "";
    QString sender = "";
    QString content = "";
    time_t endBefore = -1;

    time_t senderSended = -1;  // WebSocket 返回消息中要求类型为 string
    time_t serverReceived = -1; // WebSocket 返回消息中要求类型为 string
    time_t serverResponsed = -1; // WebSocket 返回消息中要求类型为 string
    time_t receiverReceived = -1;
};

#endif // PUBLIC_H
