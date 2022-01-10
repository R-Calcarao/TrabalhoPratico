//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_MINACARVAO_H
#define PRATICOTRABALHO_MINACARVAO_H

#include "Edificio.h"


class MinaCarvao : public Edificio{

     float ProbCollap = 10;
     int carvaoProd = 0;
     float productSize=2;
    bool deal = false;
public:
    MinaCarvao(int day) : Edificio("mnC",10/*e uma viga*/,100/*de Carvao*/,day){}

    void newDay() override;

    void produzir() override;

    void lvlUp() override;

    void addCarvaoProd(const int add) {
        carvaoProd = carvaoProd + add;
    }

    int getCarvaoProd() const{
        return carvaoProd;
    }

    void removeCarvaoProd(const int cost) {
        carvaoProd = carvaoProd - cost;
    }

    float getProductSize() const{
        return productSize;
    }

    void addProductSize(){
        productSize++;
    }

    bool getDealState() const{
        return deal;
    }

};


#endif //PRATICOTRABALHO_MINACARVAO_H
