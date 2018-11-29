#include "addcategory.h"
#include "ui_addcategory.h"
#include "addrecept.h"

addCategory::addCategory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCategory)
{
    ui->setupUi(this);
}

addCategory::~addCategory()
{
    delete ui;
}

void addCategory::on_pushButton_clicked()
{

//    mouse = new Mouses();
//    connect(ui->webView,SIGNAL(loadFinished(bool)),mouse,SLOT(doMouseLeftClick1()));


     QString categoryText = ui->lineEdit->text();

     dbCook = QSqlDatabase::addDatabase("QSQLITE");
     dbCook.setDatabaseName("/Users/daniil/Documents/SIBSUTIS/RGZ/recept.db");
     if(dbCook.open()){
        // ui->label->setText("Yeees!!!");
     }

     QSqlQuery query(dbCook);
       query.prepare("INSERT INTO category (category)"
                     "VALUES (:category)");
       query.bindValue(":category", categoryText);
       query.exec();

       this->close();

       AddRecept *AddReceptWindow;
       AddReceptWindow = new AddRecept;
       AddReceptWindow->show();

}


void addCategory::on_pushButton_2_clicked()
{
    this->close();

    AddRecept *AddReceptWindow;
    AddReceptWindow = new AddRecept;

    //AddReceptWindow = new AddRecept;

      AddReceptWindow->show();

}
