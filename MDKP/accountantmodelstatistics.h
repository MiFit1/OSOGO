#ifndef ACCOUNTANTMODELSTATISTICS_H
#define ACCOUNTANTMODELSTATISTICS_H
#include <QtSql>
#include <QObject>

class AccountantModelStatistics : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit AccountantModelStatistics(QObject *parent = nullptr);

signals:
};

#endif // ACCOUNTANTMODELSTATISTICS_H
