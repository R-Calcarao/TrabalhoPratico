
#include "MinaCarvao.h"
#include "Zona.h"

void MinaCarvao::newDay() {
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

void MinaCarvao::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveMiner() && getZonaRef()->getTipoZona() == "mnt" && getState() && getCarvaoProd() < getCapMax()) {
        getZonaRef()->addCarvao(getProductSize()*2);
        addCarvaoProd(getProductSize()*2);
    } else if(getZonaRef()->haveMiner() && getZonaRef()->getTipoZona() == "dsr" && getState() && getCarvaoProd() < getCapMax()) {
        getZonaRef()->addCarvao(getProductSize()*.5);
        addCarvaoProd(getProductSize()*.5);
    } else if (getZonaRef()->haveMiner() && getState() && getCarvaoProd() < getCapMax()) {
            getZonaRef()->addCarvao(getProductSize());
            addCarvaoProd(getProductSize());
    }else if(!getZonaRef()->haveMiner()){
        cout << "Falta um Mineiro na Zona " << getZonaRef()->getTipoZona() << endl;
    } else if(getCarvaoProd() >= getCapMax()) {
        cout << "A Mina de Carvao na Zona " << getZonaRef()->getTipoZona() << " atingiu a capacidade maxima de carvao." << endl;
    } else if(!getState()) {
        cout << "A Mina de Carvao na zona " << getZonaRef()->getTipoZona() << " ,esta desligada." << endl;
    }
    if(getCarvaoProd() > getCapMax()) {
        while(getCarvaoProd() > getCapMax()) { // Para nunca superar o limite
            removeCarvaoProd(1);
            getZonaRef()->withdrawCarvao(1);
        }
    }
}

void MinaCarvao::lvlUp() {
    Edificio::lvlUp();
    if(getLvl() != 5){
        if(getZonaRef()->getMoney() >= getLvlPrice()
         && getZonaRef()->getVigas() >= 1) {

            getZonaRef()->withdrawViga(1);
            getZonaRef()->withdrawMoney(getLvlPrice());
            addProductSize();
            addCapMax(10);
            addLvl();
            cout << "Mina de Carvao na Zona " << getZonaRef()->getTipoZona() << " evoluiu." << endl;
            cout << "Nivel: " << getLvl() << endl;
            cout << "Capacidade Maxima: " << getCapMax() << " kg" << endl;
            cout << "Quantidade de Producao: " << getProductSize() << endl;

        } else if(getZonaRef()->getMoney() < getLvlPrice()) {
            cout << "Nao tem dinheiro suficiente." << endl;
        } else if(getZonaRef()->getVigas() < 1) {
            cout << "Nao tem vigas suficientes." << endl;
        }
    } else {
        cout << "A Mina de Carvao na Zona " << getZonaRef()->getTipoZona() << " ja atingiu o nivel maximo." << endl;
    }
}