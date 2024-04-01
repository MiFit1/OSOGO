#include "ui_adminwindow.h"
#include "adminwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QSize>

AdminWindow::AdminWindow(Database* database, QWidget *parent) :
    AbstractUserWindow(parent),
    ui(new Ui::AdminWindow)
{
    qDebug() << "call constructor";
    ui->setupUi(this);
    configuringInterface();
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
    ui->tabWidget->setStyleSheet("QTabBar::tab { height: 50px;}");
    profilePanel->raise();

    layoutParentWidgetChangeUserData = new QVBoxLayout(ui->ParentWidget);
    viewUsers = new QTableView();
    changeUserDataWidget = new ChangeUserDataWidget();
    ShowViewUsers();


    u_model = new UserTableModel(this);
    viewUsers->setModel(u_model);
    viewUsers->setSelectionBehavior(QAbstractItemView::SelectRows);
    viewUsers->horizontalHeader()->setStretchLastSection(true);
    viewUsers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //
    User user1(1,1,1,"Eliseev","Vasiliy","Andreevich","Киренского 17","87777777777","Московский филиал","vasa228","VodkaBalalayka");
    User user2(2,2,2,"Петечкин","Пётр","Петрович","Свобондный 82а","87777777777","Томский филиал","HlebnyDizelky","qwerty");
    User user3(3,3,3,"фон Эверек","Ольгерд","Ольгердович","Красноярск, Ленина 15","87777777777","Красноярский филиал","Olega777","1234");
    u_model->addUser(user1);
    u_model->addUser(user2);
    u_model->addUser(user3);
}

void AdminWindow::ShowViewUsers(){
    DeleteParentWidgetChildren();
    viewUsers->setParent(ui->ParentWidget);
    layoutParentWidgetChangeUserData->addWidget(viewUsers);
}

void AdminWindow::ShowChangeUserDataWidget(){
    DeleteParentWidgetChildren();
    changeUserDataWidget->setParent(ui->ParentWidget);
    layoutParentWidgetChangeUserData->addWidget(changeUserDataWidget);
}

void AdminWindow::DeleteParentWidgetChildren(){
    QLayoutItem* item = layoutParentWidgetChangeUserData->itemAt(0);
    if(item != NULL){
        layoutParentWidgetChangeUserData->removeItem(item);
        layoutParentWidgetChangeUserData->removeWidget(item->widget());
        item->widget()->setParent(NULL);
        delete item;
        layoutParentWidgetChangeUserData->update();
    }
}

void AdminWindow::slotDoubleClikedOnUser(const QModelIndex index){
    //qDebug()<<index.row();
    ShowChangeUserDataWidget();
    User user = u_model->getUser(index);
    changeUserDataWidget->setUserToChangeWidget(user);
}

void AdminWindow::slotBackButtonChangeUserWidgetCliked(){
    ShowViewUsers();
}

