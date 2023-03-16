#ifndef VOITURE_H
#define VOITURE_H
#include<QSqlQuery>
#include<QSqlQueryModel>


class voiture
{
    QString cin,nomvoiture,prenomvoiture,matriculevoiture;

public:
    voiture(){}
    voiture(QString,QString,QString,QString);
    QString getnomvoiture(){return nomvoiture ;}
    QString getprenomvoiture(){return prenomvoiture ;}
    QString getcin(){return cin ;}
    QString getmatriculevoiture(){return matriculevoiture ;}


    void setnomvoiture(QString n ){nomvoiture=n;}
    void setprenomvoiture(QString p ){prenomvoiture=p;}
    void setcin(QString id){cin=id;}
    void setmatriculevoiture (QString A ){matriculevoiture =A;}


    bool ajouter_voiture();
    QSqlQueryModel * afficher_voiture();
    bool supprimer_voiture(QString );
    bool update(QString);
    bool verifiercin(QString);

};

#endif // VOITURE_H
