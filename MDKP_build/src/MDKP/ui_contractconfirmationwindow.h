/********************************************************************************
** Form generated from reading UI file 'contractconfirmationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRACTCONFIRMATIONWINDOW_H
#define UI_CONTRACTCONFIRMATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "phoneedit.h"

QT_BEGIN_NAMESPACE

class Ui_ContractConfirmationWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *LastName;
    QLabel *label_3;
    PhoneEdit *Phone;
    QSpacerItem *verticalSpacer;
    QLineEdit *FirstName;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *Summa;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *TypeContract;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *Comment;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *RejectButton;
    QPushButton *ConfirmButton;
    QLineEdit *Patronymic;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *ContractConfirmationWindow)
    {
        if (ContractConfirmationWindow->objectName().isEmpty())
            ContractConfirmationWindow->setObjectName("ContractConfirmationWindow");
        ContractConfirmationWindow->resize(837, 498);
        ContractConfirmationWindow->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(ContractConfirmationWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ContractConfirmationWindow);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label, 4, 1, 1, 1);

        LastName = new QLineEdit(ContractConfirmationWindow);
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
        LastName->setReadOnly(true);

        gridLayout->addWidget(LastName, 5, 1, 1, 1);

        label_3 = new QLabel(ContractConfirmationWindow);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        Phone = new PhoneEdit(ContractConfirmationWindow);
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
        Phone->setReadOnly(true);

        gridLayout->addWidget(Phone, 8, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 1);

        FirstName = new QLineEdit(ContractConfirmationWindow);
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
        FirstName->setReadOnly(true);

        gridLayout->addWidget(FirstName, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);

        Summa = new QLineEdit(ContractConfirmationWindow);
        Summa->setObjectName("Summa");
        sizePolicy.setHeightForWidth(Summa->sizePolicy().hasHeightForWidth());
        Summa->setSizePolicy(sizePolicy);
        Summa->setMinimumSize(QSize(200, 40));
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
        Summa->setReadOnly(true);

        gridLayout->addWidget(Summa, 6, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_3, 11, 3, 1, 1);

        label_2 = new QLabel(ContractConfirmationWindow);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label_2, 4, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 2, 1, 1);

        TypeContract = new QLineEdit(ContractConfirmationWindow);
        TypeContract->setObjectName("TypeContract");
        sizePolicy.setHeightForWidth(TypeContract->sizePolicy().hasHeightForWidth());
        TypeContract->setSizePolicy(sizePolicy);
        TypeContract->setMinimumSize(QSize(250, 40));
        TypeContract->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        TypeContract->setReadOnly(true);

        gridLayout->addWidget(TypeContract, 5, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        backButton = new QPushButton(ContractConfirmationWindow);
        backButton->setObjectName("backButton");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy1);
        backButton->setMinimumSize(QSize(150, 40));
        backButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_3->addWidget(backButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_3, 10, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 1);

        Comment = new QTextEdit(ContractConfirmationWindow);
        Comment->setObjectName("Comment");
        Comment->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Comment->sizePolicy().hasHeightForWidth());
        Comment->setSizePolicy(sizePolicy2);
        Comment->setMinimumSize(QSize(100, 100));
        Comment->setBaseSize(QSize(0, 0));
        Comment->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"   background: #e9e9e9;\n"
"	border-radius: 5px;\n"
"	padding: 8px;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border-color: #5fbaeb;\n"
"}"));

        gridLayout->addWidget(Comment, 2, 1, 1, 4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        RejectButton = new QPushButton(ContractConfirmationWindow);
        RejectButton->setObjectName("RejectButton");
        sizePolicy1.setHeightForWidth(RejectButton->sizePolicy().hasHeightForWidth());
        RejectButton->setSizePolicy(sizePolicy1);
        RejectButton->setMinimumSize(QSize(150, 40));
        RejectButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 500 14pt \"Montserrat Medium\";\n"
"    background-color: #ff0000; \n"
"    color: white; \n"
"    border: none;\n"
"    font-size: 14px;\n"
"    border-radius: 5px; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #d20000;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #8B0000; \n"
"}"));

        horizontalLayout_2->addWidget(RejectButton);

        ConfirmButton = new QPushButton(ContractConfirmationWindow);
        ConfirmButton->setObjectName("ConfirmButton");
        sizePolicy1.setHeightForWidth(ConfirmButton->sizePolicy().hasHeightForWidth());
        ConfirmButton->setSizePolicy(sizePolicy1);
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
"}"));

        horizontalLayout_2->addWidget(ConfirmButton);


        gridLayout->addLayout(horizontalLayout_2, 10, 4, 1, 1);

        Patronymic = new QLineEdit(ContractConfirmationWindow);
        Patronymic->setObjectName("Patronymic");
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
        Patronymic->setReadOnly(true);

        gridLayout->addWidget(Patronymic, 7, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 3, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(LastName, FirstName);
        QWidget::setTabOrder(FirstName, Patronymic);
        QWidget::setTabOrder(Patronymic, Phone);
        QWidget::setTabOrder(Phone, TypeContract);
        QWidget::setTabOrder(TypeContract, Summa);
        QWidget::setTabOrder(Summa, backButton);
        QWidget::setTabOrder(backButton, RejectButton);
        QWidget::setTabOrder(RejectButton, ConfirmButton);
        QWidget::setTabOrder(ConfirmButton, Comment);

        retranslateUi(ContractConfirmationWindow);

        QMetaObject::connectSlotsByName(ContractConfirmationWindow);
    } // setupUi

    void retranslateUi(QWidget *ContractConfirmationWindow)
    {
        ContractConfirmationWindow->setWindowTitle(QCoreApplication::translate("ContractConfirmationWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\272\320\273\320\270\320\265\320\275\321\202\320\265:", nullptr));
        LastName->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\222\320\260\321\210 \320\272\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271:", nullptr));
        Phone->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        FirstName->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\230\320\274\321\217", nullptr));
        Summa->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\265:", nullptr));
        TypeContract->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\242\320\270\320\277 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        backButton->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        Comment->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        RejectButton->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\236\321\202\320\272\320\273\320\276\320\275\320\270\321\202\321\214", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        Patronymic->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContractConfirmationWindow: public Ui_ContractConfirmationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACTCONFIRMATIONWINDOW_H
