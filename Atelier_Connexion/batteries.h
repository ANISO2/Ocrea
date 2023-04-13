#ifndef BATTERIES_H
#define BATTERIES_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDateTime>
class batteries
{
    QString IDBATTERIE,ETAT;
    QDateTime DATERECHARGE;

public:
    batteries(){};
    batteries(QString,QString,QDateTime);
    //gettters
    QString getIDBATTERIE(){return IDBATTERIE;}
    QString getETAT(){return ETAT;}
    QDateTime  getDATERECHARGE(){return DATERECHARGE;}
    //setters
    void setIDBATTERIE(QString n){IDBATTERIE=n;}
    void setETAT(QString p){ETAT=p;}
    void setDATERECHARGE(QDateTime d){DATERECHARGE=d;}
    //fonctionnalités de base relatives a l'entité batteries
    bool ajouterbatterie();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_id();
    bool supprimer(QString);
    bool checkInput(const QString &IDBATTERIE);
    bool checkInput1(const QString &ETAT);
    int statistique1();
    int statistique2();
    int statistique3();
    QSqlQueryModel * getAllId();
    int getNumIdsInDatabase();
};

#endif // BATTERIES_H
