#include "public.h"
#include "stdint.h"

uint64_t ONE = 1;

//                            Wang              Li              Sun
uint64_t RECEIVER_ID[] = { ((ONE<<30)|1),  ((ONE<<31)|1),  ((ONE<<30)|2)};
char* NAMES[] =            {   "王老师",         "李老师",        "孙老师"};

//                         Internet                     SupberBahn
char* WS_SERVER[] =  {"ws://10.208.104.9:8080/", "ws://58.240.113.38:10003/"};
char* ZMQ_SERVER[] = {"tcp://10.208.104.9:5557", "tcp://58.240.113.38:10017"};
char* MAC_ADDR;
char* NAME;

int curEnv;

int MY_ID;
int SENDER;
int MSG_SVR_ID;

LogStore logStore;
