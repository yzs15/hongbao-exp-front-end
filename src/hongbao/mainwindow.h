#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWebSockets/QtWebSockets>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTime>
#include <QRadioButton>
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
#include "message.h"
#include "hbopened.h"
#include "commutils.h"
#include "msghandler.h"

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

    QRadioButton* hbRadios[9];

    QWebSocket *socket;
    QThreadPool pool;

    int mid = 1;
    bool hidden = false;

    int recvMsgNum = 0;
    int recvHbAmount = 0;

    //QDateTime sendDate;
    //QDateTime sendTime;
    //int sendMs;
    //int sendUs;

    MsgObj* proofMsg = Q_NULLPTR;

    HBOpened* hbOpened = Q_NULLPTR;

    Alarm* alarm;
    Countdown* countdown;

    void testAndBuildProof();
    void handleMessage(MsgObj *obj, time_t receivedTime);
    void handleProof(MsgObj *obj, time_t receivedTime);
    void handleNotice(MsgObj *recvObj, time_t receivedTime);
    void handleText(MsgObj* obj, time_t receivedTime);
    void handleTest(MsgObj* obj, time_t receivedTime);

    void add2field(MsgField* field, MsgObj* obj);

private slots:
    // WebScoket
    void onConnected();
    void onBinaryReceived(QByteArray msgRaw);
    void onTextReceived(QString msg);
    void onDisConnected();

    // input change
    //void onDateChanged(const QDateTime& newDate);
    //void onTimeChanged(const QDateTime& newTime);
    //void onMsChanged(const int newVal);
    //void onUsChanged(const int oldVal);

    // send message
    void onNetBtnClicked();
    void onSpbBtnClicked();
    void onSubBtnClicked();
    void onRedirectBtnClicked();

    void onThingHideChanged();

    void onMsgSelected(MsgBox* obj);

    void onMsgSended(Alarm* alarm);

    void onMsgProcessed(MsgObj* obj);
};

#endif // MAINWINDOW_H
