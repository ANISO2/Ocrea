#ifndef BANQUE_H
#define BANQUE_H
#include<string>
#include"Compte.h"
using namespace std;

class Banque
{
    public:
        Banque();
        virtual ~Banque();


    protected:

    private:

        string nom,lieu;
};

#endif // BANQUE_H
