#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include "contract.h"
#include "client.h"
#include "user.h"
#include <stdexcept>

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
    User GetUserById(int id);
    User CheckLogin(const QString login, const QString password);
    void RegisterUser(QString LastName, QString FirstName, QString Patronymic, QString Phone, QString Role, QString Address, QString Branch, QString Login, QString Password);
    void RefreshUserById(User user);
private:
    QSqlDatabase* sqlDatabase;

signals:
};

#endif // DATABASE_H
