#ifndef USERTABLEMODEL_H
#define USERTABLEMODEL_H

#include "QAbstractTableModel"
#include <QObject>
#include <QList>
#include "user.h"

class UserTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit UserTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void addUser(const User& user);
    User getUser(int index);
    User getUser(const QModelIndex &index);
private:
    QList<User> m_users;
    int columnQuantity = 6;
signals:

};

#endif // USERTABLEMODEL_H
