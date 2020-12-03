#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include <QSql>
#include <QSqlDatabase>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
menu a;
a.exec() ;
}
