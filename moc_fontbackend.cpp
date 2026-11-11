/****************************************************************************
** Meta object code from reading C++ file 'fontbackend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/fontbackend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fontbackend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FontBackend_t {
    QByteArrayData data[22];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FontBackend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FontBackend_t qt_meta_stringdata_FontBackend = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FontBackend"
QT_MOC_LITERAL(1, 12, 15), // "familiesChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "selectionChanged"
QT_MOC_LITERAL(4, 46, 14), // "messageChanged"
QT_MOC_LITERAL(5, 61, 7), // "refresh"
QT_MOC_LITERAL(6, 69, 10), // "importFont"
QT_MOC_LITERAL(7, 80, 4), // "path"
QT_MOC_LITERAL(8, 85, 14), // "removeImported"
QT_MOC_LITERAL(9, 100, 5), // "apply"
QT_MOC_LITERAL(10, 106, 5), // "reset"
QT_MOC_LITERAL(11, 112, 17), // "restartHomeScreen"
QT_MOC_LITERAL(12, 130, 6), // "runCli"
QT_MOC_LITERAL(13, 137, 4), // "args"
QT_MOC_LITERAL(14, 142, 8), // "families"
QT_MOC_LITERAL(15, 151, 13), // "importedFonts"
QT_MOC_LITERAL(16, 165, 7), // "primary"
QT_MOC_LITERAL(17, 173, 7), // "heading"
QT_MOC_LITERAL(18, 181, 4), // "mono"
QT_MOC_LITERAL(19, 186, 13), // "defaultFamily"
QT_MOC_LITERAL(20, 200, 11), // "lastMessage"
QT_MOC_LITERAL(21, 212, 10) // "configured"

    },
    "FontBackend\0familiesChanged\0\0"
    "selectionChanged\0messageChanged\0refresh\0"
    "importFont\0path\0removeImported\0apply\0"
    "reset\0restartHomeScreen\0runCli\0args\0"
    "families\0importedFonts\0primary\0heading\0"
    "mono\0defaultFamily\0lastMessage\0"
    "configured"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FontBackend[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       8,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   67,    2, 0x02 /* Public */,
       6,    1,   68,    2, 0x02 /* Public */,
       8,    1,   71,    2, 0x02 /* Public */,
       9,    0,   74,    2, 0x02 /* Public */,
      10,    0,   75,    2, 0x02 /* Public */,
      11,    0,   76,    2, 0x02 /* Public */,
      12,    1,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Int, QMetaType::QStringList,   13,

 // properties: name, type, flags
      14, QMetaType::QStringList, 0x00495001,
      15, QMetaType::QVariantList, 0x00495001,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00095401,
      20, QMetaType::QString, 0x00495001,
      21, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       1,
       1,
       1,
       0,
       2,
       1,

       0        // eod
};

void FontBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FontBackend *_t = static_cast<FontBackend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->familiesChanged(); break;
        case 1: _t->selectionChanged(); break;
        case 2: _t->messageChanged(); break;
        case 3: _t->refresh(); break;
        case 4: { bool _r = _t->importFont((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->removeImported((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->apply();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->reset();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->restartHomeScreen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->runCli((*reinterpret_cast< const QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FontBackend::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FontBackend::familiesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FontBackend::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FontBackend::selectionChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FontBackend::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FontBackend::messageChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        FontBackend *_t = static_cast<FontBackend *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->families(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->importedFonts(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->primary(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->heading(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->mono(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->defaultFamily(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->lastMessage(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->isConfigured(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        FontBackend *_t = static_cast<FontBackend *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setPrimary(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setHeading(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setMono(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject FontBackend::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FontBackend.data,
      qt_meta_data_FontBackend,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FontBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FontBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FontBackend.stringdata0))
        return static_cast<void*>(const_cast< FontBackend*>(this));
    return QObject::qt_metacast(_clname);
}

int FontBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FontBackend::familiesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FontBackend::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FontBackend::messageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
