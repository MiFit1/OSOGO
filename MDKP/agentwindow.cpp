#include "agentwindow.h"
#include "ui_agentwindow.h"

AgentWindow::AgentWindow(Database* database, QWidget *parent)
    : AbstractUserWindow(parent)
    , ui(new Ui::AgentWindow)
{
    ui->setupUi(this);
    db = database;
    ConfiguringInterface();
    connect(viewRenegotiateContract, SIGNAL(doubleClicked(QModelIndex)), SLOT(slotDoubleClikedOnRenegitiationContract(QModelIndex)));
    connect(renegotiationContractWidget, SIGNAL(signalBackButtonClicked()), SLOT(slotRenegotiateWidgetBackButtonClicked()));
}

AgentWindow::~AgentWindow()
{
    delete ui;
}

void AgentWindow::ConfiguringInterface(){
    parentWidgetRenegotiationContract = ui->ParentWidgetRenContract;

    //Кнопка профиля
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");
    profilePanel->raise();

    //layout
    layoutParentWidgetRenegotiationContract = new QVBoxLayout(parentWidgetRenegotiationContract);
    viewRenegotiateContract = new QTableView();
    renegotiationContractWidget = new RenegotiateContractWindow();

    sqlModelRenegotiate = new QSqlQueryModel(this);
    sqlModelRenegotiate->setQuery("SELECT   Contract.ID,"
                                  "         TypeInsurance as [Тип договора],"
                                  "         Client.LastName || ' ' || Client.FirstName || ' ' || COALESCE(Client.Patronymic,'') as [ФИО клиента],"
                                  "         Contract.Datee "
                                  "FROM Contract "
                                  "     JOIN Client ON Contract.ID_Client = Client.ID;");
    viewRenegotiateContract->setModel(sqlModelRenegotiate);
    viewRenegotiateContract->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewRenegotiateContract->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewRenegotiateContract->setColumnHidden(0,true);

    ShowViewRenegotiateContract();
}

void AgentWindow::ShowViewRenegotiateContract(){
    DeleteParentRenegotiationWidgetChildren();
    viewRenegotiateContract->setParent(parentWidgetRenegotiationContract);
    layoutParentWidgetRenegotiationContract->addWidget(viewRenegotiateContract);
}

void AgentWindow::ShowRenegotiateContractWidget(){
    DeleteParentRenegotiationWidgetChildren();
    renegotiationContractWidget->setParent(parentWidgetRenegotiationContract);
    layoutParentWidgetRenegotiationContract->addWidget(renegotiationContractWidget);
}

void AgentWindow::DeleteParentRenegotiationWidgetChildren(){
    QLayoutItem* item = layoutParentWidgetRenegotiationContract->itemAt(0);
    if(item != NULL){
        layoutParentWidgetRenegotiationContract->removeItem(item);
        layoutParentWidgetRenegotiationContract->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetRenegotiationContract->update();
    }
}

void AgentWindow::slotDoubleClikedOnRenegitiationContract(const QModelIndex index){
    int indexRowClicked = index.row();
    int idContract = sqlModelRenegotiate->index(indexRowClicked, 0).data().toInt();
    //Contract contract = db->GetContractById(idContract);
    //Client client = db->GetClientById(contract.GetIdClient());
    //confirmationWindow->SetContractAndClient(contract, client);
    ShowRenegotiateContractWidget();
}

void AgentWindow::slotRenegotiateWidgetBackButtonClicked(){
    ShowViewRenegotiateContract();
}
