#include "produtoCartesiano.h"

void gerarProdutoCartesiano(char** produtoCartesiano, int tamanho){
    char* gen = (char*)malloc(tamanho+1);
    int i =0, rep =0;
    generation(produtoCartesiano,&i,gen,rep,tamanho);
    free(gen);
}

void generation(char **produtoCartesiano,int *i,char* gen,int rep,int tamanho){
    char bases[] = {'A','C','T','G'};
    if(rep == tamanho){
        gen[tamanho] = '\0';
        strcpy(produtoCartesiano[*i],gen);
        *i +=1;
        return;
    }else{
        for(int j =0;j<4;j++){
            gen[rep] = bases[j];
            generation(produtoCartesiano,i,gen,rep+1,tamanho);
        }
    }
}
