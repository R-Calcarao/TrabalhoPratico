//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_FUNDICAO_H
#define PRATICOTRABALHO_FUNDICAO_H

#include "Edificio.h"



class Fundicao : public Edificio{

    bool deal = false;
    int acoProd=0;
public:
    Fundicao(int day) : Edificio("fun",0,0,day){};

    void newDay() override;

    void produzir() override;

    bool getDealState() const{
        return deal;
    }

    int getAcoProd() const{
        return acoProd;
    }

    void addAcoProd(const int add) {
        acoProd = acoProd + add;
    }

    void removeAcoProd(const int cost) {
        acoProd = acoProd - cost;
    }



};

#endif //PRATICOTRABALHO_FUNDICAO_H
