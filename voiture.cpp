#include "voiture.h"
#include "QRegularExpression"
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QDate>



voiture::voiture(QString cin,QString nomvoiture,QString prenomvoiture,QString matriculevoiture)
{
  this->cin=cin;
   this->nomvoiture=nomvoiture;
    this->prenomvoiture=prenomvoiture;
    this->matriculevoiture=matriculevoiture;
}

QSqlQueryModel * voiture::afficher_voiture()
{
    QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("SELECT * FROM VOITURES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomvoiture"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenomvoiture"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("matriculevoiture"));
return model;


}


bool voiture::ajouter_voiture()
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$"); // Expression régulière pour vérifier si une chaîne de caractères contient uniquement des lettres

    if (!regex.match(cin).hasMatch() || cin.length() > 8 ) {
        // Vérifier si le CIN est un nombre et si les champs ne dépassent pas les limites
        return false;
    }
    if (!letterRegex.match(nomvoiture).hasMatch()) {
        // Vérifier si NOMVOITURE contient uniquement des lettres
        return false;
    }
    if (!letterRegex.match(prenomvoiture).hasMatch()) {
        // Vérifier si PRENOMVOITURE contient uniquement des lettres
        return false;
    }
    if (!matriculevoiture.contains("TUN")) {
        // Vérifier si MATRICULEVOITURE contient le mot "TUN"
        return false;
    }
    query.prepare("INSERT INTO VOITURES (CIN,NOMVOITURE,PRENOMVOITURE,MATRICULEVOITURE) values(:cin,:nomvoiture,:prenomvoiture,:matriculevoiture)");

    query.bindValue(":cin",cin);
    query.bindValue(":nomvoiture",nomvoiture.left(10)); // Tronquer le champ NOMVOITURE à 10 caractères maximum
    query.bindValue(":prenomvoiture",prenomvoiture.left(10)); // Tronquer le champ PRENOMVOITURE à 10 caractères maximum
    query.bindValue(":matriculevoiture",matriculevoiture.left(10)); // Tronquer le champ MATRICULEVOITURE à 10 caractères maximum
    return query.exec();
}



bool voiture::supprimer_voiture(QString cin)
{
    QSqlQuery query;
    if(cin.isEmpty()) {
             QMessageBox::warning(0, "Erreur", "Le champ cin est vide!");

                return false;}
    if (!verifiercin(cin)) {
           QMessageBox::warning(0, "Erreur", "Le cin de voiture n'existe pas!");
           return false;}

    QString res = QString(cin);

    QMessageBox::StandardButton reply = QMessageBox::question(
                nullptr,
                "Confirmation de suppression",
                "Êtes-vous sûr de vouloir supprimer cette voiture ?",
                QMessageBox::Yes | QMessageBox::No
                );

    if (reply == QMessageBox::Yes) {
        query.prepare("DELETE FROM VOITURES WHERE cin= :cin");
        query.bindValue(":cin",res);
        return query.exec();
    } else {
        return false;
    }
}

bool voiture::update(QString cin)
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$"); // Expression régulière pour vérifier si une chaîne de caractères contient uniquement des lettres

    if (!regex.match(cin).hasMatch() || cin.length() > 8 ) {
        // Vérifier si le CIN est un nombre et si les champs ne dépassent pas les limites
        return false;
    }
    if (!letterRegex.match(nomvoiture).hasMatch()) {
        // Vérifier si NOMVOITURE contient uniquement des lettres
        return false;
    }
    if (!letterRegex.match(prenomvoiture).hasMatch()) {
        // Vérifier si PRENOMVOITURE contient uniquement des lettres
        return false;
    }
    if (!matriculevoiture.contains("TUN")) {
        // Vérifier si MATRICULEVOITURE contient le mot "TUN"
        return false;
    }
    if(cin.isEmpty()) {
             QMessageBox::warning(0, "Erreur", "Le champ cin est vide!");

                return false;}
    if (!verifiercin(cin)) {
           QMessageBox::warning(0, "Erreur", "Le cin de voiture n'existe pas!");
           return false;}

    //Prepare the query
    query.prepare("UPDATE voitures SET cin=:cin, nomvoiture=:nomvoiture,prenomvoiture=:prenomvoiture,matriculevoiture=:matriculevoiture WHERE cin=:cin;");


    //Bind the values
    query.bindValue(":cin",cin);
    query.bindValue(":nomvoiture",nomvoiture);
    query.bindValue(":prenomvoiture",prenomvoiture);
    query.bindValue(":matriculevoiture",matriculevoiture);

    return query.exec();
}

bool voiture::verifiercin(QString cin) {
    QSqlQuery query;
    query.prepare("SELECT cin FROM voitures WHERE cin = :cin");
    query.bindValue(":cin", cin);
    if (query.exec() && query.next()) {

        // cin existe déjà
        return true;
    }
    // cin n'existe pas encore
    return false;
}
