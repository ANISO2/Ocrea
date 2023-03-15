#include"connection.h"
connection::connection() { }
bool connection::createconnection()
{
    db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ocrea");
    db.setUserName("chadha");//inserer nom de l'utilisateur
    db.setPassword("chadha");//inserer mot de passe de cet utilisateur
bool test= false;
    if (db.open())
        test=true;
        return  test;
}


    void connection::closeconnexion()  {
      db.close();
    }



