#include <stdio.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void main(){

    //int qntPadroes = 5,A[qntPadroes];
    //frequenciaHumano(humano,A);
    for(int i = 0; i < 3;i++){
        FILE *humano = fopen("human.txt", "r");
        FILE *chimpanze = fopen("chimpanzee.txt", "r");
        FILE *dog = fopen("dog.txt", "r");
        srand(time(NULL));
        printf("===========Simulação %d===========\n",i+1);
        printf("\n");
        similaridade(humano,chimpanze,dog);
        fclose(humano);
        fclose(chimpanze);
        fclose(dog);

    }
    //lerArquivoPrincipal("dog.txt", char **arrayTextParameter)
}
