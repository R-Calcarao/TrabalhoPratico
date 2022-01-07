//
// Created by ACER on 23/12/2021.
//

#include "Bateria.h"
#include "Zona.h"

void Bateria::newDay() {
    Edificio::newDay();
    if(getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    }
}

void Bateria::lvlUp() {
    Edificio::lvlUp();
    if(getLvl() != 5){
        if(getZonaRef()->getMoney() >= getLvlPrice()) {

            getZonaRef()->withdrawMoney(getLvlPrice());
            addCapMax(10);
            addLvl();
            cout << "Bateria na Zona " << getZonaRef()->getTipoZona() << " evoluiu." << endl;
            cout << "Nivel: " << getLvl() << endl;
            cout << "Capacidade Maxima: " << getCapMax() << " KWh" << endl;

        } else if(getZonaRef()->getMoney() < getLvlPrice()) {
            cout << "Nao tem dinheiro suficiente." << endl;
        }
    } else {
        cout << "A Bateria na Zona " << getZonaRef()->getTipoZona() << " ja atingiu o nivel maximo." << endl;
    }
}

bool Bateria::capMaxReach(const string type) {
    if(eletrProd >= getCapMax()){
        cout << "A Bateria na Zona " << getZonaRef()->getTipoZona() << " atingiu a capacidade maxima de eletricidade." << endl;
        while(eletrProd > getCapMax()) {
            removeEletrProd(1);
            getZonaRef()->withdrawEletr(1);
        }
        return true;
    } else {
        if(type == "elec") {
            addEletrProd(1);
            return false;
        } else if(type == "barg"){
            addEletrProd(3);
            return false;
        }
    }
    return false;
}