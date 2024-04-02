#include "accountantwindow.h"
#include "ui_accountantwindow.h"

AccountantWindow::AccountantWindow(Database* database, QWidget *parent) :
    AbstractUserWindow(parent),
    ui(new Ui::AccountantWindow)
{
    ui->setupUi(this);
    db = database;
    ConfiguringInterface();
    connect(viewContracts, SIGNAL(doubleClicked(QModelIndex)), SLOT(slotDoubleClikedOnContract(QModelIndex)));
    connect(confirmationWindow, SIGNAL(signalBackButtonClicked()),SLOT(slotConfirmWidgetBackButtonClicked()));
}

AccountantWindow::~AccountantWindow()
{
    delete ui;
}

void AccountantWindow::ConfiguringInterface(){
    //Кнопка профиля
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    profilePanel->raise();

    //layout вкладки подтверждения договоров
    layoutParentWidgetConfirmContract = new QVBoxLayout(ui->ParentWidgetConfirmContract);
    viewContracts = new QTableView();
    confirmationWindow = new ContractConfirmationWindow();
    ShowViewContracts();

    //layout вкладки статистики
    layoutParentWidgetStatistics = new QVBoxLayout(ui->ParentWidgetStatistics);
    viewStatistics = new QTableView(ui->ParentWidgetStatistics);
    layoutParentWidgetStatistics->addWidget(viewStatistics);

    //Модель договоров (для подтверждения)
    sqlModelContract = new QSqlQueryModel(this);
    sqlModelContract->setQuery("SELECT  Contract.ID,"
                       "        TypeInsurance as [Тип договора],"
                       "        Client.LastName || ' ' || Client.FirstName || ' ' || COALESCE(Client.Patronymic,'') as [ФИО клиента],"
                       "        Employee.LastName || ' ' || Employee.FirstName || ' ' || COALESCE(Employee.Patronymic,'') as [ФИО агента],"
                       "        Contract.Summa as [Сумма договора],"
                       "        Contract.Datee as [Дата заключения]"
                       "FROM Contract"
                       "    JOIN Client ON Contract.ID_Client = Client.ID "
                       "    JOIN Employee ON Contract.ID_Employee = Employee.ID "
                       "WHERE Contract.Status = 1;");
    viewContracts->setModel(sqlModelContract);
    viewContracts->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewContracts->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewContracts->setColumnHidden(0,true);

    sqlModelStatistics = new AccountantModelStatistics(this);
    viewStatistics->setModel(sqlModelStatistics);
    viewStatistics->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewStatistics->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewStatistics->setColumnHidden(0,true);
}

//установка родительского виджета для виджета представления контрактов и добаление его в layout
void AccountantWindow::ShowViewContracts(){
    DeleteParentWidgetChildren();
    viewContracts->setParent(ui->ParentWidgetConfirmContract);
    layoutParentWidgetConfirmContract->addWidget(viewContracts);
}

void AccountantWindow::ShowConfirmationWindow(){
    DeleteParentWidgetChildren();
    confirmationWindow->setParent(ui->ParentWidgetConfirmContract);
    layoutParentWidgetConfirmContract->addWidget(confirmationWindow);
}

//очистка layout у родительского виджета и удаления виджета из layout
void AccountantWindow::DeleteParentWidgetChildren(){
    QLayoutItem* item = layoutParentWidgetConfirmContract->itemAt(0);
    if(item != NULL){
        layoutParentWidgetConfirmContract->removeItem(item);
        layoutParentWidgetConfirmContract->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetConfirmContract->update();
    }
}

void AccountantWindow::slotDoubleClikedOnContract(const QModelIndex index){
    int indexRowClicked = index.row();
    int idContract = sqlModelContract->index(indexRowClicked, 0).data().toInt();
    Contract contract = db->GetContractById(idContract);
    Client client = db->GetClientById(contract.GetIdClient());
    confirmationWindow->SetContractAndClient(contract, client);
    ShowConfirmationWindow();
}

void AccountantWindow::slotConfirmWidgetBackButtonClicked(){
    ShowViewContracts();
}
