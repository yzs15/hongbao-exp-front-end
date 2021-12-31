#include "logstore.h"

LogStore::LogStore() {

}

void LogStore::add(int curEnv, uint64_t mid, time_t timestamp, QString event) {
    Log log;
    log.mid = mid;
    log.timestamp = timestamp;
    log.event = event;
    this->logs[curEnv].push_back(log);
}
