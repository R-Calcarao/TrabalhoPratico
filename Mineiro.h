//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_MINEIRO_H
#define PRATICOTRABALHO_MINEIRO_H

#include "Trabalhadores.h"

class Mineiro : public Trabalhadores{

    float probDemi=10;

public:
    Mineiro(const int dia) :  Trabalhadores("miner",10,dia){}

    void newWorkDay() override;

};


#endif //PRATICOTRABALHO_MINEIRO_H
