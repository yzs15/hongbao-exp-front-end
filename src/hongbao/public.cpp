#include "public.h"

char* WS_SERVER[] = {"ws://172.16.7.1:5554/", "ws://127.0.0.1:8080/ws"};
char* ZMQ_SERVER[] = {"tcp://172.16.7.1:5553", "tcp://127.0.0.1:8081"};

int curEnv;

LogStore logStore;
