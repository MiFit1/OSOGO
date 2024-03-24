#include "mainwindow.h"
#include "adminwindow.h"
#include "accountantwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AccountantWindow acc;
    acc.show();
    return a.exec();
}
