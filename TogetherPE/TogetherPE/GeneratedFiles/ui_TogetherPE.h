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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QLabel *outgoingLabel;
    QLabel *incomingLabel;
    QTableView *packetTable;
    QSpacerItem *horizontalSpacer;
    QPushButton *startButton;
    QPushButton *stopButton;
    QWidget *settingTab;
    QWidget *logTab;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *logEdit;
    QWidget *tab;
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
        outgoingLabel = new QLabel(packetTab);
        outgoingLabel->setObjectName(QString::fromUtf8("outgoingLabel"));
        outgoingLabel->setTextFormat(Qt::AutoText);
        outgoingLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(outgoingLabel, 3, 1, 1, 1);

        incomingLabel = new QLabel(packetTab);
        incomingLabel->setObjectName(QString::fromUtf8("incomingLabel"));

        gridLayout_2->addWidget(incomingLabel, 3, 0, 1, 1);

        packetTable = new QTableView(packetTab);
        packetTable->setObjectName(QString::fromUtf8("packetTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(packetTable->sizePolicy().hasHeightForWidth());
        packetTable->setSizePolicy(sizePolicy);
        packetTable->setLayoutDirection(Qt::LeftToRight);
        packetTable->setAutoFillBackground(false);
        packetTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        packetTable->setSelectionMode(QAbstractItemView::ContiguousSelection);
        packetTable->setWordWrap(false);

        gridLayout_2->addWidget(packetTable, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 2, 1, 2);

        startButton = new QPushButton(packetTab);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout_2->addWidget(startButton, 1, 0, 1, 2);

        stopButton = new QPushButton(packetTab);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        gridLayout_2->addWidget(stopButton, 1, 2, 1, 2);

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
        logEdit->setReadOnly(true);

        gridLayout_3->addWidget(logEdit, 0, 0, 1, 1);

        tabWidget->addTab(logTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

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
        outgoingLabel->setText(QApplication::translate("TogetherPEClass", "Outgoing: blue", nullptr));
        incomingLabel->setText(QApplication::translate("TogetherPEClass", "Incoming: red", nullptr));
        startButton->setText(QApplication::translate("TogetherPEClass", "Start", nullptr));
        stopButton->setText(QApplication::translate("TogetherPEClass", "Stop", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(packetTab), QApplication::translate("TogetherPEClass", "Packet Tab", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(settingTab), QApplication::translate("TogetherPEClass", "Setting Tab", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(logTab), QApplication::translate("TogetherPEClass", "Logs", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TogetherPEClass", "Scripter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TogetherPEClass: public Ui_TogetherPEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOGETHERPE_H
