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
    scanf("%d",&(l.carros.qtd));
    system(CMD);
    l.carros.carros = (Carro*)calloc(l.carros.qtd,sizeof(Carro));
    printf("Carros disponiveis:\n");
    printCarros(*carros);
    
    for (int i = 0; i < l.carros.qtd; i++){
        printf("Selecione um id do carro:");
        scanf("%d",&(id));
        if(id > -1 && id < carros->qtd && !estaDisponivel(carros->carros[id])){
            carros->carros[id].alugado = 1;
            l.carros.carros[i] = carros->carros[id];
            
        }
    }
    lstLocacao->tam++;
    insereI(l,lstLocacao);

    
}

void pesquisarMenu(LstCarros* carros){

    LstCarros searchCar;
    char caracteristica[50];
    int option;

    
    printf(
        "PESQUISA MENU:\n"
        "------------\n"
        "[1] Marca\n"
        "[2] Placa\n"
        "[3] Cor\n"   
        "[4] Modelo\n"   
        "[4] Ano\n"   
        "Enter option:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("Digite uma marca: ");
            scanf("%s",caracteristica);
            pesquisa_marca(caracteristica,*carros); 
            break;
        case 2:
            printf("Digite uma placa: ");
            scanf("%s",caracteristica);

            pesquisa_placa(caracteristica,*carros); 
            break;
        case 3:
            printf("Digite uma cor: ");
            scanf("%s",caracteristica);
            pesquisa_cor(caracteristica,*carros); 
            break;
        case 4:
            printf("Digite um modelo: ");
            scanf("%s",caracteristica);
            pesquisa_modelo(caracteristica,*carros); 
            break;
        case 5:
            printf("Digite um ano: ");
            scanf("%s",caracteristica);
            pesquisa_ano(caracteristica,*carros); 
            break;
        
        default:
            break;
        }
    
        printf("Press enter to continue...\n");
        int c;
        while((c = getchar() )!= '\n' && c != EOF);
        scanf("%lc",&c);
    
}

void locacaoSystem(LstCarros* carros){

    int option;
    Lista* lstLocacao = criaL();
    
    do{
        system(CMD);
        
        printf(
        "LOCALIZA SYSTEM:\n"
        "------------\n"
        "[1] Criar locacao\n"
        "[2] Pesquisar carro\n"
        "[3] Visualizar locacoes\n"   
        "[4] Sair\n"   
        "Enter option:");
        scanf("%d",&option);

        switch(option){
            case 1:
                system(CMD);
                criaLocacaoMenu(lstLocacao,carros);

                break;
            case 2:
                system("clear");
                pesquisarMenu( carros);
                
                break;
            case 3:
                system("clear");                
                imprimeL(lstLocacao);
                break;
            default:
                printf("Invalid Option");
        }
    }while(option != 4);



}