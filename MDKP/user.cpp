#include "user.h"

User::User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch) {
    //int id = -1, int post =-1, bool isWork = false, QString lastName = "", QString firstName = "", QString patronymic = "", QString address = "", QString phone = "", QString branch = ""
 //   empty = false;
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
