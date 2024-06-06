#ifndef CONTRACT_H
#define CONTRACT_H
#include <QDateTime>
#include <QString>

class Contract
{
public:
    Contract();
    Contract(QString ID, QString Date, QString Summa, QString TypeInsurance, QString TariffRate, QString IdClient, QString IdEmployee, QString Status, QString IdConfirmedAccountant = "-1");
    int GetId();
    QDateTime GetDate();
    QString GetSumma();
    QString GetTypeInsurance();
    double GetTariffRate();
    int GetIdAccountant();
    int GetIdClient();
    int GetIdEmployee();
    int GetStatus();
    bool isValid();
    void SetSumma(QString Summa);
    void SetStatus(int Status);
    void SetTypeInsurance(QString TypeContract);
    void SetIdEmployee(int IdEmployee);
    void SetTariffRate(double Rate);
    void SetIdConfirmedAccountant(int IdAccountant);
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
    bool valid;
    int idConfirmedAccountant;
};

#endif // CONTRACT_H
