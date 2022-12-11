#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "comparacao.h"
#include "produtoCartesiano.h"
#include "similaridade.h"

void frequenciaHumano(FILE *humano,int *A,int qntPadroes,int tamanhoProdCartesiano, int *posicoes,
    char **produtoCartesiano,int total);

void frequenciaChimpanzee(FILE *humano,int *A,int qntPadroes,int tamanhoProdCartesiano, int *posicoes,
    char **produtoCartesiano2,int total2);

void frequenciaDog(FILE *dog,int *A,int qntPadroes3,int tamanhoProdCartesiano3,
    int *posicoesSelecionadas3,char **produtoCartesiano3,int total3);

void similaridade(FILE *humano,FILE *chimpanzee,FILE *dog,int tamanhoProdCartesiano,char **prodCartesiano);
void lerArquivoPrincipal(char fileName, char **arrayTextParameter);

void selecionaPadrao(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNAHumano,int *posicoes);

void selecionaPadrao2(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNAHumano);