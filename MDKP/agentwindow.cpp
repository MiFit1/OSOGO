#include "agentwindow.h"
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
}

AgentWindow::~AgentWindow()
{
    delete ui;
}

void AgentWindow::ConfiguringInterface(){
    parentWidgetRenegotiationContract = ui->ParentWidgetRenContract;

    //Кнопка профиля
    ui->tabWidget->setCornerWidget(profileButton, Qt::TopLeftCorner);
    profilePanel->raise();

    //layout
    layoutParentWidgetRenegotiationContract = new QVBoxLayout(parentWidgetRenegotiationContract);
    viewRenegotiateContract = new QTableView();
    viewStatistic = ui->statisticView;
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

    sqlStatisticModel = new AgentStatisticModel(user,this);
    viewStatistic->setModel(sqlStatisticModel);
    viewStatistic->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewStatistic->setSelectionMode(QAbstractItemView::SingleSelection);
    viewStatistic->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    viewStatistic->setColumnHidden(0,true);
    viewStatistic->horizontalHeader()->setHighlightSections(false);


    //Эффект тени на дочерние объекты
    for (auto child : ui->ConcludeTab->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly)) {
        if (child->metaObject()->className() == QStringLiteral("QLabel")) {
            // Пропускаем QLabel
            continue;
        }
        QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
        shadowEffect->setBlurRadius(20);
        shadowEffect->setColor(QColor(140,140,140,255));
        shadowEffect->setOffset(3,3);
        child->setGraphicsEffect(shadowEffect);
    }
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
