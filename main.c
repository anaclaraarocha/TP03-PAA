#include <stdio.h>
#include "simulacao.h"
#include "comparacao.h"

void main(){

    int qntPadroes = 10;

    long double mediaHumanoChimp = 0, mediaHumanoDog = 0, mediaChimpDog = 0;

    int tamanhoProdCartesiano = 2;

    int qntSimulacoes = 100;

    int total = pow(4,tamanhoProdCartesiano);
    char** produtoCartesiano = (char** ) malloc(sizeof(char*)*total);
    for(int i =0;i<total;i++){
        produtoCartesiano[i] = (char*)malloc(tamanhoProdCartesiano+1);
    }
    gerarProdutoCartesiano(produtoCartesiano,tamanhoProdCartesiano);

    for(int i = 0; i < qntSimulacoes;i++){
        FILE *humano = fopen("human.txt", "r");
        FILE *chimpanze = fopen("chimpanzee.txt", "r");
        FILE *dog = fopen("dog.txt", "r");
        srand(time(NULL));
        
        simulacao(humano,chimpanze,dog,tamanhoProdCartesiano,produtoCartesiano,
        qntPadroes,&mediaHumanoChimp,&mediaHumanoDog,&mediaChimpDog);

        fclose(humano);
        fclose(chimpanze);
        fclose(dog);

    }   

    printf("Numero de simulacoes: %d \n",qntSimulacoes);
    printf("Numero de padroes: %d \n",qntPadroes);
    printf("Tamanho produto cartesiano: %d \n\n",tamanhoProdCartesiano);

    printf("==================Similaridade final==================\n");

    printf("Similaridade Humano com Chimpanze: %Lf \n\n",mediaHumanoChimp/qntSimulacoes);

    printf("Similaridade Humano com Cachorro: %Lf \n\n",mediaHumanoDog/qntSimulacoes);

    printf("Similaridade Cachorro com Chimpanze: %Lf \n\n",mediaChimpDog/qntSimulacoes);

    for(int i = 0; i < total; i++){
        free(produtoCartesiano[i]);
    }

    free(produtoCartesiano);

}
