/****************************************************************************
** Meta object code from reading C++ file 'chatpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../chatpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatPage_t {
    QByteArrayData data[16];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatPage_t qt_meta_stringdata_ChatPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ChatPage"
QT_MOC_LITERAL(1, 9, 10), // "onSendText"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "onSendImg"
QT_MOC_LITERAL(4, 31, 11), // "onSendShake"
QT_MOC_LITERAL(5, 43, 10), // "onSendFile"
QT_MOC_LITERAL(6, 54, 12), // "onScreenShot"
QT_MOC_LITERAL(7, 67, 9), // "onConnect"
QT_MOC_LITERAL(8, 77, 11), // "onConnected"
QT_MOC_LITERAL(9, 89, 8), // "friendId"
QT_MOC_LITERAL(10, 98, 15), // "onConnectFailed"
QT_MOC_LITERAL(11, 114, 13), // "onMsgReceived"
QT_MOC_LITERAL(12, 128, 8), // "Protocol"
QT_MOC_LITERAL(13, 137, 3), // "msg"
QT_MOC_LITERAL(14, 141, 11), // "QTcpSocket*"
QT_MOC_LITERAL(15, 153, 6) // "socket"

    },
    "ChatPage\0onSendText\0\0onSendImg\0"
    "onSendShake\0onSendFile\0onScreenShot\0"
    "onConnect\0onConnected\0friendId\0"
    "onConnectFailed\0onMsgReceived\0Protocol\0"
    "msg\0QTcpSocket*\0socket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      11,    2,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,

       0        // eod
};

void ChatPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSendText(); break;
        case 1: _t->onSendImg(); break;
        case 2: _t->onSendShake(); break;
        case 3: _t->onSendFile(); break;
        case 4: _t->onScreenShot(); break;
        case 5: _t->onConnect(); break;
        case 6: _t->onConnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onConnectFailed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onMsgReceived((*reinterpret_cast< const Protocol(*)>(_a[1])),(*reinterpret_cast< QTcpSocket*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChatPage.data,
    qt_meta_data_ChatPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
