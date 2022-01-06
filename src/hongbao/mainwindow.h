#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWebSockets/QtWebSockets>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTime>
#include <QSpinBox>
#include <QMap>
#include "msgfield.h"
#include "userform.h"
#include "msgdetail.h"
#include "public.h"
#include "apiutils.h"
#include "alarm.h"
#include "msgsummary.h"
#include "commutils.h"
#include "countdown.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void createSocket();

private:
    Ui::MainWindow *ui;
    MsgField *msgField;
    MsgSummary* msgSumArea;

    QWebSocket *socket;

    QDateTime sendDate;
    QDateTime sendTime;
    int sendMs;
    int sendUs;

    void start();
    void handleMessage(QJsonObject &json, time_t receivedTime);

private slots:
    // WebScoket
    void onConnected();
    void onTextReceived(QString msg);
    void onDisConnected();

    // input change
    void onDateChanged(const QDateTime& newDate);
    void onTimeChanged(const QDateTime& newTime);
    void onMsChanged(const int newVal);
    void onUsChanged(const int oldVal);

    // send message
    void onNetBtnClicked();
    void onSpbBtnClicked();

    void onThingHideChanged();

    void onMsgSelected(MsgDetailObj* obj);
};

#endif // MAINWINDOW_H
