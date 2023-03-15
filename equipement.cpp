#include "equipement.h"
#include <QMessageBox>


equipement::equipement(int ID_EQUIPEMENT,int QUANTITE,QString NOM_PRODUIT,QString TYPE_PRODUIT,QString URL,QString DESCRIPTION)
{
  this->ID_EQUIPEMENT=ID_EQUIPEMENT;
  this->QUANTITE=QUANTITE;
  this->NOM_PRODUIT=NOM_PRODUIT;
  this->TYPE_PRODUIT=TYPE_PRODUIT;
  this->URL=URL;
  this->DESCRIPTION=DESCRIPTION;
}
bool equipement::ajouter()
{
    QSqlQuery query;

QString id_string=QString::number(ID_EQUIPEMENT);
QString QUANTITE_string=QString::number(QUANTITE);

        query.prepare("INSERT INTO EQUIPEMENT"
                      "(ID_EQUIPEMENT,QUANTITE,NOM_PRODUIT,TYPE_PRODUIT,URL,DESCRIPTION) VALUES(:ID_EQUIPEMENT,:QUANTITE,:NOM_PRODUIT,:TYPE_PRODUIT,:URL,:DESCRIPTION)");
        query.bindValue(":ID_EQUIPEMENT",id_string);
        query.bindValue(":QUANTITE",QUANTITE_string);
        query.bindValue(":NOM_PRODUIT",NOM_PRODUIT);
        query.bindValue(":TYPE_PRODUIT",TYPE_PRODUIT);
        query.bindValue(":URL",URL);
        query.bindValue(":DESCRIPTION",DESCRIPTION);
         return query.exec();
     }


QSqlQueryModel * equipement::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from EQUIPEMENT");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EQUIPEMENT"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("QUANTITE"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("URL"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("DESCRIPTION"));
   return model ;
}

bool equipement::supprimer(int ID_EQUIPEMENT)
{
    QSqlQuery query;
    QString res = QString::number(ID_EQUIPEMENT);
    QMessageBox::StandardButton reply = QMessageBox::question(
                nullptr,
                "Confirmation de suppression",
                "Êtes-vous sûr de vouloir supprimer cette équipement ?",
                QMessageBox::Yes | QMessageBox::No
                );

    if (reply == QMessageBox::Yes) {
        query.prepare("DELETE FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
        query.bindValue(":id", res);
    }

    return query.exec();
}

bool equipement::modifier(int ID_EQUIPEMENT, int QUANTITE, QString NOM_PRODUIT, QString TYPE_PRODUIT, QString URL, QString DESCRIPTION)
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EQUIPEMENT);
    QString quantite_string = QString::number(QUANTITE);
    query.prepare("UPDATE EQUIPEMENT SET QUANTITE = :quantite, NOM_PRODUIT = :nom_produit, TYPE_PRODUIT = :type_produit, URL = :url, DESCRIPTION = :description WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":quantite", quantite_string);
    query.bindValue(":nom_produit", NOM_PRODUIT);
    query.bindValue(":type_produit", TYPE_PRODUIT);
    query.bindValue(":url", URL);
    query.bindValue(":description", DESCRIPTION);
    query.bindValue(":id", id_string);
    return query.exec();
}
