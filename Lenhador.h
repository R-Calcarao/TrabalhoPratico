//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_LENHADOR_H
#define PRATICOTRABALHO_LENHADOR_H

#include "Trabalhadores.h"

class Lenhador : public Trabalhadores{

    int dayCount=0;
    bool rest=false;
    bool aux = false;

public:

    Lenhador(const int dia) : Trabalhadores("len",20,dia){}

    void newWorkDay() override;

    bool Resting() override{
        return rest;
    }

};


#endif //PRATICOTRABALHO_LENHADOR_H
