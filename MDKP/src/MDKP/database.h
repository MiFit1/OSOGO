#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QList>
#include <QVariant>
#include "contract.h"
#include "client.h"
#include "user.h"
#include "comment.h"

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    void SetSqlDatabase(QSqlDatabase &sdb);
    void CreateTables();
    void InsertTestData();
    void InsertAdmin();
    Contract GetContractById(int id);
    Client GetClientById(int id);
    User GetUserById(int id);
    User CheckLogin(const QString login, const QString password);
    void RegisterUser(QString LastName, QString FirstName, QString Patronymic, QString Phone, QString Role, QString Address, QString Branch, QString Login, QString Password);
    void RefreshUserById(User user);
    void AddContract(Contract contract);
    int RegisterClient(Client client);
    void RefreshClientById(Client client);
    void RefreshContractById(Contract contract);
    void CheckClientNumberForId(Client client);//Есть ли другие клиенты с таким же телефоном, но другим id
    void AddComment(QString comment, int IdAccountant, int IdContract);
    QList<Comment> GetCommentsByIdContract(int idContract);

    static QString GetQueryToSelectEmployee();
    static QString GetQueryToSelectStatisticsAccountant(int idUser, QString fieldToSort, QString typeSort);
    static QString GetQueryToSelectContractsToConfirm();
    static QString GetQueryToSelectStatisticsAgent(int idUser, QString fieldToSort, QString typeSort);
    static QString GetQueryToSelectRenegotiateContract(int idUser);
private:
    QSqlDatabase* sqlDatabase;

signals:
};

#endif // DATABASE_H
