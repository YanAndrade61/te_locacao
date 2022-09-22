#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lista.h"


/*Cria lista vazia*/
Lista* criaL(){
    Lista* l = (Lista*)calloc(1,sizeof(Lista));
    l->primeiro = (Celula*)malloc(sizeof(Celula));
    l->ultimo=l->primeiro;
    l->ultimo->prox = NULL;
    return l;
}

/*Verifica se a lista esta vazia*/
int vaziaL(Lista l){
    return (l.primeiro == l.ultimo);
}

/*Insere o Caso na lista*/
void insereI(Locacao x,Lista* l){
    l->ultimo->prox = (Celula*)malloc(sizeof(Celula));
    l->ultimo = l->ultimo->prox;
    l->ultimo->c = x;
    l->ultimo->c.carros.carros = x.carros.carros;
    l->ultimo->prox = NULL; 
}

/*Retira Caso da lista*/
void retiraI(Celula* C, Lista* l, Locacao* x){
    
    Celula* aux = C->prox;

    *x = aux->c;
    C->prox = aux->prox;
    if(C->prox == NULL){
        l->ultimo = C;
    }
    free(aux);
}

/*Destroi lista*/
void destroiL(Lista* l){

    Celula* aux = l->primeiro->prox;

    while(aux != NULL){
        free(l->primeiro);
        l->primeiro = aux;
        aux = aux->prox;
    }    
    if (l->primeiro != NULL){
        free(l->primeiro);
    }
}

/*Imprime lista no terminal*/
void imprimeL(Lista* l){

    
    Celula* auxC = l->primeiro->prox;
    printf("Locacoes:\n");

    while(auxC != NULL)
    {
        printf("---------------------\n");
        printf("%s %s %s\n",auxC->c.name,auxC->c.date,auxC->c.time);
        printCarros(auxC->c.carros);
        auxC = auxC->prox;
    }
    printf("Press enter to continue...\n");
    
    //Limpar buffer
    int c;
    while((c = getchar() )!= '\n' && c != EOF);
    scanf("%lc",&c);
}