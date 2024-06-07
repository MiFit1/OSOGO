#ifndef CONTRACT_H
#define CONTRACT_H
#include <QDateTime>
#include <QString>

class Contract
{
public:
    Contract();
    Contract(QString ID, QString Date, QString Summa, QString TypeInsurance,
             QString TariffRate, QString IdClient, QString IdEmployee, QString Status,
             QString IdConfirmedAccountant = "-1", QString Description = "");
    int GetId();
    QDateTime GetDate();
    QString GetSumma();
    QString GetTypeInsurance();
    double GetTariffRate();
    int GetIdAccountant();
    int GetIdClient();
    int GetIdEmployee();
    int GetStatus();
    QString GetDescription();
    bool isValid();
    void SetSumma(QString Summa);
    void SetStatus(int Status);
    void SetTypeInsurance(QString TypeContract);
    void SetIdEmployee(int IdEmployee);
    void SetTariffRate(double Rate);
    void SetIdConfirmedAccountant(int IdAccountant);
    void SetDescription(QString description);
    static int ConvertTypeContractToNumber(QString TypeContract);
private:
    int id;
    QDateTime date;
    QString summa;
    QString typeInsurance;
    double tariffRate;
    int idClient;
    int idEmployee;
    int status;
    QString description;
    bool valid;
    int idConfirmedAccountant;
};

#endif // CONTRACT_H
