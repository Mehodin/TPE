/****************************************************************************
** Meta object code from reading C++ file 'TogetherPE.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TogetherPE.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TogetherPE.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TogetherPE_t {
    QByteArrayData data[8];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TogetherPE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TogetherPE_t qt_meta_stringdata_TogetherPE = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TogetherPE"
QT_MOC_LITERAL(1, 11, 12), // "stopSniffing"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "startLogging"
QT_MOC_LITERAL(4, 38, 7), // "logText"
QT_MOC_LITERAL(5, 46, 14), // "incomingPacket"
QT_MOC_LITERAL(6, 61, 13), // "PacketObject*"
QT_MOC_LITERAL(7, 75, 1) // "p"

    },
    "TogetherPE\0stopSniffing\0\0startLogging\0"
    "logText\0incomingPacket\0PacketObject*\0"
    "p"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TogetherPE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       5,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void TogetherPE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TogetherPE *_t = static_cast<TogetherPE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopSniffing(); break;
        case 1: _t->startLogging(); break;
        case 2: _t->logText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->incomingPacket((*reinterpret_cast< PacketObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TogetherPE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TogetherPE::stopSniffing)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TogetherPE::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_TogetherPE.data,
    qt_meta_data_TogetherPE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TogetherPE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TogetherPE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TogetherPE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TogetherPE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void TogetherPE::stopSniffing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
