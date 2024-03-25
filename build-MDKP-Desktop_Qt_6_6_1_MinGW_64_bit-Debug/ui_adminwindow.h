/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_8;
    QHBoxLayout *horizontalLayout_2;
    QTableView *TableView;
    QWidget *tab_7;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *Branch;
    QLineEdit *Address;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *LastName;
    QLineEdit *MiddleName;
    QLineEdit *FirstName;
    QComboBox *Post;
    QLabel *label;
    QLineEdit *Phone;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(730, 464);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setIconSize(QSize(40, 40));
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        horizontalLayout_2 = new QHBoxLayout(tab_8);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        TableView = new QTableView(tab_8);
        TableView->setObjectName("TableView");
        TableView->verticalHeader()->setMinimumSectionSize(14);
        TableView->verticalHeader()->setHighlightSections(true);

        horizontalLayout_2->addWidget(TableView);

        tabWidget->addTab(tab_8, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        horizontalLayout_3 = new QHBoxLayout(tab_7);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        Branch = new QLineEdit(tab_7);
        Branch->setObjectName("Branch");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Branch->sizePolicy().hasHeightForWidth());
        Branch->setSizePolicy(sizePolicy);
        Branch->setMinimumSize(QSize(200, 30));

        gridLayout_2->addWidget(Branch, 4, 3, 1, 1);

        Address = new QLineEdit(tab_7);
        Address->setObjectName("Address");
        sizePolicy.setHeightForWidth(Address->sizePolicy().hasHeightForWidth());
        Address->setSizePolicy(sizePolicy);
        Address->setMinimumSize(QSize(200, 30));

        gridLayout_2->addWidget(Address, 3, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(verticalSpacer_2, 6, 2, 1, 1);

        LastName = new QLineEdit(tab_7);
        LastName->setObjectName("LastName");
        sizePolicy.setHeightForWidth(LastName->sizePolicy().hasHeightForWidth());
        LastName->setSizePolicy(sizePolicy);
        LastName->setMinimumSize(QSize(200, 30));

        gridLayout_2->addWidget(LastName, 2, 1, 1, 1);

        MiddleName = new QLineEdit(tab_7);
        MiddleName->setObjectName("MiddleName");
        sizePolicy.setHeightForWidth(MiddleName->sizePolicy().hasHeightForWidth());
        MiddleName->setSizePolicy(sizePolicy);
        MiddleName->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(MiddleName, 4, 1, 1, 1);

        FirstName = new QLineEdit(tab_7);
        FirstName->setObjectName("FirstName");
        sizePolicy.setHeightForWidth(FirstName->sizePolicy().hasHeightForWidth());
        FirstName->setSizePolicy(sizePolicy);
        FirstName->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(FirstName, 3, 1, 1, 1);

        Post = new QComboBox(tab_7);
        Post->setObjectName("Post");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Post->sizePolicy().hasHeightForWidth());
        Post->setSizePolicy(sizePolicy1);
        Post->setMinimumSize(QSize(200, 30));

        gridLayout_2->addWidget(Post, 2, 3, 1, 1);

        label = new QLabel(tab_7);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        Phone = new QLineEdit(tab_7);
        Phone->setObjectName("Phone");
        sizePolicy.setHeightForWidth(Phone->sizePolicy().hasHeightForWidth());
        Phone->setSizePolicy(sizePolicy);
        Phone->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(Phone, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 5, 1, 1);

        pushButton = new QPushButton(tab_7);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(pushButton, 7, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 4, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        tabWidget->addTab(tab_7, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout);

        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 730, 17));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("AdminWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        Branch->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\244\320\270\320\273\320\270\320\260\320\273", nullptr));
        Address->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        LastName->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        MiddleName->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        FirstName->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\230\320\274\321\217", nullptr));
        Post->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("AdminWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265:", nullptr));
        Phone->setPlaceholderText(QCoreApplication::translate("AdminWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        pushButton->setText(QCoreApplication::translate("AdminWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("AdminWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
