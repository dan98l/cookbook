#ifndef ADDTIME_H
#define ADDTIME_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>

namespace Ui {
class addtime;
}

class addtime : public QDialog
{
    Q_OBJECT

public:
    explicit addtime(QWidget *parent = nullptr);
    ~addtime();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addtime *ui;
     QSqlDatabase dbCook;
     //AddRecept *recept;
};

#endif // ADDTIME_H
