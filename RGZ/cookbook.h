#ifndef COOKBOOK_H
#define COOKBOOK_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>

#include "addcategory.h"

namespace Ui {
class cookbook;
}

class cookbook : public QDialog
{
    Q_OBJECT

public:
    explicit cookbook(QWidget *parent = nullptr);
    ~cookbook();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cookbook *ui;
    QSqlDatabase dbCook;
    QSqlTableModel* model;

    addCategory *windowCategory;
};

#endif // COOKBOOK_H
