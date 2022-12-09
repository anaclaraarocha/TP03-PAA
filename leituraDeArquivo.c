#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void lerArquivo(FILE *humano){
    
    int qntRepeticoes,qntPadroes = 4;//esse tamanho dos padroes vai ser escolhido arbitrariamente
    int contador = 0;
    char DNAHumano[6000000];
    char caracter;


    char pat[1];

    char padrao[4] = {'A','T','G','C'};
    int qntCada[4] ={0,0,0,0};
    int qntCada[4] ={0,0,0,0};


    while((caracter = fgetc(humano)) != EOF){
        if(caracter !='\n'){
            DNAHumano[contador] = caracter;
            contador++;
        }
    }
    
    printf("Contador: %d\n",contador);

    for(int i =0; i < qntPadroes;i++){
        pat[0] = padrao[i];
        qntCada[i] = search(DNAHumano, pat);

    }
    
}