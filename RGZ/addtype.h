#ifndef ADDTYPE_H
#define ADDTYPE_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>

namespace Ui {
class addtype;
}

class addtype : public QDialog
{
    Q_OBJECT

public:
    explicit addtype(QWidget *parent = nullptr);
    ~addtype();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addtype *ui;
     QSqlDatabase dbCook;
};

#endif // ADDTYPE_H
