#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

#include <Compte.h>


class CompteCourant : public Compte
{
    public:
        CompteCourant();
        virtual ~CompteCourant();
bool retirerArgent(float somme);

        double Getseuil() { return seuil; }
        void Setseuil(double val) { seuil = val; }

    protected:

    private:
        double seuil;
};

#endif // COMPTECOURANT_H
