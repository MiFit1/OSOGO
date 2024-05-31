/********************************************************************************
** Form generated from reading UI file 'changeuserdatawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSERDATAWIDGET_H
#define UI_CHANGEUSERDATAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "phoneedit.h"

QT_BEGIN_NAMESPACE

class Ui_ChangeUserDataWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *PasswordLine;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *Patronymic;
    QLineEdit *LoginLine;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *Post;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *FirstName;
    QLineEdit *LastName;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    PhoneEdit *Phone;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *ConfirmButton;
    QLineEdit *Address;
    QLineEdit *Branch;
    QComboBox *Status;

    void setupUi(QWidget *ChangeUserDataWidget)
    {
        if (ChangeUserDataWidget->objectName().isEmpty())
            ChangeUserDataWidget->setObjectName("ChangeUserDataWidget");
        ChangeUserDataWidget->resize(1065, 383);
        horizontalLayout = new QHBoxLayout(ChangeUserDataWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        PasswordLine = new QLineEdit(ChangeUserDataWidget);
        PasswordLine->setObjectName("PasswordLine");
        PasswordLine->setMinimumSize(QSize(200, 40));
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

        gridLayout_2->addWidget(PasswordLine, 6, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 2, 1, 1);

        Patronymic = new QLineEdit(ChangeUserDataWidget);
        Patronymic->setObjectName("Patronymic");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Patronymic->sizePolicy().hasHeightForWidth());
        Patronymic->setSizePolicy(sizePolicy);
        Patronymic->setMinimumSize(QSize(200, 40));
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

        gridLayout_2->addWidget(Patronymic, 4, 1, 1, 1);

        LoginLine = new QLineEdit(ChangeUserDataWidget);
        LoginLine->setObjectName("LoginLine");
        LoginLine->setMinimumSize(QSize(200, 40));
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

        gridLayout_2->addWidget(LoginLine, 5, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 5, 1, 1);

        Post = new QComboBox(ChangeUserDataWidget);
        Post->addItem(QString());
        Post->addItem(QString());
        Post->addItem(QString());
        Post->setObjectName("Post");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Post->sizePolicy().hasHeightForWidth());
        Post->setSizePolicy(sizePolicy1);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 2, 1, 1);

        label = new QLabel(ChangeUserDataWidget);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        FirstName = new QLineEdit(ChangeUserDataWidget);
        FirstName->setObjectName("FirstName");
        sizePolicy.setHeightForWidth(FirstName->sizePolicy().hasHeightForWidth());
        FirstName->setSizePolicy(sizePolicy);
        FirstName->setMinimumSize(QSize(200, 40));
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

        gridLayout_2->addWidget(FirstName, 3, 1, 1, 1);

        LastName = new QLineEdit(ChangeUserDataWidget);
        LastName->setObjectName("LastName");
        sizePolicy.setHeightForWidth(LastName->sizePolicy().hasHeightForWidth());
        LastName->setSizePolicy(sizePolicy);
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

        gridLayout_2->addWidget(LastName, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 4, 1, 1);

        Phone = new PhoneEdit(ChangeUserDataWidget);
        Phone->setObjectName("Phone");
        sizePolicy.setHeightForWidth(Phone->sizePolicy().hasHeightForWidth());
        Phone->setSizePolicy(sizePolicy);
        Phone->setMinimumSize(QSize(200, 40));
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        BackButton = new QPushButton(ChangeUserDataWidget);
        BackButton->setObjectName("BackButton");
        BackButton->setMinimumSize(QSize(150, 40));
        BackButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 500 14pt \"Montserrat Medium\";\n"
"    background-color: #c8c8c8; \n"
"    color: white; \n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-radius: 5px; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #aeaeae;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #949494; \n"
"}"));

        horizontalLayout_3->addWidget(BackButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_2->addLayout(horizontalLayout_3, 8, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        ConfirmButton = new QPushButton(ChangeUserDataWidget);
        ConfirmButton->setObjectName("ConfirmButton");
        ConfirmButton->setMinimumSize(QSize(150, 40));
        ConfirmButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
""));

        horizontalLayout_4->addWidget(ConfirmButton);


        gridLayout_2->addLayout(horizontalLayout_4, 8, 5, 1, 1);

        Address = new QLineEdit(ChangeUserDataWidget);
        Address->setObjectName("Address");
        sizePolicy.setHeightForWidth(Address->sizePolicy().hasHeightForWidth());
        Address->setSizePolicy(sizePolicy);
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

        gridLayout_2->addWidget(Address, 6, 1, 1, 1);

        Branch = new QLineEdit(ChangeUserDataWidget);
        Branch->setObjectName("Branch");
        sizePolicy.setHeightForWidth(Branch->sizePolicy().hasHeightForWidth());
        Branch->setSizePolicy(sizePolicy);
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

        gridLayout_2->addWidget(Branch, 4, 3, 1, 1);

        Status = new QComboBox(ChangeUserDataWidget);
        Status->addItem(QString());
        Status->addItem(QString());
        Status->setObjectName("Status");
        Status->setMinimumSize(QSize(200, 40));
        Status->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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

        gridLayout_2->addWidget(Status, 3, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        QWidget::setTabOrder(LastName, FirstName);
        QWidget::setTabOrder(FirstName, Patronymic);
        QWidget::setTabOrder(Patronymic, Phone);
        QWidget::setTabOrder(Phone, Address);
        QWidget::setTabOrder(Address, Post);
        QWidget::setTabOrder(Post, Status);
        QWidget::setTabOrder(Status, Branch);
        QWidget::setTabOrder(Branch, LoginLine);
        QWidget::setTabOrder(LoginLine, PasswordLine);
        QWidget::setTabOrder(PasswordLine, BackButton);
        QWidget::setTabOrder(BackButton, ConfirmButton);

        retranslateUi(ChangeUserDataWidget);

        QMetaObject::connectSlotsByName(ChangeUserDataWidget);
    } // setupUi

    void retranslateUi(QWidget *ChangeUserDataWidget)
    {
        ChangeUserDataWidget->setWindowTitle(QCoreApplication::translate("ChangeUserDataWidget", "Form", nullptr));
        PasswordLine->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        Patronymic->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        LoginLine->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        Post->setItemText(0, QCoreApplication::translate("ChangeUserDataWidget", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        Post->setItemText(1, QCoreApplication::translate("ChangeUserDataWidget", "\320\220\320\263\320\265\320\275\321\202", nullptr));
        Post->setItemText(2, QCoreApplication::translate("ChangeUserDataWidget", "\320\221\321\203\321\205\320\263\320\260\320\273\321\202\320\265\321\200", nullptr));

        Post->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("ChangeUserDataWidget", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265:", nullptr));
        FirstName->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\230\320\274\321\217", nullptr));
        LastName->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        Phone->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        BackButton->setText(QCoreApplication::translate("ChangeUserDataWidget", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("ChangeUserDataWidget", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        Address->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        Branch->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\244\320\270\320\273\320\270\320\260\320\273", nullptr));
        Status->setItemText(0, QCoreApplication::translate("ChangeUserDataWidget", "\320\240\320\260\320\261\320\276\321\202\320\260\320\265\321\202", nullptr));
        Status->setItemText(1, QCoreApplication::translate("ChangeUserDataWidget", "\320\243\320\262\320\276\320\273\320\265\320\275", nullptr));

        Status->setPlaceholderText(QCoreApplication::translate("ChangeUserDataWidget", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\321\202\320\260\321\202\321\203\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeUserDataWidget: public Ui_ChangeUserDataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSERDATAWIDGET_H
