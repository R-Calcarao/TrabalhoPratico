//
// Created by ACER on 05/01/2022.
//

#ifndef PRATICOTRABALHO_SERRACAO_H
#define PRATICOTRABALHO_SERRACAO_H


#include "Edificio.h"

class Serracao : public Edificio{

public:
    Serracao(int day) : Edificio("serra",0,0/*kg de carvao*/,day){}

    void produzir() override;
};


#endif //PRATICOTRABALHO_SERRACAO_H
