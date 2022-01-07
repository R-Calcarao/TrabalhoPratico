//
// Created by ACER on 23/12/2021.
//

#include "MinaFerro.h"
#include "Zona.h"

void MinaFerro::newDay() {
    Edificio::newDay();
    bool TrueFalse = (rand() % 100) < ProbCollap;
    if(TrueFalse){
        cout << "O edificio " << getTipo() << " desabou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
    }else if(getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    }
}

void MinaFerro::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveMiner() && getZonaRef()->getTipoZona() == "mnt" && getState() && getFerroProd() < getCapMax()) {

        getZonaRef()->addFerro(getProductSize()*2);
        addFerroProd(getProductSize()*2);

    } else if(getZonaRef()->haveMiner() && getZonaRef()->getTipoZona() == "dsr" && getState() && getFerroProd() < getCapMax()) {

        getZonaRef()->addFerro(getProductSize()*.5);
        addFerroProd(getProductSize()*.5);

    } else if (getZonaRef()->haveMiner() && getState() && getFerroProd() < getCapMax()) {

        getZonaRef()->addFerro(getProductSize());
        addFerroProd(getProductSize());

    }else if(!getZonaRef()->haveMiner()){
        cout << "Falta um Mineiro na Zona " << getZonaRef()->getTipoZona() << endl;
    } else if(getFerroProd() >= getCapMax()) {
        cout << "A Mina de Ferro na Zona " << getZonaRef()->getTipoZona() << " atingiu a capacidade maxima de ferro." << endl;
    } else if(!getState()) {
        cout << "A Mina de Ferro na zona " << getZonaRef()->getTipoZona() << " ,esta desligada." << endl;
    }
    if(getFerroProd() > getCapMax()) {

        while(getFerroProd() > getCapMax()) { // Para nunca superar o limite
            removeFerroProd(1);
            getZonaRef()->withdrawFerro(1);
        }

    }
}

void MinaFerro::lvlUp() {
    Edificio::lvlUp();
    if(getLvl() != 5){
        if(getZonaRef()->getMoney() >= getLvlPrice()
           && getZonaRef()->getVigas() >= 1) {

            getZonaRef()->withdrawViga(1);
            getZonaRef()->withdrawMoney(getLvlPrice());
            addProductSize();
            addCapMax(10);
            addLvl();
            cout << "Mina de Ferro na Zona " << getZonaRef()->getTipoZona() << " evoluiu." << endl;
            cout << "Nivel: " << getLvl() << endl;
            cout << "Capacidade Maxima: " << getCapMax() << " kg" << endl;
            cout << "Quantidade de Producao: " << getProductSize() << endl;

        } else if(getZonaRef()->getMoney() < getLvlPrice()) {
            cout << "Nao tem dinheiro suficiente." << endl;
        } else if(getZonaRef()->getVigas() < 1) {
            cout << "Nao tem vigas suficientes." << endl;
        }
    } else {
        cout << "A Mina de Ferro na Zona " << getZonaRef()->getTipoZona() << " ja atingiu o nivel maximo." << endl;
    }
}