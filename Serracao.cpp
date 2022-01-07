

#include "Serracao.h"
#include "Zona.h"



void Serracao::produzir() {
    Edificio::produzir();
    if(getZonaRef()->getNumbLen() - getZonaRef()->getNumbLenResting() > 0 && getState()) {
        if(getZonaRef()->getMadeira() >= 2) {
            getZonaRef()->withdrawMadeira(2);
            getZonaRef()->addViga(1);
        } else if(getZonaRef()->getMadeira() < 2){
            cout << "Nao tem Madeira suficiente para produzir Vigas." << endl;
        }
    } else if(getZonaRef()->getNumbLen() - getZonaRef()->getNumbLenResting() <= 0){
        cout << "Nao tem nenhum Lenhador para criar Vigas de Madeira na Serracao ou tirou o dia de folga." << endl;
    } else if(!getState()) {
        cout << "A Serracao na zona " << getZonaRef()->getTipoZona() << " ,esta desligada." << endl;
    }
}