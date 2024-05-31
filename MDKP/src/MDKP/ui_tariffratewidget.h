/********************************************************************************
** Form generated from reading UI file 'tariffratewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TARIFFRATEWIDGET_H
#define UI_TARIFFRATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TariffRateWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QDoubleSpinBox *tarrifRate1;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QDoubleSpinBox *tarrifRate2;
    QDoubleSpinBox *tarrifRate3;

    void setupUi(QWidget *TariffRateWidget)
    {
        if (TariffRateWidget->objectName().isEmpty())
            TariffRateWidget->setObjectName("TariffRateWidget");
        TariffRateWidget->resize(328, 284);
        verticalLayout = new QVBoxLayout(TariffRateWidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 12, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout, 11, 1, 1, 2);

        label_4 = new QLabel(TariffRateWidget);
        label_4->setObjectName("label_4");

        gridLayout_3->addWidget(label_4, 8, 1, 1, 2);

        tarrifRate1 = new QDoubleSpinBox(TariffRateWidget);
        tarrifRate1->setObjectName("tarrifRate1");
        tarrifRate1->setMinimumSize(QSize(120, 40));
        QFont font;
        font.setPointSize(11);
        tarrifRate1->setFont(font);
        tarrifRate1->setStyleSheet(QString::fromUtf8(""));
        tarrifRate1->setDecimals(3);
        tarrifRate1->setMaximum(1.000000000000000);
        tarrifRate1->setSingleStep(0.010000000000000);

        gridLayout_3->addWidget(tarrifRate1, 5, 1, 1, 2);

        label = new QLabel(TariffRateWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 1, 1, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_3, 10, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 7, 4, 1, 1);

        label_2 = new QLabel(TariffRateWidget);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 4, 1, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        okButton = new QPushButton(TariffRateWidget);
        okButton->setObjectName("okButton");
        okButton->setMinimumSize(QSize(120, 40));
        okButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_3->addWidget(okButton);


        gridLayout_3->addLayout(horizontalLayout_3, 11, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_4, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 7, 0, 1, 1);

        label_3 = new QLabel(TariffRateWidget);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 6, 1, 1, 2);

        tarrifRate2 = new QDoubleSpinBox(TariffRateWidget);
        tarrifRate2->setObjectName("tarrifRate2");
        tarrifRate2->setMinimumSize(QSize(120, 40));
        tarrifRate2->setFont(font);
        tarrifRate2->setDecimals(3);
        tarrifRate2->setMaximum(1.000000000000000);
        tarrifRate2->setSingleStep(0.010000000000000);

        gridLayout_3->addWidget(tarrifRate2, 7, 1, 1, 2);

        tarrifRate3 = new QDoubleSpinBox(TariffRateWidget);
        tarrifRate3->setObjectName("tarrifRate3");
        tarrifRate3->setMinimumSize(QSize(120, 40));
        tarrifRate3->setFont(font);
        tarrifRate3->setDecimals(3);
        tarrifRate3->setMaximum(1.000000000000000);
        tarrifRate3->setSingleStep(0.010000000000000);

        gridLayout_3->addWidget(tarrifRate3, 9, 1, 1, 2);


        verticalLayout->addLayout(gridLayout_3);

        QWidget::setTabOrder(tarrifRate1, tarrifRate2);
        QWidget::setTabOrder(tarrifRate2, tarrifRate3);
        QWidget::setTabOrder(tarrifRate3, okButton);

        retranslateUi(TariffRateWidget);

        QMetaObject::connectSlotsByName(TariffRateWidget);
    } // setupUi

    void retranslateUi(QWidget *TariffRateWidget)
    {
        TariffRateWidget->setWindowTitle(QCoreApplication::translate("TariffRateWidget", "Form", nullptr));
        label_4->setText(QCoreApplication::translate("TariffRateWidget", "\320\224\320\276\320\261\321\200\320\276\320\262\320\276\320\273\321\214\320\275\320\276\320\265 \320\274\320\265\320\264\320\270\321\206\320\270\320\275\321\201\320\272\320\276\320\265 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label->setText(QCoreApplication::translate("TariffRateWidget", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\320\265 \321\202\320\260\321\200\320\270\321\204\320\275\321\203\321\216 \321\201\321\202\320\260\320\262\320\272\321\203", nullptr));
        label_2->setText(QCoreApplication::translate("TariffRateWidget", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265 \320\260\320\262\321\202\320\276\321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\260:", nullptr));
        okButton->setText(QCoreApplication::translate("TariffRateWidget", "\320\236\320\272", nullptr));
        label_3->setText(QCoreApplication::translate("TariffRateWidget", "\320\241\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\276\320\274\320\260\321\210\320\275\320\265\320\263\320\276 \320\270\320\274\321\203\321\211\320\265\321\201\321\202\320\262\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TariffRateWidget: public Ui_TariffRateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TARIFFRATEWIDGET_H
