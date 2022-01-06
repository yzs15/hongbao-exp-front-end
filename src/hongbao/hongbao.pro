#-------------------------------------------------
#
# Project created by QtCreator 2021-12-10T04:19:32
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hongbao
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    msgfield.cpp \
    msgbox.cpp \
    userform.cpp \
    msgdetail.cpp \
    apiutils.cpp \
    commutils.cpp \
    alarm.cpp \
    msgsummary.cpp \
    public.cpp \
    logstore.cpp \
    countdown.cpp

HEADERS += \
        mainwindow.h \
    msgfield.h \
    msgbox.h \
    userform.h \
    msgdetail.h \
    public.h \
    apiutils.h \
    commutils.h \
    alarm.h \
    msgsummary.h \
    logstore.h \
    countdown.h

FORMS += \
        mainwindow.ui \
    msgbox.ui \
    msgdetail.ui \
    msgsummary.ui

unix:!macx: LIBS += -L$$PWD/../lib/ -lczmq

# INCLUDEPATH += $$PWD/../include
# DEPENDPATH += $$PWD/../include

# unix:!macx: LIBS += -L$$PWD/../lib/ -lzmq

# INCLUDEPATH += $$PWD/../include
# DEPENDPATH += $$PWD/../include
