#include "mainwindow.h"
#include "adminwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminWindow admin;
    admin.show();
    return a.exec();
}
