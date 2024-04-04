#include "accountantmodelstatistics.h"


AccountantModelStatistics::AccountantModelStatistics(QObject *parent)
    : QSqlQueryModel(parent)
{
    setQuery("SELECT    Contract.ID,"
             "          TypeInsurance as [Тип договора],"
             "          Client.LastName || ' ' || Client.FirstName || ' ' || COALESCE(Client.Patronymic,'') as [ФИО клиента],"
             "          Employee.LastName || ' ' || Employee.FirstName || ' ' || COALESCE(Employee.Patronymic,'') as [ФИО агента],"
             "          Contract.Summa as [Сумма договора],"
             "          Contract.TariffRate as [Ставка],"
             "          Contract.TariffRate * Contract.Summa as [Плата],"
             "          Contract.Datee as [Дата заключения]"
             "FROM Contract "
             "     JOIN Client ON Contract.ID_Client = Client.ID "
             "     JOIN Employee ON Contract.ID_Employee = Employee.ID "
             "WHERE Contract.Status = 3;");
}
