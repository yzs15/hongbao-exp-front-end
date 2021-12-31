#ifndef LOGSTORE_H
#define LOGSTORE_H

#include <QString>
#include <vector>
using std::vector;

class Log {
public:
    uint64_t mid;
    time_t timestamp;
    QString event;
};


class LogStore
{
public:
    LogStore();

    void add(int curEnv, uint64_t mid, time_t timestamp, QString event);

private:
    vector<Log> logs[2];
};

#endif // LOGSTORE_H
