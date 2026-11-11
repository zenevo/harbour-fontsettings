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
    QByteArrayData data[30];
    char stringdata0[305];
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
QT_MOC_LITERAL(4, 46, 16), // "fallbacksChanged"
QT_MOC_LITERAL(5, 63, 14), // "messageChanged"
QT_MOC_LITERAL(6, 78, 7), // "refresh"
QT_MOC_LITERAL(7, 86, 10), // "importFont"
QT_MOC_LITERAL(8, 97, 4), // "path"
QT_MOC_LITERAL(9, 102, 14), // "removeImported"
QT_MOC_LITERAL(10, 117, 11), // "addFallback"
QT_MOC_LITERAL(11, 129, 6), // "family"
QT_MOC_LITERAL(12, 136, 14), // "removeFallback"
QT_MOC_LITERAL(13, 151, 12), // "moveFallback"
QT_MOC_LITERAL(14, 164, 4), // "from"
QT_MOC_LITERAL(15, 169, 2), // "to"
QT_MOC_LITERAL(16, 172, 5), // "apply"
QT_MOC_LITERAL(17, 178, 5), // "reset"
QT_MOC_LITERAL(18, 184, 17), // "restartHomeScreen"
QT_MOC_LITERAL(19, 202, 6), // "runCli"
QT_MOC_LITERAL(20, 209, 4), // "args"
QT_MOC_LITERAL(21, 214, 8), // "families"
QT_MOC_LITERAL(22, 223, 13), // "importedFonts"
QT_MOC_LITERAL(23, 237, 7), // "primary"
QT_MOC_LITERAL(24, 245, 7), // "heading"
QT_MOC_LITERAL(25, 253, 4), // "mono"
QT_MOC_LITERAL(26, 258, 9), // "fallbacks"
QT_MOC_LITERAL(27, 268, 13), // "defaultFamily"
QT_MOC_LITERAL(28, 282, 11), // "lastMessage"
QT_MOC_LITERAL(29, 294, 10) // "configured"

    },
    "FontBackend\0familiesChanged\0\0"
    "selectionChanged\0fallbacksChanged\0"
    "messageChanged\0refresh\0importFont\0"
    "path\0removeImported\0addFallback\0family\0"
    "removeFallback\0moveFallback\0from\0to\0"
    "apply\0reset\0restartHomeScreen\0runCli\0"
    "args\0families\0importedFonts\0primary\0"
    "heading\0mono\0fallbacks\0defaultFamily\0"
    "lastMessage\0configured"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FontBackend[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       9,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   88,    2, 0x02 /* Public */,
       7,    1,   89,    2, 0x02 /* Public */,
       9,    1,   92,    2, 0x02 /* Public */,
      10,    1,   95,    2, 0x02 /* Public */,
      12,    1,   98,    2, 0x02 /* Public */,
      13,    2,  101,    2, 0x02 /* Public */,
      16,    0,  106,    2, 0x02 /* Public */,
      17,    0,  107,    2, 0x02 /* Public */,
      18,    0,  108,    2, 0x02 /* Public */,
      19,    1,  109,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Int, QMetaType::QStringList,   20,

 // properties: name, type, flags
      21, QMetaType::QStringList, 0x00495001,
      22, QMetaType::QVariantList, 0x00495001,
      23, QMetaType::QString, 0x00495103,
      24, QMetaType::QString, 0x00495103,
      25, QMetaType::QString, 0x00495103,
      26, QMetaType::QStringList, 0x00495001,
      27, QMetaType::QString, 0x00095401,
      28, QMetaType::QString, 0x00495001,
      29, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       1,
       1,
       1,
       2,
       0,
       3,
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
        case 2: _t->fallbacksChanged(); break;
        case 3: _t->messageChanged(); break;
        case 4: _t->refresh(); break;
        case 5: { bool _r = _t->importFont((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->removeImported((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->addFallback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->removeFallback((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->moveFallback((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: { bool _r = _t->apply();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->reset();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->restartHomeScreen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->runCli((*reinterpret_cast< const QStringList(*)>(_a[1])));
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FontBackend::fallbacksChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FontBackend::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FontBackend::messageChanged)) {
                *result = 3;
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
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->fallbacks(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->defaultFamily(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->lastMessage(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->isConfigured(); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
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
void FontBackend::fallbacksChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void FontBackend::messageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
