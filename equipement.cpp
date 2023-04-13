#include "equipement.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QAbstractItemModel>
#include <QDesktopServices>
#include <QUrl>
equipement::equipement(int ID_EQUIPEMENT,int QUANTITE,QString NOM_EQUIPEMENT,QString ETAT_EQUIPEMENT ,QString DISPONIBILITE , QString DESCRIPTION)
{
  this->ID_EQUIPEMENT=ID_EQUIPEMENT;
  this->QUANTITE=QUANTITE;
  this->NOM_EQUIPEMENT=NOM_EQUIPEMENT;
  this->ETAT_EQUIPEMENT=ETAT_EQUIPEMENT;
  this->DISPONIBILITE=DISPONIBILITE;
  this->DESCRIPTION=DESCRIPTION;
}
bool equipement::ajouter()
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EQUIPEMENT);
    QString quantite_string = QString::number(QUANTITE);

    query.prepare("INSERT INTO EQUIPEMENT(ID_EQUIPEMENT, QUANTITE, NOM_EQUIPEMENT, ETAT_EQUIPEMENT, DISPONIBILITE, DESCRIPTION) "
                  "VALUES (:ID_EQUIPEMENT, :QUANTITE, :NOM_EQUIPEMENT, :ETAT_EQUIPEMENT, :DISPONIBILITE, :DESCRIPTION)");
    query.bindValue(":ID_EQUIPEMENT", id_string);
    query.bindValue(":QUANTITE", quantite_string);
    query.bindValue(":NOM_EQUIPEMENT", NOM_EQUIPEMENT);
    query.bindValue(":ETAT_EQUIPEMENT", ETAT_EQUIPEMENT);
    query.bindValue(":DISPONIBILITE", DISPONIBILITE);
    query.bindValue(":DESCRIPTION", DESCRIPTION);

    return query.exec();
}

QSqlQueryModel * equipement::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from EQUIPEMENT");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("DESCRIPTION"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("QUANTITE"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM_EQUIPEMENT"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ETAT_EQUIPEMENT"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EQUIPEMENT"));
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



bool equipement::rech(int ID_EQUIPEMENT )
    {
       QSqlQuery q("select * from EQUIPEMENT where ID_EQUIPEMENT = "+QString::number(ID_EQUIPEMENT) );
          QSqlRecord rec = q.record();

          qDebug() << "Number of columns: " << rec.count();

          int nameCol = rec.indexOf("ID_EQUIPEMENT"); // index of the field "name"
          while (q.next())
          {

              qDebug() << q.value(nameCol).toString();
              QString a= q.value(nameCol).toString();
              if(a!="")
              {

                    return true;

    }
    }
            return false;  }


bool equipement::modifier(int ID_EQUIPEMENT, int QUANTITE, QString NOM_EQUIPEMENT, QString ETAT_EQUIPEMENT, QString DISPONIBILITE , QString DESCRIPTION)
{
    QSqlQuery query;
    QString id_string = QString::number(ID_EQUIPEMENT);
    QString quantite_string = QString::number(QUANTITE);

    if (QUANTITE == 0) {
        QSqlQuery searchQuery;
        searchQuery.prepare("SELECT QUANTITE FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
        searchQuery.bindValue(":id", ID_EQUIPEMENT);
        searchQuery.exec();
        searchQuery.next();
        QString quantite_query = searchQuery.value(0).toString();
        QUANTITE = quantite_query.toInt();
    }

    if (NOM_EQUIPEMENT.isEmpty()) {
        QSqlQuery searchQuery;
        searchQuery.prepare("SELECT NOM_EQUIPEMENT FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
        searchQuery.bindValue(":id", ID_EQUIPEMENT);
        searchQuery.exec();
        searchQuery.next();
        NOM_EQUIPEMENT = searchQuery.value(0).toString();
    }
    if (ETAT_EQUIPEMENT.isEmpty()) {
        QSqlQuery searchQuery;
        searchQuery.prepare("SELECT ETAT_EQUIPEMENT FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
        searchQuery.bindValue(":id", ID_EQUIPEMENT);
        searchQuery.exec();
        searchQuery.next();
        ETAT_EQUIPEMENT= searchQuery.value(0).toString();
    }
    if (DISPONIBILITE.isEmpty()) {
        QSqlQuery searchQuery;
        searchQuery.prepare("SELECT DISPONIBILITE FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
        searchQuery.bindValue(":id", ID_EQUIPEMENT);
        searchQuery.exec();
        searchQuery.next();
        DISPONIBILITE = searchQuery.value(0).toString();
    }

    if (DESCRIPTION.isEmpty()) {
        QSqlQuery searchQuery;
        searchQuery.prepare("SELECT DESCRIPTION FROM EQUIPEMENT WHERE ID_EQUIPEMENT = :id");
        searchQuery.bindValue(":id", ID_EQUIPEMENT);
        searchQuery.exec();
        searchQuery.next();
        DESCRIPTION = searchQuery.value(0).toString();
    }

    query.prepare("UPDATE EQUIPEMENT SET QUANTITE = :quantite, NOM_EQUIPEMENT = :nom_equipement, ETAT_EQUIPEMENT = :etat, DESCRIPTION = :description, DISPONIBILITE = :disponibilite WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":quantite", QUANTITE);
    query.bindValue(":nom_equipement", NOM_EQUIPEMENT);
    query.bindValue(":etat", ETAT_EQUIPEMENT);
    query.bindValue(":disponibilite", DISPONIBILITE);
    query.bindValue(":description", DESCRIPTION);
    query.bindValue(":id", id_string);
    return query.exec();
}

QSqlQueryModel* equipement::afficherRecherche(QString searchValue)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    if(searchValue.isEmpty()) {
        QSqlQuery query;
        query.prepare("SELECT * FROM EQUIPEMENT");
        query.exec();
        model->setQuery(query);
        return model;
    }

    QSqlQuery query;
    if (searchValue.toInt()) {
        // Si la valeur de recherche est un nombre, on recherche par ID
        query.prepare("SELECT * FROM EQUIPEMENT WHERE ID_EQUIPEMENT=:searchValue ORDER BY ID_EQUIPEMENT ASC");
        query.bindValue(":searchValue", searchValue.toInt());
        if (!query.exec() || !query.next()) {
            QMessageBox::warning(0, "Erreur", "Aucun résultat trouvé pour la recherche !");
            return model;
        }
        model->setQuery(query);
        return model;
    }
    else {
        // Sinon, on recherche par nom ou état de EQUIPEMENT
        query.prepare("SELECT * FROM EQUIPEMENT WHERE NOM_EQUIPEMENT LIKE :searchValue OR ETAT_EQUIPEMENT LIKE :searchValue ORDER BY ID_EQUIPEMENT ASC");
        query.bindValue(":searchValue", "%" + searchValue + "%");
        if (!query.exec() || !query.next()) {
            QMessageBox::warning(0, "Erreur", "Aucun résultat trouvé pour la recherche !");
            return model;
        }
        model->setQuery(query);
        return model;
    }
}

QSqlQueryModel* equipement::tri_ID_EQUIPEMENT()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // Trier les données selon l'ID_EQUIPEMENT
    model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY ID_EQUIPEMENT ASC");

    return model;
}
void generateQRCode(QString code) {
    // Construct the URL for the Google Charts API

    QString url = QString("https://chart.googleapis.com/chart?cht=qr&chs=300x300&chl=%1").arg(code);

    // Open the URL in the default web browser
   QDesktopServices::openUrl(QUrl(url));
}

