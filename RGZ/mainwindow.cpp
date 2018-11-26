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
          ui->statusBar->showMessage("Yeees!");
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
            ui->statusBar->showMessage("No!");
        } else {
            ui->statusBar->showMessage("DataBaze is add!");

            int k = 0;
            while (query.next()) {
                QString loginSet = query.value(0).toString();
                QString passwordSet = query.value(1).toString();

               // query.next();
                if(loginSet == login & passwordSet == password){
                    ui->statusBar->showMessage("You are true!");
                }
          }

     }

//        model = new QSqlTableModel(this, db);
//        model->setTable("Users");
//        model->select();
//        ui->tableView->setModel(model);


}








