//
// Created by ACER on 05/01/2022.
//

#ifndef PRATICOTRABALHO_BARRAGEM_H
#define PRATICOTRABALHO_BARRAGEM_H


#include "Edificio.h"

class Barragem : public Edificio{
    float ProbCollap = 5;
    bool fuctional = true;
    float productSize=3;
    float eletrProd=0;
    bool deal = false;
public:
    Barragem(int day) : Edificio("barg",35,0/*de Carvao*/,day){}

    void newDay() override;

    void produzir() override;

    void lvlUp() override;

    bool isFuctional() const {
        return fuctional;
    }

    float getEletrProd() const{
        return eletrProd;
    }

    bool getDealState() const {
        return deal;
    }

    void addEletrProd(const float add) {
        eletrProd = eletrProd + add;
    }

    void removeEletrProd(const float cost) {
        eletrProd = eletrProd - cost;
    }

    float getProductSize() const{
        return productSize;
    }

    void addProductSize(){
        productSize++;
    }

};


#endif //PRATICOTRABALHO_BARRAGEM_H

};


#endif //PRATICOTRABALHO_BARRAGEM_H
