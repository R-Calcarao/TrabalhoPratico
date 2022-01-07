//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_FUNDICAO_H
#define PRATICOTRABALHO_FUNDICAO_H

#include "Edificio.h"



class Fundicao : public Edificio{

public:
    Fundicao(int day) : Edificio("fun",0,0,day){};

    void newDay() override;

    void produzir() override;



};

#endif //PRATICOTRABALHO_FUNDICAO_H
