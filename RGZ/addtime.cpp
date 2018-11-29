#include "addtime.h"
#include "ui_addtime.h"
#include "addrecept.h"

addtime::addtime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addtime)
{
    ui->setupUi(this);
}

addtime::~addtime()
{
    delete ui;
}

void addtime::on_pushButton_clicked()
{
    QString timeText = ui->lineEdit->text();

    dbCook = QSqlDatabase::addDatabase("QSQLITE");
    dbCook.setDatabaseName("/Users/daniil/Documents/SIBSUTIS/RGZ/recept.db");
    if(dbCook.open()){
       // ui->label->setText("Yeees!!!");
    }

    QSqlQuery query(dbCook);
      query.prepare("INSERT INTO time (time)"
                    "VALUES (:time)");
      query.bindValue(":time", timeText);
      query.exec();

      this->close();

      AddRecept *AddReceptWindow;
      AddReceptWindow = new AddRecept;
      AddReceptWindow->show();

}

void addtime::on_pushButton_2_clicked()
{
    this->close();

    AddRecept *AddReceptWindow;
    AddReceptWindow = new AddRecept;
    AddReceptWindow->show();

}
