/****************************************************************************
** Meta object code from reading C++ file 'chatlist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../chatlist.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSChatlistENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSChatlistENDCLASS = QtMocHelpers::stringData(
    "Chatlist",
    "signal_to_private_chat",
    "",
    "QJsonObject&",
    "signal_to_group_slot",
    "signal_to_group_chat",
    "signal_start_file",
    "signal_stop_file",
    "chat_server_reply",
    "chat_server_disconnect",
    "chat_private_slot",
    "chat_group_slot",
    "on_addButton_clicked",
    "on_createButton_clicked",
    "on_joinButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSChatlistENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x06,    1 /* Public */,
       4,    1,   89,    2, 0x06,    3 /* Public */,
       5,    1,   92,    2, 0x06,    5 /* Public */,
       6,    0,   95,    2, 0x06,    7 /* Public */,
       7,    0,   96,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   97,    2, 0x08,    9 /* Private */,
       9,    0,   98,    2, 0x08,   10 /* Private */,
      10,    0,   99,    2, 0x08,   11 /* Private */,
      11,    0,  100,    2, 0x08,   12 /* Private */,
      12,    0,  101,    2, 0x08,   13 /* Private */,
      13,    0,  102,    2, 0x08,   14 /* Private */,
      14,    0,  103,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Chatlist::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSChatlistENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSChatlistENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSChatlistENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Chatlist, std::true_type>,
        // method 'signal_to_private_chat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        // method 'signal_to_group_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        // method 'signal_to_group_chat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        // method 'signal_start_file'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signal_stop_file'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chat_server_reply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chat_server_disconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chat_private_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chat_group_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_createButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_joinButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Chatlist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Chatlist *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_to_private_chat((*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[1]))); break;
        case 1: _t->signal_to_group_slot((*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[1]))); break;
        case 2: _t->signal_to_group_chat((*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[1]))); break;
        case 3: _t->signal_start_file(); break;
        case 4: _t->signal_stop_file(); break;
        case 5: _t->chat_server_reply(); break;
        case 6: _t->chat_server_disconnect(); break;
        case 7: _t->chat_private_slot(); break;
        case 8: _t->chat_group_slot(); break;
        case 9: _t->on_addButton_clicked(); break;
        case 10: _t->on_createButton_clicked(); break;
        case 11: _t->on_joinButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Chatlist::*)(QJsonObject & );
            if (_t _q_method = &Chatlist::signal_to_private_chat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Chatlist::*)(QJsonObject & );
            if (_t _q_method = &Chatlist::signal_to_group_slot; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Chatlist::*)(QJsonObject & );
            if (_t _q_method = &Chatlist::signal_to_group_chat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Chatlist::*)();
            if (_t _q_method = &Chatlist::signal_start_file; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Chatlist::*)();
            if (_t _q_method = &Chatlist::signal_stop_file; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *Chatlist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chatlist::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSChatlistENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Chatlist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Chatlist::signal_to_private_chat(QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Chatlist::signal_to_group_slot(QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Chatlist::signal_to_group_chat(QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Chatlist::signal_start_file()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Chatlist::signal_stop_file()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
