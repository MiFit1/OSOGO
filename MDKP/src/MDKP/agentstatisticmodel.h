#ifndef AGENTSTATISTICMODEL_H
#define AGENTSTATISTICMODEL_H
#include "user.h"
#include <QObject>
#include <QtSql>

class AgentStatisticModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit AgentStatisticModel(const User user,QObject *parent = nullptr);
    void UpdateView(int numberColumnToSort = 3);
    QString convertNumberColumnToName(int numberColumn);
private:
    bool currentSortingTypeToColumn[6];
    void ResetCurrentSortingTypeToColumn();
    User user;
signals:
};

#endif // AGENTSTATISTICMODEL_H
