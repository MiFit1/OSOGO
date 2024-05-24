#include "agentwindow.h"
#include "ui_agentwindow.h"


AgentWindow::AgentWindow(const User& us,Database* database, QWidget *parent)
    : AbstractUserWindow(us,parent)
    , ui(new Ui::AgentWindow)
{
    ui->setupUi(this);
    db = database;
    ConfiguringInterface();
    ClearContractDataUi();
    SetValidationOnConfirmContract();
    AddShadow(ui->ConcludeTab);
    AddShadow(renegotiationContractWidget);
    ReadAndSetShadowSettings();
    QHeaderView* headerStatistics = viewStatistic->horizontalHeader();
    connect(viewRenegotiateContract, SIGNAL(doubleClicked(QModelIndex)), SLOT(slotDoubleClikedOnRenegitiationContract(QModelIndex)));
    connect(renegotiationContractWidget, SIGNAL(signalBackButtonClicked()), SLOT(slotRenegotiateWidgetBackButtonClicked()));
    connect(ui->ConcludeContractButton,SIGNAL(clicked()),SLOT(slotConcludeContractButtonClicked()));
    connect(headerStatistics,SIGNAL(sectionClicked(int)),SLOT(slotHeaderInStatisticWidgetClicked(int)));
    connect(renegotiationContractWidget,SIGNAL(signalSendButtonClicked()),SLOT(slotRenegotiateWidgetSendButtonClicked()));
}

AgentWindow::~AgentWindow()
{
    delete ui;
}

void AgentWindow::ConfiguringInterface(){
    messagePanel->raise();
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
    sqlModelRenegotiate->setQuery(Database::GetQueryToSelectRenegotiateContract(user.GetId()));
    viewRenegotiateContract->setModel(sqlModelRenegotiate);
    DefaultSettingView(viewRenegotiateContract);

    sqlStatisticModel = new AgentStatisticModel(user,this);
    sqlStatisticModel->UpdateView();
    viewStatistic->setModel(sqlStatisticModel);
    DefaultSettingView(viewStatistic);

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
    renegotiationContractWidget->ClearUserData();
    renegotiationContractWidget->SetContractAndClient(contract, client);
    renegotiationContractWidget->UpdateAccountantComments();
    ShowRenegotiateContractWidget();
}

void AgentWindow::slotRenegotiateWidgetBackButtonClicked(){
    ShowViewRenegotiateContract();
}

void AgentWindow::slotConcludeContractButtonClicked(){
    try {
        CheckingContractDataFieldsEmpty();
    } catch (std::runtime_error& err) {
        ShowMessage(err.what(),false,ui->ConcludeContractButton);
        return;
    }

    QString lastName = ui->LastName->text();
    QString firstName = ui->FirstName->text();
    QString patronymic = ui->Patronymic->text();
    QString phone = ui->Phone->text();
    Client client("-1",lastName,firstName,patronymic,phone);

    int idClient = -1;
    try {
        idClient = db->RegisterClient(client);
    } catch (std::runtime_error& err) {
        ShowMessage(err.what(),false,ui->ConcludeContractButton);
        return;
    }

    Contract contract("-1", "", ui->Summa->text(), ui->TypeContract->currentText(), "", QString::number(idClient), QString::number(user.GetId()), "1");

    try {
        db->AddContract(contract);
    } catch (std::runtime_error& err) {
        ShowMessage(err.what(),false,ui->ConcludeContractButton);
        return;
    }

    ShowMessage("Договор успешно добавлен.",true);
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

void AgentWindow::slotRenegotiateWidgetSendButtonClicked(){
    try {
        renegotiationContractWidget->CheckingFieldsEmpty();
    } catch (std::runtime_error& err) {
        QPushButton* sendButton = renegotiationContractWidget->GetSendButton();
        ShowMessage(err.what(),false,sendButton);
        return;
    }

    Client changedClient = renegotiationContractWidget->GetChangedClient();
    try {
        db->CheckClientNumberForId(changedClient);
        db->RefreshClientById(changedClient);
    } catch (std::runtime_error& err) {
        QPushButton* sendButton = renegotiationContractWidget->GetSendButton();
        ShowMessage(err.what(),false,sendButton);
        return;
    }

    Contract changedContract = renegotiationContractWidget->GetChangedContract();
    try {
        db->RefreshContractById(changedContract);
    } catch (std::runtime_error& err) {
        QPushButton* sendButton = renegotiationContractWidget->GetSendButton();
        ShowMessage(err.what(),false,sendButton);
        return;
    }

    viewRenegotiateContractRefresh();
    ShowViewRenegotiateContract();
}

void AgentWindow::slotHeaderInStatisticWidgetClicked(int index){
    sqlStatisticModel->UpdateView(index);
}

void AgentWindow::CheckingContractDataFieldsEmpty(){
    if(ui->LastName->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле фамилии не может быть пустым.");
    }
    if(ui->FirstName->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле имени не может быть пустым.");
    }
    if(ui->Phone->text().trimmed().isEmpty()){
        throw std::runtime_error("Поле телефона не может быть пустым.");
    }
    if(ui->TypeContract->currentIndex() == -1){
        throw std::runtime_error("Не выбран тип договора.");
    }
    if(ui->Summa->text().trimmed().isEmpty()){
        throw std::runtime_error("Не указана сумма договора.");
    }
}

void AgentWindow::SetValidationOnConfirmContract(){
    ui->LastName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->FirstName->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->Patronymic->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_FIO,this));
    ui->Summa->setValidator(new QRegularExpressionValidator(ValidationConstant::EXP_ON_NUMBER_LINE,this));
}
