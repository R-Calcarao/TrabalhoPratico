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
public:
    Barragem(int day) : Edificio("barg",35,0/*de Carvao*/,day){}

    void newDay() override;

    void produzir() override;

    void lvlUp() override;

    bool isFuctional() const {
        return fuctional;
    }

    float getProductSize() const{
        return productSize;
    }

    void addProductSize(){
        productSize++;
    }

};


#endif //PRATICOTRABALHO_BARRAGEM_H
