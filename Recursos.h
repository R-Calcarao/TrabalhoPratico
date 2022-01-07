//
// Created by ACER on 26/12/2021.
//

#ifndef PRATICOTRABALHO_RECURSOS_H
#define PRATICOTRABALHO_RECURSOS_H


class Recursos {

    float money=1000;
    float madeira=5;
    float ferro=100;
    float barraAco=70;
    float carvao=1000;
    int vigaMadeira=200;
    float eletricidade=0;

public:


    float getMoney() const{
        return money;
    }

    void withdrawMoney(const float cost) {
        money = money - cost;
    }

    void addMoney(const float add) {
        money = money + add;
    }

    float getMadeira() const{
        return madeira;
    }

    void withdrawMadeira(const float cost) {
        madeira = madeira - cost;
    }

    void addMadeira(const float add) {
        madeira=madeira+add;
    }

    void addElectr(const float add) {
        eletricidade = eletricidade + add;
    }

    float getFerro() const{
        return ferro;
    }

    void withdrawFerro(const float cost) {
        ferro = ferro - cost;
    }

    void addFerro(const float add) {
        ferro = ferro + add;
    }

    float getBarraAco() const{
        return barraAco;
    }

    void addBarraAco(const float add) {
        barraAco = barraAco + add;
    }

    void withdrawAco(const float cost ){
        barraAco = barraAco - cost;
    }

    float getCarvao() const{
        return carvao;
    }

    void withdrawCarvao(const float cost){
        carvao = carvao - cost;
    }

    void addCarvao(const float add) {
        carvao = carvao + add;
    }

    int getVigaMadeira() const{
        return vigaMadeira;
    }

    void addViga(const int add) {
        vigaMadeira = vigaMadeira + add;
    }

    void withdrawVigas(const int cost) {
        vigaMadeira = vigaMadeira - cost;
    }

    float getEletricidade() const{
        return eletricidade;
    }

    void withdrawEletr(const float cost) {
        eletricidade = eletricidade - cost;
    }

};


#endif //PRATICOTRABALHO_RECURSOS_H
