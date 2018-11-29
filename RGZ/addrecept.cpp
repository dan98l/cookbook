#include "addrecept.h"
#include "ui_addrecept.h"

AddRecept::AddRecept(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecept)
{
    ui->setupUi(this);

    dbCook = QSqlDatabase::addDatabase("QSQLITE");
    dbCook.setDatabaseName("/Users/daniil/Documents/SIBSUTIS/RGZ/recept.db");
    if(dbCook.open()){
      //  ui->label->setText("Yeees!!!");
    }

    QSqlQuery query = QSqlQuery(dbCook);

    if(!query.exec("SELECT category FROM category")){
        //ui->label->setText("valueName");
    } else {
        while (query.next()) {
             QString valueName = query.value(0).toString();
             ui->comboBox_3->addItem(valueName);
            // ui->label->setText(valueName);
             //query.next();
    }}

    if(!query.exec("SELECT time FROM time")){
        //ui->label->setText("valueName");
    } else {
        while (query.next()) {
             QString valueName = query.value(0).toString();
             ui->comboBox_2->addItem(valueName);
            // ui->label->setText(valueName);
             //query.next();
    }}

    if(!query.exec("SELECT type FROM type")){
        //ui->label->setText("valueName");
    } else {
        while (query.next()) {
             QString valueName = query.value(0).toString();
             ui->comboBox->addItem(valueName);
            // ui->label->setText(valueName);
             //query.next();
    }}

    if(!query.exec("SELECT list FROM list")){
       // ui->label->setText("valueName");
    } else {
        while (query.next()) {
             QString valueName = query.value(0).toString();
             ui->comboBox_4->addItem(valueName);
            // ui->label->setText(valueName);
             //query.next();
    }}

}

AddRecept::~AddRecept()
{
    delete ui;
}

void AddRecept::on_pushButton_2_clicked()
{
     hide();
    windowCategory = new addCategory(this);
    windowCategory->show();
}

void AddRecept::on_pushButton_3_clicked()
{
    hide();
    windowTime = new addtime(this);
    windowTime->show();
}

void AddRecept::on_pushButton_4_clicked()
{
    hide();
    windowType = new addtype(this);
    windowType->show();
}

void AddRecept::on_toolButton_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.png *.jpeg");

    if(str != NULL){
        dbCook = QSqlDatabase::addDatabase("QSQLITE");
        dbCook.setDatabaseName("/Users/daniil/Documents/SIBSUTIS/RGZ/recept.db");
        if(dbCook.open()){
           // ui->label->setText("Yeees!!!");
        }

        QSqlQuery query(dbCook);
          query.prepare("INSERT INTO images (img)"
                        "VALUES (:img)");
          query.bindValue(":img", str);
          query.exec();
    }


}

void AddRecept::on_pushButton_6_clicked()
{
    this->close();
}
