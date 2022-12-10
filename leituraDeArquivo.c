#include "leituraDeArquivo.h"

void lerArquivo(FILE *humano){
    
    int qntRepeticoes,qntPadroes = 5;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    int tamanhoProdCartesiano = 2;
    char DNAHumano[6000000];
    char caracter;
    int A[qntPadroes],B[qntPadroes];


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

    selecionaPadrao(qntPadroes,A,B,produtoCartesiano,total,DNAHumano);


    
    
}

void selecionaPadrao(int qntPadroes,int *A,int *B, char** produtoCartesiano,int tamanhoVetorCartesiano,
                    char *DNAHumano){


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
        A[i] = search(DNAHumano, padroes);
        printf("qnt cada:%d\n",A[i]);
        printf("\n");
    }


}