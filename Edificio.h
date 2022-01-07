//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_EDIFICIO_H
#define PRATICOTRABALHO_EDIFICIO_H

#include <string>
#include <sstream>

using namespace std;

class Recursos;
class Zona;

class Edificio {

    const string tipo;
    int lvlPrice;
    int lvl=1;
    int capMax;
    int construcDay;
    Recursos* recursos;
    Zona* zona;
    bool ligado = false;


public:
    Edificio(const string tipo, const int lvlPrice, int capMax, int construcDay) : tipo(tipo),lvlPrice(lvlPrice),
                                                                                   capMax(capMax), construcDay(construcDay){}

    void pointToRecursos(Recursos* abc){
        recursos = abc;
    }

    int getCapMax() const{
        return capMax;
    }

    int getLvlPrice() const{
        return lvlPrice;
    }

    int getLvl() const{
        return lvl;
    }

    void addLvl() {
        lvl++;
    }

    string getTipo() const{
        return tipo;
    }

    int getConstrucDay() const{
        return construcDay;
    }

    void pointToZona(Zona* abc){
        zona = abc;
    }

    Zona* getZonaRef() const{
        return zona;
    }

    void addCapMax(const int add){
        capMax = capMax + add;
    }

    void ligaEdi(){
        ligado = true;
    }

    void desligaEdi(){
        ligado = false;
    }

    bool getState() const{
        return ligado;
    }

     virtual void newDay(){}

     virtual void produzir(){}

     virtual void lvlUp(){}

     virtual bool capMaxReach(const string type){}

};


#endif //PRATICOTRABALHO_EDIFICIO_H
