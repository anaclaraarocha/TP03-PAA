#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "comparacao.h"
#include "produtoCartesiano.h"


void frequenciaHumano(FILE *humano,int *A);
void frequenciaChimpanzee(FILE *humano,int *A);
void frequenciaDog(FILE *humano,int *A);
void similaridade(FILE *humano,FILE *chimpanzee,FILE *dog);
void lerArquivoPrincipal(char fileName, char **arrayTextParameter);

void selecionaPadrao(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNAHumano);