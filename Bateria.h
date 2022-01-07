//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_BATERIA_H
#define PRATICOTRABALHO_BATERIA_H

#include "Edificio.h"


using namespace std;
class Bateria : public Edificio{

    int eletrProd = 0;
public:
    Bateria(int day) : Edificio("bat",5,100/*KWh*/,day){}

    void newDay() override;

    void lvlUp() override;

    bool capMaxReach(const string type) override;

    void addEletrProd(const int add) {
        eletrProd = eletrProd + add;
    }

    int getEletrProd() const{
        return eletrProd;
    }

    void removeEletrProd(const int cost) {
        eletrProd = eletrProd - cost;
    }

};


#endif //PRATICOTRABALHO_BATERIA_H
