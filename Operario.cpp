//
// Created by ACER on 23/12/2021.
//

#include "Operario.h"
#include "Zona.h"

void Operario::newWorkDay() {
    if(giveZonaRef()->getTipoZona()=="mnt" && giveZonaRef()->getDay() - getContractDay() >= 10){
        int p = probDemi + (probDemi*0.05);
        bool TrueFalse = (rand() % 100) < p;
        if(TrueFalse){
            cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
            getId() << " . Adeus!!" << endl;
            giveZonaRef()->fireWorker(getId());
        }

    } else if(giveZonaRef()->getDay() - getContractDay() >= 10 && giveZonaRef()->getTipoZona() != "pas"){
        bool TrueFalse = (rand() % 100) < probDemi;
        if(TrueFalse){
            cout << "Vou me embora da zona: " << giveZonaRef()->getTipoZona() << ", sou o " << getTipo() << " de id: " <<
                 getId() << " . Adeus!!" << endl;
            giveZonaRef()->fireWorker(getId());
        }
    }
}
