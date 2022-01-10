#ifndef PUBLIC_H
#define PUBLIC_H

#define ENV_NAME "Hongbao"

#define INTERNET 0
#define SUPERBAHN 1

#define SLEEP_THRESHOLD_NS 120000
#define SLEEP_DURATION_NS 100000

#define SID(id) (id & ((1<<30)-1))
#define CID(id) (id >> 30)

#include <QString>
#include "logstore.h"

extern char *NAMES[];

extern char* WS_SERVER[];
extern char* ZMQ_SERVER[];
extern uint64_t RECEIVER_ID[];
extern char* MAC_ADDR;
extern char* NAME;

extern int curEnv;

extern int MY_ID;
extern int SENDER;
extern int MSG_SVR_ID;

extern LogStore logStore;


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
