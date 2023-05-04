#include "Compte.h"

Compte::Compte()
{
    //ctor
}

Compte::~Compte()
{
    //dtor
}

void Compte::saisir()
{
    cout<<"Donner le num du compte"<<endl;
    cin>>numCompte;

     cout<<"Donner votre solde"<<endl;
    cin>>solde;
}


bool Compte::retirerArgent(float somme)
{
    if(solde>=somme)
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

void Compte::deposerArgent(float somme)
{
    solde+=somme;
}
void Compte::consulterSolde()
{
    cout<<"Votre solde est: "<<solde<<endl;
}


void Compte::transfererArgent(float somme, Compte &C)
{
    if (retirerArgent(somme))
        C.deposerArgent(somme);
}
