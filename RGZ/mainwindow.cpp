#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       db = QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName("/Users/daniil/Documents/SIBSUTIS/RGZ/database.db");
       if(db.open()){
        //  ui->statusBar->showMessage("Yeees!");
       }
}

MainWindow::~MainWindow()
{
    delete ui;



}

void MainWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    QSqlQuery query = QSqlQuery(db);


    if(!query.exec("SELECT name, password FROM Users")){
            ui->statusBar->showMessage("DataBaze don't add!");
        } else {
           // ui->statusBar->showMessage("DataBaze is add!");
            while (query.next()) {
                QString loginSet = query.value(0).toString();
                QString passwordSet = query.value(1).toString();

               // query.next();
                if(loginSet == login & passwordSet == password){
                    ui->statusBar->showMessage("You are true!");
                    hide();
                         windowMainWindowCookbook = new MainWindowCookbook;
                         windowMainWindowCookbook->show();

//                        windowCookbook = new cookbook(this);
//                        windowCookbook->show();
                } else {
                    ui->statusBar->showMessage("Who are you? Try again...");
                }
          }

     }

//        model = new QSqlTableModel(this, db);
//        model->setTable("Users");
//        model->select();
//        ui->tableView->setModel(model);


}








