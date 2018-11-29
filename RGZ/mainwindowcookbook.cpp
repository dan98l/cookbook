#include "mainwindowcookbook.h"
#include "ui_mainwindowcookbook.h"

MainWindowCookbook::MainWindowCookbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowCookbook)
{
    ui->setupUi(this);
}

MainWindowCookbook::~MainWindowCookbook()
{
    delete ui;


}


void MainWindowCookbook::on_pushButton_2_clicked()
{
    addReceptWindow = new AddRecept(this);
    addReceptWindow->show();
}
