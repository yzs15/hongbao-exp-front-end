#include "public.h"

char* WS_SERVER[] = {"ws://58.213.121.2:10022/", "ws://58.240.113.38:10003/"};
char* ZMQ_SERVER[] = {"tcp://58.213.121.2:10025", "tcp://58.240.113.38:10017"};

int curEnv;

LogStore logStore;
