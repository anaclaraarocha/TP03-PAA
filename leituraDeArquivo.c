#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void lerArquivo(FILE *humano){
    
    int qntRepeticoes,qntPadroes = 2;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    int tamanhoProdCartesiano = 2;
    char DNAHumano[6000000];
    char caracter;


    char pat[tamanhoProdCartesiano];

    char padrao[2][2] = {{'A','A'},{'T','G'}};
    int qntCada[4] ={0,0,0,0};
    //int qntCada[4] ={0,0,0,0};


    while((caracter = fgetc(humano)) != EOF){
        
        DNAHumano[contador] = caracter;
        contador++;
    }
    
    printf("Contador: %d\n",contador);
    for(int i =0; i < qntPadroes;i++){
        for(int j =0; j < tamanhoProdCartesiano;j++){
            pat[j] = padrao[i][j];
            printf("pat: %c\n",pat[i]);

        }
        qntCada[i] = search(DNAHumano, pat);
        printf("qnt cada:%d\n",qntCada[i]);
        //pat[0] = padrao[i];
        //strcpy(pat,padrao[i]);
        //pat[i] = padrao[i][i];
        //qntCada[i] = search(DNAHumano, pat);
        //printf("Pat:%s\n",pat);
        //printf("Qnt cada: %d",qntCada[i]);
        //printf("Padrao 1: %d",padrao[0][i]);

    }
    //char aux[] = "TT";
    //int numeroTeste = search(DNAHumano, pat);
    qntRepeticoes = qntCada[0]+qntCada[1];
    printf("Qnt repeticoes: %d",qntRepeticoes);
}