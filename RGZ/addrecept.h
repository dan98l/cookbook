#ifndef ADDRECEPT_H
#define ADDRECEPT_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QFileDialog>

#include "addcategory.h"
#include "addtime.h"
#include "addtype.h"

namespace Ui {
class AddRecept;


}

class AddRecept : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecept(QWidget *parent = nullptr);
    ~AddRecept();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_toolButton_clicked();

    void on_pushButton_6_clicked();

private:

    Ui::AddRecept *ui;
    addCategory *windowCategory;
     QSqlDatabase dbCook;
     AddRecept *recept;
     addtime *windowTime;
     addtype *windowType;

};

#endif // ADDRECEPT_H
