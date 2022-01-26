#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include "public.h"
#include <QScreen>
#include "all_clock.h"

//                        Beijing                     Nanjing
char *ws_end_net[] = {"ws://10.208.104.9:8082/", "ws://192.168.143.4:8082/"};
char *zmq_end_net[] = {"tcp://10.208.104.9:8081", "tcp://192.168.143.4:8081"};

char *ws_end_spb[] = {"ws://10.208.104.3:8082/", "ws://192.168.143.1:8082/"};
char *zmq_end_spb[] = {"tcp://10.208.104.3:8081", "tcp://192.168.143.1:8081"};

char *mac_addr[] = {
    "02:42:ac:13:00:01",
    "02:42:ac:13:00:02",
    "02:42:ac:13:00:03"
};

int main(int argc, char *argv[])
{
    // qputenv("QT_SCALE_FACTOR", QString::number(2.0).toLatin1());

    int sid;
    int cid;
    if (argc < 3) {
        sid = 1;
        cid = 1;
    } else {
        sid = atoi(argv[1]);
        cid = atoi(argv[2]);
    }

    WS_SERVER[0] = ws_end_net[sid - 1];
    WS_SERVER[1] = ws_end_spb[sid - 1];

    ZMQ_SERVER[0] = zmq_end_net[sid - 1];
    ZMQ_SERVER[1] = zmq_end_spb[sid - 1];

    if (sid == 2 && cid == 1) {
        WHOAMI = WANG;
    } else if (sid == 1 && cid == 1) {
        WHOAMI = SUN;
        //qputenv("QT_SCALE_FACTOR", "2.0");
    } else {
        WHOAMI = LI;
    }

    if (WHOAMI == WANG) {
        CLK_ID = utils_get_clockid("/dev/ptp0");
    } else {
        CLK_ID = utils_get_clockid("/dev/ptp0");
    }

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
