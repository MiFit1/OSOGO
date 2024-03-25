#include "user.h"

User::User(int id, int post, bool isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch) {
    //int id = -1, int post =-1, bool isWork = false, QString lastName = "", QString firstName = "", QString patronymic = "", QString address = "", QString phone = "", QString branch = ""
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

int User::getRole() const{
    return post;
}
