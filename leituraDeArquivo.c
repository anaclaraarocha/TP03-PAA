

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leituraDeArquivo.h"
#include "comparacao.h"

void lerArquivo(FILE *humano){
    /*
    int tamanhoReal = 7665720-819;
    char DNAHumano[tamanhoReal];*/
    int varAux =0;
    char string[3] = "ATG";
    int contador = 0,aux = 819;
    char DNAHumano[6000000];
    char caracter;

    while((caracter = fgetc(humano)) != EOF){
        if(caracter !='\n'){
            DNAHumano[contador] = caracter;
            contador++;
        }

    }
    
    char next[10];
    int numero;
    printf("Contador: %d",contador);
    next[1] = 'a';
    printf("A");
    /*
    for (int i = 0; i < 10; i++) {
        next[i] = '0';
    }
    /*
    for (int i = 1; i < contador; i++)
    {
        numero = next[i+1];
        int j = numero;
        while (j > 0 && string[j] != string[i]) {
            j = next[j];
        }
 
        if (j > 0 || string[j] == string[i]) {
            next[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < 3; i++) // m é o tamanho do padrão; roda o for com a quantidade de caracteres que tem que buscar
    {
        if (*(DNAHumano + i) == *(string + j)) 
        {
            if (++j == contador) {
                varAux++;
                
                //printf("The string occurs with shift %d\n", i - j + 1);
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    // já que `i` será incrementado na próxima iteração
        }
    }
    printf("varAux: %d", varAux);

    //KMP(DNAHumano,string,contador,3);
    /*
    printf("contador: %d",contador);
    for(int i = 0;i < contador;i++){
        printf("%c",DNAHumano[i]);
    }*/

}