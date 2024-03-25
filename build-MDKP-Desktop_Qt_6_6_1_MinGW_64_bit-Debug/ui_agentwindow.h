/********************************************************************************
** Form generated from reading UI file 'agentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTWINDOW_H
#define UI_AGENTWINDOW_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_8;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_6;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AgentWindow)
    {
        if (AgentWindow->objectName().isEmpty())
            AgentWindow->setObjectName("AgentWindow");
        AgentWindow->resize(748, 361);
        centralwidget = new QWidget(AgentWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        comboBox = new QComboBox(tab);
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(comboBox, 2, 3, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 3, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_4, 6, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_6, 3, 3, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 2, 1, 1);

        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_4, 5, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout->addItem(verticalSpacer_3, 0, 2, 1, 1);

        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_3, 4, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(120, 30));

        horizontalLayout_5->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_5, 7, 5, 1, 1);

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 2, 5, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_6 = new QHBoxLayout(tab_2);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        tableView = new QTableView(tab_2);
        tableView->setObjectName("tableView");

        horizontalLayout_6->addWidget(tableView);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        AgentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AgentWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 748, 17));
        AgentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AgentWindow);
        statusbar->setObjectName("statusbar");
        AgentWindow->setStatusBar(statusbar);

        retranslateUi(AgentWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AgentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AgentWindow)
    {
        AgentWindow->setWindowTitle(QCoreApplication::translate("AgentWindow", "MainWindow", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("AgentWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("AgentWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\265:", nullptr));
        label->setText(QCoreApplication::translate("AgentWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\272\320\273\320\270\320\265\320\275\321\202\320\265:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AgentWindow", "\320\227\320\260\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\264\320\276\320\263\320\276\320\262\320\276\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("AgentWindow", "\320\227\320\260\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\264\320\276\320\263\320\276\320\262\320\276\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("AgentWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentWindow: public Ui_AgentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTWINDOW_H
