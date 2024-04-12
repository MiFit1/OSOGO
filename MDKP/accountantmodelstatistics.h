#ifndef ACCOUNTANTMODELSTATISTICS_H
#define ACCOUNTANTMODELSTATISTICS_H
#include <QtSql>
#include <QObject>

class AccountantModelStatistics : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit AccountantModelStatistics(QObject *parent = nullptr);
    void UpdateView(int numberColumnToSort = 7);
    QString convertNumberColumnToName(int numberColumn);

private:
    bool currentSortingTypeToColumn[7];
    void ResetCurrentSortingTypeToColumn();

signals:
};

#endif // ACCOUNTANTMODELSTATISTICS_H
