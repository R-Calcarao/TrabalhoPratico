//
// Created by ACER on 23/12/2021.
//

#include "Ilha.h"
#include "CentralEletrica.h"
#include "Barragem.h"

void Zona::addTrabalhador(const string &t,const int dia) { //Recebe tipo e quantidade de dinheiro do Player

    if(t=="miner" && recursos->getMoney() >= 10){

        recursos->withdrawMoney(10);
        TrabalhadoresDaZona.push_back(new Mineiro(dia));//Push_back no vetor Trabalhadores da Zona(Pasto)
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() << " euros" <<"\n" <<endl;
        (*e)->entrarNaZona(this);//Trabalhador vai passar a apontar para a Zona em que se encontra

    } else if(t=="len" && recursos->getMoney() >= 20){

        recursos->withdrawMoney(20);
        TrabalhadoresDaZona.push_back(new Lenhador(dia));
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() << " euros" <<"\n" <<endl;
        (*e)->entrarNaZona(this);


    } else if(t=="oper" && recursos->getMoney() >= 15){

        recursos->withdrawMoney(15);
        TrabalhadoresDaZona.push_back(new Operario(dia));
        auto e = (TrabalhadoresDaZona.end()-1);
        cout << (*e)->getTipo() <<" contratado" << " por " << (*e)->getPrice() << " euros" <<"\n" <<endl;
        (*e)->entrarNaZona(this);

    } else {
        cout << "Tipo de trabalhador indisponivel(oper/miner/len), ou dinheiro insuficiente." << endl;
    }
}

float Zona::getMadeira() const{
    return recursos->getMadeira();
}

float Zona::getMoney() const{
    return recursos->getMoney();
}

void Zona::addMoney(const float add) const {
    recursos->addMoney(add);
}

int Zona::getVigas() const {
    return recursos->getVigaMadeira();
}

float Zona::getBarraAco() const {
    return recursos->getBarraAco();
}

void Zona::withrawAco(const float cost) {
    recursos->withdrawAco(cost);
}

void Zona::withdrawMoney(const float cost) {
    recursos->withdrawMoney(cost);
}

void Zona::withdrawEletr(const float cost) {
    recursos->withdrawEletr(cost);
}

void Zona::withdrawViga(const int cost) {
    recursos->withdrawVigas(cost);
}

void Zona::addMadeira(const float add) {
    recursos->addMadeira(add);
}

void Zona::withdrawMadeira(const float cost) {
    recursos->withdrawMadeira(cost);
}

void Zona::addBarraAco(const float add) {
    recursos->addBarraAco(add);
}

void Zona::addViga(const int add) {
    recursos->addViga(add);
}

float Zona::getFerro() const{
    return recursos->getFerro();
}

float Zona::getCarvao() const {
    return recursos->getCarvao();
}

float Zona::getEletr() const {
    return recursos->getEletricidade();
}

void Zona::addFerro(const float add) {
    recursos->addFerro(add);
}

void Zona::addCarvao(const float add) {
    recursos->addCarvao(add);
}

void Zona::addEletrc(const float add) {
    recursos->addElectr(add);
}

void Zona::withdrawCarvao(const float cost) {
    recursos->withdrawCarvao(cost);
}

void Zona::withdrawFerro(const float cost) {
    recursos->withdrawFerro(cost);
}

bool Zona::HavemnAround() {
    if(ilha->HaveMnAround(linha,coluna)){
        return true;
    } else {
        return false;
    }
}

bool Zona::HaveflrAround() {
    if(ilha->HaveflrAround(linha,coluna)){
        return true;
    } else {
        return false;
    }
}

bool Zona::HavebatAround() {
    if(ilha->HavebatAround(linha,coluna)){
        return true;
    } else {
        return false;
    }
}

bool Zona::HavebarragemAround() {
    if(ilha->HavebarragemAround(linha,coluna)){
        return true;
    } else {
        return false;
    }
}

void Zona::addEdificio(const string &t) {

    if(N_edificios==0) { //Se a zona n tiver edificios

        if(t == "barg" && getTipoZona() == "mnt") {
            if(recursos->getMoney() >= 20 && recursos->getVigaMadeira() >= 24) {
                recursos->withdrawMoney(20);
                recursos->withdrawVigas(24);
                EdificioDaZona.push_back(new Barragem(getDay()));
                cout << "Barragem construida em " << getTipoZona() << endl;
                N_edificios++;
            } else if(recursos->getMoney() < 20) {
                cout << "Nao tem dinheiro suficiente." << endl;
            } else if(recursos->getVigaMadeira() < 24) {
                cout << "Nao tem vigas de madeira suficientes." << endl;
            }
        } else if(t == "barg") {
            if(getTipoZona() == "dsr") {
                cout << "Nao pode construir uma Barragem no Deserto." << endl;
            } else if(recursos->getMoney() >= 10 && recursos->getVigaMadeira() >= 12) {
                recursos->withdrawMoney(10);
                recursos->withdrawVigas(12);
                EdificioDaZona.push_back(new Barragem(getDay()));
                cout << "Barragem construida em " << getTipoZona() << endl;
                N_edificios++;
            } else if(recursos->getMoney() < 10) {
                cout << "Nao tem dinheiro suficiente." << endl;
            } else if(recursos->getVigaMadeira() < 12) {
                cout << "Nao tem vigas de madeira suficientes." << endl;
            }
        } else if(t == "serra") {
            if(recursos->getMoney() >= 10 && recursos->getMadeira() >= 5 && getTipoZona() == "flr") {
                recursos->withdrawMoney(10);
                recursos->withdrawMadeira(5);
                EdificioDaZona.push_back(new Serracao(getDay()));
                cout << "Serracao construida em " << getTipoZona() << endl;
                N_edificios++;
            } else if(recursos->getMoney() < 10) {
                cout << "Nao tem dinheiro suficiente." << endl;
            } else if(recursos->getMadeira() < 5){
                cout << "Nao tem madeira suficiente." << endl;
            } else {
                cout << "So pode construir Serracao em zonas do tipo Floresta." << endl;
            }
        } else if (t == "mnC" && getTipoZona()=="mnt") {
                if(recursos->getVigaMadeira() >= 20) {
                    recursos->withdrawVigas(20);
                    EdificioDaZona.push_back(new MinaCarvao(getDay()));
                    cout << "Mina de Carvao construida em " << getTipoZona() << endl;
                    N_edificios++;
                } else { //Se n houver vigas suficientes
                    float rest = 20 - recursos->getVigaMadeira();
                    cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                    rest = rest*20;
                    cout << "O restante custa: " << rest << " euros" << endl;
                    cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                    char resp;
                    cin >> resp;
                    if(resp == 'S'){
                        if(recursos->getMoney() >= rest){
                            recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                            recursos->withdrawMoney(rest);
                            EdificioDaZona.push_back(new MinaCarvao(getDay()));
                            cout << "Mina de Carvao construida em " << getTipoZona() << endl;
                            N_edificios++;
                        } else {
                            cout << "Nao tem dinheiro suficiente..." << endl;
                        }
                    }
                }
            } else if (t == "mnC") {
            if(recursos->getVigaMadeira() >= 10) {
                recursos->withdrawVigas(10);
                EdificioDaZona.push_back(new MinaCarvao(getDay()));
                cout << "Mina de Carvao construida em " << getTipoZona() << endl;
                N_edificios++;
            } else { //Se n houver vigas suficientes
                float rest = 10 - recursos->getVigaMadeira();
                cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                rest = rest*10;
                cout << "O restante custa: " << rest << " euros" << endl;
                cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                char resp;
                cin >> resp;
                if(resp == 'S'){
                    if(recursos->getMoney() >= rest){
                        recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                        recursos->withdrawMoney(rest);
                        EdificioDaZona.push_back(new MinaCarvao(getDay()));
                        cout << "Mina de Carvao construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "mnF" && getTipoZona()=="mnt") {
            if(recursos->getVigaMadeira() >= 20) {
                recursos->withdrawVigas(20);
                EdificioDaZona.push_back(new MinaFerro(getDay()));
                cout << "Mina de Ferro construida em " << getTipoZona() << endl;
                N_edificios++;
            } else {// Se n houver vigas sufientes
                float rest = 20 - recursos->getVigaMadeira();
                cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                rest = rest*20;
                cout << "O restante custa: " << rest << " euros" << endl;
                cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                char resp;
                cin >> resp;
                if(resp == 'S'){
                    if(recursos->getMoney() >= rest){
                        recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                        recursos->withdrawMoney(rest);
                        EdificioDaZona.push_back(new MinaFerro(getDay()));
                        cout << "Mina de Ferro construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "mnF") {
            if(recursos->getVigaMadeira() >= 10) {
                recursos->withdrawVigas(10);
                EdificioDaZona.push_back(new MinaFerro(getDay()));
                cout << "Mina de Ferro construida em " << getTipoZona() << endl;
                N_edificios++;
            } else {// Se n houver vigas sufientes
                float rest = 10 - recursos->getVigaMadeira();
                cout << "Nao tem vigas de madeira suficientes, faltam-lhe " << rest << " vigas." << endl;
                rest = rest*10;
                cout << "O restante custa: " << rest << " euros" << endl;
                cout << "Pretende pagar as vigas restantes com dinheiro?(S/N): ";
                char resp;
                cin >> resp;
                if(resp == 'S'){
                    if(recursos->getMoney() >= rest){
                        recursos->withdrawVigas(recursos->getVigaMadeira()); //Zerar as vigas umas vez que n há suf...
                        recursos->withdrawMoney(rest);
                        EdificioDaZona.push_back(new MinaFerro(getDay()));
                        cout << "Mina de Ferro construida em " << getTipoZona() << endl;
                        N_edificios++;
                    } else {
                        cout << "Nao tem dinheiro suficiente..." << endl;
                    }
                }
            }
        } else if (t == "bat" && getTipoZona() == "mnt") {
            if(recursos->getVigaMadeira() >= 20 && recursos->getMoney() >= 20) {
                recursos->withdrawMoney(20);
                recursos->withdrawVigas(20);
                EdificioDaZona.push_back(new Bateria(getDay()));
                N_edificios++;
                cout << "Bateria construida em " << getTipoZona() << endl;
            } else if(recursos->getVigaMadeira() < 20){
                cout << "Nao tem Vigas de Madeira suficientes." << endl;
            } else if(recursos->getMoney() < 20){
                cout << "Nao tem dinheiro suficiente." << endl;
            }
        } else if (t == "bat") {
            if(recursos->getVigaMadeira() >= 10 && recursos->getMoney() >= 10) {
                recursos->withdrawMoney(10);
                recursos->withdrawVigas(10);
                EdificioDaZona.push_back(new Bateria(getDay()));
                N_edificios++;
                cout << "Bateria construida em " << getTipoZona() << endl;
            } else if(recursos->getVigaMadeira() < 10){
                cout << "Nao tem Vigas de Madeira suficientes." << endl;
            } else if(recursos->getMoney() < 10){
                cout << "Nao tem dinheiro suficiente." << endl;
            }
        } else if (t == "fun" && getTipoZona()=="mnt") {
            if(recursos->getMoney() >= 20) {
                recursos->withdrawMoney(20);
                cout << "Fundicao construida em " << getTipoZona() << endl;
                EdificioDaZona.push_back(new Fundicao(getDay()));
                N_edificios++;
            } else {
                cout << "Dinheiro insuficiente..." << endl;
            }
        } else if(t == "fun"){
            if(recursos->getMoney() >= 10){
                recursos->withdrawMoney(10);
                cout << "Fundicao construida em " << getTipoZona() << endl;
                EdificioDaZona.push_back(new Fundicao(getDay()));
                N_edificios++;
            } else {
                cout << "Dinheiro insuficiente..." << endl;
            }
        } else if (t == "elec" && getTipoZona() == "mnt") {
            if(recursos->getMoney() >= 30){
                recursos->withdrawMoney(30);
                EdificioDaZona.push_back(new CentralEletrica(getDay()));
                cout << "Central Eletrica construida em " << getTipoZona() << endl;
                N_edificios++;
            } else {
                cout << "Nao tem dinheiro suficiente." << endl;
            }
        } else if(t == "elec"){
            if(recursos->getMoney() >= 15){
                recursos->withdrawMoney(15);
                EdificioDaZona.push_back(new CentralEletrica(getDay()));
                cout << "Central Eletrica construida em " << getTipoZona() << endl;
                N_edificios++;
            } else {
                cout << "Nao tem dinheiro suficiente." << endl;
            }
        } else {
            cout << "Tipo de Edificio nao existente." << endl;
        }
    } else {
        cout << "Esta Zona ja contem um Edificio." << endl;
    }
    if(N_edificios==1) {
        for (auto e = EdificioDaZona.begin(); e < EdificioDaZona.end(); e++) {
            (*e)->pointToRecursos(recursos);
            (*e)->pointToZona(this);
        }
    }
}

void Zona::vendeEdificio() {
    for (auto e = EdificioDaZona.begin(); e < EdificioDaZona.end(); e++) {
        if ((*e)->getTipo() == "mnF") {
            delete *e;
            EdificioDaZona.erase(e);
            N_edificios--;
            cout << "Mina de Ferro demolida na zona " << getTipoZona() << endl;
        } else if((*e)->getTipo() == "mnC"){
            delete *e;
            EdificioDaZona.erase(e);
            N_edificios--;
            cout << "Mina de Carvao demolida na zona " << getTipoZona() << endl;
        } else if ((*e)->getTipo() == "elec") {
            if (getTipoZona() == "mnt") {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(30);
                cout << "30 euros recebidos pelo demolicao da Central na zona " << getTipoZona() << "." << endl;
            } else {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(15);
                cout << "15 euros recebidos pelo demolicao da Central na zona " << getTipoZona() << "." << endl;
            }
        } else if ((*e)->getTipo() == "bat") {
            if (getTipoZona() == "mnt") {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(20);
                cout << "20 euros recebidos pelo demolicao da Bateria na zona " << getTipoZona() << "." << endl;
            } else {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(10);
                cout << "10 euros recebidos pelo demolicao da Bateria na zona " << getTipoZona() << "." << endl;
            }
        } else if ((*e)->getTipo() == "barg") {
            if (getTipoZona() == "mnt") {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(20);
                cout << "20 euros recebidos pelo demolicao da Barragem na zona " << getTipoZona() << "." << endl;
            } else {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(10);
                cout << "10 euros recebidos pelo demolicao da Barragem na zona " << getTipoZona() << "." << endl;
            }
        } else if ((*e)->getTipo() == "fun") {
            if (getTipoZona() == "mnt") {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(20);
                cout << "20 euros recebidos pelo demolicao da Fundicao na zona " << getTipoZona() << "." << endl;
            } else {
                delete *e;
                EdificioDaZona.erase(e);
                N_edificios--;
                recursos->addMoney(10);
                cout << "10 euros recebidos pelo demolicao da Fundicao na zona " << getTipoZona() << "." << endl;
            }
        }
    }
}
