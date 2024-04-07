#include "user.h"

User::User(int id, int post, int isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch) {
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

User::User(QString ID,QString IsWorked, QString LastName, QString FirstName, QString Patronymic, QString Address, QString Phone, QString Branch, QString Login, QString Password, QString Role){
    empty = false;
    id = ID.toInt();
    isWork = IsWorked.toInt();
    lastName = LastName;
    firstName = FirstName;
    patronymic = Patronymic;
    address = Address;
    phone = Phone;
    branch = Branch;
    login = Login;
    post = User::convertPostToInt(Role);
}

User::User(int id, int post, int isWork, QString lastName, QString firstName, QString patronymic, QString address, QString phone, QString branch, QString Login, QString Password) {
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

void User::operator << (QSqlQuery& query){
    query.next();
    if(query.value(0).isNull()){
        empty = true;
        return;
    }

    id = query.value("ID").toString().toInt();
    isWork = query.value("IsWorked").toString().toInt();
    lastName = query.value("LastName").toString();
    firstName = query.value("FirstName").toString();
    patronymic = query.value("Patronymic").toString();
    address = query.value("Address").toString();
    phone = query.value("Phone").toString();
    branch = query.value("Branch").toString();
    login = query.value("Login").toString();
    password = query.value("Password").toString();
    int role = User::convertPostToInt(query.value("Role").toString());
    post = role;
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
int User::GetId() const{
    return id;
}

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

QString User::convertPost(int post){
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

int User::convertPostToInt(QString post){
    if(post == "Агент"){
        return Agent;
    }
    if(post == "Бухгалтер"){
        return Accountant;
    }
    if(post == "Администратор"){
        return Admin;
    }

    return Unknown;
}
