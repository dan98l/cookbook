#ifndef MAINWINDOWCOOKBOOK_H
#define MAINWINDOWCOOKBOOK_H

#include <QDialog>
#include <QDialog>
#include <QString>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>

#include "addcategory.h"
#include "addrecept.h"

namespace Ui {
class MainWindowCookbook;


}

class MainWindowCookbook : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindowCookbook(QWidget *parent = nullptr);
    ~MainWindowCookbook();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindowCookbook *ui;
     addCategory *windowCategory;
     AddRecept *addReceptWindow;
      QSqlDatabase dbCook;
};

#endif // MAINWINDOWCOOKBOOK_H
