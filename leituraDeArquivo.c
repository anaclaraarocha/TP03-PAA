

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void lerArquivo(FILE *humano){
    /*
    int tamanhoReal = 7665720-819;
    char DNAHumano[tamanhoReal];*/
    char string[3] = "ATG";
    int contador = 0,aux = 819;
    char DNAHumano[6000000];
    char caracter;

    printf("entrou em ler arquivo");

    while((caracter = fgetc(humano)) != EOF){
        if(caracter !='\n'){
            DNAHumano[contador] = caracter;
            contador++;
        }

    }
    printf("aqui");
    //KMP(DNAHumano,string,contador,strlen(string));
    /*
    printf("contador: %d",contador);
    for(int i = 0;i < contador;i++){
        printf("%c",DNAHumano[i]);
    }*/

}