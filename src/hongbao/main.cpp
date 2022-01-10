#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include "public.h"

//                        Beijing                     Nanjing
char *ws_end_net[] = {"ws://10.208.104.9:8080/", "ws://172.16.32.12:8080/"};
char *zmq_end_net[] = {"tcp://10.208.104.9:5557", "tcp://172.16.32.12:5557"};

char *ws_end_spb[] = {"ws://10.208.104.9:8080/", "ws://172.16.32.12:8080/"};
char *zmq_end_spb[] = {"tcp://10.208.104.9:5557", "tcp://172.16.32.12:5557"};

char *mac_addr[] = {
    "02:42:ac:13:00:01",
    "02:42:ac:13:00:02",
    "02:42:ac:13:00:03"
};

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("need SID CID");
        exit(1);
    }

    int sid = atoi(argv[1]);
    int cid = atoi(argv[2]);

    WS_SERVER[0] = ws_end_net[sid - 1];
    WS_SERVER[1] = ws_end_spb[sid - 1];

    ZMQ_SERVER[0] = zmq_end_net[sid - 1];
    ZMQ_SERVER[1] = zmq_end_spb[sid - 1];

    if (sid == 1) {
        MAC_ADDR = mac_addr[cid - 1];
        NAME = NAMES[cid - 1];
    } else {
        MAC_ADDR = mac_addr[2];
        NAME = NAMES[2];
    }


    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
