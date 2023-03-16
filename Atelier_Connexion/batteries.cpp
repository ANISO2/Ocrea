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
    for (int i = 0; i < IDBATTERIE.size(); ++i)
    {
            if (IDBATTERIE.at(i).isDigit())
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






