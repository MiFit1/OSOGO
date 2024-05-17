#include "accountantwindow.h"
#include "ui_accountantwindow.h"

AccountantWindow::AccountantWindow(const User& us, Database* database, QWidget *parent) :
    AbstractUserWindow(us,parent),
    ui(new Ui::AccountantWindow)
{
    ui->setupUi(this);
    db = database;
    ConfiguringInterface(us);
    AddShadow(confirmationWindow);
    ReadAndSetShadowSettings();
    QHeaderView* headerStatistics = viewStatistics->horizontalHeader();
    connect(viewContracts, SIGNAL(doubleClicked(QModelIndex)), SLOT(slotDoubleClikedOnContract(QModelIndex)));
    connect(confirmationWindow, SIGNAL(signalBackButtonClicked()),SLOT(slotConfirmWidgetBackButtonClicked()));
    connect(confirmationWindow, SIGNAL(signalConfirmButtonClicked()),SLOT(slotConfirmContractButtonClicked()));
    connect(confirmationWindow, SIGNAL(signalRejectButtonClicked()),SLOT(slotRejectContractButtonClicked()));
    connect(tariffRateWidget, SIGNAL(signalOkButtonClicked()), tariffRateButton, SIGNAL(clicked()));
    connect(headerStatistics, SIGNAL(sectionClicked(int)),SLOT(slotHeaderInStatisticWidgetClicked(int)));
}

AccountantWindow::~AccountantWindow()
{
    delete ui;
}

void AccountantWindow::ConfiguringInterface(User user){
    messagePanel->raise();
    //Кнопка профиля и кнопка настройки ставки
    tabCornerWidget = new QWidget(this);
    tariffRateButton = new QPushButton(this);
    tariffRateButton->setIcon(QIcon(":/images/resources/tariff.png"));
    tariffRateButton->setIconSize(QSize(40, 40));
    tariffRateButton->setMinimumHeight(50);

    tabCornerWidgetLayout = new QHBoxLayout(tabCornerWidget);
    tabCornerWidgetLayout->addWidget(profileButton);
    tabCornerWidgetLayout->addWidget(tariffRateButton);
    tabCornerWidgetLayout->setSpacing(0);
    tabCornerWidgetLayout->setContentsMargins(0,0,0,0);
    tabCornerWidget->setLayout(tabCornerWidgetLayout);

    ui->tabWidget->setCornerWidget(tabCornerWidget, Qt::TopLeftCorner);
    profilePanel->raise();

    tariffRatePanel = new PanelLeftSide(this);
    tariffRatePanel->setOpenEasingCurve(QEasingCurve::Type::OutExpo);
    tariffRatePanel->setCloseEasingCurve(QEasingCurve::Type::InExpo);
    tariffRatePanel->init();

    connect(tariffRateButton,SIGNAL(clicked()),tariffRatePanel,SLOT(slotStartAnimation()));

    tariffRateWidget = new TariffRateWidget(this);
    tariffRatePanel->setPanelSize(tariffRateWidget->size().width()+160);
    tariffRatePanel->setWidgetResizable(true);
    tariffRatePanel->setWidget(tariffRateWidget);
    tariffRateWidget->raise();


    //layout вкладки подтверждения договоров
    stackedWidgetConfirmContract = ui->stackedWidgetConfirmContract;
    viewContracts = new QTableView(stackedWidgetConfirmContract);
    confirmationWindow = new ContractConfirmationWindow(stackedWidgetConfirmContract);
    stackedWidgetConfirmContract->addWidget(viewContracts);
    stackedWidgetConfirmContract->addWidget(confirmationWindow );
    ShowViewContracts();

    ///layout вкладки статистики ЗАМЕНИТЬ НА STACKED WIDGET
    layoutParentWidgetStatistics = new QVBoxLayout(ui->ParentWidgetStatistics);
    viewStatistics = new QTableView(ui->ParentWidgetStatistics);
    layoutParentWidgetStatistics->addWidget(viewStatistics);

    //Модель договоров (для подтверждения)
    sqlModelContract = new QSqlQueryModel(this);
    UpdateViewContracts();

    viewContracts->setModel(sqlModelContract);
    DefaultSettingView(viewContracts);

    sqlModelStatistics = new AccountantModelStatistics(user,this);
    viewStatistics->setModel(sqlModelStatistics);
    DefaultSettingView(viewStatistics);
}

void AccountantWindow::ShowViewContracts(){
    stackedWidgetConfirmContract->setCurrentWidget(viewContracts);
}

void AccountantWindow::ShowConfirmationWindow(){
    stackedWidgetConfirmContract->setCurrentWidget(confirmationWindow);
}

void AccountantWindow::slotDoubleClikedOnContract(const QModelIndex index){
    int indexRowClicked = index.row();
    int idContract = sqlModelContract->index(indexRowClicked, 0).data().toInt();
    Contract contract = db->GetContractById(idContract);
    Client client = db->GetClientById(contract.GetIdClient());
    confirmationWindow->ClearUserData();
    confirmationWindow->SetContractAndClient(contract, client);
    ShowConfirmationWindow();
}

void AccountantWindow::slotConfirmWidgetBackButtonClicked(){
    ShowViewContracts();
}

void AccountantWindow::slotConfirmContractButtonClicked(){
    Contract changedContract = confirmationWindow->GetCurrentContract();
    double changedRate = 0;

    if(changedContract.GetTypeInsurance() == "Страхование автотранспорта"){
        changedRate = tariffRateWidget->GetVehicleInsuranceRate();
    }
    else if(changedContract.GetTypeInsurance() == "Страхование домашнего имущества"){
        changedRate = tariffRateWidget->GetHomePropertyInsuranceRate();
    }
    else if(changedContract.GetTypeInsurance() == "Добровольное медицинское страхование"){
        changedRate = tariffRateWidget->GetHealthInsuranceRate();
    }
    else{
        QPushButton* confirmButton = confirmationWindow->GetConfirmButton();
        ShowMessage("Ошибка: неизвестный тип договора.",false,confirmButton);
        return;
    }

    if(changedRate <= 0){
        QPushButton* confirmButton = confirmationWindow->GetConfirmButton();
        ShowMessage("Ошибка: для данного типа договоров не установлена ставка. Пожалуйста, зайдите в окно настройки ставок.",false,confirmButton);
        return;
    }

    changedContract.SetTariffRate(changedRate);
    changedContract.SetStatus(3);
    changedContract.SetIdConfirmedAccountant(user.GetId());
    try {
        db->RefreshContractById(changedContract);
    } catch (std::runtime_error& err) {
        QPushButton* confirmButton = confirmationWindow->GetConfirmButton();
        ShowMessage(err.what(),false,confirmButton);
        return;
    }
    UpdateViewContracts();
    sqlModelStatistics->UpdateView();
    ShowViewContracts();
}

void AccountantWindow::slotRejectContractButtonClicked(){
    Contract changedContract = confirmationWindow->GetCurrentContract();
    changedContract.SetStatus(2);
    try {
        db->RefreshContractById(changedContract);
        if(!confirmationWindow->GetComment().trimmed().isEmpty()){
            db->AddComment(confirmationWindow->GetComment(),user.GetId(),changedContract.GetId());
        }
    } catch (std::runtime_error& err) {
        QPushButton* rejectButton = confirmationWindow->GetConfirmButton();
        ShowMessage(err.what(),false,rejectButton);
        return;
    }
    UpdateViewContracts();
    ShowViewContracts();
}

void AccountantWindow::slotHeaderInStatisticWidgetClicked(int index){
    sqlModelStatistics->UpdateView(index);
}

void AccountantWindow::UpdateViewContracts(){
    sqlModelContract->setQuery(Database::GetQueryToSelectContractsToConfirm());
}


