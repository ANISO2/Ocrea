#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDateTime>
class evenements
{
private:
    QString idevenement,nomevenement,duree,urlvideo;
    QDateTime datedebut;
public:
    evenements(){}
    evenements(QString,QString,QDateTime,QString,QString);
    QString getidevenement(){return idevenement ;}
    QString getnomevenement(){return nomevenement;}
    QDateTime getdatedebut(){return datedebut;}
    QString getduree(){return duree ;}
    QString geturlvideo(){return urlvideo ;}


    void setidevenement(QString n ){idevenement=n;}
    void setnomevenement(QString p ){nomevenement=p;}
    void setdatedebut(QDateTime d){datedebut=d;}
    void seturlvideo (QString a){urlvideo =a;}
    void setduree (QString b ){duree =b;}


    bool ajouter_evenements();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool update(QString);
    bool verifierid(QString);
};

#endif // EVENEMENTS_H
