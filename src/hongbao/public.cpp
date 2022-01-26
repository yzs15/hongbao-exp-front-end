#include "public.h"
#include "stdint.h"

uint64_t ONE = 1;

int WHOAMI;
//                            Wang                  Li                   Sun
uint64_t RECEIVER_ID[] = {  DID(2,1),             DID(1,2),           DID(1,1)};
char* NAMES[] =          {  "开发团队",             "彭老师",             "王老师"};
char *MAC_ADDRS[] =      {"02:42:ac:13:00:01", "02:42:ac:13:00:02", "02:42:ac:13:00:03"};

//                         Internet                     SupberBahn
char* WS_SERVER[] =  {"ws://10.208.104.9:8080/", "ws://58.240.113.38:10003/"};
char* ZMQ_SERVER[] = {"tcp://10.208.104.9:5557", "tcp://58.240.113.38:10017"};

int curEnv;
uint64_t SENDER;

LogStore logStore;

int THING_NUM = 1;
int THING_IDS[] = { DID(2, 2) };

int LOG_ANALYZER_ID = DID(2, 3);

clockid_t CLK_ID;
