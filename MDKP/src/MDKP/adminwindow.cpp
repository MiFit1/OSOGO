#include "ui_adminwindow.h"
#include "adminwindow.h"

AdminWindow::AdminWindow(const User& us, Database* database, QWidget *parent) :
    AbstractUserWindow(us,parent),
    ui(new Ui::AdminWindow)
{
    qDebug() << "call constructor";
    ui->setupUi(this);
    db = database;
    defaulStyleSheetRegButton = ui->registrationButton->styleSheet();
    configuringInterface();
    ClearDataRegistrationUserWidget();
    SetValidationOnCreateUsers();
    AddShadow(changeUserDataWidget);
    AddShadow(ui->AddUserTab);
    ReadAndSetShadowSettings();
    connect(viewUsers,SIGNAL(doubleClicked(QModelIndex)),SLOT(slotDoubleClikedOnUser(QModelIndex)));
    connect(changeUserDataWidget, SIGNAL(signalBackButtonCliked()),SLOT(slotBackButtonChangeUserWidgetCliked()));
    connect(changeUserDataWidget,SIGNAL(signalConfirmButtonClicked()),SLOT(slotChangeUserConfirmButtonClicked()));
    connect(ui->registrationButton, SIGNAL(clicked()),SLOT(slotRegistrationButtonClicked()));
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
    messagePanel->raise();

    stackedWidgetUserManagement = ui->stackedWidgetUserManagement;
    viewUsers = new QTableView(stackedWidgetUserManagement);
    changeUserDataWidget = new ChangeUserDataWidget(stackedWidgetUserManagement);
    stackedWidgetUserManagement->addWidget(viewUsers);
    stackedWidgetUserManagement->addWidget(changeUserDataWidget);
    ShowViewUsers();

   //ФИО телефон должность филиал
    usersModel = new QSqlQueryModel(this);
    usersModel->setQuery(Database::GetQueryToSelectEmployee());
    viewUsers->setModel(usersModel);
    DefaultSettingView(viewUsers);
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
        ShowMessage(err.what(),false, ui->registrationButton);
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
        ShowMessage(err.what(),false);
        return;
    }

    ShowMessage("Пользователь добавлен",true);
    ClearDataRegistrationUserWidget();
    RefreshDataView();
}

void AdminWindow::RefreshDataView(){
    usersModel->setQuery(usersModel->query().lastQuery());
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
    if(ui->Phone->text().length() < 18){
        throw std::runtime_error("Телефон не указан полностью.");
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
    ui->LastName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->FirstName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->Patronymic->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->Branch->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_BRANCH_AND_ADDRESS,this));
    ui->Address->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_BRANCH_AND_ADDRESS,this));
    ui->LoginLine->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_LOGIN,this));
}

void AdminWindow::slotChangeUserConfirmButtonClicked(){
    try {
        changeUserDataWidget->CheckingFieldsEmpty();
    } catch (std::runtime_error& err) {
        QPushButton* confirmButton = changeUserDataWidget->GetConfirmBurron();
        ShowMessage(err.what(),false,confirmButton);
        return;
    }

    User changeUser = changeUserDataWidget->GetSelectUser();
    db->RefreshUserById(changeUser);
    RefreshDataView();
    ShowViewUsers();
}

