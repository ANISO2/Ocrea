#ifndef COMPTE_H
#define COMPTE_H
#include<string>
#include<iostream>
using namespace std;

class Compte
{
    public:
        Compte();
        virtual ~Compte();
        void saisir();
        void afficher();
        bool retirerArgent(float somme);
        void deposerArgent(float somme);
        void consulterSolde();
        void transfererArgent(float somme, Compte & C);
        int getNumCompte()const {return numCompte;}
        float getSolde(){return solde;}

    protected:
        float solde;
        int numCompte;
    private:

};

#endif // COMPTE_H
