//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_TRABALHADORES_H
#define PRATICOTRABALHO_TRABALHADORES_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;
class Zona; // Existe uma classe que é Zona

class Trabalhadores {

    int price;
    static int Serie;
    int d;
    int id;
    int  contracDay;
    string tipo;
    Zona* zona = nullptr;

public:

    Trabalhadores() = delete;
    Trabalhadores(const string tipo, const int price,  int contracDay);

    virtual void newWorkDay(){}

    //virtual void letsWork(){}

    virtual bool Resting(){}; //Saber se o Lenhador esta a trabalhar

    int getId() const {
        return id;
    }

    int getContractDay() const {
        return contracDay;
    }

    string getTipo() const {
        return tipo;
    }

    int getPrice() const {
        return price;
    }

    void entrarNaZona(Zona* abc);

    Zona* giveZonaRef(){
        return zona;
    }

    void sairDaZona(){
        zona = nullptr;
    }

};


#endif //PRATICOTRABALHO_TRABALHADORES_H
