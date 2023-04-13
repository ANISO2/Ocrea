#include "batteries.h"
#include <QtCore>
batteries::batteries(QString IDBATTERIE,QString ETAT,QDateTime DATERECHARGE)
{
        this->IDBATTERIE=IDBATTERIE;
        this->ETAT=ETAT;
        this->DATERECHARGE=DATERECHARGE;
}
bool batteries::ajouterbatterie()
{
   QSqlQuery query;


   query.prepare("insert into BATTERIES(IDBATTERIE,ETAT,DATERECHARGE)""VALUES(:IDBATTERIE, :ETAT, :DATERECHARGE)");

   query.bindValue(":IDBATTERIE",IDBATTERIE);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":DATERECHARGE",DATERECHARGE);

   return query.exec();

}
QSqlQueryModel *  batteries::afficher()
{
     QSqlQueryModel *model=new  QSqlQueryModel();
     model->setQuery("select * from BATTERIES");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDBATTERIE"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATERECHARGE"));
     return model;
}


QSqlQueryModel *  batteries::afficher_id()
{

    QSqlQueryModel *model=new  QSqlQueryModel();
    model->setQuery("select * from BATTERIES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDBATTERIE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATERECHARGE"));
    return model;
}





bool batteries:: supprimer(QString IDBATTERIE)
{
  QSqlQuery query;
query.prepare("Delete from BATTERIES where IDBATTERIE= :IDBATTERIE");
query.bindValue(":IDBATTERIE",IDBATTERIE);
return query.exec();
}
bool batteries::checkInput(const QString &IDBATTERIE)
{
    bool test;
   while(IDBATTERIE.size()<=8)
   {
    for (int i = 0; i < IDBATTERIE.size(); ++i)
    {
            if (IDBATTERIE.at(i).isDigit())
            {
                test=true;

            }
            else
            {
                test=false;

            }


    }
    return  test;
   }
}
bool batteries::checkInput1(const QString &ETAT)
{
        bool test;
        QString str1 = "charge";
        QString str2 = "non charge";

        int result = ETAT.compare(str1, Qt::CaseSensitive);
       int result1 = ETAT.compare(str2, Qt::CaseSensitive);

        if (result == 0 ||result1==0)
        {
            test=true;
            return test;
        }
        else
            {
            test=false;
        return test;
            }
}

//Statistiques
int batteries::statistique1(){
    QSqlQuery query;
            int count=0 ;
            QSqlQuery requete("select * from BATTERIES where ETAT like 'charge' ") ;
            while(requete.next())
            {
                    count++ ;
            }

        return count ;
}

int batteries::statistique2(){
    QSqlQuery query;
            int count=0 ;
            QSqlQuery requete("select * from BATTERIES where ETAT like 'non charge' ") ;
            while(requete.next())
            {
                    count++ ;
            }

        return count ;
}
int batteries::statistique3(){

}
QSqlQueryModel * batteries:: getAllId(){
    QSqlQueryModel * model =new QSqlQueryModel();
            model->setQuery("select IDBATTERIE from BATTERIES ");
            return model ;
}
int batteries:: getNumIdsInDatabase() {


    // Execute a query to get the number of IDs in the database
    QSqlQuery query;
    query.exec("SELECT COUNT(IDBATTERIE) FROM BATTERIES");
    if (query.next()) {
        int numIds = query.value(0).toInt();
        return numIds;
    }
}







