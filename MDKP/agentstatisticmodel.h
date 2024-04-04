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

signals:
};

#endif // AGENTSTATISTICMODEL_H
