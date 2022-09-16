#include"carro.h"

LstCarros* carregaCarros(char path[]){

    LstCarros* lstCarro = (LstCarros*)calloc(1,sizeof(LstCarros));
    FILE* fp = NULL;
    Carro* car;

    fp = fopen(path,"r");
    if(fp == NULL){
        fprintf(stderr, "entradaCarro : Erro ao abir arquivo de entrada\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp,"%d",&lstCarro->qtd);
    lstCarro->carros = (Carro*)calloc(lstCarro->qtd,sizeof(Carro));

    for (int i = 0; i < lstCarro->qtd; i++){
        car = &(lstCarro->carros[i]);

        fscanf(fp,"%d %s %s %s %s %d\n",&(car->id),car->marca,car->placa,car->cor,car->modelo,&(car->ano));    
        car->alugado = 0;
        // string2car(&(lstCarro->carros[i]),fp);  
    }
    
    fclose(fp);
    return lstCarro;

}

void printCarros(LstCarros lstCarros){

    Carro car;
    for (int i = 0; i < lstCarros.qtd; i++)
    {
        car = lstCarros.carros[i];
        if(car.alugado == 0){
            printf("\tCarro: %d\n"
                "\t\tMarca: %s\n"
                "\t\tPlaca: %s\n"
                "\t\tCor: %s\n"
                "\t\tModelo: %s\n"
                "\t\tAno: %d\n",car.id,car.marca,car.placa,car.cor,car.modelo,car.ano);
        }
    }
}