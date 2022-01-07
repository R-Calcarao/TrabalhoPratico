//
// Created by ACER on 23/12/2021.
//

#ifndef PRATICOTRABALHO_ZONA_H
#define PRATICOTRABALHO_ZONA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "Trabalhadores.h"
#include "Mineiro.h"
#include "Lenhador.h"
#include "Operario.h"
#include "Edificio.h"
#include "MinaCarvao.h"
#include "MinaFerro.h"
#include "Bateria.h"
#include "Fundicao.h"
#include "Serracao.h"


using namespace std;

class Recursos;
class Ilha;

class Zona {

    vector<Trabalhadores* > TrabalhadoresDaZona;
    vector<Edificio* > EdificioDaZona;
    Recursos* recursos;
    Ilha* ilha;
    int N_edificios;
    int linha;
    int coluna;
    const string tipo;
    int day=1;

public:

    Zona(const string t,const int linha, const int coluna)  : tipo(t),linha(linha),coluna(coluna){
        N_edificios=0;
    };

    void pointToIlha(Ilha* abc){
        ilha = abc;
    }

    void pointToRecursos(Recursos* abc){
        recursos = abc;
    }

    void addTrabalhador(const string &t, const int dia);


    int workerCost(const string t){ //Recebe o tipo de Trabalhador contratado e dá return do preço do mesmo
                                    //que será descontado no dinheiro do Player
        if(t=="miner"){
            return 10;
        } else if(t=="oper"){
            return 15;
        } else if(t=="len"){
            return 20;
        }
        return 0;
    }

    void addEdificio(const string &t);

    void lvlEdi(){
        if(N_edificios != 0){
            for(auto e = EdificioDaZona.begin(); e<EdificioDaZona.end(); e++){
                (*e)->lvlUp();
            }
        } else {
            cout << "A Zona " << getTipoZona() << " nao tem nenhum edificio." << endl;
        }
    }

    void moveToHere(Trabalhadores* abc){//Pega num determinado Worker do pasto e mete-o nesta zona
                                        //recebemo-lo em ponteiro e fazemos push_back e ele passa a apontar
                                        //para esta zona, na Ilha faz-se o erase no vector onde o Trabalhador estava antes
        TrabalhadoresDaZona.push_back(abc);
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() << " movido para " << getTipoZona() << "\n" << endl;
        (*e)->entrarNaZona(this);//Passa a apontar para esta zona agora
    }

    void showWorkers() const {//Corre o Vetor dos Trabalhadores de Zona
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            cout << "Trabalhadores n@ " << getTipoZona() << " : " << (*e)->getTipo() << "." << (*e)->getContractDay() << endl;
        }
    }

    int NumbWorkers() const {//Conta o numero de trabalhadores da zona
        int count=0;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            count++;
        }
        return count;
    }

    int getNumEdificios() const{
        return N_edificios;
    }

    bool iHaveThisId(const int i){//Recebe um id por argumento e corre o vetor de Trabalhadores para ver se tem
                                 // se tiver dá return de true.
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            if((*e)->getId()==i){
                return true;
            }
        }
        return false;
    }

    Trabalhadores* passWorkerRef(const int i){//Auxiliar no processo de movimentar o Trabalhador para outra zona
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            if((*e)->getId()==i){
                return *e;
            }
        }
        return nullptr;
    }

    void removeWorker(const int i){//Auxiliar no processo de mover Trabalhador de Zona
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++){
            if((*e)->getId()==i){
                TrabalhadoresDaZona.erase(e);
            }
        }
    }

    void removeEdificio(){//Para o Pantano
        for(auto e = EdificioDaZona.begin(); e<EdificioDaZona.end(); e++){
                delete *e;
                EdificioDaZona.erase(e);
        }
        N_edificios--;
    }

    void vendeEdificio();

    virtual void newDay(){//Dar inicio ao Trabalhado dos Trabalhadores da Zona, é chamada uma função Virtual..
        day++;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++){
            (*e)->newWorkDay();
        }
        for(auto e = EdificioDaZona.begin(); e<EdificioDaZona.end(); e++){
            (*e)->newDay();
        }
    }

    virtual bool HaveProduceThisDay(){}

    void produzir(){
        for(auto e = EdificioDaZona.begin(); e<EdificioDaZona.end(); e++){
            (*e)->produzir();
        }
    }

    void ligaEdi(){
        if(N_edificios != 0){
            for(auto e = EdificioDaZona.begin(); e < EdificioDaZona.end(); e++){
                (*e)->ligaEdi();
                cout << "Edificio " << (*e)->getTipo() << " ligado." << endl;
            }
        } else {
            cout << "A Zona " << getTipoZona() << " nao tem nenhum edificio." << endl;
        }
    }

    void desligaEdi(){
        if(N_edificios != 0){
            for(auto e = EdificioDaZona.begin(); e < EdificioDaZona.end(); e++){
                (*e)->desligaEdi();
                cout << "Edificio " << (*e)->getTipo() << " desligado." << endl;
            }
        } else {
            cout << "A Zona " << getTipoZona() << " nao tem nenhum edificio." << endl;
        }
    }

    bool CapMaxReach(const string tipoEdi){
        for(auto e = EdificioDaZona.begin(); e < EdificioDaZona.end(); e++){
            if((*e)->capMaxReach(tipoEdi)){
                return true;
            }
        }
        return false;
    }

    void fireAllWorkers(){//Para o pantano
        int tam = TrabalhadoresDaZona.size();
        for(int i = 0; i < tam; i++){
            auto e = TrabalhadoresDaZona[i];
            cout << (*e).getTipo() << " - " << (*e).getId() << " ,pediu demissao na Zona -> " << getTipoZona() << endl;
            delete e;
        }
        TrabalhadoresDaZona.clear();
    }

    void fireWorker(const int id){//Caso um Trabalhador de demita num dia de Trabalho
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++){
            if((*e)->getId()==id){
                delete *e;
                TrabalhadoresDaZona.erase(e);
            }
        }
    }

    string getWorkerId() {
        ostringstream oss;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            oss << (*e)->getId() << " ";
        }
        return oss.str();
    }

    string getTipoZona() const{
        return tipo;
    }

    string getTipoEdificio() const{
        if(N_edificios == 1){
            auto e = (EdificioDaZona.end()-1);
            return (*e)->getTipo();
        } else {
            return " ";
        }
    }

    virtual string getAsString() {
        ostringstream oss;
        oss << endl;
        oss << "Dia: " <<getDay() << endl;
        oss << "Tipo de Zona: " << getTipoZona() << endl;
        oss << "Trabalhadores da Zona:" << endl;
        for(auto e = TrabalhadoresDaZona.begin(); e<TrabalhadoresDaZona.end(); e++) {
            oss <<  "   Id: " << (*e)->getId() << "." << (*e)->getContractDay() << " - " << (*e)->getTipo() << endl;
        }
        oss << "Edificio na Zona: " << endl;
        for(auto e = EdificioDaZona.begin(); e<EdificioDaZona.end(); e++) {
            oss <<  "   Tipo - " << (*e)->getTipo() << endl;
        }
        return oss.str();
    }

    int getDay() const{
        return day;
    }

    int getNumbLen() const{
        int count=0;
        for(auto e = TrabalhadoresDaZona.begin(); e < TrabalhadoresDaZona.end(); e++){
            if((*e)->getTipo() == "len"){
                count++;
            }
        }
        return count;
    }

    int getNumbLenResting() const{
        int count=0;
        for(auto e = TrabalhadoresDaZona.begin(); e < TrabalhadoresDaZona.end(); e++){
            if((*e)->getTipo() == "len" && (*e)->Resting()){
                count++;
            }
        }
        return count;
    }

    bool haveMiner() const{
        for(auto e = TrabalhadoresDaZona.begin(); e < TrabalhadoresDaZona.end(); e++){
            if((*e)->getTipo() == "miner"){
                return true;
            }
        }
        return false;
    }

    bool haveOper() const{
        for(auto e = TrabalhadoresDaZona.begin(); e < TrabalhadoresDaZona.end(); e++){
            if((*e)->getTipo() == "oper"){
                return true;
            }
        }
        return false;
    }

    int getMadeira()const;

    int getVigas() const;

    void addMadeira(const float add);

    int getMoney()const;

    void withdrawMoney(const float cost);

    void withdrawEletr(const float cost);

    void withdrawViga(const int cost);

    void withdrawMadeira(const float cost);

    void addBarraAco(const float add);

    void addViga(const int add);

    void withdrawCarvao(const float cost);

    int getFerro()const;

    void addFerro(const float add);

    void withdrawFerro(const float cost);

    int getCarvao()const;

    void addCarvao(const float add);

    void addEletrc(const float add);

    bool HavemnAround();

    bool HaveflrAround();

    bool HavebatAround();

    bool HavebarragemAround();

};


#endif //PRATICOTRABALHO_ZONA_H
