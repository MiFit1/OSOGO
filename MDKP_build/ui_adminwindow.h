/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "phoneedit.h"

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *AddUserTab;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *LoginLine;
    QComboBox *Post;
    QSpacerItem *verticalSpacer;
    QLineEdit *Branch;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *LastName;
    QLineEdit *PasswordLine;
    PhoneEdit *Phone;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *Address;
    QLabel *label;
    QLineEdit *Patronymic;
    QLineEdit *FirstName;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *registrationButton;
    QWidget *tab_8;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidgetUserManagement;
    QWidget *page;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(938, 526);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
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
"\n"
""));
        tabWidget->setIconSize(QSize(40, 40));
        AddUserTab = new QWidget();
        AddUserTab->setObjectName("AddUserTab");
        horizontalLayout_3 = new QHBoxLayout(AddUserTab);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 4, 1, 1);

        LoginLine = new QLineEdit(AddUserTab);
        LoginLine->setObjectName("LoginLine");
        LoginLine->setMinimumSize(QSize(0, 40));
        LoginLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        LoginLine->setMaxLength(40);

        gridLayout_2->addWidget(LoginLine, 5, 3, 1, 1);

        Post = new QComboBox(AddUserTab);
        Post->addItem(QString());
        Post->addItem(QString());
        Post->addItem(QString());
        Post->setObjectName("Post");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Post->sizePolicy().hasHeightForWidth());
        Post->setSizePolicy(sizePolicy);
        Post->setMinimumSize(QSize(200, 40));
        Post->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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

        gridLayout_2->addWidget(Post, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(verticalSpacer, 0, 2, 1, 1);

        Branch = new QLineEdit(AddUserTab);
        Branch->setObjectName("Branch");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Branch->sizePolicy().hasHeightForWidth());
        Branch->setSizePolicy(sizePolicy1);
        Branch->setMinimumSize(QSize(200, 40));
        Branch->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Branch->setMaxLength(100);

        gridLayout_2->addWidget(Branch, 4, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        LastName = new QLineEdit(AddUserTab);
        LastName->setObjectName("LastName");
        sizePolicy1.setHeightForWidth(LastName->sizePolicy().hasHeightForWidth());
        LastName->setSizePolicy(sizePolicy1);
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
        LastName->setMaxLength(40);

        gridLayout_2->addWidget(LastName, 2, 1, 1, 1);

        PasswordLine = new QLineEdit(AddUserTab);
        PasswordLine->setObjectName("PasswordLine");
        PasswordLine->setMinimumSize(QSize(0, 40));
        PasswordLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        PasswordLine->setMaxLength(40);

        gridLayout_2->addWidget(PasswordLine, 6, 3, 1, 1);

        Phone = new PhoneEdit(AddUserTab);
        Phone->setObjectName("Phone");
        sizePolicy1.setHeightForWidth(Phone->sizePolicy().hasHeightForWidth());
        Phone->setSizePolicy(sizePolicy1);
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

        gridLayout_2->addWidget(Phone, 5, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        Address = new QLineEdit(AddUserTab);
        Address->setObjectName("Address");
        sizePolicy1.setHeightForWidth(Address->sizePolicy().hasHeightForWidth());
        Address->setSizePolicy(sizePolicy1);
        Address->setMinimumSize(QSize(200, 40));
        Address->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        Address->setMaxLength(100);

        gridLayout_2->addWidget(Address, 3, 3, 1, 1);

        label = new QLabel(AddUserTab);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        Patronymic = new QLineEdit(AddUserTab);
        Patronymic->setObjectName("Patronymic");
        sizePolicy1.setHeightForWidth(Patronymic->sizePolicy().hasHeightForWidth());
        Patronymic->setSizePolicy(sizePolicy1);
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
        Patronymic->setMaxLength(40);

        gridLayout_2->addWidget(Patronymic, 4, 1, 1, 1);

        FirstName = new QLineEdit(AddUserTab);
        FirstName->setObjectName("FirstName");
        sizePolicy1.setHeightForWidth(FirstName->sizePolicy().hasHeightForWidth());
        FirstName->setSizePolicy(sizePolicy1);
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
        FirstName->setMaxLength(40);

        gridLayout_2->addWidget(FirstName, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 5, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_6 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        registrationButton = new QPushButton(AddUserTab);
        registrationButton->setObjectName("registrationButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(registrationButton->sizePolicy().hasHeightForWidth());
        registrationButton->setSizePolicy(sizePolicy2);
        registrationButton->setMinimumSize(QSize(150, 40));
        registrationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_4->addWidget(registrationButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout_2, 7, 5, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        tabWidget->addTab(AddUserTab, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        horizontalLayout_2 = new QHBoxLayout(tab_8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        stackedWidgetUserManagement = new QStackedWidget(tab_8);
        stackedWidgetUserManagement->setObjectName("stackedWidgetUserManagement");
        page = new QWidget();
        page->setObjectName("page");
        stackedWidgetUserManagement->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidgetUserManagement->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidgetUserManagement);

        tabWidget->addTab(tab_8, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout);

        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 938, 17));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(tabWidget, LastName);
        QWidget::setTabOrder(LastName, FirstName);
        QWidget::setTabOrder(FirstName, Patronymic);
        QWidget::setTabOrder(Patronymic, Phone);
        QWidget::setTabOrder(Phone, Post);
        QWidget::setTabOrder(Post, Address);
        QWidget::setTabOrder(Address, Branch);
        QWidget::setTabOrder(Branch, LoginLine);
        QWidget::setTabOrder(LoginLine, PasswordLine);
        QWidget::setTabOrder(PasswordLine, registrationButton);

        retranslateUi(AdminWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        LoginLine->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        Post->setItemText(0, QCoreApplication::translate("AdminWindow", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        Post->setItemText(1, QCoreApplication::translate("AdminWindow", "\320\220\320\263\320\265\320\275\321\202", nullptr));
        Post->setItemText(2, QCoreApplication::translate("AdminWindow", "\320\221\321\203\321\205\320\263\320\260\320\273\321\202\320\265\321\200", nullptr));

        Post->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        Branch->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\244\320\270\320\273\320\270\320\260\320\273", nullptr));
        LastName->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        PasswordLine->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        Phone->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        Address->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        label->setText(QCoreApplication::translate("AdminWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265:", nullptr));
        Patronymic->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        FirstName->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\230\320\274\321\217", nullptr));
        registrationButton->setText(QCoreApplication::translate("AdminWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AddUserTab), QCoreApplication::translate("AdminWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("AdminWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\320\274\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
