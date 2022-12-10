#include "leituraDeArquivo.h"

void similaridade(FILE *humano,FILE *chimpanzee,FILE *dog){
    int qntPadroes = 5,A[qntPadroes],B[qntPadroes];
    printf("Humano:\n");
    frequenciaHumano(humano,A);
    printf("Chimpanzee:\n");
    frequenciaChimpanzee(chimpanzee,B);
    printf("Dog:\n");
    frequenciaDog(dog,A);
    

}


void frequenciaHumano(FILE *humano,int *A){
    
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

    selecionaPadrao(qntPadroes,A,produtoCartesiano,total,DNAHumano);   
}
void frequenciaChimpanzee(FILE *chimpanze,int *A){
    
    int qntRepeticoes,qntPadroes = 5;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    int tamanhoProdCartesiano = 2;
    char DNAChimpanze[6000000];
    char caracter;
    //int A[qntPadroes];


    //cria o produto cartesiano com o codigo do bijas
    int total = pow(4,tamanhoProdCartesiano);
    char** produtoCartesiano = (char** ) malloc(sizeof(char*)*total);
    for(int i =0;i<total;i++){
        produtoCartesiano[i] = (char*)malloc(tamanhoProdCartesiano+1);
    }
    gerarProdutoCartesiano(produtoCartesiano,tamanhoProdCartesiano);


    //preenche o vetor DNAChimpanze com o arquivo human.txt
    while((caracter = fgetc(chimpanze)) != EOF){
        
        DNAChimpanze[contador] = caracter;
        contador++;
    }
    
    selecionaPadrao(qntPadroes,A,produtoCartesiano,total,DNAChimpanze); 

    for(int i = 0; i < total-1; i++){
        free(produtoCartesiano[i]);
    }

    free(produtoCartesiano);
}
void frequenciaDog(FILE *dog,int *A){
    
    int qntRepeticoes,qntPadroes = 5;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    int tamanhoProdCartesiano = 2;
    char DNADog[6000000];
    char caracter;
    //int A[qntPadroes];


    //cria o produto cartesiano com o codigo do bijas
    int total = pow(4,tamanhoProdCartesiano);
    char** produtoCartesiano = (char** ) malloc(sizeof(char*)*total);
    for(int i =0;i<total;i++){
        produtoCartesiano[i] = (char*)malloc(tamanhoProdCartesiano+1);
    }
    gerarProdutoCartesiano(produtoCartesiano,tamanhoProdCartesiano);


    //preenche o vetor DNADog com o arquivo human.txt
    while((caracter = fgetc(dog)) != EOF){
        
        DNADog[contador] = caracter;
        contador++;
    }

    selecionaPadrao(qntPadroes,A,produtoCartesiano,total,DNADog);  
    for(int i = 0; i < total-1; i++){
        free(produtoCartesiano[i]);
    }

    free(produtoCartesiano); 
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
        printf("Padroes: %s \n",padroes);
        vetorFrequencia[i] = search(DNA, padroes);
        printf("qnt cada:%d\n",vetorFrequencia[i]);
        printf("\n");
    }


}