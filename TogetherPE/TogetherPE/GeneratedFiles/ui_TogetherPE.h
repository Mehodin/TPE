/********************************************************************************
** Form generated from reading UI file 'TogetherPE.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOGETHERPE_H
#define UI_TOGETHERPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TogetherPEClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *packetTab;
    QGridLayout *gridLayout_2;
    QPushButton *startButton;
    QTableWidget *packetTable;
    QWidget *settingTab;
    QWidget *logTab;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *logEdit;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *TogetherPEClass)
    {
        if (TogetherPEClass->objectName().isEmpty())
            TogetherPEClass->setObjectName(QString::fromUtf8("TogetherPEClass"));
        TogetherPEClass->resize(678, 429);
        centralWidget = new QWidget(TogetherPEClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        packetTab = new QWidget();
        packetTab->setObjectName(QString::fromUtf8("packetTab"));
        gridLayout_2 = new QGridLayout(packetTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        startButton = new QPushButton(packetTab);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout_2->addWidget(startButton, 1, 0, 1, 1);

        packetTable = new QTableWidget(packetTab);
        packetTable->setObjectName(QString::fromUtf8("packetTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(packetTable->sizePolicy().hasHeightForWidth());
        packetTable->setSizePolicy(sizePolicy);
        packetTable->setLayoutDirection(Qt::LeftToRight);
        packetTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        packetTable->setSelectionMode(QAbstractItemView::ContiguousSelection);
        packetTable->setWordWrap(false);

        gridLayout_2->addWidget(packetTable, 0, 0, 1, 1);

        tabWidget->addTab(packetTab, QString());
        settingTab = new QWidget();
        settingTab->setObjectName(QString::fromUtf8("settingTab"));
        tabWidget->addTab(settingTab, QString());
        logTab = new QWidget();
        logTab->setObjectName(QString::fromUtf8("logTab"));
        gridLayout_3 = new QGridLayout(logTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        logEdit = new QPlainTextEdit(logTab);
        logEdit->setObjectName(QString::fromUtf8("logEdit"));

        gridLayout_3->addWidget(logEdit, 0, 0, 1, 1);

        tabWidget->addTab(logTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        TogetherPEClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TogetherPEClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TogetherPEClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(TogetherPEClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 678, 22));
        TogetherPEClass->setMenuBar(menuBar);

        retranslateUi(TogetherPEClass);
        QObject::connect(startButton, SIGNAL(clicked()), TogetherPEClass, SLOT(startLogging()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TogetherPEClass);
    } // setupUi

    void retranslateUi(QMainWindow *TogetherPEClass)
    {
        TogetherPEClass->setWindowTitle(QApplication::translate("TogetherPEClass", "TogetherPE", nullptr));
        startButton->setText(QApplication::translate("TogetherPEClass", "Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(packetTab), QApplication::translate("TogetherPEClass", "Packet Tab", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(settingTab), QApplication::translate("TogetherPEClass", "Setting Tab", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(logTab), QApplication::translate("TogetherPEClass", "Logs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TogetherPEClass: public Ui_TogetherPEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOGETHERPE_H
