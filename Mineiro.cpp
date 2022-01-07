//
// Created by ACER on 23/12/2021.
//

#include "Mineiro.h"
#include "Zona.h"

void Mineiro::newWorkDay() {
    if(giveZonaRef()->getTipoZona()=="mnt" && giveZonaRef()->getDay()>=2){
        int p = probDemi + (probDemi*0.05);
        bool TrueFalse = (rand() % 100) < p;
        if(TrueFalse){
            cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
                 getId() << " . Adeus!!" << endl;
            giveZonaRef()->fireWorker(getId());
        }

    } else if(giveZonaRef()->getDay()>=2 && giveZonaRef()->getTipoZona() != "pas"){
        bool TrueFalse = (rand() % 100) < probDemi;
        if(TrueFalse){
            cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
                 getId() << " . Adeus!!" << endl;
            giveZonaRef()->fireWorker(getId());
        }
    }
}