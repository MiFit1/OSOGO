#include "windownavigator.h"
#include "agentwindow.h"
#include <QApplication>
#include <QtSql>
#include <QString>

void SetStyleSheets();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SetStyleSheets();

    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("OSOGO.sqlite");
    if (!sdb.open()) {
        qDebug()<<"Не удалось открыть базу данных";
    }

    Database* db = new Database();
    db->SetSqlDatabase(sdb);
    db->CreateTables();
    db->InsertAdmin();
    //db->InsertTestData();

    WindowNavigator navigator(db);
    return a.exec();
}

void SetStyleSheets(){
    QString styleSheet = "QLineEdit {                           "
                         "font: 500 9pt \"Montserrat Medium\";  "
                         "background: #e9e9e9;                  "
                         "border-radius: 5px;                   "
                         "padding: 8px;                         "
                         "border: 1px solid gray;               "
                         "}                                     "
                         "                                      "
                         "QLineEdit:focus {                     "
                         "border-color: #5fbaeb;                "
                         "}                                     "
                         "                                      "
                         "QLabel {                              "
                         "font: 500 11pt \"Montserrat Medium\"; "
                         "}                                     "
                         "QComboBox {                           "
                         "font: 500 9pt \"Montserrat Medium\";  "
                         "background: #e9e9e9;                  "
                         "border-radius: 5px;                   "
                         "padding: 8px;                         "
                         "border: 1px solid gray;               "
                         "}                                     "
                         "QComboBox:editable {                  "
                         "background: #5fbaeb;                  "
                         "}                                     "
                         "QComboBox:!editable:on, QComboBox::drop-down:editable:on { "
                         "background: #cdcdcd;                  "
                         "}                                     "
                         "QComboBox::drop-down {                "
                         "subcontrol-origin: padding;           "
                         "subcontrol-position: top right;       "
                         "width: 25px;                          "
                         "border-left-width: 1px;               "
                         "}                                     "
                         "QComboBox::down-arrow {               "
                         "image: url(:/images/resources/CheckMark.png); "
                         "width: 12px;                          "
                         "height: 12px;                         "
                         "}                                     "
                         "QComboBox QAbstractItemView::item {   "
                         "height: 40px;                         "
                         "}                                     "
                         "QTableView {                          "
                         "color: black;                         "
                         "gridline-color: black;                "
                         "}                                     "
                         "QHeaderView::section {                "
                         "background-color: #e9e9e9;            "
                         "color: black;                         "
                         "}                                     "
                         "QScrollBar:horizontal                 "
                         "{                                     "
                         "background-color: #e9e9e9;            "
                         "border: 1px solid  #7a7a7a;           "
                         "}                                     "
                         "QScrollBar::handle:horizontal         "
                         "{                                     "
                         "background-color: #aeaeae;            "
                         "}                                     "
                         "QScrollBar::add-line:horizontal,      "
                         "QScrollBar::sub-line:horizontal,      "
                         "QScrollBar::add-page:horizontal,      "
                         "QScrollBar::sub-page:horizontal       "
                         "{                                     "
                         "width: 0px;                           "
                         "background-color: transparent;        "
                         "}                                     "
                         "QScrollBar:vertical                   "
                         "{                                     "
                         "background-color: #e9e9e9;            "
                         "border: 1px solid  #7a7a7a;           "
                         "}                                     "
                         "QScrollBar::handle:vertical           "
                         "{                                     "
                         "background-color: #aeaeae;            "
                         "}                                     "
                         "QScrollBar::add-line:vertical,        "
                         "QScrollBar::sub-line:vertical,        "
                         "QScrollBar::add-page:vertical,        "
                         "QScrollBar::sub-page:vertical         "
                         "{                                     "
                         "height: 0px;                          "
                         "background-color: transparent;        "
                         "}                                     "
                         "QFrame[notifyArea=true] { background-color: white; }"
                         "QFrame[notifyMessage=true] { background-color: #232323; color: white; }"
                         "QLabel[notifyMessage=true] { background-color: #232323; color: white;";
    qApp->setStyleSheet(styleSheet);
}
