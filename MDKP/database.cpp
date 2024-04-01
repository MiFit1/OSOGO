#include "database.h"
#include <QDateTime>

Database::Database(QObject *parent)
    : QObject{parent}
{

}

void Database::SetSqlDatabase(QSqlDatabase &sdb){
    sqlDatabase = &sdb;
}

void  Database::CreateTables(){
    QSqlQuery query;
    QString str_query = "CREATE TABLE if not exists Contract ("
                        "ID INTEGER PRIMARY KEY NOT NULL,"
                        "Datee DATE NOT NULL,"
                        "Summa DECIMAL(10,2) NOT NULL,"
                        "TypeInsurance NVARCHAR(100) NOT NULL,"
                        "TariffRate FLOAT NULL,"
                        "ID_Client INTEGER NOT NULL,"
                        "ID_Employee INTEGER NOT NULL,"
                        "Status INTEGER NOT NULL,"
                        "FOREIGN KEY (ID_Client) REFERENCES Client(ID),"
                        "FOREIGN KEY (ID_Employee) REFERENCES Employee(ID));";
    bool queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся создать таблицу Contract";
        qDebug() << query.lastError();
    }

    str_query = "CREATE TABLE if not exists Client ("
                        "ID INTEGER PRIMARY KEY NOT NULL,"
                        "LastName NVARCHAR(20) NOT NULL,"
                        "FirstName NVARCHAR(20) NOT NULL,"
                        "Patronymic NVARCHAR(20) NULL,"
                        "Phone NVARCHAR(20) NOT NULL);";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся создать таблицу Client";
        qDebug() << query.lastError();
    }

    str_query = "CREATE TABLE if not exists Employee ("
                "ID INTEGER PRIMARY KEY NOT NULL,"
                "IsWorked INTEGER NOT NULL,"
                "LastName NVARCHAR(20) NOT NULL,"
                "FirstName NVARCHAR(20) NOT NULL,"
                "Patronymic NVARCHAR(20) NULL,"
                "Address NVARCHAR(100) NULL,"
                "Phone NVARCHAR(20) NOT NULL,"
                "Branch NVARCHAR(100) NOT NULL,"
                "Login NVARCHAR(40) NOT NULL,"
                "Password NVARCHAR(40) NOT NULL,"
                "Role NVARCHAR(20) NOT NULL);";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся создать таблицу Client";
        qDebug() << query.lastError();
    }

    str_query = "CREATE TABLE if not exists CommentsOn ("
                "ID INTEGER PRIMARY KEY NOT NULL,"
                "ID_Employee INTEGER NOT NULL,"
                "ID_Contract INTEGER NOT NULL,"
                "ID_Comment INTEGER NOT NULL,"
                "FOREIGN KEY (ID_Employee) REFERENCES Employee(ID),"
                "FOREIGN KEY (ID_Contract) REFERENCES Contract(ID),"
                "FOREIGN KEY (ID_Comment) REFERENCES Commment(ID));";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся создать таблицу CommentsOn";
        qDebug() << query.lastError();
    }

    str_query = "CREATE TABLE if not exists Comment ("
                "ID INTEGER PRIMARY KEY NOT NULL,"
                "Comment NVARCHAR(1000) NOT NULL,"
                "Datee DATE NOT NULL);";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся создать таблицу Comment";
        qDebug() << query.lastError();
    }

}

void  Database::InsertTestData(){
    QSqlQuery query;
    QString str_query = "INSERT INTO Contract (Datee, Summa, TypeInsurance, TariffRate, ID_Client, ID_Employee, Status) VALUES "
                        "(DATETIME(), 690700,'Договор страхования жизни', 0.56, 1,2,1),"
                        "(DATETIME(), 346798,'Договор страхования жизни', 0.678, 2,2,1),"
                        "(DATETIME(), 488000,'Договор страхования машины', 0.8, 3,2,3);";
    bool queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся вставить данные";
        qDebug() << query.lastError();
    }

    str_query = "INSERT INTO Client (LastName, FirstName, Patronymic, Phone) VALUES "
                        "('Иванов', 'Максим', 'Артёмович', '74950065354'),"
                        "('Романова', 'Татьяна', 'Борисовна', '74951348095'),"
                        "('Зайцева', 'Виктория', NULL, '74950956851');";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся вставить данные";
        qDebug() << query.lastError();
    }

    str_query = "INSERT INTO Employee (IsWorked, LastName, FirstName, Patronymic, Phone, Branch, Login, Password, Role) VALUES "
                "(1, 'Семенов', 'Николай', 'Тимофеевич', '74956772849', '125149, г. Москва, ул. Куйбышева, 12, оф. 58', 'admin', 'admin', 'Администратор'),"
                "(1, 'Козырева', 'София', 'Назаровна', '74954657197', '630597, г. Новосибирск, ул. Южная, 37, оф. 51', 'agent1', '1', 'Агент'),"
                "(1, 'Яковлев', 'Михаил', 'Георгиевич', '74959388993', '630597, г. Новосибирск, ул. Южная, 37, оф. 51', 'accountant1', '1', 'Бухгалтер');";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся вставить данные";
        qDebug() << query.lastError();
    }

    str_query = "SELECT *"
                "FROM Contract;";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся вставить данные";
        qDebug() << query.lastError();
    }

}

Contract Database::GetContractById(int id){
    QSqlQuery query;
    QString str_query = QString("SELECT *"
                                "FROM Contract "
                                "WHERE ID = %1;").arg(id);

    bool queryResult = query.exec(str_query);

    if(!queryResult){
        qDebug() << query.lastError();
        return Contract();
    }

    query.next();
    if(query.value(0).isNull()){
        return Contract();
    }

    QString ID = query.value("ID").toString();
    QString Datee = query.value("Datee").toString();
    QString Summa = query.value("Summa").toString();
    QString TypeInsurance = query.value("TypeInsurance").toString();
    QString TariffRate = query.value("TariffRate").toString();
    QString ID_Client = query.value("ID_Client").toString();
    QString ID_Employee = query.value("ID_Employee").toString();
    QString Status = query.value("Status").toString();

    return Contract(ID,Datee,Summa,TypeInsurance,TariffRate,ID_Client,ID_Employee,Status);
}

Client Database::GetClientById(int id){
    QSqlQuery query;
    QString str_query = QString("SELECT *"
                                "FROM Client "
                                "WHERE ID = %1;").arg(id);

    bool queryResult = query.exec(str_query);

    if(!queryResult){
        qDebug() << query.lastError();
        return Client();
    }

    query.next();
    if(query.value(0).isNull()){
        return Client();
    }

    QString ID = query.value("ID").toString();
    QString LastName = query.value("LastName").toString();
    QString FirstName = query.value("FirstName").toString();
    QString Patronymic = query.value("Patronymic").toString();
    QString Phone = query.value("Phone").toString();

    return Client(ID,LastName,FirstName,Patronymic,Phone);
}
