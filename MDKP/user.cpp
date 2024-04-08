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

    empty = false;
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

void User::SetLastName(QString lastName){
    this->lastName = lastName;
}
void User::SetFirstName(QString firstName){
    this->firstName = firstName;
}
void User::SetPatronymic(QString patronymic){
    this->patronymic = patronymic;
}
void User::SetPhone(QString phone){
    this->phone = phone;
}
void User::SetAddress(QString address){
    this->address = address;
}
void User::SetPost(int post){
    this->post = post;
}
void User::SetStatus(int status){
    this->isWork = status;
}
void User::SetBranch(QString branch){
    this->branch = branch;
}
void User::SetPassword(QString password){
    this->password = password;
}
void User::SetLogin(QString login){
    this->login = login;
}

User::User(){
    empty = true;
}

int User::getRole() const{
    return post;
}

int User::GetStatus() const{
    return isWork;
}

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

int User::convertStatusToInt(QString status){
    if(status == "Работает"){
        return Works;
    }
    if(status == "Уволен"){
        return Fired;
    }
    return UnknownStatus;
}

QString User::convertStatusToString(int status){
    switch (status) {
    case Fired:
        return QString("Уволен");
        break;
    case Works:
        return QString("Работает");
        break;
    case UnknownStatus:
        return QString("Unknown");
        break;
    default:
        break;
    }
    return QString("Unknown");
}
