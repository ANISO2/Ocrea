#include "CompteCourant.h"

CompteCourant::CompteCourant()
{
    seuil=-500;
}

CompteCourant::~CompteCourant()
{
    //dtor
}
bool CompteCourant::retirerArgent(float somme)
{
    if(solde-somme>=-500)
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

