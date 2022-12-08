
#include "leituraDeArquivo.h"

void lerArquivo(FILE *humano){
    /*
    int tamanhoReal = 7665720-819;
    char DNAHumano[tamanhoReal];*/
    int contador = 0,aux = 819;
    char DNAHumano[6000000];
    char caracter;

    while((caracter = fgetc(humano)) != EOF){
        if(caracter !='\n'){
            DNAHumano[contador] = caracter;
            contador++;
        }
    }
    /*
    printf("contador: %d",contador);
    for(int i = 0;i < contador;i++){
        printf("%c",DNAHumano[i]);
    }*/

}