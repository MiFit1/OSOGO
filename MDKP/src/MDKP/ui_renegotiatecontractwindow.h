/********************************************************************************
** Form generated from reading UI file 'renegotiatecontractwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENEGOTIATECONTRACTWINDOW_H
#define UI_RENEGOTIATECONTRACTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "numberedit.h"
#include "phoneedit.h"

QT_BEGIN_NAMESPACE

class Ui_RenegotiateContractWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLineEdit *LastName;
    QLabel *label;
    QLineEdit *Patronymic;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    PhoneEdit *Phone;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QLineEdit *FirstName;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *SendButton;
    QLabel *label_3;
    QTextEdit *AccountantComments;
    QSpacerItem *verticalSpacer_2;
    NumberEdit *Summa;
    QComboBox *TypeContract;

    void setupUi(QWidget *RenegotiateContractWindow)
    {
        if (RenegotiateContractWindow->objectName().isEmpty())
            RenegotiateContractWindow->setObjectName("RenegotiateContractWindow");
        RenegotiateContractWindow->resize(723, 478);
        horizontalLayout = new QHBoxLayout(RenegotiateContractWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 1);

        LastName = new QLineEdit(RenegotiateContractWindow);
        LastName->setObjectName("LastName");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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

        gridLayout->addWidget(LastName, 5, 1, 1, 1);

        label = new QLabel(RenegotiateContractWindow);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label, 4, 1, 1, 1);

        Patronymic = new QLineEdit(RenegotiateContractWindow);
        Patronymic->setObjectName("Patronymic");
        sizePolicy.setHeightForWidth(Patronymic->sizePolicy().hasHeightForWidth());
        Patronymic->setSizePolicy(sizePolicy);
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

        gridLayout->addWidget(Patronymic, 7, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 3, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_3, 11, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        Phone = new PhoneEdit(RenegotiateContractWindow);
        Phone->setObjectName("Phone");
        sizePolicy.setHeightForWidth(Phone->sizePolicy().hasHeightForWidth());
        Phone->setSizePolicy(sizePolicy);
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

        gridLayout->addWidget(Phone, 8, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        BackButton = new QPushButton(RenegotiateContractWindow);
        BackButton->setObjectName("BackButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BackButton->sizePolicy().hasHeightForWidth());
        BackButton->setSizePolicy(sizePolicy1);
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

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_3, 10, 1, 1, 1);

        label_2 = new QLabel(RenegotiateContractWindow);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label_2, 4, 3, 1, 1);

        FirstName = new QLineEdit(RenegotiateContractWindow);
        FirstName->setObjectName("FirstName");
        sizePolicy.setHeightForWidth(FirstName->sizePolicy().hasHeightForWidth());
        FirstName->setSizePolicy(sizePolicy);
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

        gridLayout->addWidget(FirstName, 6, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        SendButton = new QPushButton(RenegotiateContractWindow);
        SendButton->setObjectName("SendButton");
        sizePolicy1.setHeightForWidth(SendButton->sizePolicy().hasHeightForWidth());
        SendButton->setSizePolicy(sizePolicy1);
        SendButton->setMinimumSize(QSize(150, 40));
        SendButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_2->addWidget(SendButton);


        gridLayout->addLayout(horizontalLayout_2, 10, 4, 1, 1);

        label_3 = new QLabel(RenegotiateContractWindow);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        AccountantComments = new QTextEdit(RenegotiateContractWindow);
        AccountantComments->setObjectName("AccountantComments");
        AccountantComments->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AccountantComments->sizePolicy().hasHeightForWidth());
        AccountantComments->setSizePolicy(sizePolicy2);
        AccountantComments->setMinimumSize(QSize(100, 100));
        AccountantComments->setBaseSize(QSize(0, 0));
        AccountantComments->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"	selection-color: white;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border-color: #5fbaeb;\n"
"}"));
        AccountantComments->setReadOnly(true);

        gridLayout->addWidget(AccountantComments, 2, 1, 1, 4);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);

        Summa = new NumberEdit(RenegotiateContractWindow);
        Summa->setObjectName("Summa");
        sizePolicy.setHeightForWidth(Summa->sizePolicy().hasHeightForWidth());
        Summa->setSizePolicy(sizePolicy);
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

        gridLayout->addWidget(Summa, 6, 3, 1, 1);

        TypeContract = new QComboBox(RenegotiateContractWindow);
        TypeContract->addItem(QString());
        TypeContract->addItem(QString());
        TypeContract->addItem(QString());
        TypeContract->setObjectName("TypeContract");
        TypeContract->setMinimumSize(QSize(0, 40));
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

        gridLayout->addWidget(TypeContract, 5, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(LastName, FirstName);
        QWidget::setTabOrder(FirstName, Patronymic);
        QWidget::setTabOrder(Patronymic, Phone);
        QWidget::setTabOrder(Phone, TypeContract);
        QWidget::setTabOrder(TypeContract, Summa);
        QWidget::setTabOrder(Summa, BackButton);
        QWidget::setTabOrder(BackButton, SendButton);
        QWidget::setTabOrder(SendButton, AccountantComments);

        retranslateUi(RenegotiateContractWindow);

        QMetaObject::connectSlotsByName(RenegotiateContractWindow);
    } // setupUi

    void retranslateUi(QWidget *RenegotiateContractWindow)
    {
        RenegotiateContractWindow->setWindowTitle(QCoreApplication::translate("RenegotiateContractWindow", "Form", nullptr));
        LastName->setPlaceholderText(QCoreApplication::translate("RenegotiateContractWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("RenegotiateContractWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\272\320\273\320\270\320\265\320\275\321\202\320\265:", nullptr));
        Patronymic->setPlaceholderText(QCoreApplication::translate("RenegotiateContractWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        Phone->setPlaceholderText(QCoreApplication::translate("RenegotiateContractWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        BackButton->setText(QCoreApplication::translate("RenegotiateContractWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("RenegotiateContractWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\265:", nullptr));
        FirstName->setPlaceholderText(QCoreApplication::translate("RenegotiateContractWindow", "\320\230\320\274\321\217", nullptr));
        SendButton->setText(QCoreApplication::translate("RenegotiateContractWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("RenegotiateContractWindow", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271 \320\261\321\203\321\205\320\263\320\260\320\273\321\202\320\265\321\200\320\260:", nullptr));
        AccountantComments->setPlaceholderText(QCoreApplication::translate("RenegotiateContractWindow", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        Summa->setPlaceholderText(QCoreApplication::translate("RenegotiateContractWindow", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        TypeContract->setItemText(0, QCoreApplication::translate("RenegotiateContractWindow", "\320\224\320\276\320\261\321\200\320\276\320\262\320\276\320\273\321\214\320\275\320\276\320\265 \320\274\320\265\320\264\320\270\321\206\320\270\320\275\321\201\320\272\320\276\320\265 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        TypeContract->setItemText(1, QCoreApplication::translate("RenegotiateContractWindow", "C\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\276\320\274\320\260\321\210\320\275\320\265\320\263\320\276 \320\270\320\274\321\203\321\211\320\265\321\201\321\202\320\262\320\260", nullptr));
        TypeContract->setItemText(2, QCoreApplication::translate("RenegotiateContractWindow", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265 \320\260\320\262\321\202\320\276\321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260", nullptr));

        TypeContract->setPlaceholderText(QCoreApplication::translate("RenegotiateContractWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenegotiateContractWindow: public Ui_RenegotiateContractWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENEGOTIATECONTRACTWINDOW_H
