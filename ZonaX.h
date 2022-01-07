//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_ZONAX_H
#define PRATICOTRABALHO_ZONAX_H

#include "Zona.h"

class ZonaX : public Zona{
    const string tipo;
public:
    ZonaX(int linha,int coluna): Zona("znZ",linha,coluna){};

};


#endif //PRATICOTRABALHO_ZONAX_H
