#include <stdio.h>
#include <time.h>
#include"locacao.h"

#ifdef _WIN32
    #define CMD "cls"
#else
    #define CMD "clear"
#endif

void getTimeLocation(Locacao* l){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    sprintf(l->date,"%d-%02d-%02d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(l->time,"%02d:%02d:%02d",tm.tm_hour, tm.tm_min, tm.tm_sec);

}

bool estaDisponivel(Carro c){
    return c.alugado;
}

void criaLocacaoMenu(Lista* lstLocacao,LstCarros* carros){

    Locacao l;
    int id;
    printf("Cria locacao\n");
    printf("Escreva seu nome:\n");
    scanf("%s",l.name);
    getTimeLocation(&l);
    printf("Quantos carros [1 - %d]:\n",carros->qtd);
    scanf("%d",&(l.qtd));
    l.carros.carros = (Carro*)calloc(l.qtd,sizeof(Carro));
    printCarros(*carros);
    for (int i = 0; i < l.qtd; i++){
        printf("Selecione um id do carro:");
        scanf("%d",&(id));
        if(id > -1 && id < carros->qtd && !estaDisponivel(carros->carros[id]))
        carros->carros[id].alugado = 1;
        l.carros.carros[i] = carros->carros[id];
    }
    
}

void locacaoSystem(LstCarros* carros){

    int option;
    Lista* lstLocacao;
    criaL(lstLocacao);
    do{
        printf(
        "LOCALIZA SYSTEM:\n"
        "------------\n"
        "[1] Criar locacao\n"
        "[2] Pesquisar carro\n"
        "[3] Visualizar locacoes\n"   
        "[3] Sair\n"   
        "Enter option:");
        scanf("%d",&option);

        switch(option){
            case 1:
                system(CMD);
                criaLocacaoMenu(lstLocacao,carros);
                
                break;
            case 2:
                system("clear");
                printf("Enter path of sudoku game:");
                break;
            case 3:
                system("clear");
                imprimeL(lstLocacao);
                break;
            default:
                printf("Invalid Option");
        }
    }while(option != 3);



}