#include "logstore.h"

LogStore::LogStore(QString me) {
    this->me = me;
}

void LogStore::add(int curEnv, uint64_t mid, time_t timestamp, QString event) {
    Log log;
    log.mid = mid;
    log.timestamp = timestamp;
    log.event = event;
    log.me = this->me;
    this->logs[curEnv].push_back(log);
}
