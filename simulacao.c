#include "simulacao.h"


void simulacao(FILE *humano,FILE *chimpanzee,FILE *dog,int tamanhoProdCartesiano,
    char **prodCartesiano, int qntPadroes, long double *mediaHumanoChimp,
    long double *mediaHumanoDog,long double *mediaChimpDog){

    int freqHumano[qntPadroes],freqChimpanze[qntPadroes],freqDog[qntPadroes];

    for(int i =0; i < qntPadroes;i++){
        freqHumano[i] = 0;
        freqChimpanze[i] = 0;
        freqDog[i] = 0;
    }
    
    int posicoesSelecionadas[qntPadroes];
    int tamanhoVetorCartesiano = pow(4,tamanhoProdCartesiano);

    for(int i =0; i <qntPadroes;i++){
        posicoesSelecionadas[i] = rand()%tamanhoVetorCartesiano;
    }

    frequenciaHumano(humano,freqHumano,qntPadroes,tamanhoProdCartesiano,posicoesSelecionadas,
        prodCartesiano,tamanhoProdCartesiano);

    frequenciaChimpanzee(chimpanzee,freqChimpanze,qntPadroes,tamanhoProdCartesiano,posicoesSelecionadas,
        prodCartesiano,tamanhoProdCartesiano);

    frequenciaDog(dog,freqDog,qntPadroes,tamanhoProdCartesiano,posicoesSelecionadas,
        prodCartesiano,tamanhoProdCartesiano);

    *mediaHumanoChimp += similaridadeHumChimp(qntPadroes,freqHumano,freqChimpanze);

    *mediaChimpDog += similaridadeDogChimp(qntPadroes,freqDog,freqChimpanze);

    *mediaHumanoDog += similaridadeHumDog(qntPadroes,freqHumano,freqDog);

    


    
}


void frequenciaHumano(FILE *humano,int *teste,int qntPadroes,int tamanhoProdCartesiano,
    int *posicoesSelecionadas, char **produtoCartesiano1,int total){
    
    int contador = 0;
    char DNAHumano[6000000];
    char caracter;

    while((caracter = fgetc(humano)) != EOF){
        
        DNAHumano[contador] = caracter;
        contador++;
    }

    selecionaPadrao(qntPadroes,teste,produtoCartesiano1,total,DNAHumano,posicoesSelecionadas);   

}

void frequenciaChimpanzee(FILE *chimpanze,int *A,int qntPadroes2,int tamanhoProdCartesiano,
    int *posicoesSelecionadas2,char **produtoCartesiano2,int total2){

    int contador = 0;
    char DNAChimpanze[6000000];
    char caracter;


    while((caracter = fgetc(chimpanze)) != EOF){
        
        DNAChimpanze[contador] = caracter;
        contador++;
    }
    selecionaPadrao(qntPadroes2,A,produtoCartesiano2,total2,DNAChimpanze,posicoesSelecionadas2); 

}

void frequenciaDog(FILE *dog,int *A,int qntPadroes3,int tamanhoProdCartesiano3,
    int *posicoesSelecionadas3,char **produtoCartesiano3,int total3){
        
    int contador = 0;;
    char DNADog[6000000];
    char caracter;
    
    while((caracter = fgetc(dog)) != EOF){
        
        DNADog[contador] = caracter;
        contador++;
    }

    selecionaPadrao(qntPadroes3,A,produtoCartesiano3,total3,DNADog,posicoesSelecionadas3);  

}

void selecionaPadrao(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNA,int *posicoesSelecionadas0){


    char padroes[qntPadroes];


    for(int i = 0; i < qntPadroes;i++){

        strcpy(padroes, produtoCartesiano[posicoesSelecionadas0[i]]);
        vetorFrequencia[i] = busca(DNA, padroes);
    }
    
}