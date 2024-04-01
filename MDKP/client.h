#ifndef CLIENT_H
#define CLIENT_H
#include <QString>

class Client
{
public:
    Client();
    Client(QString ID, QString LastName, QString FirstName, QString Patronymic, QString Phone);
    int GetId();
    QString GetLastName();
    QString GetFirstName();
    QString GetPatronymic();
    QString GetPhone();
    bool isValid();
private:
    int id;
    QString lastName;
    QString firstName;
    QString patronymic;
    QString phone;
    bool valid;
};

#endif // CLIENT_H
