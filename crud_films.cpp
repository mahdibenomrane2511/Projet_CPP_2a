#include "crud_films.h"
#include<QString>
#include "menu.h"
crud_films::crud_films()
{

}
crud_films::crud_films(QString i,QString n,QString t)
{
    date_film=i;
    nom_film=n;
    type_film=t;


}
bool crud_films::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FILM1 (date_film,nom_film,type_film) VALUES  (:date_film,:nom_film,:type_film)");
    //QString res= QString(date_film);
    query.bindValue(":date_film",date_film);
    query.bindValue(":nom_film",nom_film);
    query.bindValue(":type_film",type_film);
    return query.exec();
}
bool crud_films::ajouter2()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CINEHOME (date_film,nom_film,type_film) VALUES  (:date_film,:nom_film,:type_film)");
    //QString res= QString(date_film);
    query.bindValue(":date_film",date_film);
    query.bindValue(":nom_film",nom_film);
    query.bindValue(":type_film",type_film);
    return query.exec();
}

bool crud_films::ajouter3()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CINEDRIVE (date_film,nom_film,type_film) VALUES  (:date_film,:nom_film,:type_film)");
    //QString res= QString(date_film);
    query.bindValue(":date_film",date_film);
    query.bindValue(":nom_film",nom_film);
    query.bindValue(":type_film",type_film);
    return query.exec();
}
bool crud_films::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM FILM1 where nom_film=:abc");
    //QString res= QString(id);
    query.bindValue(":abc",id);
    return query.exec();
}
bool crud_films::supprimer2(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CINEHOME where nom_film=:abc");
    //QString res= QString(id);
    query.bindValue(":abc",id);
    return query.exec();
}
bool crud_films::supprimer3(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CINEDRIVE where nom_film=:abc");
    //QString res= QString(id);
    query.bindValue(":abc",id);
    return query.exec();
}
bool crud_films::modifer(QString nom, QString type, QString date )
{
    QSqlQuery query;
    query.prepare("UPDATE FILM1 SET nom_film=:nom_film, date_film=:date_film, type_film=:type_film,where nom_film=:nom_film");
    query.bindValue(":date_film",date);
    query.bindValue(":nom_film", nom);
    query.bindValue(":type_film",type);

    return query.exec();
}
QSqlQueryModel * crud_films::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from FILM1 ");

    model->setHeaderData(0,Qt::Horizontal,"nom_film");
    model->setHeaderData(2,Qt::Horizontal,"type_film");
    model->setHeaderData(1,Qt::Horizontal,"date_film");
    return model ;
}
QSqlQueryModel * crud_films::afficher2()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CINEHOME ");

    model->setHeaderData(0,Qt::Horizontal,"nom_film");
    model->setHeaderData(2,Qt::Horizontal,"type_film");
    model->setHeaderData(1,Qt::Horizontal,"date_film");
    return model ;
}
QSqlQueryModel * crud_films::afficher3()
{

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from CINEDRIVE ");

    model->setHeaderData(0,Qt::Horizontal,"nom_film");
    model->setHeaderData(2,Qt::Horizontal,"type_film");
    model->setHeaderData(1,Qt::Horizontal,"date_film");
    return model ;
}
QSqlQueryModel * crud_films::trierdate_film()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from FILM1 ORDER BY date_film");

    model->setHeaderData(0,Qt::Horizontal,"nom_film");
    model->setHeaderData(1,Qt::Horizontal,"type_film");
     model->setHeaderData(2,Qt::Horizontal,"date_film");
     return model ;
}
QSqlQueryModel * crud_films::triernom_film()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from FILM1 ORDER BY nom_film");

    model->setHeaderData(0,Qt::Horizontal,"nom_film");
    model->setHeaderData(1,Qt::Horizontal,"type_film");
    model->setHeaderData(2,Qt::Horizontal,"date_film");
    return model ;

}
QSqlQueryModel * crud_films::triertype_film()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from FILM1 ORDER BY type_film");

    model->setHeaderData(0,Qt::Horizontal,"nom_film");
    model->setHeaderData(1,Qt::Horizontal,"type_film");
    model->setHeaderData(2,Qt::Horizontal,"date_film");
    return model ;
}
QSqlQueryModel * crud_films::afficher_films(QString nom,QString type,QString date)
{
//    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from FILM1 WHERE nom_film  = '"+ nom +"' or type_film = '"+type+"' or date_film = '"+date+"'");
//    query.bindValue(":nom", nom);
    model->setHeaderData(0,Qt::Horizontal,"nom_film");
    model->setHeaderData(1,Qt::Horizontal,"type_film");
    model->setHeaderData(2,Qt::Horizontal,"date_film");
    return model ;
}

