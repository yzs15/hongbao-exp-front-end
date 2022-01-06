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
    QString me;
};


class LogStore
{
public:
    LogStore(QString me = "");

    QString me;

    void add(int curEnv, uint64_t mid, time_t timestamp, QString event);

private:
    vector<Log> logs[2];
};

#endif // LOGSTORE_H
