#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"menu.h"
#include"carro.h"
#include"locacao.h"


int main(int argc, const char* argv[]){

    char path[100];
    int option;
    LstCarros* carros;
    printf("Enter path of car data: ");
    scanf("%s",path);
    carros = carregaCarros(path);

    locacaoSystem(carros);
    
    return 0;

}