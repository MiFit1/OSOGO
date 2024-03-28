#include "user.h"

User::User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch) {
    empty = false;
    this->id = id;
    this->post = post;
    this->isWork = isWork;
    this->lastName = lastName;
    this->firstName = firstName;
    this->patronymic = patronymic;
    this->address = address;
    this->phone = phone;
    this->branch = branch;
}

User::User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch, QString Login, QString Password) {
    empty = false;
    this->id = id;
    this->post = post;
    this->isWork = isWork;
    this->lastName = lastName;
    this->firstName = firstName;
    this->patronymic = patronymic;
    this->address = address;
    this->phone = phone;
    this->branch = branch;
    this->login = Login;
    this->password = Password;
}
//(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch, QString Login, QString Password)
User::User(){
    empty = true;
}

int User::getRole() const{
    return post;
}

// void User::operator =(const User &user){
//     this->id = user.id;
//     this->post = user.post;
//     this->isWork = user.isWork;
//     this->lastName = user.lastName;
//     this->firstName = user.firstName;
//     this->patronymic = user.patronymic;
//     this->address = user.address;
//     this->phone = user.phone;
//     this->branch = user.branch;
// }

bool User::isEmpty() const{
    return empty;
}

QString User::GetLastName() const{
    return lastName;
}

QString User::GetFirstName() const{
    return firstName;
}

QString User::GetPatronymic() const{
    return patronymic;
}
QString User::GetPhone() const{
    return phone;
}

int User::GetPost() const{
    return post;
}

QString User::GetBranch() const{
    return branch;
}

QString User::GetAddress() const{
    return address;
}

QString User::GetLogin() const{
    return login;
}

QString User::GetPassword() const{
    return password;
}

static QString convertPost(int post){
    switch (post) {
    case Admin:
        return QString("Администратор");
        break;
    case Accountant:
        return QString("Бухгалтер");
        break;
    case Agent:
        return QString("Агент");
        break;
    case Unknown:
        return QString("Unknown");
        break;
    default:
        break;
    }
    return QString("Unknown");
}
