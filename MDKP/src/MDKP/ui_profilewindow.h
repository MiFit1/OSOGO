/********************************************************************************
** Form generated from reading UI file 'profilewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWINDOW_H
#define UI_PROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *LogoutButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *LastNameLine;
    QLineEdit *PatronymicLine;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *CancelButton;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *FirstNameLine;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *shadowCheckBox;

    void setupUi(QWidget *ProfileWindow)
    {
        if (ProfileWindow->objectName().isEmpty())
            ProfileWindow->setObjectName("ProfileWindow");
        ProfileWindow->resize(346, 301);
        horizontalLayout = new QHBoxLayout(ProfileWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        LogoutButton = new QPushButton(ProfileWindow);
        LogoutButton->setObjectName("LogoutButton");
        LogoutButton->setMinimumSize(QSize(120, 40));
        LogoutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(LogoutButton, 7, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 2, 1, 1);

        label = new QLabel(ProfileWindow);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 500 11pt \"Montserrat Medium\";\n"
"}\n"
""));

        gridLayout->addWidget(label, 1, 1, 1, 2);

        LastNameLine = new QLineEdit(ProfileWindow);
        LastNameLine->setObjectName("LastNameLine");
        LastNameLine->setMinimumSize(QSize(200, 40));
        LastNameLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        LastNameLine->setReadOnly(true);

        gridLayout->addWidget(LastNameLine, 2, 1, 1, 2);

        PatronymicLine = new QLineEdit(ProfileWindow);
        PatronymicLine->setObjectName("PatronymicLine");
        PatronymicLine->setMinimumSize(QSize(200, 40));
        PatronymicLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        PatronymicLine->setReadOnly(true);

        gridLayout->addWidget(PatronymicLine, 4, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_3, 8, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        CancelButton = new QPushButton(ProfileWindow);
        CancelButton->setObjectName("CancelButton");
        CancelButton->setMinimumSize(QSize(120, 40));
        CancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(CancelButton, 7, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 7, 4, 1, 1);

        FirstNameLine = new QLineEdit(ProfileWindow);
        FirstNameLine->setObjectName("FirstNameLine");
        FirstNameLine->setMinimumSize(QSize(200, 40));
        FirstNameLine->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        FirstNameLine->setReadOnly(true);

        gridLayout->addWidget(FirstNameLine, 3, 1, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        shadowCheckBox = new QCheckBox(ProfileWindow);
        shadowCheckBox->setObjectName("shadowCheckBox");
        shadowCheckBox->setMinimumSize(QSize(20, 20));
        shadowCheckBox->setChecked(false);
        shadowCheckBox->setTristate(false);

        gridLayout->addWidget(shadowCheckBox, 5, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(LastNameLine, FirstNameLine);
        QWidget::setTabOrder(FirstNameLine, PatronymicLine);
        QWidget::setTabOrder(PatronymicLine, LogoutButton);
        QWidget::setTabOrder(LogoutButton, CancelButton);

        retranslateUi(ProfileWindow);

        QMetaObject::connectSlotsByName(ProfileWindow);
    } // setupUi

    void retranslateUi(QWidget *ProfileWindow)
    {
        ProfileWindow->setWindowTitle(QCoreApplication::translate("ProfileWindow", "Form", nullptr));
        LogoutButton->setText(QCoreApplication::translate("ProfileWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("ProfileWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        LastNameLine->setPlaceholderText(QCoreApplication::translate("ProfileWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        PatronymicLine->setPlaceholderText(QCoreApplication::translate("ProfileWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        CancelButton->setText(QCoreApplication::translate("ProfileWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        FirstNameLine->setText(QString());
        FirstNameLine->setPlaceholderText(QCoreApplication::translate("ProfileWindow", "\320\230\320\274\321\217", nullptr));
        shadowCheckBox->setText(QCoreApplication::translate("ProfileWindow", "\320\222\320\272\320\273. / \320\262\321\213\320\272\320\273. \321\202\320\265\320\275\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileWindow: public Ui_ProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWINDOW_H
