//
// Created by ACER on 23/12/2021.
//

#include "CentralEletrica.h"
#include "Zona.h"

void CentralEletrica::newDay() {
    Edificio::newDay();
    if(getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    } else if (getZonaRef()->getTipoZona() == "fav" && !getDealState()) {
        bool TrueFalse = (rand() % 100) < 20;
        if (TrueFalse) {
            if(getCarvaoProd() <= getZonaRef()->getCarvao() && getCarvaoProd() != 0) {
                getZonaRef()->withdrawCarvao(getCarvaoProd());
                cout << "A Central Eletrica foi assaltada na Zona " << getZonaRef()->getTipoZona() << endl;
                cout << "Prejuizo de " << getCarvaoProd() << " kg de Carvao" << endl;
                removeCarvaoProd(getCarvaoProd());//Esvaziar o armazem
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
                cout << "Houve uma tentativa de assalto na Mina de Carvao na Zona " << getZonaRef()->getTipoZona() << endl;
            }
        }
    }
}

void CentralEletrica::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveOper()
       && getZonaRef()->getMadeira() >= 1
       && getZonaRef()->HaveflrAround()
       && getState()
       && getCarvaoProd() < getCapMax()
       && getDealState()
       && getZonaRef()->getTipoZona() == "fav") {

        bool TrueFalse = (rand() % 100) < 30;
        if(TrueFalse) {

            cout << "Foi apanhado pelas Autoridades." << endl;
            exit(-1);

        } else if(getZonaRef()->HavebatAround()) {

            getZonaRef()->withdrawMadeira(1);
            getZonaRef()->addCarvao(1);
            addCarvaoProd(1);
            getZonaRef()->addEletrc(1);

            int f = (rand() % 500) + 1;
            getZonaRef()->addMoney(f);
            cout << f << " euros, foram enviados pela Mafia." << endl;

        } else {

            cout << "Eletricidade perdida na zona -> " << getZonaRef()->getTipoZona() <<" por falta de uma bateria adjacente." << endl;
            getZonaRef()->withdrawMadeira(1);
            getZonaRef()->addCarvao(1);
            addCarvaoProd(1);

            int f = (rand() % 500) + 1;
            getZonaRef()->addMoney(f);
            cout << f << " euros, foram enviados pela Mafia." << endl;

        }


    } else if(getZonaRef()->haveOper()
      && getZonaRef()->getMadeira() >= 1
      && getZonaRef()->HaveflrAround()
      && getState()
      && getCarvaoProd() < getCapMax()){

        if(getZonaRef()->HavebatAround()){

            getZonaRef()->withdrawMadeira(1);
            getZonaRef()->addCarvao(1);
            addCarvaoProd(1);
            getZonaRef()->addEletrc(1);

        } else {

            cout << "Eletricidade perdida na zona -> " << getZonaRef()->getTipoZona() <<" por falta de uma bateria adjacente." << endl;
            getZonaRef()->withdrawMadeira(1);
            getZonaRef()->addCarvao(1);
            addCarvaoProd(1);

        }

    } else {
        if(!getZonaRef()->haveOper()) {
            cout << "A Central Eletrica nao tem nenhum operario a trabalhar." << endl;
        } else if(getZonaRef()->getMadeira() < 1) {
            cout << "A Central Eletrica nao tem materia suficiente." << endl;
        } else if(!getZonaRef()->HaveflrAround()) {
            cout << "A Central nao esta adjacente a nenhuma floresta ou a floresta nao produziu madeira." << endl;
        } else if(getCarvaoProd() >= getCapMax()) {
            cout << "A Central na Zona " << getZonaRef()->getTipoZona() << " atingiu a capacidade maxima de carvao." << endl;
        }
    }
    if(getCarvaoProd() > getCapMax()) {
        while(getCarvaoProd() > getCapMax()) { // Para nunca superar o limite
            removeCarvaoProd(1);
            getZonaRef()->withdrawCarvao(1);
        }
    }
}
