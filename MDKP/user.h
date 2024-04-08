#ifndef USER_H
#define USER_H
#include <QString>
#include <QtSql>
#include "Global.h"

class User
{
public:
    User(QString ID,QString IsWorked, QString LastName, QString FirstName, QString Patronymic, QString Address, QString Phone, QString Branch, QString Login, QString Password, QString Role);
    User(int id, int post, int isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch);
    User(int id, int post, int isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch, QString Login, QString Password);
    User();
    int getRole() const;
private:
    int id;
    int post;
    int isWork;
    QString lastName;
    QString firstName;
    QString patronymic;
    QString address;
    QString phone;
    QString branch;
    QString login;
    QString password;
    bool empty;

public:
    //void operator = (const User &user);
    void operator << (QSqlQuery &query);
    void SetLastName(QString lastName);
    void SetFirstName(QString firstName);
    void SetPatronymic(QString patronymic);
    void SetPhone(QString phone);
    void SetAddress(QString address);
    void SetPost(int post);
    void SetStatus(int status);
    void SetBranch(QString branch);
    void SetPassword(QString password);
    void SetLogin(QString login);
    int GetId() const;
    QString GetLastName() const;
    QString GetFirstName() const;
    QString GetPatronymic() const;
    QString GetPhone() const;
    QString GetAddress() const;
    int GetPost() const;
    int GetStatus() const;
    QString GetBranch() const;
    QString GetPassword() const;
    QString GetLogin() const;
    bool isEmpty() const;
    static QString convertPost(int post);
    static int convertPostToInt(QString post);
    static QString convertStatusToString(int status);
    static int convertStatusToInt(QString status);
};
//Q_DECLARE_METATYPE(User)

#endif // USER_H
