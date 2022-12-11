#include <stdio.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void main(){

    int tamanhoProdCartesiano = 10;

    int total = pow(4,tamanhoProdCartesiano);
    char** produtoCartesiano = (char** ) malloc(sizeof(char*)*total);
    for(int i =0;i<total;i++){
        produtoCartesiano[i] = (char*)malloc(tamanhoProdCartesiano+1);
    }
    gerarProdutoCartesiano(produtoCartesiano,tamanhoProdCartesiano);

    //printf("gera\n");
    for(int i = 0; i < 10;i++){
        FILE *humano = fopen("human.txt", "r");
        FILE *chimpanze = fopen("chimpanzee.txt", "r");
        FILE *dog = fopen("dog.txt", "r");
        srand(time(NULL));
        printf("===========Simulação %d===========\n",i+1);
        printf("\n");
        similaridade(humano,chimpanze,dog,tamanhoProdCartesiano,produtoCartesiano);
        fclose(humano);
        fclose(chimpanze);
        fclose(dog);

    }

    for(int i = 0; i < total; i++){
        free(produtoCartesiano[i]);
    }

    free(produtoCartesiano);
}
