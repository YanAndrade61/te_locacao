#ifndef __CARRO_H__
#define __CARRO_H__
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct carro{

    char marca[50];
    char placa[50];
    char cor[50];
    char modelo[50];
    int ano;
    int id;
    bool alugado;
}Carro;

typedef struct lstCarros{

    int qtd;
    Carro* carros;

}LstCarros;

void printCarros(LstCarros lstCarros);
LstCarros* carregaCarros(char path[]);

#endif