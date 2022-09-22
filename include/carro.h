#ifndef __CARRO_H__
#define __CARRO_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct carro{

    char marca[50];
    char placa[50];
    char cor[50];
    char modelo[50];
    char ano[50];
    int id;
    bool alugado;
}Carro;

typedef struct lstCarros{

    int qtd;
    Carro* carros;

}LstCarros;

#define criar_assinatura_func(field) void pesquisa_##field(char* nome,LstCarros carros);
criar_assinatura_func(placa)

criar_assinatura_func(marca)

criar_assinatura_func(cor)

criar_assinatura_func(ano)

criar_assinatura_func(modelo)

void printCarros(LstCarros lstCarros);
void printCarro(Carro car);
LstCarros* carregaCarros(char path[]);

#endif