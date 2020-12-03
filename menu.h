#ifndef MENU_H
#define MENU_H
#include "crud_films.h"
#include <QDialog>
#include <QComboBox>
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_billet_2_clicked();

    void on_billetterie_clicked();

    void on_stock_clicked();

    void on_abonnement_clicked();

    void on_salaries_clicked();

    void on_materiel_clicked();

    void on_cinehome_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_ajouter_clicked();

    void on_ajout_customContextMenuRequested(const QPoint &pos);

    void on_comboBox_editTextChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_afficher_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_AjouterFilm_clicked();

    void on_supprimer_clicked();

    void on_pushButton_3_clicked();

    void on_modifier_clicked();

    void on_AjouterFilm2_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_tableView_4_clicked(const QModelIndex &index);

    void on_AjouterFilm2_2_clicked();

    void on_SuppFilm_2_clicked();

    void on_SuppFilm2_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_tableView_5_clicked(const QModelIndex &index);

    void on_billetterie_clicked(bool checked);

    void on_billetterie_windowIconChanged(const QIcon &icon);

private:
    Ui::menu *ui;
     crud_films tempcommandes;
};

#endif // MENU_H
