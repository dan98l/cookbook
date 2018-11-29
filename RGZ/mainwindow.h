#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>

#include "cookbook.h"
#include "addcategory.h"
#include "mainwindowcookbook.h"
#include "addrecept.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel* model;

    cookbook *windowCookbook;

    MainWindowCookbook *windowMainWindowCookbook;

};

#endif // MAINWINDOW_H
