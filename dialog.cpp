#include "dialog.h"
#include "ui_dialog.h"
#include "Employe.h"
#include <QMainWindow>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    }


void Dialog::on_pushButton_8_clicked() // button Ajouter
{


    QString IDEMPLOYE=ui->lineEdit->text();
    if(IDEMPLOYE.length() < 9 || !IDEMPLOYE.contains(QRegularExpression("[A-Z]")) || IDEMPLOYE.length() > 9  || !IDEMPLOYE.contains(QRegularExpression("[0-9]")))
    {
    QMessageBox::warning(this, "Erreur de validation de l'identifiant", "L'identifiant doit comporter 9 caractères et inclure des lettres majuscules.");
    return;
    }

    QString NOMEMPLOYE=ui->lineEdit_2->text();
    QString PRENOMEMPLOYE=ui->lineEdit_4->text();
    QString PASSWORDEMPLOYE=ui->lineEdit_3->text();

   if(PASSWORDEMPLOYE.length() < 8 || !PASSWORDEMPLOYE.contains(QRegularExpression("[A-Z]")) || !PASSWORDEMPLOYE.contains(QRegularExpression("[a-z]")) || !PASSWORDEMPLOYE.contains(QRegularExpression("[0-9]")))
    {
    QMessageBox::warning(this, "Erreur de validation du mot de passe", "Le mot de passe doit comporter au moins 8 caractères et inclure des lettres majuscules, des lettres minuscules et des chiffres.");
    return;
    }

    EMPLOYE E(IDEMPLOYE,NOMEMPLOYE,PRENOMEMPLOYE,PASSWORDEMPLOYE);
    if(IDEMPLOYE!="" && NOMEMPLOYE!="" && PRENOMEMPLOYE!="" && PASSWORDEMPLOYE!="")
    {
        bool test=E.ajouter();

        if(test)

        {  //Refresh the page

            ui->tableView->setModel(Etmp.afficher());

            QMessageBox::information(nullptr, QObject::tr("notification"),
                                  QObject::tr("ajout avec succes .\n"
                                              "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);


              }
                  else{
                      QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                                  QObject::tr("echec d ajout utilisateur deja existé .\n"
                                              "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);

            }
    }

    else {
        QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                    QObject::tr("case vide veuillez le verifier.\n"
                                " Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);

    }

}
/*
void Dialog::on_pushButton_10_clicked() // BUTTON Supprimer
{
    QString IDEMPLOYE=ui->lineEdit->text();
    EMPLOYE E(IDEMPLOYE,NULL,NULL,NULL);


    if(IDEMPLOYE!="")
    {
    bool test=E.supprimer();
    if(test)
    {
        //Refresh the page

                ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                              QObject::tr("suppression effectuée.\n"
                                          "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);

          }
              else{
                  QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                              QObject::tr("suppression non effectuée\n"
                                          "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);

        }
}
            else{
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("utilisateur n 'existe pas \n"
                                "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);

}
}
*/

void Dialog::on_pushButton_10_clicked() // BUTTON Supprimer
{
    QString IDEMPLOYE = ui->lineEdit->text();
    EMPLOYE E(IDEMPLOYE, NULL, NULL, NULL);

    if (IDEMPLOYE != "") {
        bool employeExists = E.checkExistence(); // check if the employee exists

        if (employeExists) { // if the employee exists, proceed with the deletion
            bool test = E.supprimer();

            if (test) {
                // Refresh the page
                ui->tableView->setModel(Etmp.afficher());
                QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppression effectuée.\n"
                                "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
            } else {
                QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("suppression non effectuée\n"
                                "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
            }
        } else { // if the employee does not exist, show an error message
            QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                QObject::tr("L'employé n'existe pas.\n"
                            "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
        }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
            QObject::tr("utilisateur n'existe pas.\n"
                        "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);
    }
}


void Dialog::on_tableView_activated(const QModelIndex &index)
{

}

void Dialog::on_pushButton_9_clicked() // MODIFIER
{
    QString IDEMPLOYE=ui->lineEdit->text();

    QString NOMEMPLOYE=ui->lineEdit_2->text();

    QString PRENOMEMPLOYE=ui->lineEdit_4->text();
    QString PASSWORDEMPLOYE=ui->lineEdit_3->text();

    if(PASSWORDEMPLOYE.length() < 8 || !PASSWORDEMPLOYE.contains(QRegularExpression("[A-Z]")) || !PASSWORDEMPLOYE.contains(QRegularExpression("[a-z]")) || !PASSWORDEMPLOYE.contains(QRegularExpression("[0-9]")))
     {
     QMessageBox::warning(this, "Erreur de validation du mot de passe", "Le mot de passe doit comporter au moins 8 caractères et inclure des lettres majuscules, des lettres minuscules et des chiffres.");
     return;
     }

    EMPLOYE E(IDEMPLOYE,NOMEMPLOYE,PRENOMEMPLOYE,PASSWORDEMPLOYE);


    bool test=E.modifier();
    if(test)
    {
        //Refresh the page

                ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("notification"),
                              QObject::tr("Modification effectuée.\n"
                                          "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);

          }
              else{
                  QMessageBox::critical(nullptr, QObject::tr("Probleme"),
                              QObject::tr("Modification non effectuée\n"
                                          "Cliquez sur Cancel pour quitter."), QMessageBox::Cancel);

        }
}
