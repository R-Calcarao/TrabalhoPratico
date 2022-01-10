//
// Created by ACER on 05/01/2022.
//

#include "Barragem.h"
#include "Zona.h"

void Barragem::newDay() {
    Edificio::newDay();
    bool TrueFalse;
    if (getZonaRef()->getDay() - getConstrucDay() >= 8) {
        TrueFalse = (rand() % 100) < ProbCollap;
        if (TrueFalse) {

            cout << "O edificio " << getTipo() << " desabou devido as cheias na Zona " << getZonaRef()->getTipoZona()
                 << endl;
            getZonaRef()->removeEdificio();

        } else if (getZonaRef()->getDay() - getConstrucDay() >= 10 && getZonaRef()->getTipoZona() == "pnt") {

            cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
            getZonaRef()->removeEdificio();
            getZonaRef()->fireAllWorkers();

        }
    }

    if (getZonaRef()->getTipoZona() == "fav" && !getDealState()){
        TrueFalse = (rand() % 100) < 20;
        if (getEletrProd() <= getZonaRef()->getEletr() && getEletrProd() != 0) {
            getZonaRef()->withdrawEletr(getEletrProd());
            cout << "A Barragem foi assaltada na Zona " << getZonaRef()->getTipoZona() << endl;
            cout << "Prejuizo de " << getEletrProd() << " KWh de Eletricidade" << endl;
            removeEletrProd(getEletrProd());//Esvaziar o armazem
            cout << endl;
            cout << "A Mafia da Zona proposeram-lhe uma parceria de lavagem de dinheiro..." << endl;
            cout << "Embora seja extremamente lucrativa, ha uma grande chance de ser apanhado pelas autoridades!" << endl;
            cout << "Deseja aceitar?(S/N): ";
            char aux;
            cin >> aux;
            if (aux == 'S') {
                cout << "Parceria realizada, boa sorte!" << endl;
                deal = true;
            } else {
                cout << "Parceria negada." << endl;
            }
        } else {
            cout << "Houve uma tentativa de assalto na Barragem na Zona " << getZonaRef()->getTipoZona() << endl;
        }
      }
    }



void Barragem::produzir() {
    Edificio::produzir();
    if(getZonaRef()->getDay() - getConstrucDay() > 3 && getZonaRef()->getDay()%2 != 0) {
        cout << "A Barragem parou de produzir eletricidade pois uma viga de madeira ficou presa." << endl;
        fuctional = false;
    }
    if(getZonaRef()->haveOper()
    && getZonaRef()->getNumbLen() - getZonaRef()->getNumbLenResting() > 0
    && getState()
    && isFuctional()
    && getZonaRef()->HavebatAround()) {

        if(getZonaRef()->getTipoZona() == "mnt") {

            getZonaRef()->addEletrc(getProductSize()*2);
            addEletrProd(getProductSize()*2);

        } else if(getZonaRef()->getTipoZona() == "fav" && getDealState()){

            bool TrueFalse = (rand() % 100) < 30;
            getZonaRef()->addEletrc(getProductSize());
            addEletrProd(getProductSize());

            if(TrueFalse) {

                cout << "Foi apanhado pelas Autoridades." << endl;
                exit(-1);

            } else {

                int f = (rand() % 500) + 1;
                getZonaRef()->addMoney(f);
                cout << f << " euros, foram enviados pela Mafia." << endl;

            }
        } else {

            getZonaRef()->addEletrc(getProductSize());
            addEletrProd(getProductSize());

        }
    } else if(!getZonaRef()->haveOper()) {
        cout << "A Barragem na zona " << getZonaRef()->getTipoZona() << " ,nao tem um Operario presente." << endl;
    } else if(getZonaRef()->getNumbLen() - getZonaRef()->getNumbLenResting() <= 0) {
        cout << "A Barragem na zona " << getZonaRef()->getTipoZona() <<" ,nao tem presente um Lenhador ou o mesmo tirou o dia de folga." << endl;
    } else if(!getState()) {
        cout << "A Barragem na zona " << getZonaRef()->getTipoZona() << " ,esta desligada." << endl;
    } else if(!isFuctional() && getZonaRef()->getNumbLen() - getZonaRef()->getNumbLenResting() > 0) { //Só lá vai se algum lenhador estiver a trabalhar naquele dia
        cout << "Um Lenhador retirou a viga de madeira e a Barragem ja esta funcional." << endl;
        fuctional = true;
    }
}

void Barragem::lvlUp() {
    Edificio::lvlUp();
    if(getLvl() != 5){
        if(getZonaRef()->getMoney() >= getLvlPrice() && getZonaRef()->getVigas() >= 5) {

            getZonaRef()->withdrawMoney(getLvlPrice());
            getZonaRef()->withdrawViga(5);
            addProductSize();
            addLvl();
            cout << "Barragem na Zona " << getZonaRef()->getTipoZona() << " evoluiu." << endl;
            cout << "Nivel: " << getLvl() << endl;
            cout << "Capacidade de Producao: " << getProductSize() << endl;

        } else if(getZonaRef()->getMoney() < getLvlPrice()) {
            cout << "Nao tem dinheiro suficiente." << endl;
        } else if(getZonaRef()->getVigas() < 5) {
            cout << "Nao tem vigas suficientes." << endl;
        }
    } else {
        cout << "A Barragem na Zona " << getZonaRef()->getTipoZona() << " ja atingiu o nivel maximo." << endl;
    }
}
