#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include "contract.h"
#include "client.h"

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    void SetSqlDatabase(QSqlDatabase &sdb);
    void CreateTables();
    void InsertTestData();
    Contract GetContractById(int id);
    Client GetClientById(int id);
private:
    QSqlDatabase* sqlDatabase;

signals:
};

#endif // DATABASE_H
