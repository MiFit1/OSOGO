/********************************************************************************
** Form generated from reading UI file 'accountantwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTANTWINDOW_H
#define UI_ACCOUNTANTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountantWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QWidget *ParentWidgetConfirmContract;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountantWindow)
    {
        if (AccountantWindow->objectName().isEmpty())
            AccountantWindow->setObjectName("AccountantWindow");
        AccountantWindow->resize(726, 466);
        centralwidget = new QWidget(AccountantWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName("verticalLayout");
        ParentWidgetConfirmContract = new QWidget(tab);
        ParentWidgetConfirmContract->setObjectName("ParentWidgetConfirmContract");

        verticalLayout->addWidget(ParentWidgetConfirmContract);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

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
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AccountantWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountantWindow: public Ui_AccountantWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTANTWINDOW_H
