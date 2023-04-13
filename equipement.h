#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QObject>
#include <QSqlRecord>
#include <QDebug>

class equipement
{
    int ID_EQUIPEMENT,QUANTITE;
    QString NOM_EQUIPEMENT,ETAT_EQUIPEMENT,DISPONIBILITE,DESCRIPTION;
public:
    equipement(){}
    equipement(int ,int ,QString,QString,QString,QString) ;

    int getID_EQUIPEMENT(){return ID_EQUIPEMENT;}
    int getQUANTITE(){return QUANTITE;}

    QString getNOM_EQUIPEMENT(){return NOM_EQUIPEMENT;}
    QString getETAT_EQUIPEMENT(){return ETAT_EQUIPEMENT;}
    QString getDISPONIBILITE(){return DISPONIBILITE;}
    QString getDescription(){return DESCRIPTION;}

    void setID_EQUIPEMENT(int ID_EQUIPEMENT){this->ID_EQUIPEMENT=ID_EQUIPEMENT;}
    void setQUANTITE(int QUANTITE){this->QUANTITE=QUANTITE;}
    void setNOM_EQUIPEMENT(QString NOM_EQUIPEMENT){this->NOM_EQUIPEMENT=NOM_EQUIPEMENT;}
    void setETAT_EQUIPEMENT(QString ETAT_EQUIPEMENT){this->ETAT_EQUIPEMENT=ETAT_EQUIPEMENT;}
    void setDISPONIBILITE(QString DISPONIBILITE){this->DISPONIBILITE=DISPONIBILITE;}
    void setDESCRIPTION(QString DESCRIPTION){this->DESCRIPTION=DESCRIPTION;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int ID_EQUIPEMENT, int QUANTITE, QString NOM_EQUIPEMENT, QString ETAT_EQUIPEMENT,QString DISPONIBILITE, QString DESCRIPTION);
    bool rech(int ID_EQUIPEMENT);
    QSqlQueryModel* afficherRecherche(QString NOM_EQUIPEMENT);
    QSqlQueryModel* tri_ID_EQUIPEMENT();
    void generateQRCode(QString code);
};
#endif // EQUIPEMENT_H
