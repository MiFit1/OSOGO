#ifndef USER_H
#define USER_H
#include <QString>
#include "Global.h"

class User
{
public:
    User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch);
    User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch, QString Login, QString Password);
    User();
    int getRole() const;
private:
    int id;
    int post;
    bool isWork;
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
    int GetId() const;
    QString GetLastName() const;
    QString GetFirstName() const;
    QString GetPatronymic() const;
    QString GetPhone() const;
    QString GetAddress() const;
    int GetPost() const;
    QString GetBranch() const;
    QString GetPassword() const;
    QString GetLogin() const;
    bool isEmpty() const;
    static QString convertPost(int post);
};
//Q_DECLARE_METATYPE(User)

#endif // USER_H
