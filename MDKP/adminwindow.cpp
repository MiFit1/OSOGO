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

    // QWidget* central = new QWidget(this);
    // QLabel* lbl = new QLabel("TEST",this);
    // stackedLayout = new QStackedLayout(central);
    // stackedLayout->addWidget(lbl);
    // stackedLayout->addWidget(centralWidget());
    // stackedLayout->setStackingMode(QStackedLayout::StackAll);
    // central->setLayout(stackedLayout);
    // setCentralWidget(central);

    //Тесты
   // notify = new QFrame(this);
   // notify->setProperty("notifyArea", true);
   // notify->setFrameShape(QFrame::NoFrame);
   // connectionMessage = new NotifyMessage("Привет ад.", notify);
   // subscriptionMessage = new NotifyMessage("Я честно сам делал эти всплывающие виджеты.", notify);
   // QVBoxLayout* notifyLayout = new QVBoxLayout(notify);
   // notifyLayout->setContentsMargins(QMargins());
   // notifyLayout->setSpacing(1);
   // notifyLayout->addWidget(connectionMessage);
   // notifyLayout->addWidget(subscriptionMessage);
   // notify->hide();
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
    //ShowMessage("Тестовое сообщение, всё гуд kjsdfhgks\n jdhgkj hfkjdjkg djdf",true);
    //kkkkkk
     // notify->show();
     // WAF::Animation::sideSlideIn(notify, WAF::BottomSide, false);
     // connectionMessage->showMessage();
     // subscriptionMessage->showMessage();


    try {
        CheckingFieldsEmpty();
    } catch (std::runtime_error& err) {
        //QMessageBox::information(this,"Предупреждение",err.what());
        ShowMessage(err.what(),false);
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
        //QMessageBox::critical(this,"Ошибка",err.what());
        ShowMessage(err.what(),false);
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
    ui->LastName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->FirstName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->Patronymic->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));

    ui->Branch->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_BRANCH_AND_ADDRESS,this));
    ui->Address->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_BRANCH_AND_ADDRESS,this));

    ui->LoginLine->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_LOGIN,this));
}
