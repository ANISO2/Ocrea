#include "CompteEpargne.h"

CompteEpargne::CompteEpargne()
{
    solde=5;
}

CompteEpargne::~CompteEpargne()
{
    //dtor
}
bool CompteEpargne::retirerArgent(float somme)
{
    if(solde-somme>=5)
    {
        solde=solde-somme;
        cout<<"Retrait effectue avec succes"<<endl;
        return true;
    }
    else
    {
        cout<<"Solde insuffisant"<<endl;
        return false;
    }
}
