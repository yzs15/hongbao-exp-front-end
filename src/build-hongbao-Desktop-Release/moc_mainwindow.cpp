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
    QByteArrayData data[27];
    char stringdata0[301];
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
QT_MOC_LITERAL(9, 95, 13), // "onDateChanged"
QT_MOC_LITERAL(10, 109, 7), // "newDate"
QT_MOC_LITERAL(11, 117, 13), // "onTimeChanged"
QT_MOC_LITERAL(12, 131, 7), // "newTime"
QT_MOC_LITERAL(13, 139, 11), // "onMsChanged"
QT_MOC_LITERAL(14, 151, 6), // "newVal"
QT_MOC_LITERAL(15, 158, 11), // "onUsChanged"
QT_MOC_LITERAL(16, 170, 6), // "oldVal"
QT_MOC_LITERAL(17, 177, 15), // "onNetBtnClicked"
QT_MOC_LITERAL(18, 193, 15), // "onSpbBtnClicked"
QT_MOC_LITERAL(19, 209, 15), // "onSubBtnClicked"
QT_MOC_LITERAL(20, 225, 18), // "onThingHideChanged"
QT_MOC_LITERAL(21, 244, 13), // "onMsgSelected"
QT_MOC_LITERAL(22, 258, 13), // "MsgDetailObj*"
QT_MOC_LITERAL(23, 272, 3), // "obj"
QT_MOC_LITERAL(24, 276, 11), // "onMsgSended"
QT_MOC_LITERAL(25, 288, 6), // "Alarm*"
QT_MOC_LITERAL(26, 295, 5) // "alarm"

    },
    "MainWindow\0createSocket\0\0onConnected\0"
    "onBinaryReceived\0msgRaw\0onTextReceived\0"
    "msg\0onDisConnected\0onDateChanged\0"
    "newDate\0onTimeChanged\0newTime\0onMsChanged\0"
    "newVal\0onUsChanged\0oldVal\0onNetBtnClicked\0"
    "onSpbBtnClicked\0onSubBtnClicked\0"
    "onThingHideChanged\0onMsgSelected\0"
    "MsgDetailObj*\0obj\0onMsgSended\0Alarm*\0"
    "alarm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    1,   98,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,
      19,    0,  112,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,
      21,    1,  114,    2, 0x08 /* Private */,
      24,    1,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   10,
    QMetaType::Void, QMetaType::QDateTime,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25,   26,

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
        case 5: _t->onDateChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 6: _t->onTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 7: _t->onMsChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 8: _t->onUsChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->onNetBtnClicked(); break;
        case 10: _t->onSpbBtnClicked(); break;
        case 11: _t->onSubBtnClicked(); break;
        case 12: _t->onThingHideChanged(); break;
        case 13: _t->onMsgSelected((*reinterpret_cast< MsgDetailObj*(*)>(_a[1]))); break;
        case 14: _t->onMsgSended((*reinterpret_cast< Alarm*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
