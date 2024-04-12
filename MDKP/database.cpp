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
                        "Summa FLOAT NOT NULL,"
                        "TypeInsurance NVARCHAR(100) NOT NULL,"
                        "TariffRate FLOAT NULL,"
                        "ID_Client INTEGER NOT NULL,"
                        "ID_Employee INTEGER NULL,"
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
                        "LastName NVARCHAR(40) NOT NULL,"
                        "FirstName NVARCHAR(40) NOT NULL,"
                        "Patronymic NVARCHAR(40) NULL,"
                        "Phone NVARCHAR(20) NOT NULL);";
    queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << "Не удаётся создать таблицу Client";
        qDebug() << query.lastError();
    }

    str_query = "CREATE TABLE if not exists Employee ("
                "ID INTEGER PRIMARY KEY NOT NULL,"
                "IsWorked INTEGER NOT NULL,"
                "LastName NVARCHAR(40) NOT NULL,"
                "FirstName NVARCHAR(40) NOT NULL,"
                "Patronymic NVARCHAR(40) NULL,"
                "Address NVARCHAR(100) NULL,"
                "Phone NVARCHAR(20) NOT NULL,"
                "Branch NVARCHAR(100) NULL,"
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
                        "(DATETIME('now', '+7 hours'), 690700,'Добровольное медицинское страхование', 0.56, 1,2,1),"
                        "(DATETIME('now', '+7 hours'), 346798,'Cтрахование домашнего имущества', 0.678, 2,2,2),"
                        "(DATETIME('now', '+7 hours'), 488000,'Cтрахование автотранспорта', 0.8, 3,2,3);";
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
                "(1, 'Семенов', 'Николай', 'Тимофеевич', '74956772849', '125149, г. Москва, ул. Куйбышева, 12, оф. 58', '1', '1', 'Администратор'),"
                "(1, 'Козырева', 'София', NULL, '74954657197', '630597, г. Новосибирск, ул. Южная, 37, оф. 51', '2', '2', 'Агент'),"
                "(1, 'Яковлев', 'Михаил', 'Георгиевич', '74959388993', '630597, г. Новосибирск, ул. Южная, 37, оф. 51', '3', '3', 'Бухгалтер');";
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


    if(query.next() && query.value(0).isNull()){
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

    if(query.next() && query.value(0).isNull()){
        return Client();
    }

    QString ID = query.value("ID").toString();
    QString LastName = query.value("LastName").toString();
    QString FirstName = query.value("FirstName").toString();
    QString Patronymic = query.value("Patronymic").toString();
    QString Phone = query.value("Phone").toString();

    return Client(ID,LastName,FirstName,Patronymic,Phone);
}

User Database::GetUserById(int id){
    QSqlQuery query;
    QString str_query = QString("SELECT * "
                                "FROM Employee "
                                "WHERE ID = %1;").arg(id);

    bool queryResult = query.exec(str_query);

    if(!queryResult){
        qDebug() << query.lastError();
        return User();
    }

    User user;
    user << query;

    return user;
}

User Database::CheckLogin(const QString login, const QString password){
    QSqlQuery query;
    QString str_query = QString("SELECT * "
                                "FROM Employee "
                                "WHERE Login = '%1' AND Password = '%2';").arg(login,password);

    bool queryResult = query.exec(str_query);

    if(!queryResult){
        qDebug() << query.lastError();
        return User();
    }

    User user;
    user << query;
    return user;
}

void Database::RegisterUser(QString LastName, QString FirstName, QString Patronymic, QString Phone, QString Role, QString Address, QString Branch, QString Login, QString Password){
    QSqlQuery query;
    QString str_query = QString("SELECT * "
                                "FROM Employee "
                                "WHERE Login = '%1';").arg(Login);

    bool queryResult = query.exec(str_query);
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось выполнить запрос.");
    }

    if(query.next() && !query.value(0).isNull()){
        throw std::runtime_error("Данный логин уже используется.");
    }

    query.prepare("SELECT ID "
                  "FROM Employee "
                  "WHERE Phone = :phone;");
    query.bindValue(":phone",Phone);
    query.exec();
    if(query.next() && !query.value(0).isNull()){
        throw std::runtime_error("Данный номер телефона уже используется.");
    }

    query.prepare("INSERT INTO Employee (IsWorked, LastName, FirstName, Patronymic, Phone, Branch, Login, Password, Role, Address) VALUES "
                  "(1, :lastName, :firstName, :patronymic, :phone, :branch, :login, :password, :role,:address);");
    query.bindValue(":lastName",LastName);
    query.bindValue(":firstName",FirstName);
    query.bindValue(":patronymic",Patronymic);
    query.bindValue(":phone",Phone);
    query.bindValue(":branch",Branch);
    query.bindValue(":login",Login);
    query.bindValue(":password",Password);
    query.bindValue(":role",Role);
    query.bindValue(":address",Address);
    queryResult = query.exec();

    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Вставка данных не выполнена.");
    }
}

void Database::RefreshUserById(User user){
    QSqlQuery query;
    query.prepare("UPDATE  Employee "
                  "SET    IsWorked = :worked, "
                  "       LastName = :lastName, "
                  "       FirstName = :firstName, "
                  "       Patronymic = :patronymic,"
                  "       Address = :address, "
                  "       Phone = :phone, "
                  "       Branch = :branch, "
                  "       Login = :login, "
                  "       Password = :password, "
                  "       Role = :role "
                  "WHERE ID = :id;");
    query.bindValue(":worked", user.GetStatus());
    query.bindValue(":lastName", user.GetLastName());
    query.bindValue(":firstName", user.GetFirstName());
    query.bindValue(":patronymic", user.GetPatronymic());
    query.bindValue(":address", user.GetAddress());
    query.bindValue(":phone", user.GetPhone());
    query.bindValue(":branch", user.GetBranch());
    query.bindValue(":login", user.GetLogin());
    query.bindValue(":password", user.GetPassword());
    query.bindValue(":role", User::convertPost(user.GetPost()));
    query.bindValue(":id", user.GetId());

    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось обновить данные.");
    }
}

int Database::RegisterClient(Client client){
    QSqlQuery query;
    query.prepare("SELECT * "
                  "FROM Client "
                  "WHERE Phone = :phone;");
    query.bindValue(":phone",client.GetPhone());
    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось проверить данные клиента в БД.");
    }

    //Если номер занят
    if(query.next() && !query.value(0).isNull()){
        //Номер занят, но ФИО не совпадает
        if((query.value("LastName").toString() != client.GetLastName()) ||
            (query.value("FirstName").toString() != client.GetFirstName()) ||
            (query.value("Patronymic").toString() != client.GetPatronymic())){
            throw std::runtime_error("Данный номер занят другим клиентом.");
        }
        //Номер занят, но ФИО совпадают
        return query.value("ID").toInt();
    }

    //Номер не занят
    query.prepare("INSERT INTO Client (LastName, FirstName, Patronymic, Phone) VALUES"
                  "(:lastName, :firstName, :patronymic, :phone)");
    query.bindValue(":lastName", client.GetLastName());
    query.bindValue(":firstName", client.GetFirstName());
    query.bindValue(":patronymic", client.GetPatronymic());
    query.bindValue(":phone", client.GetPhone());
    queryResult = query.exec();

    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось вставить данные о клиенте в БД.");
    }

    //Поиск только что вставленного клиента
    query.prepare("SELECT * "
                  "FROM Client "
                  "WHERE LastName = :lastName AND "
                  "     FirstName = :firstName AND "
                  "     Patronymic = :patronymic AND "
                  "     Phone = :phone;");
    query.bindValue(":lastName", client.GetLastName());
    query.bindValue(":firstName", client.GetFirstName());
    query.bindValue(":patronymic", client.GetPatronymic());
    query.bindValue(":phone", client.GetPhone());
    queryResult = query.exec();

    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось осуществить поиск вставленного пользователя.");
    }

    if(query.next() && query.value(0).isNull()){
        qDebug() << query.lastError();
        throw std::runtime_error("Вставленный пользователь не найден.");
    }

    return query.value("ID").toInt();
}

void Database::AddContract(Contract contract){
    QSqlQuery query;
    query.prepare("INSERT INTO Contract (Datee, Summa, TypeInsurance, ID_Client, ID_Employee, Status) VALUES "
                  "(DATETIME('now', '+7 hours'), :summa, :typeContract, :idClient, :idEmployee, :status);");
    query.bindValue(":summa", contract.GetSumma());
    query.bindValue(":typeContract", contract.GetTypeInsurance());
    query.bindValue(":idClient", contract.GetIdClient());
    query.bindValue(":idEmployee", contract.GetIdEmployee());
    query.bindValue(":status", contract.GetStatus());

    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось вставить данные в БД.");
    }
}

void Database::RefreshClientById(Client client){
    QSqlQuery query;
    query.prepare("UPDATE  Client "
                  "SET    LastName = :lastName, "
                  "       FirstName = :firstName, "
                  "       Patronymic = :patronymic, "
                  "       Phone = :phone "
                  "WHERE ID = :id;");
    query.bindValue(":lastName", client.GetLastName());
    query.bindValue(":firstName", client.GetFirstName());
    query.bindValue(":patronymic", client.GetPatronymic());
    query.bindValue(":phone", client.GetPhone());
    query.bindValue(":id", client.GetId());

    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось обновить данные.");
    }
}
void Database::RefreshContractById(Contract contract){
    QSqlQuery query;
    query.prepare("UPDATE  Contract "
                  "SET    Datee = DATETIME('now', '+7 hours'), "
                  "       Summa = :summa, "
                  "       TariffRate = :rate, "
                  "       TypeInsurance = :typeContract, "
                  "       ID_Client = :idClient,"
                  "       ID_Employee = :idEmployee, "
                  "       Status = :status "
                  "WHERE ID = :id;");
    query.bindValue(":summa", contract.GetSumma());
    query.bindValue(":rate", contract.GetTariffRate());
    query.bindValue(":typeContract", contract.GetTypeInsurance());
    query.bindValue(":idClient", contract.GetIdClient());
    query.bindValue(":idEmployee", contract.GetIdEmployee());
    query.bindValue(":status", contract.GetStatus());
    query.bindValue(":id", contract.GetId());
    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось обновить данные.");
    }
}

void Database::CheckClientNumberForId(Client client){
    QSqlQuery query;
    query.prepare("SELECT * "
                  "FROM Client "
                  "WHERE ID <> :id AND Phone = :phone;");
    query.bindValue(":id",client.GetId());
    query.bindValue(":phone",client.GetPhone());

    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось осуществить поиск.");
    }

    if(query.next() && !query.value(0).isNull()){
        qDebug() << query.lastError();
        throw std::runtime_error("Клиент с таким номером телефона уже есть.");
    }
}
void Database::AddComment(QString comment, int IdAccountant, int IdContract){
    QSqlQuery query;
    query.prepare("INSERT INTO Comment (Comment, Datee) VALUES "
                  "(:comment , DATETIME('now', '+7 hours'));");
    query.bindValue(":comment", comment);

    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось вставить комментарий в БД.");
    }

    int idComment = query.lastInsertId().toInt();
    query.prepare("INSERT INTO CommentsOn (ID_Employee, ID_Contract, ID_Comment) VALUES "
                  "(:idEmployee, :idContract, :idComment);");
    query.bindValue(":idEmployee", IdAccountant);
    query.bindValue(":idContract", IdContract);
    query.bindValue(":idComment", idComment);

    queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось вставить данные в CommentsOn.");
    }
}

QList<Comment> Database::GetCommentsByIdContract(int idContract){
    QList<Comment> comments;
    QSqlQuery query;
    query.prepare("SELECT   Employee.LastName || ' ' || Employee.FirstName || ' ' || COALESCE(Employee.Patronymic,''), "
                  "         strftime('%H:%M', Comment.Datee), "
                  "         Comment.Comment "
                  "FROM CommentsOn "
                  " JOIN Employee ON Employee.ID = CommentsOn.ID_Employee "
                  " JOIN Contract ON Contract.ID = CommentsOn.ID_Contract "
                  " JOIN Comment ON Comment.ID = CommentsOn.ID_Comment "
                  "WHERE Contract.ID = :idContract;");
    query.bindValue(":idContract", idContract);

    bool queryResult = query.exec();
    if(!queryResult){
        qDebug() << query.lastError();
        throw std::runtime_error("Не удалось осуществить поиск в БД.");
    }

    if(!query.next() && query.value(0).isNull()){
        return comments;
    }

    do{
        Comment comm;
        comm.SetAccountantData(query.value(0).toString());
        comm.SetDate(query.value(1).toString());
        comm.SetComment(query.value(2).toString());
        comments.push_back(comm);
    }
    while(query.next());

    return comments;
}

void Database::InsertAdmin(){
    QSqlQuery query;
    query.prepare("SELECT ID "
                  "FROM Employee "
                  "WHERE Login = 'admin' AND Password = 'admin';");
    if(!query.exec()){
        qDebug()<<"Не удалось вставить админа";
    }

    if(query.next() && !query.value(0).isNull()){
        return;
    }
    else{
        query.prepare("INSERT INTO Employee (IsWorked, LastName, FirstName, Patronymic, Phone, Branch, Login, Password, Role) VALUES "
                      "(1, 'Super', 'User', NULL , '89243341176', '125149, г. Москва, ул. Куйбышева, 12, оф. 58', 'admin', 'admin', 'Администратор')");
        query.exec();
    }
}
