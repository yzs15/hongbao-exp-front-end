#include "countdown.h"

Countdown::Countdown(QObject* parent, time_t t, QLabel* b, QString te)
    : QThread(parent), startTime(t), board(b), temp(te)
{

}

Countdown::~Countdown() {
}

void Countdown::run() {
    time_t curTime = get_current_ns_timestamp();
    while (curTime < this->startTime && !this->stop) {
        time_t remain = (startTime - curTime) / 1e9;
        this->board->setText(temp.arg(remain));
        this->board->update();
        sleep(1);
        curTime = get_current_ns_timestamp();
    }
}
