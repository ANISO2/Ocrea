#ifndef VOITURE_H
#define VOITURE_H
#include<QSqlQuery>
#include<QSqlQueryModel>

#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QChartView>
class voiture
{
    QString cin,nomvoiture,prenomvoiture,matriculevoiture,IDBATTERIE;

public:
    voiture(){}
    voiture(QString,QString,QString,QString,QString);
    QString getnomvoiture(){return nomvoiture ;}
    QString getprenomvoiture(){return prenomvoiture ;}
    QString getcin(){return cin ;}
    QString getmatriculevoiture(){return matriculevoiture ;}
    QString getIDBATTERIE(){return IDBATTERIE ;}


    void setnomvoiture(QString n ){nomvoiture=n;}
    void setprenomvoiture(QString p ){prenomvoiture=p;}
    void setcin(QString id){cin=id;}
    void setmatriculevoiture (QString A ){matriculevoiture =A;}
    void setIDBATTERIE (QString A ){IDBATTERIE =A;}


    bool ajouter_voiture();
    QSqlQueryModel * afficher_voiture();
    bool supprimer_voiture(QString );
    bool update(QString);
    bool verifiercin(QString);
    //QSqlQueryModel * rechercher_cin(QString);
    QSqlQueryModel* tri_cin();
    QChartView *statistique();


};

#endif // VOITURE_H
