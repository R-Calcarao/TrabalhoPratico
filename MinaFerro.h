//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_MINAFERRO_H
#define PRATICOTRABALHO_MINAFERRO_H

#include "Edificio.h"


class MinaFerro : public Edificio{

     float ProbCollap = 15;
     int ferroProd = 0;
    float productSize=2;
public:
    MinaFerro(int day) : Edificio("mnF",15/*e uma viga*/,100/*kg de ferro*/, day){};

    void newDay() override;

    void produzir() override;

    void lvlUp() override;

    void addFerroProd(const int add) {
        ferroProd = ferroProd + add;
    }

    int getFerroProd() const{
        return ferroProd;
    }

    void removeFerroProd(const int cost) {
        ferroProd = ferroProd - cost;
    }

    float getProductSize() const{
        return productSize;
    }

    void addProductSize(){
        productSize++;
    }


};


#endif //PRATICOTRABALHO_MINAFERRO_H
