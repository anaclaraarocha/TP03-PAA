#include <stdio.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void main(){

    FILE *humano = fopen("human.txt", "r");
    lerArquivo(humano);
    //lerArquivoPrincipal("dog.txt", char **arrayTextParameter)
    fclose(humano);
}
