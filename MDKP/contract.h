#ifndef CONTRACT_H
#define CONTRACT_H
#include <QDateTime>
#include <QString>

class Contract
{
public:
    Contract();
    Contract(QString ID, QString Date, QString Summa, QString TypeInsurance, QString TariffRate, QString IdClient, QString IdEmployee, QString Status);
    int GetId();
    QDateTime GetDate();
    double GetSumma();
    QString GetSummaString();
    QString GetTypeInsurance();
    double GetTariffRate();
    int GetIdClient();
    int GetIdEmployee();
    int GetStatus();
    bool isValid();
private:
    int id;
    QDateTime date;
    double summa;
    QString typeInsurance;
    double tariffRate;
    int idClient;
    int idEmployee;
    int status;
    bool valid;
};

#endif // CONTRACT_H
