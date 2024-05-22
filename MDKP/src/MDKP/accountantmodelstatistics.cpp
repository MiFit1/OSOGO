#include "accountantmodelstatistics.h"
#include "database.h"


AccountantModelStatistics::AccountantModelStatistics(User user, QObject *parent)
    : QSqlQueryModel(parent)
{
    this->user = user;
    ResetCurrentSortingTypeToColumn();
    UpdateView();
}
void AccountantModelStatistics::ResetCurrentSortingTypeToColumn(){
    for (int i = 0; i < 7; ++i) {
        currentSortingTypeToColumn[i] = true;
    }
}

QString AccountantModelStatistics::convertNumberColumnToName(int numberColumn){
    if(numberColumn == 1)
        return "[Тип договора]";
    if(numberColumn == 2)
        return "[ФИО клиента]";
    if(numberColumn == 3)
        return "[ФИО агента]";
    if(numberColumn == 4)
        return "[Сумма договора]";
    if(numberColumn == 5)
        return "[Ставка]";
    if(numberColumn == 6)
        return "[Плата]";
    if(numberColumn == 7)
        return "[Дата заключения]";
    return QString();
}

void AccountantModelStatistics::UpdateView(int numberColumnToSort){

    QString fieldToSort = convertNumberColumnToName(numberColumnToSort);
    if(fieldToSort.isEmpty()){
        throw std::runtime_error("Поля для сортировки с таким номером не существует.");
    }

    QString typeSort;
    int indexCurrentColumn = numberColumnToSort - 1;
    if(currentSortingTypeToColumn[indexCurrentColumn]){
        typeSort = "ASC";
    }
    else{
        typeSort = "DESC";
    }
    currentSortingTypeToColumn[indexCurrentColumn] = !currentSortingTypeToColumn[indexCurrentColumn];

    setQuery(Database::GetQueryToSelectStatisticsAccountant(user.GetId(), fieldToSort, typeSort));
}
