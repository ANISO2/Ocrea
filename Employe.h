#ifndef EMPLOYE_H
#define EMPLOYE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class EMPLOYE
{
    QString IDEMPLOYE;
    QString NOMEMPLOYE ,PRENOMEMPLOYE ,PASSWORDEMPLOYE ;

public:
    EMPLOYE();
    EMPLOYE(QString ,QString ,QString,QString);
    QString getid();
     QString getnom();
      QString getprenom();
      QString getpassword();

      void setid(QString);
      void setnom(QString);
      void setprenom(QString);
      void setpassword(QString);

bool ajouter();
bool supprimer();
QSqlQueryModel * afficher();
bool modifier();
//bool existe();
bool checkExistence() const; // declaration of the checkExistence function

   // static void modifyStudent(const QString& id, const QString& newName, const QString& newLastName, const QString& newPassword);

private:


};

#endif // EMPLOYE_H
