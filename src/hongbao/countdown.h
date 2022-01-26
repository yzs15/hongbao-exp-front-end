#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QLabel>
#include <commutils.h>
#include <QThread>

class Countdown: public QThread
{
    Q_OBJECT
public:
    Countdown(QObject* parent=0, time_t t = 0, QLabel* b = Q_NULLPTR, QString te = "");
    ~Countdown();

    QLabel* board;
    time_t startTime;
    QString temp;

    bool stop = false;

    void run();
};

#endif // COUNTDOWN_H
