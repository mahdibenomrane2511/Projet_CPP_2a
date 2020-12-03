#ifndef CRUD_FILMS_H
#define CRUD_FILMS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class crud_films
{
    QString date_film;
    QString nom_film;
    QString type_film;


public:
    crud_films();
    crud_films(QString,QString,QString);
    QString get_date_film(){return     date_film;}
    QString get_nom_film(){return nom_film;}
    QString get_type_film(){return type_film;}
    bool ajouter();
     bool ajouter2();
      bool ajouter3();
    bool supprimer(QString);
    bool supprimer2(QString);
     bool supprimer3(QString);
    bool modifer(QString,QString,QString);
    QSqlQueryModel *afficher();
    QSqlQueryModel *afficher2();
    QSqlQueryModel *afficher3();
    QSqlQueryModel  *trierdate_film();
    QSqlQueryModel  *triernom_film();
    QSqlQueryModel  *triertype_film();
    QSqlQueryModel *afficher_films(QString,QString,QString);
};




#endif // CRUD_FILMS_H
