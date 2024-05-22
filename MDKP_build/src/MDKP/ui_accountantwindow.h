/********************************************************************************
** Form generated from reading UI file 'accountantwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTANTWINDOW_H
#define UI_ACCOUNTANTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountantWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidgetConfirmContract;
    QWidget *page;
    QWidget *page_2;
    QWidget *StatisticsTab;
    QVBoxLayout *verticalLayout_3;
    QWidget *ParentWidgetStatistics;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountantWindow)
    {
        if (AccountantWindow->objectName().isEmpty())
            AccountantWindow->setObjectName("AccountantWindow");
        AccountantWindow->resize(726, 470);
        AccountantWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f2f2f2; /* \320\241\320\262\320\265\321\202\320\273\320\276-\321\201\320\265\321\200\321\213\320\271 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 */\n"
"}"));
        centralwidget = new QWidget(AccountantWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
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
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidgetConfirmContract = new QStackedWidget(tab);
        stackedWidgetConfirmContract->setObjectName("stackedWidgetConfirmContract");
        page = new QWidget();
        page->setObjectName("page");
        stackedWidgetConfirmContract->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidgetConfirmContract->addWidget(page_2);

        verticalLayout->addWidget(stackedWidgetConfirmContract);

        tabWidget->addTab(tab, QString());
        StatisticsTab = new QWidget();
        StatisticsTab->setObjectName("StatisticsTab");
        verticalLayout_3 = new QVBoxLayout(StatisticsTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        ParentWidgetStatistics = new QWidget(StatisticsTab);
        ParentWidgetStatistics->setObjectName("ParentWidgetStatistics");

        verticalLayout_3->addWidget(ParentWidgetStatistics);

        tabWidget->addTab(StatisticsTab, QString());

        verticalLayout_2->addWidget(tabWidget);

        AccountantWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AccountantWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 726, 17));
        AccountantWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AccountantWindow);
        statusbar->setObjectName("statusbar");
        AccountantWindow->setStatusBar(statusbar);

        retranslateUi(AccountantWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AccountantWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AccountantWindow)
    {
        AccountantWindow->setWindowTitle(QCoreApplication::translate("AccountantWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AccountantWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\264\320\276\320\263\320\276\320\262\320\276\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(StatisticsTab), QCoreApplication::translate("AccountantWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountantWindow: public Ui_AccountantWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTANTWINDOW_H
