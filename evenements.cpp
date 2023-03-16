#include "evenements.h"
#include <QMessageBox>
#include "QRegularExpression"
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QDate>
evenements::evenements(QString idevenement,QString nomevenement,QDateTime datedebut,QString duree,QString urlvideo)
{
  this->idevenement=idevenement;
   this->nomevenement=nomevenement;
    this->datedebut=datedebut;
    this->duree=duree;
    this->urlvideo=urlvideo;
}
bool evenements::ajouter_evenements()
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$");
    QRegularExpression durationRegex("^[0-9]+ jours$");

    if (!regex.match(idevenement).hasMatch() || idevenement.length() > 5 ) {
        QMessageBox::warning(0, "Erreur", "id invalid!");

        return false;

    }
    if (!letterRegex.match(nomevenement).hasMatch()) {
        QMessageBox::warning(0, "Erreur", "nom doit contient seulement des lettres alphabetiques!");

        return false;
    }
    if (duree.contains(QRegularExpression("[^a-zA-Z0-9 ]"))) {
        QMessageBox::warning(0, "Erreur", "duree invalid!");

        return false;
    }
    if (!durationRegex.match(duree).hasMatch()) {
        QMessageBox::warning(0, "Erreur", "duree invalid!");

        return false;
    }
    if (!urlvideo.startsWith("https://")) {
        QMessageBox::warning(0, "Erreur", "url commence par https://!");

        return false;
    }
    query.prepare("INSERT INTO EVENEMENTS (IDEVENEMENT, NOMEVENEMENT, DATEDEBUT, DUREE, URLVIDEO)" "VALUES (:idevenement, :nomevenement, :datedebut, :duree, :urlvideo)");

    query.bindValue(":idevenement",idevenement);
    query.bindValue(":nomevenement",nomevenement);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":duree",duree);
    query.bindValue(":urlvideo",urlvideo);
    return query.exec();
}
QSqlQueryModel * evenements::afficher()
{

QSqlQueryModel * model=new  QSqlQueryModel();

model->setQuery("SELECT * FROM EVENEMENTS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("idevenement"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("nomevenement")),
model->setHeaderData(0,Qt::Horizontal,QObject::tr("datedebut"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("duree"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("urlvideo"));


return model;
}
bool evenements ::supprimer(QString idevenement)
{
    QSqlQuery query;
    if(idevenement.isEmpty()) {
             QMessageBox::warning(0, "Erreur", "Le champ id est vide!");

                return false;}
    if (!verifierid(idevenement)) {
           QMessageBox::warning(0, "Erreur", "Lid  de levenement n'existe pas!");
           return false;}
    query.prepare("Delete from evenements where idevenement= :idevenement");
    query.bindValue(":idevenement",idevenement);
    return query.exec();

}
bool evenements::update(QString idevenement)
{
    QSqlQuery query;
    QRegularExpression regex("[0-9]+");
    QRegularExpression letterRegex("^[a-zA-Z]+$");
    QRegularExpression durationRegex("^[0-9]+ jours$");

    if (!regex.match(idevenement).hasMatch() || idevenement.length() > 5 ) {
        QMessageBox::warning(0, "Erreur", "id invalid!");

        return false;

    }
    if (!letterRegex.match(nomevenement).hasMatch()) {
        QMessageBox::warning(0, "Erreur", "nom doit contient seulement des lettres alphabetiques!");

        return false;
    }
    if (duree.contains(QRegularExpression("[^a-zA-Z0-9 ]"))) {
        QMessageBox::warning(0, "Erreur", "duree invalid!");

        return false;
    }
    if (!durationRegex.match(duree).hasMatch()) {
        QMessageBox::warning(0, "Erreur", "duree invalid!");

        return false;
    }
    if (!urlvideo.startsWith("https://")) {
        QMessageBox::warning(0, "Erreur", "url commence par https://!");

        return false;
    }
    //Prepare the query
    query.prepare("UPDATE evenements SET idevenement=:idevenement, nomevenement=:nomevenement,datedebut=:datedebut,duree=:duree,urlvideo=:urlvideo WHERE idevenement=:idevenement;");


    //Bind the values
    query.bindValue(":idevenement",idevenement);
    query.bindValue(":nomevenement",nomevenement);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":duree",duree);
    query.bindValue(":urlvideo",urlvideo);

    return query.exec();
}

bool evenements::verifierid(QString idevenement) {
    QSqlQuery query;
    query.prepare("SELECT idevenement FROM evenements WHERE idevenement = :idevenement");
    query.bindValue(":idevenement", idevenement);
    if (query.exec() && query.next()) {

        // id existe déjà
        return true;
    }
    // id n'existe pas encore
    return false;
}



