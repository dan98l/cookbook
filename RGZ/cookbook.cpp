#include "cookbook.h"
#include "ui_cookbook.h"
#include "addcategory.h"

cookbook::cookbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cookbook)
{
    ui->setupUi(this);

    dbCook = QSqlDatabase::addDatabase("QSQLITE");
    dbCook.setDatabaseName("/Users/daniil/Documents/SIBSUTIS/RGZ/recept.db");
    if(dbCook.open()){
      //  ui->label->setText("Yeees!!!");
    }

    QSqlQuery query = QSqlQuery(dbCook);

    if(!query.exec("SELECT category FROM category")){
        ui->label->setText("valueName");
    } else {
        while (query.next()) {
             QString valueName = query.value(0).toString();
             ui->comboBox->addItem(valueName);
             ui->label->setText(valueName);
             //query.next();
    }}

}

cookbook::~cookbook()
{
    delete ui;
}

void cookbook::on_pushButton_clicked()
{
    QSqlQuery query = QSqlQuery(dbCook);

    windowCategory = new addCategory(this);
    windowCategory->show();

         model = new QSqlTableModel(this, dbCook);
         model->setTable("category");
         model->select();
         ui->tableView->setModel(model);
}


void cookbook::on_pushButton_2_clicked()
{
    ui->label->setText(ui->comboBox->currentText());
}
