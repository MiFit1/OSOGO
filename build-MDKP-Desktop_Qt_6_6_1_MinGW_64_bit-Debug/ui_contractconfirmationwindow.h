/********************************************************************************
** Form generated from reading UI file 'contractconfirmationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
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

QT_BEGIN_NAMESPACE

class Ui_ContractConfirmationWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *ContractConfirmationWindow)
    {
        if (ContractConfirmationWindow->objectName().isEmpty())
            ContractConfirmationWindow->setObjectName("ContractConfirmationWindow");
        ContractConfirmationWindow->resize(720, 440);
        horizontalLayout = new QHBoxLayout(ContractConfirmationWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lineEdit_3 = new QLineEdit(ContractConfirmationWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_3, 6, 1, 1, 1);

        lineEdit_2 = new QLineEdit(ContractConfirmationWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_2, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 1);

        textEdit = new QTextEdit(ContractConfirmationWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(100, 100));
        textEdit->setBaseSize(QSize(0, 0));

        gridLayout->addWidget(textEdit, 2, 1, 1, 4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_2 = new QPushButton(ContractConfirmationWindow);
        pushButton_2->setObjectName("pushButton_2");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setMinimumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ContractConfirmationWindow);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton_3->setMinimumSize(QSize(120, 30));

        horizontalLayout_2->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout_2, 9, 4, 1, 1);

        lineEdit_6 = new QLineEdit(ContractConfirmationWindow);
        lineEdit_6->setObjectName("lineEdit_6");
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);
        lineEdit_6->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_6, 5, 3, 1, 1);

        lineEdit_4 = new QLineEdit(ContractConfirmationWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);
        lineEdit_4->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_4, 7, 1, 1, 1);

        label = new QLabel(ContractConfirmationWindow);
        label->setObjectName("label");

        gridLayout->addWidget(label, 3, 1, 1, 1);

        lineEdit = new QLineEdit(ContractConfirmationWindow);
        lineEdit->setObjectName("lineEdit");
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(lineEdit, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        label_2 = new QLabel(ContractConfirmationWindow);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_3, 10, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(ContractConfirmationWindow);
        lineEdit_5->setObjectName("lineEdit_5");
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);
        lineEdit_5->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(lineEdit_5, 4, 3, 1, 1);

        pushButton = new QPushButton(ContractConfirmationWindow);
        pushButton->setObjectName("pushButton");
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(pushButton, 9, 1, 1, 1);

        label_3 = new QLabel(ContractConfirmationWindow);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(ContractConfirmationWindow);

        QMetaObject::connectSlotsByName(ContractConfirmationWindow);
    } // setupUi

    void retranslateUi(QWidget *ContractConfirmationWindow)
    {
        ContractConfirmationWindow->setWindowTitle(QCoreApplication::translate("ContractConfirmationWindow", "Form", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\230\320\274\321\217", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\236\321\202\320\272\320\273\320\276\320\275\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\272\320\273\320\270\320\265\320\275\321\202\320\265:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\265:", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("ContractConfirmationWindow", "\320\242\320\270\320\277 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("ContractConfirmationWindow", "\320\222\320\260\321\210 \320\272\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContractConfirmationWindow: public Ui_ContractConfirmationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACTCONFIRMATIONWINDOW_H
