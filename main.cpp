#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <oracle.h>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    oracle c;
    bool test=c.create_cnx();
    if(test){

        QMessageBox::information(nullptr,QObject::tr("database is open"),
                QObject::tr("connexion etablie"),QMessageBox::Ok);


        //qDebug() <<"Connexion établie";

    }
    else {

        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                QObject::tr("erreur de connexion"),QMessageBox::Cancel);

       // qDebug()<<"erreur de connexion";
    }

    return a.exec();
}
