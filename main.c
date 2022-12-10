#include <stdio.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void main(){

    FILE *humano = fopen("human.txt", "r");
    FILE *chimpanze = fopen("chimpanzee.txt", "r");
    FILE *dog = fopen("teste.txt", "r");
    //int qntPadroes = 5,A[qntPadroes];
    //frequenciaHumano(humano,A);
    similaridade(humano,chimpanze,dog);
    //lerArquivoPrincipal("dog.txt", char **arrayTextParameter)
    fclose(humano);
    fclose(chimpanze);
    fclose(dog);
}
