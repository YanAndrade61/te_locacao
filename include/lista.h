#ifndef __LISTA_H__
#define __LISTA_H__

#include"locacao.h"
#include"carro.h"

typedef struct lista Lista;
typedef struct celula Celula;

typedef struct locacao{

    char name[100];
    char date[12];
    char time[12];
    LstCarros carros;

}Locacao;

struct celula{

    Locacao c;
    Celula* prox;

};

struct lista{

    int tam;
    Celula* primeiro;
    Celula* ultimo;

};

int vaziaL(Lista);
Lista* criaL();
void insereI(Locacao, Lista*);
void retiraI(Celula*, Lista*, Locacao*);
void destroiL(Lista*);
void imprimeL(Lista*);

#endif