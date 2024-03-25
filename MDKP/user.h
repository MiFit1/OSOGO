#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch);
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
};
//Q_DECLARE_METATYPE(User)

#endif // USER_H
