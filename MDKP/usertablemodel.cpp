#include "usertablemodel.h"


UserTableModel::UserTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int UserTableModel::rowCount(const QModelIndex &parent) const{
    return m_users.size();
}

int UserTableModel::columnCount(const QModelIndex &parent) const{
    return columnQuantity;
}

QVariant UserTableModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || index.row() >= m_users.size() || index.column() >= columnQuantity)
    {
        return QVariant();
    }

    const User& user = m_users.at(index.row());
    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
        case 0:
            return user.GetLastName();
        case 1:
            return user.GetFirstName();
        case 2:
            return user.GetPatronymic();
        case 3:
            return user.GetPhone();
        case 4:
            return user.GetPost();
        case 5:
            return user.GetBranch();
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant UserTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return "Фамилия";
        case 1:
            return "Имя";
        case 2:
            return "Отчество";
        case 3:
            return "Телефон";
        case 4:
            return "Должность";
        case 5:
            return "Филиал";
        default:
            return QVariant();
        }
    }
    return QVariant();
}

void UserTableModel::addUser(const User &user)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_users << user;
    endInsertRows();
}

User UserTableModel::getUser(int index){
    if(index < 0 || index > (m_users.size()-1)){
        return User();
    }
    return m_users.at(index);
}

User UserTableModel::getUser(const QModelIndex& index){
    if(index.row() < 0 || index.row() > (m_users.size() -1)){
        return User();
    }
    return m_users.at(index.row());
}
