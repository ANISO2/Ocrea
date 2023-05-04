#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include <Compte.h>


class CompteEpargne : public Compte
{
    public:
        CompteEpargne();
        virtual ~CompteEpargne();
        bool retirerArgent(float somme);

        double Gettaux() { return taux; }
        void Settaux(double val) { taux = val; }

    protected:

    private:
        double taux;
};

#endif // COMPTEEPARGNE_H
