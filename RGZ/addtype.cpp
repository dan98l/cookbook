#include "addtype.h"
#include "ui_addtype.h"
#include "addrecept.h"



addtype::addtype(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addtype)
{
    ui->setupUi(this);
}

addtype::~addtype()
{
    delete ui;
}

void addtype::on_pushButton_2_clicked()
{
    this->close();

    AddRecept *AddReceptWindow;
    AddReceptWindow = new AddRecept;
    AddReceptWindow->show();

}

void addtype::on_pushButton_clicked()
{

    QString typeText = ui->lineEdit->text();

    dbCook = QSqlDatabase::addDatabase("QSQLITE");
    dbCook.setDatabaseName("/Users/daniil/Documents/SIBSUTIS/RGZ/recept.db");
    if(dbCook.open()){
       // ui->label->setText("Yeees!!!");
    }

    QSqlQuery query(dbCook);
      query.prepare("INSERT INTO type (type)"
                    "VALUES (:type)");
      query.bindValue(":type", typeText);
      query.exec();



    this->close();

    AddRecept *AddReceptWindow;
    AddReceptWindow = new AddRecept;
    AddReceptWindow->show();

}
