#include "agentstatisticmodel.h"
#include "database.h"

AgentStatisticModel::AgentStatisticModel(const User user, QObject *parent)
    : QSqlQueryModel(parent)
{
    this->user = user;
    ResetCurrentSortingTypeToColumn();

}

QString AgentStatisticModel::convertNumberColumnToName(int numberColumn){
    if(numberColumn == 1)
        return "[Тип договора]";
    if(numberColumn == 2)
        return "[ФИО клиента]";
    if(numberColumn == 3)
        return "[Дата заключения]";
    if(numberColumn == 4)
        return "[Ставка]";
    if(numberColumn == 5)
        return "[Сумма договора]";
    if(numberColumn == 6)
        return "[Плата]";
    return QString();
}

void AgentStatisticModel::ResetCurrentSortingTypeToColumn(){
    for (int i = 0; i < 6; ++i) {
        currentSortingTypeToColumn[i] = true;
    }
}

void AgentStatisticModel::UpdateView(int numberColumnToSort){

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

    QString str = (Database::GetQueryToSelectStatisticsAgent(user.GetId(),fieldToSort,typeSort));
    setQuery(str);

    if(this->lastError().isValid()){
        qDebug()<<"Не удалось выполнить сортировку.";
        throw std::runtime_error("Не удалось выполнить сортировку.");
    }

}
