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
    AddShadowToChildren(changeUserDataWidget);
    AddShadowToChildren(ui->AddUserTab);
    connect(viewUsers,SIGNAL(doubleClicked(QModelIndex)),SLOT(slotDoubleClikedOnUser(QModelIndex)));
    connect(changeUserDataWidget, SIGNAL(signalBackButtonCliked()),SLOT(slotBackButtonChangeUserWidgetCliked()));
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
                         "      LastName ||' '|| FirstName ||' '||Patronymic as [ФИО],"
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
