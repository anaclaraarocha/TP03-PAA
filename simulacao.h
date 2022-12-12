#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "comparacao.h"
#include "produtoCartesiano.h"
#include "similaridade.h"

void simulacao(FILE *humano,FILE *chimpanzee,FILE *dog,int tamanhoProdCartesiano,
    char **prodCartesiano,int qntPadroes,long double *mediaHumanoChimp,
    long double *mediaHumanoDog,long double *mediaChimpDog);

void frequenciaHumano(FILE *humano,int *vetorFrequencia,int qntPadroes,int tamanhoProdCartesiano,
    int *posicoes,char **produtoCartesiano,int total);

void frequenciaChimpanzee(FILE *chimpanze,int *vetorFrequencia,int qntPadroes,
    int tamanhoProdCartesiano, int *posicoes,char **produtoCartesiano2,int total2);

void frequenciaDog(FILE *dog,int *vetorFrequencia,int qntPadroes3,int tamanhoProdCartesiano3,
    int *posicoes,char **produtoCartesiano3,int total3);

void selecionaPadrao(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,
    int tamanhoVetorCartesiano,char *DNA,int *posicoes);