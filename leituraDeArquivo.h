#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "comparacao.h"
#include "produtoCartesiano.h"
#include "similaridade.h"

void frequenciaHumano(FILE *humano,int *A,int qntPadroes,int tamanhoProdCartesiano, int *posicoes);
void frequenciaChimpanzee(FILE *humano,int *A,int qntPadroes,int tamanhoProdCartesiano, int *posicoes);
void frequenciaDog(FILE *dog,int *A,int qntPadroes3,int tamanhoProdCartesiano3,
    int *posicoesSelecionadas);
void similaridade(FILE *humano,FILE *chimpanzee,FILE *dog);
void lerArquivoPrincipal(char fileName, char **arrayTextParameter);

void selecionaPadrao(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNAHumano,int *posicoes);

void selecionaPadrao2(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNAHumano);