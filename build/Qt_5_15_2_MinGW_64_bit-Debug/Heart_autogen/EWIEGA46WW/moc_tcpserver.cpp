/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpServer_t {
    QByteArrayData data[16];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpServer_t qt_meta_stringdata_TcpServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpServer"
QT_MOC_LITERAL(1, 10, 11), // "msgReceived"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "Protocol"
QT_MOC_LITERAL(4, 32, 3), // "msg"
QT_MOC_LITERAL(5, 36, 11), // "QTcpSocket*"
QT_MOC_LITERAL(6, 48, 6), // "socket"
QT_MOC_LITERAL(7, 55, 14), // "shakeRequested"
QT_MOC_LITERAL(8, 70, 8), // "senderId"
QT_MOC_LITERAL(9, 79, 12), // "fileReceived"
QT_MOC_LITERAL(10, 92, 18), // "newClientConnected"
QT_MOC_LITERAL(11, 111, 7), // "sendAck"
QT_MOC_LITERAL(12, 119, 4), // "uuid"
QT_MOC_LITERAL(13, 124, 15), // "onNewConnection"
QT_MOC_LITERAL(14, 140, 11), // "onReadyRead"
QT_MOC_LITERAL(15, 152, 14) // "onDisconnected"

    },
    "TcpServer\0msgReceived\0\0Protocol\0msg\0"
    "QTcpSocket*\0socket\0shakeRequested\0"
    "senderId\0fileReceived\0newClientConnected\0"
    "sendAck\0uuid\0onNewConnection\0onReadyRead\0"
    "onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       7,    1,   59,    2, 0x06 /* Public */,
       9,    1,   62,    2, 0x06 /* Public */,
      10,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   68,    2, 0x0a /* Public */,
      13,    0,   73,    2, 0x08 /* Private */,
      14,    0,   74,    2, 0x08 /* Private */,
      15,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString,    6,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->msgReceived((*reinterpret_cast< const Protocol(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        case 1: _t->shakeRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->fileReceived((*reinterpret_cast< const Protocol(*)>(_a[1]))); break;
        case 3: _t->newClientConnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sendAck((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->onNewConnection(); break;
        case 6: _t->onReadyRead(); break;
        case 7: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpServer::*)(const Protocol & , QTcpSocket * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::msgReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::shakeRequested)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(const Protocol & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::fileReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::newClientConnected)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpServer.data,
    qt_meta_data_TcpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TcpServer::msgReceived(const Protocol & _t1, QTcpSocket * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServer::shakeRequested(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServer::fileReceived(const Protocol & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpServer::newClientConnected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
