//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_MONTANHA_H
#define PRATICOTRABALHO_MONTANHA_H

#include "Zona.h"

class Montanha : public Zona {

    const string tipo;
public:
    Montanha(int linha, int coluna) : Zona("mnt",linha,coluna){};

    void newDay() override {
        Zona::newDay();
        addFerro(NumbWorkers()*.1);
    }

};

#endif //PRATICOTRABALHO_MONTANHA_H