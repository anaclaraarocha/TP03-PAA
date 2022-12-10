#include "leituraDeArquivo.h"

void similaridade(FILE *humano,FILE *chimpanzee,FILE *dog){
    int qntPadroes = 5;
    int freqHumano[qntPadroes],freqChimpanze[qntPadroes],freqDog[qntPadroes];
    long int numerador=0;
    long double somaDenominador1=0.0,somaDenominador2=0.0;
    long double similaridade;
    long int aux;
    for(int i =0; i < qntPadroes;i++){
        freqHumano[i] = 0;
        freqChimpanze[i] = 0;
        freqDog[i] = 0;
    }
    //printf("Humano:\n");
    frequenciaHumano(humano,freqHumano);
    //printf("Chimpanzee:\n");
    frequenciaChimpanzee(chimpanzee,freqChimpanze);
    //printf("Dog:\n");
    frequenciaDog(dog,freqDog);
    

    for(int i =0;i<qntPadroes;i++){
        aux = freqHumano[i]*freqChimpanze[i];
        printf("Freq humano posicao[%d]: %d\n",i,freqHumano[i]);
        printf("Freq Chimpa posicao[%d]: %d\n",i,freqChimpanze[i]);
        printf("Multiplicacao dos 2: %ld\n",aux);
        numerador += aux;
        printf("\n");
        //printf("numerador: %f\n",similaridade);
        somaDenominador1 += freqHumano[i]*freqHumano[i];
        somaDenominador2 += freqChimpanze[i]*freqChimpanze[i];
        /*printf("HUmanin %d ",freqHumano[i]);
        printf("Chacorro %d ",freqDog[i]);
        printf("Chimpa %d \n",freqChimpanze[i]); */
    }
    somaDenominador1 = sqrt(somaDenominador1);
    somaDenominador2 = sqrt(somaDenominador2);
    similaridade = numerador / (somaDenominador1*somaDenominador2);
    printf("Numerador: %ld ",numerador);
    printf("Denominador: %Lf\n",(somaDenominador1*somaDenominador2));
    
    printf("Similaridade Humano x Chimpanze: %Lf\n",similaridade);

    numerador=0,somaDenominador1=0,somaDenominador2=0;
    
}


void frequenciaHumano(FILE *humano,int *teste){
    
    int qntRepeticoes,qntPadroes = 5;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    int tamanhoProdCartesiano = 2;
    char DNAHumano[6000000];
    char caracter;
    //int A[qntPadroes];


    //cria o produto cartesiano com o codigo do bijas
    int total = pow(4,tamanhoProdCartesiano);
    char** produtoCartesiano = (char** ) malloc(sizeof(char*)*total);
    for(int i =0;i<total;i++){
        produtoCartesiano[i] = (char*)malloc(tamanhoProdCartesiano+1);
    }
    gerarProdutoCartesiano(produtoCartesiano,tamanhoProdCartesiano);


    //preenche o vetor DNAHumano com o arquivo human.txt
    while((caracter = fgetc(humano)) != EOF){
        
        DNAHumano[contador] = caracter;
        contador++;
    }

    selecionaPadrao(qntPadroes,teste,produtoCartesiano,total,DNAHumano);   
    for(int i = 0; i < total; i++){
        free(produtoCartesiano[i]);
    }

    free(produtoCartesiano);
}

void frequenciaChimpanzee(FILE *chimpanze,int *A){
    
    int qntRepeticoes = 0,qntPadroes2 = 5;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    int tamanhoProdCartesiano = 2;
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
    printf("\nContador: %d\n",contador);

    selecionaPadrao(qntPadroes2,A,produtoCartesiano2,total2,DNAChimpanze); 


    for(int i = 0; i < total2-1; i++){
        free(produtoCartesiano2[i]);
    }

    free(produtoCartesiano2);
}
void frequenciaDog(FILE *dog,int *A){
    
    int qntRepeticoes,qntPadroes3 = 5;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    int tamanhoProdCartesiano3 = 2;
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

    selecionaPadrao(qntPadroes3,A,produtoCartesiano3,total3,DNADog);  
    for(int i = 0; i < total3-1; i++){
        free(produtoCartesiano3[i]);
    }

    free(produtoCartesiano3); 
}

void selecionaPadrao(int qntPadroes,int *vetorFrequencia, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNA){


    char padroes[qntPadroes];

    int posicoesSelecionadas[qntPadroes];
    srand(time(NULL));
    for(int i =0; i <qntPadroes;i++){
        posicoesSelecionadas[i] = rand()%tamanhoVetorCartesiano;
    }

    for(int i =0; i < qntPadroes;i++){
        for(int j =0; j < qntPadroes;j++){
            strcpy(padroes, produtoCartesiano[posicoesSelecionadas[i]]);
        }
        //printf("Padroes: %s \n",padroes);
        vetorFrequencia[i] = search(DNA, padroes);
        //printf("qnt cada:%d\n",vetorFrequencia[i]);
        //printf("\n");
    }
    
}