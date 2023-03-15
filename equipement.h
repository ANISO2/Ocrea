#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class equipement
{
    int ID_EQUIPEMENT,QUANTITE;
    QString NOM_PRODUIT,TYPE_PRODUIT,URL,DESCRIPTION;

public:
    equipement(){}
    equipement(int ,int ,QString,QString,QString,QString) ;

    int getID_EQUIPEMENT(){return ID_EQUIPEMENT;}
    int getQUANTITE(){return QUANTITE;}
    QString getNOM_PRODUIT(){return NOM_PRODUIT;}
    QString getTYPE_PRODUIT(){return TYPE_PRODUIT;}
    QString getURL(){return URL;}
    QString getDescription(){return DESCRIPTION;}

    void setID_EQUIPEMENT(int ID_EQUIPEMENT){this->ID_EQUIPEMENT=ID_EQUIPEMENT;}
    void setQUANTITE(int QUANTITE){this->QUANTITE=QUANTITE;}
    void setNOM_PRODUIT(QString NOM_PRODUIT){this->NOM_PRODUIT=NOM_PRODUIT;}
    void setTYPE_PRODUIT(QString TYPE_PRODUIT){this->TYPE_PRODUIT=TYPE_PRODUIT;}
    void setURL(QString URL){this->URL=URL;}
    void setDESCRIPTION(QString DESCRIPTION){this->DESCRIPTION=DESCRIPTION;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int ID_EQUIPEMENT, int QUANTITE, QString NOM_PRODUIT, QString TYPE_PRODUIT, QString URL, QString DESCRIPTION);
};

#endif // EQUIPEMENT_H
