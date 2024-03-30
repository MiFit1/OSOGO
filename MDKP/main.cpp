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

    QSqlQuery query;
    QString str_query = "CREATE TABLE if not exists test_table ("
                        "ID integer PRIMARY KEY NOT NULL,"
                        "LastName NVARCHAR(20) NOT NULL,"
                        "FirstName NVARCHAR(20) NOT NULL,"
                        "Patronymic NVARCHAR(20) NULL,"
                        "Datee date NULL);";
    bool queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся создать таблицу";
        qDebug() << query.lastError();
    }

    str_query = "INSERT INTO test_table (LastName, FirstName, Patronymic, Datee) VALUES "
                "('Eliseev','Vasiliy','Andreevych', DATE()),"
                "('Петечкин','Пётр','Петрович', DATE()),"
                "('Ольгерд','фон Эверек', NULL, DATE());";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся вставить данные";
        qDebug() << query.lastError();
    }

    Database* db = new Database();

    WindowNavigator navigator(db);
    return a.exec();
}

