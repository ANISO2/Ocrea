#include "Employe.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlError>
EMPLOYE::EMPLOYE()
{
    IDEMPLOYE=""; NOMEMPLOYE=""; PRENOMEMPLOYE=""; PASSWORDEMPLOYE="";
 }
 EMPLOYE::EMPLOYE(QString IDEMPLOYE,QString NOMEMPLOYE,QString PRENOMEMPLOYE ,QString PASSWORDEMPLOYE )
   {
        this->IDEMPLOYE = IDEMPLOYE ; this ->NOMEMPLOYE=NOMEMPLOYE; this->PRENOMEMPLOYE=PRENOMEMPLOYE;
      this->PASSWORDEMPLOYE=PASSWORDEMPLOYE;

    }
 QString EMPLOYE::getid(){return IDEMPLOYE;}
 QString EMPLOYE:: getnom(){return NOMEMPLOYE ;}
 QString EMPLOYE:: getprenom(){return PRENOMEMPLOYE ; }
 QString EMPLOYE:: getpassword(){return PASSWORDEMPLOYE ; }

 void EMPLOYE:: setid(QString IDEMPLOYE){this->IDEMPLOYE=IDEMPLOYE;}
 void EMPLOYE:: setnom(QString NOMEMPLOYE){this->NOMEMPLOYE = NOMEMPLOYE;}
 void EMPLOYE:: setprenom(QString PRENOMEMPLOYE ){this->PRENOMEMPLOYE =PRENOMEMPLOYE ; }
 void EMPLOYE:: setpassword(QString PASSWORDEMPLOYE ){this->PASSWORDEMPLOYE =PASSWORDEMPLOYE ; }

 bool EMPLOYE::ajouter()
 {
    // bool test=false;

     QSqlQuery query;
          query.prepare("INSERT INTO EMPLOYE (IDEMPLOYE, NOMEMPLOYE, PRENOMEMPLOYE ,PASSWORD) "
                        "VALUES (:IDEMPLOYE, :NOMEMPLOYE, :PRENOMEMPLOYE , :PASSWORDEMPLOYE)");
          query.bindValue(":IDEMPLOYE", IDEMPLOYE);
          query.bindValue(":NOMEMPLOYE", NOMEMPLOYE);
          query.bindValue(":PRENOMEMPLOYE", PRENOMEMPLOYE);
          query.bindValue(":PASSWORDEMPLOYE", PASSWORDEMPLOYE);


         return query.exec();
     //return test;
 }

 bool EMPLOYE :: supprimer()

 {
     QSqlQuery query;
     query.prepare("Delete from EMPLOYE where IDEMPLOYE= :IDEMPLOYE ");
     query.bindValue(":IDEMPLOYE",IDEMPLOYE);

     return query.exec();


 }
 QSqlQueryModel * EMPLOYE::afficher()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from EMPLOYE");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDEMPLOYE"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMEMPLOYE"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMEMPLOYE"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("PASSWORDEMPLOYE"));

     return  model;

 }


 // modifier
 bool EMPLOYE::modifier()
 {
     QSqlQuery query;
      QString IDEMPLOYE_string = IDEMPLOYE;
     query.prepare("UPDATE EMPLOYE SET IDEMPLOYE=:IDEMPLOYE,NOMEMPLOYE=:NOMEMPLOYE,PRENOMEMPLOYE=:PRENOMEMPLOYE,PASSWORD=:PASSWORDEMPLOYE WHERE IDEMPLOYE=:IDEMPLOYE");
     query.bindValue(":IDEMPLOYE", IDEMPLOYE);
     query.bindValue(":NOMEMPLOYE", NOMEMPLOYE);
     query.bindValue(":PRENOMEMPLOYE", PRENOMEMPLOYE);
     query.bindValue(":PASSWORDEMPLOYE", PASSWORDEMPLOYE);

     return query.exec();
 }


 /*
 bool EMPLOYE::modifier()
 {
     QSqlQuery query;
     QString IDEMPLOYE_string = IDEMPLOYE;

     query.prepare("UPDATE EMPLOYE SET NOMEMPLOYE=:NOMEMPLOYE, PRENOMEMPLOYE=:PRENOMEMPLOYE, PASSWORDEMPLOYE=:PASSWORDEMPLOYE WHERE IDEMPLOYE=:IDEMPLOYE");
     query.bindValue(":IDEMPLOYE", IDEMPLOYE);
     query.bindValue(":NOMEMPLOYE", NOMEMPLOYE);
     query.bindValue(":PRENOMEMPLOYE", PRENOMEMPLOYE);
     query.bindValue(":PASSWORDEMPLOYE", PASSWORDEMPLOYE);
     return query.exec();
 }
*/

 bool EMPLOYE::checkExistence() const
 {
     QSqlQuery query;
     query.prepare("SELECT IDEMPLOYE FROM employe WHERE IDEMPLOYE = :IDEMPLOYE");
     query.bindValue(":IDEMPLOYE", IDEMPLOYE);
     if (query.exec() && query.next()) {
         return true; // if a row is returned, the employee exists
     } else {
         return false; // if no row is returned, the employee does not exist
     }
 }

