/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox_5;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QComboBox *cbSort_2;
    QComboBox *cbFilter_2;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *btnSave;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_5;
    QPushButton *btnDelete_2;
    QPushButton *btnAdd_2;
    QPushButton *btnUpdate_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QLineEdit *txtID_2;
    QLabel *dLabel_3;
    QLineEdit *txtBrand_2;
    QLabel *label_11;
    QLineEdit *txtModel_2;
    QLabel *label_12;
    QLineEdit *txtChipset_2;
    QLabel *tx_2;
    QLineEdit *txtGPU_2;
    QLabel *label_13;
    QLineEdit *txtStorage_2;
    QLabel *label_14;
    QLineEdit *txtRam_2;
    QLabel *dLabel_4;
    QLineEdit *txtPrice_2;
    QLabel *dQWDLabel_2;
    QLineEdit *txtYear_2;
    QLabel *lbPage;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QPushButton *btnPrePage_2;
    QPushButton *btnNextP_2;
    QGroupBox *groupBox_6;
    QLineEdit *txtSearch_2;
    QComboBox *cbSearch_2;
    QPushButton *btnSearch_2;
    QPushButton *btnClear;
    QSpinBox *sbPage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(960, 678);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 120, 931, 241));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(400, 490, 321, 141));
        gridLayoutWidget_3 = new QWidget(groupBox_5);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(20, 30, 281, 91));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        cbSort_2 = new QComboBox(gridLayoutWidget_3);
        cbSort_2->addItem(QString());
        cbSort_2->addItem(QString());
        cbSort_2->addItem(QString());
        cbSort_2->addItem(QString());
        cbSort_2->addItem(QString());
        cbSort_2->setObjectName("cbSort_2");

        gridLayout_4->addWidget(cbSort_2, 1, 0, 1, 1);

        cbFilter_2 = new QComboBox(gridLayoutWidget_3);
        cbFilter_2->addItem(QString());
        cbFilter_2->addItem(QString());
        cbFilter_2->addItem(QString());
        cbFilter_2->setObjectName("cbFilter_2");

        gridLayout_4->addWidget(cbFilter_2, 3, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName("label_8");

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName("label_9");

        gridLayout_4->addWidget(label_9, 2, 0, 1, 1);

        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(760, 450, 90, 41));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(400, 370, 321, 81));
        gridLayoutWidget_4 = new QWidget(groupBox_4);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(20, 30, 281, 41));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        btnDelete_2 = new QPushButton(gridLayoutWidget_4);
        btnDelete_2->setObjectName("btnDelete_2");

        gridLayout_5->addWidget(btnDelete_2, 1, 1, 1, 1);

        btnAdd_2 = new QPushButton(gridLayoutWidget_4);
        btnAdd_2->setObjectName("btnAdd_2");

        gridLayout_5->addWidget(btnAdd_2, 1, 0, 1, 1);

        btnUpdate_2 = new QPushButton(gridLayoutWidget_4);
        btnUpdate_2->setObjectName("btnUpdate_2");

        gridLayout_5->addWidget(btnUpdate_2, 1, 2, 1, 1);

        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 370, 341, 263));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName("label_10");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        txtID_2 = new QLineEdit(formLayoutWidget);
        txtID_2->setObjectName("txtID_2");
        txtID_2->setTabletTracking(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, txtID_2);

        dLabel_3 = new QLabel(formLayoutWidget);
        dLabel_3->setObjectName("dLabel_3");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, dLabel_3);

        txtBrand_2 = new QLineEdit(formLayoutWidget);
        txtBrand_2->setObjectName("txtBrand_2");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, txtBrand_2);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName("label_11");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        txtModel_2 = new QLineEdit(formLayoutWidget);
        txtModel_2->setObjectName("txtModel_2");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, txtModel_2);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName("label_12");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_12);

        txtChipset_2 = new QLineEdit(formLayoutWidget);
        txtChipset_2->setObjectName("txtChipset_2");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, txtChipset_2);

        tx_2 = new QLabel(formLayoutWidget);
        tx_2->setObjectName("tx_2");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, tx_2);

        txtGPU_2 = new QLineEdit(formLayoutWidget);
        txtGPU_2->setObjectName("txtGPU_2");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, txtGPU_2);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName("label_13");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_13);

        txtStorage_2 = new QLineEdit(formLayoutWidget);
        txtStorage_2->setObjectName("txtStorage_2");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, txtStorage_2);

        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName("label_14");

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_14);

        txtRam_2 = new QLineEdit(formLayoutWidget);
        txtRam_2->setObjectName("txtRam_2");

        formLayout_2->setWidget(6, QFormLayout::FieldRole, txtRam_2);

        dLabel_4 = new QLabel(formLayoutWidget);
        dLabel_4->setObjectName("dLabel_4");

        formLayout_2->setWidget(7, QFormLayout::LabelRole, dLabel_4);

        txtPrice_2 = new QLineEdit(formLayoutWidget);
        txtPrice_2->setObjectName("txtPrice_2");

        formLayout_2->setWidget(7, QFormLayout::FieldRole, txtPrice_2);

        dQWDLabel_2 = new QLabel(formLayoutWidget);
        dQWDLabel_2->setObjectName("dQWDLabel_2");

        formLayout_2->setWidget(8, QFormLayout::LabelRole, dQWDLabel_2);

        txtYear_2 = new QLineEdit(formLayoutWidget);
        txtYear_2->setObjectName("txtYear_2");

        formLayout_2->setWidget(8, QFormLayout::FieldRole, txtYear_2);

        lbPage = new QLabel(centralwidget);
        lbPage->setObjectName("lbPage");
        lbPage->setGeometry(QRect(10, 82, 61, 20));
        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(310, 70, 281, 41));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        btnPrePage_2 = new QPushButton(gridLayoutWidget_5);
        btnPrePage_2->setObjectName("btnPrePage_2");

        gridLayout_6->addWidget(btnPrePage_2, 1, 0, 1, 1);

        btnNextP_2 = new QPushButton(gridLayoutWidget_5);
        btnNextP_2->setObjectName("btnNextP_2");

        gridLayout_6->addWidget(btnNextP_2, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 0, 931, 71));
        txtSearch_2 = new QLineEdit(groupBox_6);
        txtSearch_2->setObjectName("txtSearch_2");
        txtSearch_2->setGeometry(QRect(10, 30, 661, 22));
        cbSearch_2 = new QComboBox(groupBox_6);
        cbSearch_2->addItem(QString());
        cbSearch_2->addItem(QString());
        cbSearch_2->addItem(QString());
        cbSearch_2->setObjectName("cbSearch_2");
        cbSearch_2->setGeometry(QRect(700, 30, 111, 22));
        btnSearch_2 = new QPushButton(groupBox_6);
        btnSearch_2->setObjectName("btnSearch_2");
        btnSearch_2->setGeometry(QRect(830, 30, 90, 21));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setGeometry(QRect(760, 380, 90, 41));
        sbPage = new QSpinBox(centralwidget);
        sbPage->setObjectName("sbPage");
        sbPage->setGeometry(QRect(50, 80, 42, 22));
        sbPage->setMaximum(999999999);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(8, QCoreApplication::translate("MainWindow", "Year", nullptr));
        ___qtreewidgetitem->setText(7, QCoreApplication::translate("MainWindow", "Price", nullptr));
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("MainWindow", "Ram", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("MainWindow", "Storage", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("MainWindow", "GPU", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "Chipset", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "Model", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Brand", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Sort and Find", nullptr));
        cbSort_2->setItemText(0, QCoreApplication::translate("MainWindow", "Select arrangement", nullptr));
        cbSort_2->setItemText(1, QCoreApplication::translate("MainWindow", "Sort by Model -  A --> Z", nullptr));
        cbSort_2->setItemText(2, QCoreApplication::translate("MainWindow", "Sort by Model - Z --> A", nullptr));
        cbSort_2->setItemText(3, QCoreApplication::translate("MainWindow", "Sort by Price - Ascending", nullptr));
        cbSort_2->setItemText(4, QCoreApplication::translate("MainWindow", "Sort by Price - Descending", nullptr));

        cbFilter_2->setItemText(0, QCoreApplication::translate("MainWindow", "Select Filter", nullptr));
        cbFilter_2->setItemText(1, QCoreApplication::translate("MainWindow", "MIN PRICE", nullptr));
        cbFilter_2->setItemText(2, QCoreApplication::translate("MainWindow", "MAX YEAR", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Sort:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Find:", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Task", nullptr));
        btnDelete_2->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        btnAdd_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        btnUpdate_2->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        dLabel_3->setText(QCoreApplication::translate("MainWindow", "Brand", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Chipset", nullptr));
        tx_2->setText(QCoreApplication::translate("MainWindow", "GPU", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Storage", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Ram", nullptr));
        dLabel_4->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        dQWDLabel_2->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        lbPage->setText(QCoreApplication::translate("MainWindow", "Page:", nullptr));
        btnPrePage_2->setText(QCoreApplication::translate("MainWindow", "Previous Page", nullptr));
        btnNextP_2->setText(QCoreApplication::translate("MainWindow", "Next Page", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Search", nullptr));
        cbSearch_2->setItemText(0, QCoreApplication::translate("MainWindow", "Search", nullptr));
        cbSearch_2->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        cbSearch_2->setItemText(2, QCoreApplication::translate("MainWindow", "Model", nullptr));

        btnSearch_2->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
