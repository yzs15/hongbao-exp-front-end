#ifndef PUBLIC_H
#define PUBLIC_H

#define ENV_NAME "Hongbao"

#define INTERNET 0
#define SUPERBAHN 1

#define WANG  0
#define LI    1
#define SUN   2

#define SLEEP_THRESHOLD_NS 120000
#define SLEEP_DURATION_NS 100000

#define PROOF_TIME    (100)
#define ANALYSIS_TIME (30)
#define PREPARE_TIME  (30)
#define WAIT_TIME     (100)
#define B_WAIT_TIME   (25)
#define HONGBAO_TIME  (10)

#define ID_LEN 20
#define SID(id)         (id & ((1<<ID_LEN)-1))
#define CID(id)         ((id >> ID_LEN) & ((1<<ID_LEN)-1))
#define DID(sid, cid)   ((cid<<ID_LEN)|sid)
#define MID(aid, mid)   ((uint64_t(mid)<<(2*ID_LEN)) | aid)
#define DMID(id)        (id>>(2*ID_LEN))
#define BROADCASE_ID    ((uint64_t(1)<<(2*ID_LEN))-1)

#define full (uint8_t((1<<8)-1))

#include <QString>
#include "logstore.h"


// People
extern int WHOAMI;
extern char *NAMES[];
extern uint64_t RECEIVER_ID[];
extern char *MAC_ADDRS[];

// Internet and SuperBahn environment
extern int curEnv;
extern char* WS_SERVER[];
extern char* ZMQ_SERVER[];

extern int THING_NUM;
extern int THING_IDS[];

extern int LOG_ANALYZER_ID;

extern uint64_t SENDER;

extern clockid_t CLK_ID;

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
