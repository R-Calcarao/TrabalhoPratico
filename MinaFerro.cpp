//
// Created by ACER on 23/12/2021.
//

#include "MinaFerro.h"
#include "Zona.h"

void MinaFerro::newDay() {
    Edificio::newDay();
    bool TrueFalse = (rand() % 100) < ProbCollap;
    if (TrueFalse) {
        cout << "O edificio " << getTipo() << " desabou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
    } else if (getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    } else if (getZonaRef()->getTipoZona() == "fav" && !getDealState()) {
        TrueFalse = (rand() % 100) < 20;
        if (TrueFalse) {
            if(getFerroProd() <= getZonaRef()->getFerro() && getFerroProd() != 0) {
                getZonaRef()->withdrawFerro(getFerroProd());
                cout << "A Mina de Ferro foi assaltada na Zona " << getZonaRef()->getTipoZona() << endl;
                cout << "Prejuizo de " << getFerroProd() << " kg de Ferro" << endl;
                removeFerroProd(getFerroProd());//Esvaziar o armazem
                cout << endl;
                cout << "A Mafia da Zona proposeram-lhe uma parceria de lavagem de dinheiro..." << endl;
                cout << "Embora seja extremamente lucrativa, ha uma grande chance de ser apanhado pelas autoridades!" << endl;
                cout << "Deseja aceitar?(S/N): ";
                char aux;
                cin >> aux;
                if(aux == 'S'){
                    cout << "Parceria realizada, boa sorte!" << endl;
                    deal = true;
                } else {
                    cout << "Parceria negada." << endl;
                }
            } else {
                cout << "Houve uma tentativa de assalto na Mina de Ferro na Zona " << getZonaRef()->getTipoZona() << endl;
            }
        }
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

    } else if(getZonaRef()->haveMiner() && getZonaRef()->getTipoZona() == "fav" && getState() && getFerroProd() < getCapMax() && getDealState()){

        bool TrueFalse = (rand() % 100) < 30;
        getZonaRef()->addFerro(getProductSize());
        addFerroProd(getProductSize());
        if(TrueFalse) {
            cout << "Foi apanhado pelas Autoridades." << endl;
            exit(-1);
        } else {
            int f = (rand() % 500) + 1;
            getZonaRef()->addMoney(f);
            cout << f << " euros, foram enviados pela Mafia." << endl;
        }


    } else if (getZonaRef()->haveMiner() && getState() && getFerroProd() < getCapMax()) {

        getZonaRef()->addFerro(getProductSize());
        addFerroProd(getProductSize());

    } else if(!getZonaRef()->haveMiner()){
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
