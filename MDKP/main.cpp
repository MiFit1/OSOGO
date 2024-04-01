#include "windownavigator.h"
#include "agentwindow.h"
#include <QApplication>
#include <QtSql>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("OSOGO.sqlite");
    if (!sdb.open()) {
        qDebug()<<"Не удалось открыть базу данных";
    }

    Database* db = new Database();
    db->SetSqlDatabase(sdb);
    db->CreateTables();
    db->InsertTestData();

    WindowNavigator navigator(db);
    return a.exec();
}

