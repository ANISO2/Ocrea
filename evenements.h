#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDateTime>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QChartView>
class evenements
{
private:
    QString idevenement,nomevenement,etat,urlvideo;
    QDateTime datedebut;
public:
    evenements(){}
    evenements(QString,QString,QDateTime,QString,QString);
    QString getidevenement(){return idevenement ;}
    QString getnomevenement(){return nomevenement;}
    QDateTime getdatedebut(){return datedebut;}
    QString getduree(){return etat ;}
    QString geturlvideo(){return urlvideo ;}


    void setidevenement(QString n ){idevenement=n;}
    void setnomevenement(QString p ){nomevenement=p;}
    void setdatedebut(QDateTime d){datedebut=d;}
    void seturlvideo (QString a){urlvideo =a;}
    void setduree (QString b ){etat =b;}



    bool ajouter_evenements();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool update(QString);
    bool verifierid(QString);
    QSqlQueryModel * rechercher_nom(QString);
    bool verifiernom(QString);
    QSqlQueryModel* tri_date();
    QSqlQueryModel* rechercher_url(QString );
    QChartView *statistique();



};

#endif // EVENEMENTS_H
