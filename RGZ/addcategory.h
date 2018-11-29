#ifndef ADDCATEGORY_H
#define ADDCATEGORY_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>

//#include "addrecept.h"

namespace Ui {
class addCategory;
}

class addCategory : public QDialog
{
    Q_OBJECT

public:
    explicit addCategory(QWidget *parent = nullptr);
    ~addCategory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addCategory *ui;
    QSqlDatabase dbCook;
   // addrecept *reploidCategory;

};

#endif // ADDCATEGORY_H
