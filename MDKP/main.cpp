#include "windownavigator.h"
#include "agentwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Database* db = new Database();
    QApplication a(argc, argv);
    WindowNavigator navigator(db);
    return a.exec();
}


