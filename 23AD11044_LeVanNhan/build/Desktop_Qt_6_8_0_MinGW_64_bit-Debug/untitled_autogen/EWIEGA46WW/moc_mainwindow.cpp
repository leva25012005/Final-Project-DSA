/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "PaginationInWidget",
    "",
    "QTreeWidget*",
    "treeWidget",
    "BSTPhone*",
    "treeRoot",
    "btnPrePage_2_clicked",
    "btnNextP_2_clicked",
    "treeWidget_itemClicked",
    "QTreeWidgetItem*",
    "item",
    "column",
    "btnAdd_2_clicked",
    "btnDelete_2_clicked",
    "btnUpdate_2_clicked",
    "btnSave_clicked",
    "btnClear_clicked",
    "cbSort_2_currentIndexChanged",
    "index"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x08,    1 /* Private */,
       7,    0,   79,    2, 0x08,    4 /* Private */,
       8,    0,   80,    2, 0x08,    5 /* Private */,
       9,    2,   81,    2, 0x08,    6 /* Private */,
      13,    0,   86,    2, 0x08,    9 /* Private */,
      14,    0,   87,    2, 0x08,   10 /* Private */,
      15,    0,   88,    2, 0x08,   11 /* Private */,
      16,    0,   89,    2, 0x08,   12 /* Private */,
      17,    0,   90,    2, 0x08,   13 /* Private */,
      18,    1,   91,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'PaginationInWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<BSTPhone *, std::false_type>,
        // method 'btnPrePage_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btnNextP_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'treeWidget_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'btnAdd_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btnDelete_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btnUpdate_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btnSave_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'btnClear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cbSort_2_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->PaginationInWidget((*reinterpret_cast< std::add_pointer_t<QTreeWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<BSTPhone*>>(_a[2]))); break;
        case 1: _t->btnPrePage_2_clicked(); break;
        case 2: _t->btnNextP_2_clicked(); break;
        case 3: _t->treeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->btnAdd_2_clicked(); break;
        case 5: _t->btnDelete_2_clicked(); break;
        case 6: _t->btnUpdate_2_clicked(); break;
        case 7: _t->btnSave_clicked(); break;
        case 8: _t->btnClear_clicked(); break;
        case 9: _t->cbSort_2_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTreeWidget* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
