#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch);
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
    bool empty;

public:
    //void operator = (const User &user);
    QString GetLastName() const;
    QString GetFirstName() const;
    QString GetPatronymic() const;
    bool isEmpty() const;
};
//Q_DECLARE_METATYPE(User)

#endif // USER_H
