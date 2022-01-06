#include "countdown.h"

Countdown::Countdown(QObject* parent, time_t t, QLabel* b)
    : QThread(parent), startTime(t), board(b)
{

}

Countdown::~Countdown() {
}

void Countdown::run() {
    time_t curTime = get_current_ns_timestamp();
    while (curTime < this->startTime) {
        curTime = get_current_ns_timestamp();
        time_t remain = (startTime - curTime) / 1e9;
        this->board->setText(QString::number(remain));
        this->board->update();
        sleep(1);
    }
}
