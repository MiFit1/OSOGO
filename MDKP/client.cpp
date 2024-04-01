#include "client.h"

Client::Client() {
    valid = false;
}

Client::Client(QString ID, QString LastName, QString FirstName, QString Patronymic, QString Phone){
    id = ID.toInt();
    lastName = LastName;
    firstName = FirstName;
    patronymic = Patronymic;
    phone = Phone;
    valid = true;
}

int Client::GetId(){
    return id;
}

QString Client::GetFirstName(){
    return firstName;
}

QString Client::GetLastName(){
    return lastName;
}

QString Client::GetPatronymic(){
    return patronymic;
}

QString Client::GetPhone(){
    return phone;
}

bool Client::isValid(){
    return valid;
}
