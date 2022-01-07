//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_OPERARIO_H
#define PRATICOTRABALHO_OPERARIO_H

#include "Trabalhadores.h"

class Operario : public Trabalhadores{

    const float probDemi=5;

public:
    Operario(const int dia) : Trabalhadores("oper",15,dia){}

    void newWorkDay() override;
};


#endif //PRATICOTRABALHO_OPERARIO_H
