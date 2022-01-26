/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hongbao/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "createSocket"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "onConnected"
QT_MOC_LITERAL(4, 37, 16), // "onBinaryReceived"
QT_MOC_LITERAL(5, 54, 6), // "msgRaw"
QT_MOC_LITERAL(6, 61, 14), // "onTextReceived"
QT_MOC_LITERAL(7, 76, 3), // "msg"
QT_MOC_LITERAL(8, 80, 14), // "onDisConnected"
QT_MOC_LITERAL(9, 95, 15), // "onNetBtnClicked"
QT_MOC_LITERAL(10, 111, 15), // "onSpbBtnClicked"
QT_MOC_LITERAL(11, 127, 15), // "onSubBtnClicked"
QT_MOC_LITERAL(12, 143, 20), // "onRedirectBtnClicked"
QT_MOC_LITERAL(13, 164, 18), // "onThingHideChanged"
QT_MOC_LITERAL(14, 183, 13), // "onMsgSelected"
QT_MOC_LITERAL(15, 197, 7), // "MsgBox*"
QT_MOC_LITERAL(16, 205, 3), // "obj"
QT_MOC_LITERAL(17, 209, 11), // "onMsgSended"
QT_MOC_LITERAL(18, 221, 6), // "Alarm*"
QT_MOC_LITERAL(19, 228, 5), // "alarm"
QT_MOC_LITERAL(20, 234, 14), // "onMsgProcessed"
QT_MOC_LITERAL(21, 249, 7) // "MsgObj*"

    },
    "MainWindow\0createSocket\0\0onConnected\0"
    "onBinaryReceived\0msgRaw\0onTextReceived\0"
    "msg\0onDisConnected\0onNetBtnClicked\0"
    "onSpbBtnClicked\0onSubBtnClicked\0"
    "onRedirectBtnClicked\0onThingHideChanged\0"
    "onMsgSelected\0MsgBox*\0obj\0onMsgSended\0"
    "Alarm*\0alarm\0onMsgProcessed\0MsgObj*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       6,    1,   84,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,
      17,    1,   96,    2, 0x08 /* Private */,
      20,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createSocket(); break;
        case 1: _t->onConnected(); break;
        case 2: _t->onBinaryReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->onTextReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onDisConnected(); break;
        case 5: _t->onNetBtnClicked(); break;
        case 6: _t->onSpbBtnClicked(); break;
        case 7: _t->onSubBtnClicked(); break;
        case 8: _t->onRedirectBtnClicked(); break;
        case 9: _t->onThingHideChanged(); break;
        case 10: _t->onMsgSelected((*reinterpret_cast< MsgBox*(*)>(_a[1]))); break;
        case 11: _t->onMsgSended((*reinterpret_cast< Alarm*(*)>(_a[1]))); break;
        case 12: _t->onMsgProcessed((*reinterpret_cast< MsgObj*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MsgBox* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Alarm* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
