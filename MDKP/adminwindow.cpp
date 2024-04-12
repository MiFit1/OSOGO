#include "ui_adminwindow.h"
#include "adminwindow.h"

AdminWindow::AdminWindow(const User& us, Database* database, QWidget *parent) :
    AbstractUserWindow(us,parent),
    ui(new Ui::AdminWindow)
{
    qDebug() << "call constructor";
    ui->setupUi(this);
    db = database;
    configuringInterface();
    ClearDataRegistrationUserWidget();
    SetValidationOnCreateUsers();
    AddShadowToChildren(changeUserDataWidget);
    AddShadowToChildren(ui->AddUserTab);
    connect(viewUsers,SIGNAL(doubleClicked(QModelIndex)),SLOT(slotDoubleClikedOnUser(QModelIndex)));
    connect(changeUserDataWidget, SIGNAL(signalBackButtonCliked()),SLOT(slotBackButtonChangeUserWidgetCliked()));
    connect(ui->registrationButton, SIGNAL(clicked()),SLOT(slotRegistrationButtonClicked()));
    connect(changeUserDataWidget, SIGNAL(signalRefreshUser(User&)),SLOT(slotRefreshUserInDatabase(User&)));
}

AdminWindow::~AdminWindow()
{
    qDebug() << "call destructor";
    delete ui;
}

void AdminWindow::configuringInterface(){

    //Кнопка профиля
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    profilePanel->raise();

    stackedWidgetUserManagement = ui->stackedWidgetUserManagement;
    viewUsers = new QTableView(stackedWidgetUserManagement);
    changeUserDataWidget = new ChangeUserDataWidget(stackedWidgetUserManagement);
    stackedWidgetUserManagement->addWidget(viewUsers);
    stackedWidgetUserManagement->addWidget(changeUserDataWidget);
    ShowViewUsers();

   //ФИО телефон должность филиал
    usersModel = new QSqlQueryModel(this);
    usersModel->setQuery("SELECT Employee.ID, "
                         "      LastName ||' '|| FirstName ||' '||COALESCE(Patronymic,'') as [ФИО],"
                         "      Phone as [Телефон], "
                         "      Role as [Должность], "
                         "      Branch as [Филиал]"
                         " FROM Employee");
    viewUsers->setModel(usersModel);
    viewUsers->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewUsers->horizontalHeader()->setStretchLastSection(true);
    viewUsers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewUsers->setSelectionMode(QAbstractItemView::SingleSelection);
    viewUsers->horizontalHeader()->setHighlightSections(false);
    viewUsers->setColumnHidden(0,true);
}

void AdminWindow::ShowViewUsers(){
    stackedWidgetUserManagement->setCurrentWidget(viewUsers);
}

void AdminWindow::ShowChangeUserDataWidget(){
    stackedWidgetUserManagement->setCurrentWidget(changeUserDataWidget);
}

void AdminWindow::slotDoubleClikedOnUser(const QModelIndex index){
    //qDebug()<<index.row();
    ShowChangeUserDataWidget();
    QModelIndex indexID = usersModel->index(index.row(),0);
    int IdUser = usersModel->data(indexID).toInt();
    User user = db->GetUserById(IdUser);
    changeUserDataWidget->setUserToChangeWidget(user);
}

void AdminWindow::slotBackButtonChangeUserWidgetCliked(){
    ShowViewUsers();
}

void AdminWindow::slotRegistrationButtonClicked(){

    try {
        CheckingFieldsEmpty();
    } catch (std::runtime_error& err) {
        QMessageBox::information(this,"Предупреждение",err.what());
        return;
    }

    QString LastName = ui->LastName->text();
    QString FirstName = ui->FirstName->text();
    QString Patronymic = ui->Patronymic->text();
    QString Phone = ui->Phone->text();
    QString Role = ui->Post->currentText();
    QString Address = ui->Address->text();
    QString Branch = ui->Branch->text();
    QString Login = ui->LoginLine->text();
    QString Password = ui->PasswordLine->text();

    try {
        db->RegisterUser(LastName,FirstName,Patronymic,Phone,Role,Address,Branch,Login,Password);
    } catch (const std::runtime_error& err) {
        QMessageBox::critical(this,"Ошибка",err.what());
        return;
    }

    ClearDataRegistrationUserWidget();
    RefreshDataView();
}

void AdminWindow::RefreshDataView(){
    usersModel->setQuery(usersModel->query().lastQuery());
}

void AdminWindow::slotRefreshUserInDatabase(User& user){
    db->RefreshUserById(user);
    RefreshDataView();
    ShowViewUsers();
}

void AdminWindow::ClearDataRegistrationUserWidget(){
    ui->LastName->clear();
    ui->FirstName->clear();
    ui->Patronymic->clear();
    ui->Phone->clear();
    ui->Address->clear();
    ui->Branch->clear();
    ui->LoginLine->clear();
    ui->PasswordLine->clear();
    ui->Post->setCurrentIndex(-1);
}

void AdminWindow::CheckingFieldsEmpty(){
    if(ui->LastName->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле фамилии не может быть пустым.");
    }
    if(ui->FirstName->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле имени не может быть пустым.");
    }
    if(ui->Phone->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле телефона не может быть пустым.");
    }
    if(ui->LoginLine->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле логина не может быть пустым.");
    }
    if(ui->PasswordLine->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле пароля не может быть пустым.");
    }
    if(ui->Post->currentIndex() == -1){
        throw std::runtime_error("Не указана должность пользователя.");
    }
}

void AdminWindow::SetValidationOnCreateUsers(){
    QRegularExpression regExpOnFIO("[A-Za-zA-яа-я\\s-]*");
    ui->LastName->setValidator(new QRegularExpressionValidator(regExpOnFIO,this));
    ui->FirstName->setValidator(new QRegularExpressionValidator(regExpOnFIO,this));
    ui->Patronymic->setValidator(new QRegularExpressionValidator(regExpOnFIO,this));

    QRegularExpression regExpOnBranchAndAddress("[A-Za-zA-яа-я0-9\\s\\-,.]*");
    ui->Branch->setValidator(new QRegularExpressionValidator(regExpOnBranchAndAddress,this));
    ui->Address->setValidator(new QRegularExpressionValidator(regExpOnBranchAndAddress,this));

    QRegularExpression regExpOnLogin("[A-Za-zA-яа-я0-9\\s\\-_.]*");
    ui->LoginLine->setValidator(new QRegularExpressionValidator(regExpOnLogin,this));
}
