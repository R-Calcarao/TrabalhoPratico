//
// Created by ACER on 23/12/2021.
//

#include "Fundicao.h"
#include "Zona.h"

void Fundicao::newDay() {
    Edificio::newDay();
    if(getZonaRef()->getDay() - getConstrucDay() == 10 && getZonaRef()->getTipoZona() == "pnt") {
        cout << "O edificio " << getTipo() << " afundou na Zona " << getZonaRef()->getTipoZona() << endl;
        getZonaRef()->removeEdificio();
        getZonaRef()->fireAllWorkers();
    } else if (getZonaRef()->getTipoZona() == "fav" && !getDealState()) {
        bool TrueFalse = (rand() % 100) < 20;
        if (TrueFalse) {
            if(getAcoProd() <= getZonaRef()->getBarraAco() && getAcoProd() != 0) {
                getZonaRef()->withdrawFerro(getAcoProd());
                cout << "A Fundicao foi assaltada na Zona " << getZonaRef()->getTipoZona() << endl;
                cout << "Prejuizo de " << getAcoProd() << " barras de Aco" << endl;
                removeAcoProd(getAcoProd());//Esvaziar o armazem
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
                cout << "Houve uma tentativa de assalto na Fundicao " << getZonaRef()->getTipoZona() << endl;
            }
        }
    }
}

void Fundicao::produzir() {
    Edificio::produzir();
    if(getZonaRef()->haveOper()
       && getZonaRef()->getCarvao() >= .5
       && getZonaRef()->getFerro() >= 1.5
       && getZonaRef()->HavemnAround()
       && getState()
       && getDealState()
       && getZonaRef()->getTipoZona() == "fav") {

        bool TrueFalse = (rand() % 100) < 30;

        getZonaRef()->withdrawCarvao(.5);
        getZonaRef()->withdrawFerro(1.5);
        getZonaRef()->addBarraAco(1);
        addAcoProd(1);

        if(TrueFalse) {
            cout << "Foi apanhado pelas Autoridades." << endl;
            exit(-1);
        } else {
            int f = (rand() % 500) + 1;
            getZonaRef()->addMoney(f);
            cout << f << " euros, foram enviados pela Mafia." << endl;
        }

    }else if(getZonaRef()->haveOper()
              && getZonaRef()->getCarvao() >= .5
              && getZonaRef()->getFerro() >= 1.5
              && getZonaRef()->HavemnAround()
              && getState()) {

        getZonaRef()->withdrawCarvao(.5);
        getZonaRef()->withdrawFerro(1.5);
        getZonaRef()->addBarraAco(1);
        addAcoProd(1);

    } else {
        if(!getZonaRef()->haveOper()) {
            cout << "A Fundicao nao tem nenhum operario a trabalhar." << endl;
        } else if(!getZonaRef()->HavemnAround()){
            cout << "A Fundicao nao esta adjacente a uma mnC e mnF ou a uma elec." << endl;
        }  else if(getZonaRef()->getCarvao() < .5 || getZonaRef()->getFerro() < 1.5) {
            cout << "A Fundicao nao tem a quantidade de materia suficiente." << endl;
        }
    }
}
