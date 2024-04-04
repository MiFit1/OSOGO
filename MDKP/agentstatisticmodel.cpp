#include "agentstatisticmodel.h"

AgentStatisticModel::AgentStatisticModel(const User user, QObject *parent)
    : QSqlQueryModel(parent)
{
    setQuery(QString("SELECT    Contract.ID, "
             "          TypeInsurance as [Тип договора], "
             "          Client.LastName || ' ' || Client.FirstName || ' ' || COALESCE(Client.Patronymic,'') as [ФИО клиента], "
             "          Contract.Datee as [Дата заключения], "
             "          Contract.TariffRate as [Ставка], "
             "          Contract.Summa as [Сумма договора], "
             "          Contract.TariffRate * Contract.Summa as [Плата] "
             "FROM Contract "
             "     JOIN Client ON Contract.ID_Client = Client.ID "
             "     JOIN Employee ON Contract.ID_Employee = Employee.ID "
             "WHERE Contract.Status = 3 AND Contract.ID_Employee = %1;").arg(user.GetId()));
    qDebug()<<user.GetId() <<"StatisticModel";
}
