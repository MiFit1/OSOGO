#include "contract.h"

Contract::Contract(){
    valid = false;
}
Contract::Contract(QString ID, QString Date, QString Summa, QString TypeInsurance,
                   QString TariffRate, QString IdClient, QString IdEmployee, QString Status,
                   QString IdConfirmedAccountant, QString Description) {
    id = ID.toInt();
    date =  QDateTime::fromString(Date,"yyyy-MM-dd hh:mm:ss");
    summa = Summa;
    typeInsurance = TypeInsurance;
    tariffRate = TariffRate.toDouble();
    idClient = IdClient.toInt();
    idEmployee = IdEmployee.toInt();
    status = Status.toInt();
    description = Description;
    idConfirmedAccountant = IdConfirmedAccountant.toInt();
    valid = true;
}

void Contract::SetIdConfirmedAccountant(int IdAccountant){
    idConfirmedAccountant = IdAccountant;
}

int Contract::GetIdAccountant(){
    return idConfirmedAccountant;
}

int Contract::GetId(){
    return id;
}

QDateTime Contract::GetDate(){
    return date;
}

QString Contract::GetSumma(){
    return summa;
}

QString Contract::GetTypeInsurance(){
    return typeInsurance;
}

double Contract::GetTariffRate(){
    return tariffRate;
}

int Contract::GetIdClient(){
    return idClient;
}

int Contract::GetIdEmployee(){
    return idEmployee;
}

int Contract::GetStatus(){
    return status;
}

QString Contract::GetDescription(){
    return description;
}

bool Contract::isValid(){
    return valid;
}

void Contract::SetSumma(QString Summa){
    summa = Summa;
}
void Contract::SetStatus(int Status){
    status = Status;
}
void Contract::SetTypeInsurance(QString TypeContract){
    typeInsurance = TypeContract;
}
void Contract::SetIdEmployee(int IdEmployee){
    idEmployee = IdEmployee;
}

void Contract::SetTariffRate(double Rate){
    tariffRate = Rate;
}

int Contract::ConvertTypeContractToNumber(QString TypeContract){
    if(TypeContract == "Добровольное медицинское страхование"){
        return 0;
    }
    else if(TypeContract == "Страхование домашнего имущества"){
        return 1;
    }
    else if(TypeContract == "Страхование автотранспорта"){
        return 2;
    }

    throw std::runtime_error("Не удалось преобразовать тип договора");
    return -1;
}

