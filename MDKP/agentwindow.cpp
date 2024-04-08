#include "agentwindow.h"
#include "qmessagebox.h"
#include "ui_agentwindow.h"


AgentWindow::AgentWindow(const User& us,Database* database, QWidget *parent)
    : AbstractUserWindow(us,parent)
    , ui(new Ui::AgentWindow)
{
    ui->setupUi(this);
    db = database;
    ConfiguringInterface();
    connect(viewRenegotiateContract, SIGNAL(doubleClicked(QModelIndex)), SLOT(slotDoubleClikedOnRenegitiationContract(QModelIndex)));
    connect(renegotiationContractWidget, SIGNAL(signalBackButtonClicked()), SLOT(slotRenegotiateWidgetBackButtonClicked()));
    connect(ui->ConcludeContractButton,SIGNAL(clicked()),SLOT(slotConcludeContractButtonClicked()));
    connect(renegotiationContractWidget, SIGNAL(signalRenegotiateContractDataChanged()),SLOT(slotRenegotiateContractDataChanged()));
}

AgentWindow::~AgentWindow()
{
    delete ui;
}

void AgentWindow::ConfiguringInterface(){

    //Кнопка профиля
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    profilePanel->raise();

    //layout
    stackedWidgetRenegotiateContract = ui->stackedWidgetRenegotiateContract;
    viewRenegotiateContract = new QTableView(stackedWidgetRenegotiateContract);
    viewStatistic = ui->statisticView;
    renegotiationContractWidget = new RenegotiateContractWindow(user,db,stackedWidgetRenegotiateContract);
    stackedWidgetRenegotiateContract->addWidget(viewRenegotiateContract);
    stackedWidgetRenegotiateContract->addWidget(renegotiationContractWidget);

    sqlModelRenegotiate = new QSqlQueryModel(this);
    sqlModelRenegotiate->setQuery("SELECT   Contract.ID,"
                                  "         TypeInsurance as [Тип договора],"
                                  "         Client.LastName || ' ' || Client.FirstName || ' ' || COALESCE(Client.Patronymic,'') as [ФИО клиента],"
                                  "         Contract.Datee "
                                  "FROM Contract "
                                  "     JOIN Client ON Contract.ID_Client = Client.ID "
                                  "WHERE Contract.Status = 2;");
    viewRenegotiateContract->setModel(sqlModelRenegotiate);
    viewRenegotiateContract->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewRenegotiateContract->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewRenegotiateContract->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewRenegotiateContract->horizontalHeader()->setHighlightSections(false);
    viewRenegotiateContract->setColumnHidden(0,true);

    sqlStatisticModel = new AgentStatisticModel(user,this);
    viewStatistic->setModel(sqlStatisticModel);
    viewStatistic->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewStatistic->setSelectionMode(QAbstractItemView::SingleSelection);
    viewStatistic->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewStatistic->setColumnHidden(0,true);
    viewStatistic->horizontalHeader()->setHighlightSections(false);

    AddShadowToChildren(ui->ConcludeTab);
    ShowViewRenegotiateContract();
}

void AgentWindow::ShowViewRenegotiateContract(){
    stackedWidgetRenegotiateContract->setCurrentWidget(viewRenegotiateContract);
}

void AgentWindow::ShowRenegotiateContractWidget(){
    stackedWidgetRenegotiateContract->setCurrentWidget(renegotiationContractWidget);
}

void AgentWindow::slotDoubleClikedOnRenegitiationContract(const QModelIndex index){
    int indexRowClicked = index.row();
    int idContract = sqlModelRenegotiate->index(indexRowClicked, 0).data().toInt();
    Contract contract = db->GetContractById(idContract);
    Client client = db->GetClientById(contract.GetIdClient());
    renegotiationContractWidget->SetContractAndClient(contract, client);
    ShowRenegotiateContractWidget();
}

void AgentWindow::slotRenegotiateWidgetBackButtonClicked(){
    ShowViewRenegotiateContract();
}

void AgentWindow::slotConcludeContractButtonClicked(){
    QString lastName = ui->LastName->text();
    QString firstName = ui->FirstName->text();
    QString patronymic = ui->Patronymic->text();
    QString phone = ui->Phone->text();
    Client client("-1",lastName,firstName,patronymic,phone);

    int idClient = -1;
    try {
        idClient = db->RegisterClient(client);
    } catch (std::runtime_error& err) {
        QMessageBox::critical(this,"Ошибка",err.what());
        return;
    }

    Contract contract("-1", "", ui->Summa->text(), ui->TypeContract->currentText(), "", QString::number(idClient), QString::number(user.GetId()), "1");

    try {
        db->AddContract(contract);
    } catch (std::runtime_error& err) {
        QMessageBox::critical(this,"Ошибка",err.what());
        return;
    }

    ClearContractDataUi();
}

void AgentWindow::ClearContractDataUi(){
    ui->LastName->clear();
    ui->FirstName->clear();
    ui->Patronymic->clear();
    ui->Phone->clear();
    ui->Summa->clear();
    ui->TypeContract->setCurrentIndex(-1);
}

void AgentWindow::viewRenegotiateContractRefresh(){
    sqlModelRenegotiate->setQuery(sqlModelRenegotiate->query().lastQuery());
}

void AgentWindow::slotRenegotiateContractDataChanged(){
    viewRenegotiateContractRefresh();
    ShowViewRenegotiateContract();
}
