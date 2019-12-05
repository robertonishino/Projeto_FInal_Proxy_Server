/****************************************************************************
** Meta object code from reading C++ file 'aracne.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Aracne/aracne.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aracne.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Aracne_t {
    QByteArrayData data[13];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Aracne_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Aracne_t qt_meta_stringdata_Aracne = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Aracne"
QT_MOC_LITERAL(1, 7, 12), // "send_request"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "send_reply"
QT_MOC_LITERAL(4, 32, 7), // "turn_on"
QT_MOC_LITERAL(5, 40, 8), // "turn_off"
QT_MOC_LITERAL(6, 49, 8), // "set_mode"
QT_MOC_LITERAL(7, 58, 24), // "on_requestButton_clicked"
QT_MOC_LITERAL(8, 83, 22), // "on_replyButton_clicked"
QT_MOC_LITERAL(9, 106, 28), // "on_startServerButton_clicked"
QT_MOC_LITERAL(10, 135, 27), // "on_stopServerButton_clicked"
QT_MOC_LITERAL(11, 163, 11), // "new_request"
QT_MOC_LITERAL(12, 175, 9) // "new_reply"

    },
    "Aracne\0send_request\0\0send_reply\0turn_on\0"
    "turn_off\0set_mode\0on_requestButton_clicked\0"
    "on_replyButton_clicked\0"
    "on_startServerButton_clicked\0"
    "on_stopServerButton_clicked\0new_request\0"
    "new_reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Aracne[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       3,    2,   74,    2, 0x06 /* Public */,
       4,    0,   79,    2, 0x06 /* Public */,
       5,    0,   80,    2, 0x06 /* Public */,
       6,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    2,   88,    2, 0x0a /* Public */,
      12,    2,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    2,    2,

       0        // eod
};

void Aracne::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Aracne *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_request((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->send_reply((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->turn_on(); break;
        case 3: _t->turn_off(); break;
        case 4: _t->set_mode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_requestButton_clicked(); break;
        case 6: _t->on_replyButton_clicked(); break;
        case 7: _t->on_startServerButton_clicked(); break;
        case 8: _t->on_stopServerButton_clicked(); break;
        case 9: _t->new_request((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->new_reply((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Aracne::*)(QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Aracne::send_request)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Aracne::*)(QByteArray , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Aracne::send_reply)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Aracne::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Aracne::turn_on)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Aracne::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Aracne::turn_off)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Aracne::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Aracne::set_mode)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Aracne::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Aracne.data,
    qt_meta_data_Aracne,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Aracne::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Aracne::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Aracne.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Aracne::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Aracne::send_request(QByteArray _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Aracne::send_reply(QByteArray _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Aracne::turn_on()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Aracne::turn_off()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Aracne::set_mode(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
