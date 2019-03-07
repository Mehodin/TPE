/****************************************************************************
** Meta object code from reading C++ file 'packetLogger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../packetLogger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packetLogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PacketLogger_t {
    QByteArrayData data[7];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PacketLogger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PacketLogger_t qt_meta_stringdata_PacketLogger = {
    {
QT_MOC_LITERAL(0, 0, 12), // "PacketLogger"
QT_MOC_LITERAL(1, 13, 10), // "attemptLog"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "incomingPacket"
QT_MOC_LITERAL(4, 40, 13), // "PacketObject*"
QT_MOC_LITERAL(5, 54, 7), // "process"
QT_MOC_LITERAL(6, 62, 11) // "stopLogging"

    },
    "PacketLogger\0attemptLog\0\0incomingPacket\0"
    "PacketObject*\0process\0stopLogging"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PacketLogger[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   40,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PacketLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PacketLogger *_t = static_cast<PacketLogger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->attemptLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->incomingPacket((*reinterpret_cast< PacketObject*(*)>(_a[1]))); break;
        case 2: _t->process(); break;
        case 3: _t->stopLogging(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PacketLogger::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketLogger::attemptLog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PacketLogger::*)(PacketObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PacketLogger::incomingPacket)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PacketLogger::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_PacketLogger.data,
    qt_meta_data_PacketLogger,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PacketLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PacketLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PacketLogger.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PacketLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PacketLogger::attemptLog(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PacketLogger::incomingPacket(PacketObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
