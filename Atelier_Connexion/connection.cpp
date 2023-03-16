#include "connection.h"
Connection::Connection(){}

bool Connection::createconnect()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_project2A");
db.setUserName("oussema");//inserer nom de l'utilisateur
db.setPassword("kill");//inserer mot de passe de cet utilisateur

if (db.open())  test=true;
 return  test;
}
void Connection ::closeconnect(){db.close();}
