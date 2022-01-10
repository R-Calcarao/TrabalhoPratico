#include <iostream>
#include <cstdlib>
#include "Ilha.h"


int main() {

   // cout << RED << "hello world" << RESET << endl;

    Ilha I(5,5);

    int linha;
    int coluna;
    int id;
    int option;
    float quant;
    string tipo;








   while(1){
        cout << "1 - Contratar Worker. (oper/len/miner)" << endl;
        cout << "2 - Mover Worker." << endl;
        cout << "3 - Listar Zona." << endl;
        cout << "4 - Construir Edificio. (mnC/mnF/bat/fun/serra/barg/elec)" << endl;
        cout << "5 - New Day." << endl;
        cout << "6 - Produzir." << endl;
        cout << "7 - Ligar Edificio." << endl;
        cout << "8 - Desligar Edificio." << endl;
        cout << "9 - Vender Recursos." << endl;
        cout << "10 - Evoluir Edificio.  (barg/mnC/mnF/bat)" << endl;
        cout << "11 - Vender Edificio." << endl;
        cout << ">>  ";
        scanf("%d",&option);

        switch (option) {


            case 1:
                cout << "Tipo: ";
                cin >> tipo;
                I.contWorker(tipo);
                I.showIlha();
                break;

            case 2:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                cout << "Id: ";
                scanf("%d", &id);
                I.moveWorker(id, linha, coluna);
                I.showIlha();
                break;

            case 3:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.listZona(linha, coluna);
                I.showIlha();
                break;

            case 4:
                cout << "Tipo: ";
                cin >> tipo;
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.addEdi(tipo,linha,coluna);
                I.showIlha();
                break;

            case 5:
                I.newDay();
                I.showIlha();
                break;

            case 6:
                I.produzir();
                I.showIlha();
                break;

            case 7:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.ligaEdi(linha,coluna);
                I.showIlha();
                break;

            case 8:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.desligaEdi(linha,coluna);
                I.showIlha();
                break;

            case 9:
                cout << "Tipo: ";
                cin >> tipo;
                cout << "Quanto: ";
                scanf("%f", &quant);
                I.vendeRecurso(tipo,quant);
                I.showIlha();
                break;

            case 10:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.lvlUpEdi(linha,coluna);
                I.showIlha();
                break;

            case 11:
                cout << "Linha: ";
                scanf("%d", &linha);
                cout << "Coluna: ";
                scanf("%d", &coluna);
                I.vendeEdificio(linha,coluna);
                I.showIlha();
                break;

            case 0:
                exit(1);
        }
    }

}
