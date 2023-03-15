#include "equipement_window.h"
#include "ui_equipement_window.h"
#include <QApplication>
#include <QMessageBox>
#include "equipement.h"

equipement_window::equipement_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::equipement_window)
{
    ui->setupUi(this);
}

equipement_window::~equipement_window()
{
    delete ui;
}

void equipement_window::on_pushButton_10_clicked()
{
    // supprimer
    bool ok;
    int ID_EQUIPEMENT = ui->lineEdit_6->text().toInt(&ok);
    if (!ok || ID_EQUIPEMENT <= 0) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Invalid ID_EQUIPEMENT: %1\n"
                        "Please enter a valid integer ID.")
            .arg(ui->lineEdit_6->text()));
        return;
    }

    // Call the supprimer function to delete the equipment
    bool test = e.supprimer(ID_EQUIPEMENT);

    // Show a message box based on whether the deletion was successful
    if (test) {
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("Success"),
            QObject::tr("Suppression effectuée.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Suppression non effectuée.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void equipement_window::on_pushButton_8_clicked()
{
    //ajouter

   int ID_EQUIPEMENT =ui->lineEdit_6->text().toInt();
   int QUANTITE =ui->lineEdit_3->text().toInt();
   QString NOM_PRODUIT=ui->lineEdit->text();
   QString TYPE_PRODUIT =ui->lineEdit_2->text();
   QString URL =ui->lineEdit_4->text();
   QString DESCRIPTION =ui->lineEdit_5->text();

   equipement e(ID_EQUIPEMENT,QUANTITE,NOM_PRODUIT,TYPE_PRODUIT,URL,DESCRIPTION);

   bool test=e.ajouter();
    if(test)
    {
          ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
        QObject::tr("ajout effectuée\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
         QObject::tr("ajout non effectuée.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void equipement_window::on_pushButton_9_clicked()
{
    // modifier


    int ID_EQUIPEMENT=ui->lineEdit_6->text().toInt();
    int QUANTITE=ui->lineEdit_3->text();
   QString NOM_PRODUIT=ui->lineEdit_17->text();
   QString TYPE_PRODUIT=ui->lineEdit_18->text();
   QString URL=ui->lineEdit_18->text();
   QString DESCRIPTION=ui->lineEdit_18->text();
     tache T(id_taches,nom,sujet,contenu);
    QMessageBox msgBox;
    if(T.rech(id_taches))
       {
    if (T.modifer(id_taches,nom,sujet,contenu))
    {
        ui->tableView_2->setModel(T.afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("UPDATE successfully.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}


        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("UPDATE failed \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
  }  else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                                   QObject::tr("Not found \n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}



}
