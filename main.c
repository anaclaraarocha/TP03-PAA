#include <stdio.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void main(){

    FILE *humano = fopen("teste.txt", "r");
    lerArquivo(humano);
    //lerArquivoPrincipal("dog.txt", char **arrayTextParameter)
    fclose(humano);
}
