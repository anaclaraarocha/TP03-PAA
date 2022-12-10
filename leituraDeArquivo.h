#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "comparacao.h"
#include "produtoCartesiano.h"


void lerArquivo(FILE *humano);
void lerArquivoPrincipal(char fileName, char **arrayTextParameter);

void selecionaPadrao(int qntPadroes,int *A,int *B, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNAHumano);