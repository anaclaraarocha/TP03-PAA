#include "leituraDeArquivo.h"


void similaridade(FILE *humano,FILE *chimpanzee,FILE *dog){
    int qntPadroes = 1000 , tamanhoProdCartesiano = 10;
    int freqHumano[qntPadroes],freqChimpanze[qntPadroes],freqDog[qntPadroes];
    //long int numerador=0;
    //long double somaDenominador1=0.0,somaDenominador2=0.0;
    //long double similaridade;
    //long int aux;
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
    //printf("Humano:\n");
    frequenciaHumano(humano,freqHumano,qntPadroes,tamanhoProdCartesiano,posicoesSelecionadas);
    //printf("Chimpanzee:\n");
    frequenciaChimpanzee(chimpanzee,freqChimpanze,qntPadroes,tamanhoProdCartesiano,posicoesSelecionadas);
    //printf("Dog:\n");
    frequenciaDog(dog,freqDog,qntPadroes,tamanhoProdCartesiano,posicoesSelecionadas);

    similaridadeHumChimp(qntPadroes,freqHumano,freqChimpanze);
    similaridadeDogChimp(qntPadroes,freqDog,freqChimpanze);
    similaridadeHumDog(qntPadroes,freqHumano,freqDog);


    
}


void frequenciaHumano(FILE *humano,int *teste,int qntPadroes,int tamanhoProdCartesiano,
    int *posicoesSelecionadas){
    
    int qntRepeticoes;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    char DNAHumano[6000000];
    char caracter;
    //int A[qntPadroes];


    //cria o produto cartesiano com o codigo do bijas
    int total = pow(4,tamanhoProdCartesiano);
    char** produtoCartesiano1 = (char** ) malloc(sizeof(char*)*total);
    for(int i =0;i<total;i++){
        produtoCartesiano1[i] = (char*)malloc(tamanhoProdCartesiano+1);
    }
    gerarProdutoCartesiano(produtoCartesiano1,tamanhoProdCartesiano);


    //preenche o vetor DNAHumano com o arquivo human.txt
    while((caracter = fgetc(humano)) != EOF){
        
        DNAHumano[contador] = caracter;
        contador++;
    }

    //printf("Padroes usados para o humano:\n");
    selecionaPadrao(qntPadroes,teste,produtoCartesiano1,total,DNAHumano,posicoesSelecionadas);   
    //printf("======================================\n");
    for(int i = 0; i < total; i++){
        free(produtoCartesiano1[i]);
    }

    free(produtoCartesiano1);
}

void frequenciaChimpanzee(FILE *chimpanze,int *A,int qntPadroes2,int tamanhoProdCartesiano,
    int *posicoesSelecionadas2){
    
    int qntRepeticoes = 0;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    char DNAChimpanze[6000000];
    char caracter;
    //int A[qntPadroes2];


    //cria o produto cartesiano com o codigo do bijas
    int total2 = pow(4,tamanhoProdCartesiano);
    char** produtoCartesiano2 = (char** ) malloc(sizeof(char*)*total2);
    for(int i =0;i<total2;i++){
        produtoCartesiano2[i] = (char*)malloc(tamanhoProdCartesiano+1);
    }
    gerarProdutoCartesiano(produtoCartesiano2,tamanhoProdCartesiano);


    //preenche o vetor DNAChimpanze com o arquivo human.txt
    while((caracter = fgetc(chimpanze)) != EOF){
        
        DNAChimpanze[contador] = caracter;
        contador++;
    }
    //printf("\nContador: %d\n",contador);

    //printf("Padroes usados pelo chimpanze:\n");
    selecionaPadrao(qntPadroes2,A,produtoCartesiano2,total2,DNAChimpanze,posicoesSelecionadas2); 

    //printf("=======================");

    for(int i = 0; i < total2-1; i++){
        free(produtoCartesiano2[i]);
    }

    free(produtoCartesiano2);
}

void frequenciaDog(FILE *dog,int *A,int qntPadroes3,int tamanhoProdCartesiano3,
    int *posicoesSelecionadas3){
    
    int qntRepeticoes;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;;
    char DNADog[6000000];
    char caracter;
    //int A[qntPadroes3];


    //cria o produto cartesiano com o codigo do bijas
    int total3 = pow(4,tamanhoProdCartesiano3);
    char** produtoCartesiano3 = (char** ) malloc(sizeof(char*)*total3);
    for(int i =0;i<total3;i++){
        produtoCartesiano3[i] = (char*)malloc(tamanhoProdCartesiano3+1);
    }
    gerarProdutoCartesiano(produtoCartesiano3,tamanhoProdCartesiano3);


    //preenche o vetor DNADog com o arquivo human.txt
    while((caracter = fgetc(dog)) != EOF){
        
        DNADog[contador] = caracter;
        contador++;
    }

    //printf("Padroes usados pelo dog:\n");
    selecionaPadrao(qntPadroes3,A,produtoCartesiano3,total3,DNADog,posicoesSelecionadas3);  
    //printf("=============\n");
    for(int i = 0; i < total3-1; i++){
        free(produtoCartesiano3[i]);
    }

    free(produtoCartesiano3); 
}

void selecionaPadrao(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNA,int *posicoesSelecionadas0){


    char padroes[qntPadroes];

    for(int i =0; i < qntPadroes;i++){
        for(int j =0; j < qntPadroes;j++){
            strcpy(padroes, produtoCartesiano[posicoesSelecionadas0[i]]);
        }
        //printf("Padroes: %s\n",padroes);
        vetorFrequencia[i] = search(DNA, padroes);
    }
    
}