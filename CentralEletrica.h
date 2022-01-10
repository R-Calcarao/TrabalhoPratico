//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_CENTRALELETRICA_H
#define PRATICOTRABALHO_CENTRALELETRICA_H

#include "Edificio.h"



class CentralEletrica : public Edificio{

    int carvaoProd = 0;
    bool deal = false;
public:
    CentralEletrica(int day) : Edificio("elec",0,100/*kg de carvao*/,day){}

    void newDay() override;

    void produzir() override;

    void addCarvaoProd(const int add) {
        carvaoProd = carvaoProd + add;
    }

    int getCarvaoProd() const{
        return carvaoProd;
    }

    void removeCarvaoProd(const int cost) {
        carvaoProd = carvaoProd - cost;
    }

    bool getDealState() const{
        return deal;
    }
};


#endif //PRATICOTRABALHO_CENTRALELETRICA_H
