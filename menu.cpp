#include "menu.h"
#include "ui_menu.h"
#include <QComboBox>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include "crud_films.h"
#include<QSql>
#include <QTableView>
#include "ui_menu.h"
#include <QSqlQueryModel>
#include<QModelIndex>
#include<QModelIndexList>
#include<QDateEdit>
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{

    ui->setupUi(this);

    ui->tableView->setModel(tempcommandes.afficher());
    ui->tableView_2->setModel(tempcommandes.afficher());
    ui->tableView_3->setModel(tempcommandes.afficher2());
    ui->tableView_4->setModel(tempcommandes.afficher());
    ui->tableView_5->setModel(tempcommandes.afficher3());


    //comboboxdonnées

    ui->TypeFilm->addItem("comédie");
    ui->TypeFilm->addItem("action");
     ui->TypeFilm->addItem("romance");
      ui->TypeFilm->addItem("sci-fi");
       ui->TypeFilm->addItem("classique");
        ui->TypeFilm->addItem("aventure");


}

menu::~menu()
{

    delete ui;
}







  //ui->stackedWidget->setCurrentIndex(0) ;



void menu::on_billetterie_clicked()
{
  ui->stackedWidget->setCurrentIndex(0) ;
}

void menu::on_stock_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void menu::on_abonnement_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;

}

void menu::on_salaries_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;

}

void menu::on_materiel_clicked()
{
    ui->stackedWidget->setCurrentIndex(5) ;

}

void menu::on_cinehome_clicked()
{
    ui->stackedWidget->setCurrentIndex(6) ;

}

















void menu::on_afficher_clicked()
{



   QMessageBox::information(nullptr,"ok","ok");
ui->tableView->setModel(tempcommandes.afficher());
}

void menu::on_tableView_clicked(const QModelIndex &index)
{
//ui->idaffich->setText(QString("Row%1, Column%2").arg(index.row() + 1).arg(0));
ui->NomFilm->setText(QString (ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString()));
ui->TypeFilm->setCurrentText(QString (ui->tableView->model()->data(ui->tableView->model()->index(index.row(),2)).toString()));
ui->DateFilm->setDate(QDate::fromString(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),1)).toString(),"dd/MM/yyyy"));
//ui->dateembauche->setDate(QDate::fromString(query.value(8).toString(),"MM/dd/yyyy"));
}

void menu::on_AjouterFilm_clicked()
{
    QString i=ui->DateFilm->text();
       QString n=ui->NomFilm->text();
       QString t=ui->TypeFilm->currentText();

 bool test2 = ui->NomFilm->text()==NULL or ui->TypeFilm->currentText()==NULL or ui->DateFilm->text()==NULL;
       if(test2)
       {
      QMessageBox::warning(nullptr,"ATTENTION","les cases ne peuvent pas etre vides pour ajouter un film");
       }
       else
       {
           crud_films c(i,n,t);
             bool test = c.ajouter();
             if (test)
             {
    QMessageBox::information(nullptr,"AJOUT FILM","FILM AJOUTEE");
             }
             else
             {
    QMessageBox::warning(nullptr,"AJOUT FILM","FILM NON AJOUTEE");
             }
ui->tableView->setModel(tempcommandes.afficher());
ui->tableView_2->setModel(tempcommandes.afficher());
ui->tableView_4->setModel(tempcommandes.afficher());
       }
}

void menu::on_supprimer_clicked()
{
   QString nom_filmm = ui->NomFilm->text();

    bool test = tempcommandes.supprimer(nom_filmm);
    if (test)
    {

        ui->tableView->setModel(tempcommandes.afficher());
        ui->tableView_2->setModel(tempcommandes.afficher());
         ui->tableView_4->setModel(tempcommandes.afficher());
        QMessageBox::information(nullptr,"SUPPRIMER FILM","FILM SUPPRIME !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER FILM","FILM NON SUPPRIME !");
    }

  ui->NomFilm->setText("");
   ui->TypeFilm->setCurrentText("Type");
    //ui->DateFilm->setText("");

}

void menu::on_pushButton_3_clicked()
{
    QString nom_filmm = ui->NomFilm->text();
    QString type_filmm = ui->TypeFilm->currentText();
    QString date_filmm = ui->DateFilm->text();
//     bool test = tempcommandes.afficher_films(nom_filmm,type_filmm,date_filmm);

      bool test = ui->NomFilm->text()==NULL and ui->TypeFilm->currentText()==NULL and ui->DateFilm->text()==NULL;
     if (test)

     {
         ui->tableView->setModel(tempcommandes.afficher());


     }
     else
    {
      ui->tableView->setModel(tempcommandes.afficher_films(nom_filmm,type_filmm,date_filmm));

}
}

void menu::on_modifier_clicked()
{
    QString nom_filmm = ui->NomFilm->text();
    QString type_filmm = ui->TypeFilm->currentText();
    QString date_filmm = ui->DateFilm->text();




      bool test = ui->NomFilm->text()==NULL or ui->TypeFilm->currentText()==NULL or ui->DateFilm->text()==NULL;
     if (test)

     {
        QMessageBox::warning(nullptr,"ATTENTION","les cases ne peuvent pas etre vides pour ajouter un film");

//         QMessageBox::information(nullptr,"SUPPRIMER FILM","FILM SUPPRIME !");
     }
     else
    {
      //bool test2 = tempcommandes.modifer(nom_filmm,type_filmm,date_filmm);
      bool test2 = tempcommandes.supprimer(nom_filmm);
       crud_films c(date_filmm,nom_filmm,type_filmm);
         test2 = c.ajouter();
      if(test2)
      {
         QMessageBox::information(nullptr,"MODIFICATION FILM","FILM MODIFIE !");

//         ui->NomFilm->setText("");
//          ui->TypeFilm->setText("");
//           ui->DateFilm->setText("");

           ui->tableView->setModel(tempcommandes.afficher());
     }
     else
    {
          QMessageBox::warning(nullptr,"ATTENTION","probléme de modification");

     }
}
}


void menu::on_AjouterFilm2_clicked()
{

    QString i=ui->DateFilm_cinehome->text();
       QString n=ui->NomFilm_Cinehome->text();
       QString t=ui->TypeFilm_cinehome->text();


           crud_films c(i,n,t);
             bool test = c.ajouter2();
             if (test)
             {
    QMessageBox::information(nullptr,"AJOUT FILM","FILM AJOUTEE");
             }
             else
             {
    QMessageBox::warning(nullptr,"AJOUT FILM","FILM NON AJOUTEE");
             }
ui->tableView_3->setModel(tempcommandes.afficher2());




}

void menu::on_tableView_2_clicked(const QModelIndex &index)
{
    ui->NomFilm_Cinehome->setText(QString (ui->tableView_2->model()->data(ui->tableView->model()->index(index.row(),0)).toString()));
    ui->TypeFilm_cinehome->setText(QString (ui->tableView_2->model()->data(ui->tableView->model()->index(index.row(),2)).toString()));
    ui->DateFilm_cinehome->setText(QString (ui->tableView_2->model()->data(ui->tableView->model()->index(index.row(),1)).toString()));
}

void menu::on_tableView_4_clicked(const QModelIndex &index)
{
    ui->NomFilm_Cinehome_2->setText(QString (ui->tableView_4->model()->data(ui->tableView_4->model()->index(index.row(),0)).toString()));
    ui->TypeFilm_cinehome_2->setText(QString (ui->tableView_4->model()->data(ui->tableView_4->model()->index(index.row(),2)).toString()));
    ui->DateFilm_cinehome_2->setText(QString (ui->tableView_4->model()->data(ui->tableView_4->model()->index(index.row(),1)).toString()));
}

void menu::on_AjouterFilm2_2_clicked()
{
    QString i=ui->DateFilm_cinehome_2->text();
       QString n=ui->NomFilm_Cinehome_2->text();
       QString t=ui->TypeFilm_cinehome_2->text();


           crud_films c(i,n,t);
             bool test = c.ajouter3();
             if (test)
             {
    QMessageBox::information(nullptr,"AJOUT FILM","FILM AJOUTEE");
             }
             else
             {
    QMessageBox::warning(nullptr,"AJOUT FILM","FILM NON AJOUTEE");
             }
ui->tableView_5->setModel(tempcommandes.afficher3());

ui->DateFilm_cinehome_2->setText("");
       ui->NomFilm_Cinehome_2->setText("");
       ui->TypeFilm_cinehome_2->setText("");


}

void menu::on_SuppFilm_2_clicked()
{
    QString nom_filmm = ui->NomFilm_Cinehome_2->text();
     bool test = tempcommandes.supprimer3(nom_filmm);
     if (test)
     {

         ui->tableView->setModel(tempcommandes.afficher());

         QMessageBox::information(nullptr,"SUPPRIMER FILM","FILM SUPPRIME !");
     }
     else
     {
         QMessageBox::warning(nullptr,"SUPPRIMER FILM","FILM NON SUPPRIME !");
     }
ui->tableView_5->setModel(tempcommandes.afficher3());
}

void menu::on_SuppFilm2_clicked()
{
    QString nom_filmm = ui->NomFilm_Cinehome->text();
     bool test = tempcommandes.supprimer2(nom_filmm);
     if (test)
     {

         ui->tableView->setModel(tempcommandes.afficher());

         QMessageBox::information(nullptr,"SUPPRIMER FILM","FILM SUPPRIME !");
     }
     else
     {
         QMessageBox::warning(nullptr,"SUPPRIMER FILM","FILM NON SUPPRIME !");
     }
ui->tableView_3->setModel(tempcommandes.afficher2());
ui->NomFilm_Cinehome->setText("");
ui->TypeFilm_cinehome->setText("");
ui->DateFilm_cinehome->setText("");
}

void menu::on_tableView_3_clicked(const QModelIndex &index)
{
    ui->NomFilm_Cinehome->setText(QString (ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),0)).toString()));
    ui->TypeFilm_cinehome->setText(QString (ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),2)).toString()));
    ui->DateFilm_cinehome->setText(QString (ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),1)).toString()));

}

void menu::on_tableView_5_clicked(const QModelIndex &index)
{


        ui->NomFilm_Cinehome_2->setText(QString (ui->tableView_5->model()->data(ui->tableView_4->model()->index(index.row(),0)).toString()));
        ui->TypeFilm_cinehome_2->setText(QString (ui->tableView_5->model()->data(ui->tableView_4->model()->index(index.row(),2)).toString()));
        ui->DateFilm_cinehome_2->setText(QString (ui->tableView_5->model()->data(ui->tableView_4->model()->index(index.row(),1)).toString()));
}




