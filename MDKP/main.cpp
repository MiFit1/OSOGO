#include "mainwindow.h"
#include "adminwindow.h"
#include "accountantwindow.h"
#include "agentwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AgentWindow acc;
    acc.show();
    return a.exec();
}
