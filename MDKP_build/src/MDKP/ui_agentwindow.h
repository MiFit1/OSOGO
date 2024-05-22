/********************************************************************************
** Form generated from reading UI file 'agentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTWINDOW_H
#define UI_AGENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "phoneedit.h"

QT_BEGIN_NAMESPACE

class Ui_AgentWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *ConcludeTab;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_10;
    PhoneEdit *Phone;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *Patronymic;
    QComboBox *TypeContract;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QLineEdit *Summa;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *ConcludeContractButton;
    QLineEdit *LastName;
    QLabel *label_2;
    QLineEdit *FirstName;
    QWidget *RenegotiateContract;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidgetRenegotiateContract;
    QWidget *page;
    QWidget *page_2;
    QWidget *StatisticTab;
    QHBoxLayout *horizontalLayout_6;
    QTableView *statisticView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AgentWindow)
    {
        if (AgentWindow->objectName().isEmpty())
            AgentWindow->setObjectName("AgentWindow");
        AgentWindow->resize(917, 465);
        centralwidget = new QWidget(AgentWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab { \n"
"	font: 500 8pt \"Montserrat Medium\";\n"
"    background:	#e9e9e9;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"	height: 34 px;\n"
"	padding: 8px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"}\n"
""));
        ConcludeTab = new QWidget();
        ConcludeTab->setObjectName("ConcludeTab");
        horizontalLayout_2 = new QHBoxLayout(ConcludeTab);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_10 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 3, 0, 1, 1);

        Phone = new PhoneEdit(ConcludeTab);
        Phone->setObjectName("Phone");
        Phone->setMinimumSize(QSize(0, 40));
        Phone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 500 9pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #5fbaeb;\n"
"}\n"
""));
        Phone->setMaxLength(18);

        gridLayout->addWidget(Phone, 5, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 2, 5, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_3, 0, 2, 1, 1);

        Patronymic = new QLineEdit(ConcludeTab);
        Patronymic->setObjectName("Patronymic");
        Patronymic->setMinimumSize(QSize(0, 40));
        Patronymic->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 500 9pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #5fbaeb;\n"
"}\n"
""));

        gridLayout->addWidget(Patronymic, 4, 1, 1, 1);

        TypeContract = new QComboBox(ConcludeTab);
        TypeContract->addItem(QString());
        TypeContract->addItem(QString());
        TypeContract->addItem(QString());
        TypeContract->setObjectName("TypeContract");
        TypeContract->setMinimumSize(QSize(300, 40));
        TypeContract->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font: 500 9pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: #5fbaeb;\n"
"}\n"
"\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"    background: #cdcdcd;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 25px;\n"
"	border-left-width: 1px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"   image: url(:/images/resources/CheckMark.png);\n"
"	width: 12px;\n"
"	height: 12px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height: 40px;\n"
"}\n"
""));

        gridLayout->addWidget(TypeContract, 2, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_4, 6, 2, 1, 1);

        label = new QLabel(ConcludeTab);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        Summa = new QLineEdit(ConcludeTab);
        Summa->setObjectName("Summa");
        Summa->setMinimumSize(QSize(0, 40));
        Summa->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 500 9pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #5fbaeb;\n"
"}\n"
""));

        gridLayout->addWidget(Summa, 3, 3, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        ConcludeContractButton = new QPushButton(ConcludeTab);
        ConcludeContractButton->setObjectName("ConcludeContractButton");
        ConcludeContractButton->setMinimumSize(QSize(160, 40));
        ConcludeContractButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"font: 500 14pt \"Montserrat Medium\";\n"
"    background-color: #4CAF50; \n"
"    color: white; \n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-radius: 5px; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #357a38; \n"
"}"));

        horizontalLayout_5->addWidget(ConcludeContractButton);


        gridLayout->addLayout(horizontalLayout_5, 7, 5, 1, 1);

        LastName = new QLineEdit(ConcludeTab);
        LastName->setObjectName("LastName");
        LastName->setMinimumSize(QSize(200, 40));
        LastName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 500 9pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #5fbaeb;\n"
"}\n"
""));

        gridLayout->addWidget(LastName, 2, 1, 1, 1);

        label_2 = new QLabel(ConcludeTab);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        FirstName = new QLineEdit(ConcludeTab);
        FirstName->setObjectName("FirstName");
        FirstName->setMinimumSize(QSize(0, 40));
        FirstName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 500 9pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #5fbaeb;\n"
"}\n"
""));

        gridLayout->addWidget(FirstName, 3, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        tabWidget->addTab(ConcludeTab, QString());
        RenegotiateContract = new QWidget();
        RenegotiateContract->setObjectName("RenegotiateContract");
        verticalLayout = new QVBoxLayout(RenegotiateContract);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidgetRenegotiateContract = new QStackedWidget(RenegotiateContract);
        stackedWidgetRenegotiateContract->setObjectName("stackedWidgetRenegotiateContract");
        page = new QWidget();
        page->setObjectName("page");
        stackedWidgetRenegotiateContract->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidgetRenegotiateContract->addWidget(page_2);

        verticalLayout->addWidget(stackedWidgetRenegotiateContract);

        tabWidget->addTab(RenegotiateContract, QString());
        StatisticTab = new QWidget();
        StatisticTab->setObjectName("StatisticTab");
        horizontalLayout_6 = new QHBoxLayout(StatisticTab);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        statisticView = new QTableView(StatisticTab);
        statisticView->setObjectName("statisticView");
        statisticView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    color: black; /*\321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262\320\275\321\203\321\202\321\200\320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213*/\n"
"    gridline-color: black /*\321\206\320\262\320\265\321\202 \321\201\320\265\321\202\320\272\320\270*/;\n"
"}\n"
"QHeaderView::section {\n"
"	background-color: #e9e9e9; /*\321\206\320\262\320\265\321\202 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217 \321\201\320\276\320\273\320\261\321\206\320\276\320\262 \320\270 \320\275\320\276\320\274\320\265\321\200\320\276\320\262 \321\201\321\202\321\200\320\276\320\272\320\270*/\n"
"   color: black; /*\321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \321\205\321\215\320\264\320\265\321\200\320\276\320\262*/\n"
"}\n"
"\n"
"QScrollBar:horizontal \n"
"{\n"
"   background-color: #e9e9e9;\n"
"	border: 1px solid  #7a7a7a;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:horizontal \n"
"{\n"
"    background"
                        "-color: #aeaeae;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, \n"
"QScrollBar::sub-line:horizontal,\n"
"QScrollBar::add-page:horizontal, \n"
"QScrollBar::sub-page:horizontal \n"
"{\n"
"    width: 0px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical \n"
"{\n"
"  	background-color: #e9e9e9;\n"
"	border: 1px solid  #7a7a7a;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical \n"
"{\n"
"    background-color: #aeaeae;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:vertical, \n"
"QScrollBar::sub-line:vertical,\n"
"QScrollBar::add-page:vertical, \n"
"QScrollBar::sub-page:vertical \n"
"{\n"
"    height: 0px;\n"
"    background-color: transparent;\n"
"}"));

        horizontalLayout_6->addWidget(statisticView);

        tabWidget->addTab(StatisticTab, QString());

        horizontalLayout->addWidget(tabWidget);

        AgentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AgentWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 917, 17));
        AgentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AgentWindow);
        statusbar->setObjectName("statusbar");
        AgentWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(tabWidget, LastName);
        QWidget::setTabOrder(LastName, FirstName);
        QWidget::setTabOrder(FirstName, Patronymic);
        QWidget::setTabOrder(Patronymic, Phone);
        QWidget::setTabOrder(Phone, TypeContract);
        QWidget::setTabOrder(TypeContract, Summa);
        QWidget::setTabOrder(Summa, ConcludeContractButton);
        QWidget::setTabOrder(ConcludeContractButton, statisticView);

        retranslateUi(AgentWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AgentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AgentWindow)
    {
        AgentWindow->setWindowTitle(QCoreApplication::translate("AgentWindow", "MainWindow", nullptr));
        Phone->setPlaceholderText(QCoreApplication::translate("AgentWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        Patronymic->setPlaceholderText(QCoreApplication::translate("AgentWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        TypeContract->setItemText(0, QCoreApplication::translate("AgentWindow", "\320\224\320\276\320\261\321\200\320\276\320\262\320\276\320\273\321\214\320\275\320\276\320\265 \320\274\320\265\320\264\320\270\321\206\320\270\320\275\321\201\320\272\320\276\320\265 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        TypeContract->setItemText(1, QCoreApplication::translate("AgentWindow", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\276\320\274\320\260\321\210\320\275\320\265\320\263\320\276 \320\270\320\274\321\203\321\211\320\265\321\201\321\202\320\262\320\260", nullptr));
        TypeContract->setItemText(2, QCoreApplication::translate("AgentWindow", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265 \320\260\320\262\321\202\320\276\321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));

        TypeContract->setPlaceholderText(QCoreApplication::translate("AgentWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        label->setText(QCoreApplication::translate("AgentWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\272\320\273\320\270\320\265\320\275\321\202\320\265:", nullptr));
        Summa->setPlaceholderText(QCoreApplication::translate("AgentWindow", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        ConcludeContractButton->setText(QCoreApplication::translate("AgentWindow", "\320\227\320\260\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\264\320\276\320\263\320\276\320\262\320\276\321\200", nullptr));
        LastName->setPlaceholderText(QCoreApplication::translate("AgentWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("AgentWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\265:", nullptr));
        FirstName->setPlaceholderText(QCoreApplication::translate("AgentWindow", "\320\230\320\274\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ConcludeTab), QCoreApplication::translate("AgentWindow", "\320\227\320\260\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\264\320\276\320\263\320\276\320\262\320\276\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RenegotiateContract), QCoreApplication::translate("AgentWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\264\320\276\320\263\320\276\320\262\320\276\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(StatisticTab), QCoreApplication::translate("AgentWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentWindow: public Ui_AgentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTWINDOW_H
