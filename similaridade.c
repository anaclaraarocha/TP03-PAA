#include "similaridade.h"


void similaridadeHumChimp(int qntPadroes,int *freqHumano, int *freqChimpanze){
    long double resultadoHC = 0.0;
    long double soma1HC = 0.0;
    long double soma2HC = 0.0;
    long double modulo1HC = 0.0;
    long double modulo2HC = 0.0;
    long double similaridadeHC = 0.0;

    for(int i=0;i<qntPadroes;i++){
        resultadoHC += (long double)freqHumano[i] * (long double)freqChimpanze[i];
    }
    for(int i=0;i<qntPadroes;i++){
        soma1HC += pow(freqHumano[i],2);

    }
    modulo1HC = sqrt(soma1HC);

    for(int i=0;i<qntPadroes;i++){
        soma2HC += pow(freqChimpanze[i],2);
        
    }

    modulo2HC = sqrt(soma2HC);

    similaridadeHC = (resultadoHC/(modulo1HC*modulo2HC));

    printf("Similaridade Humano com Chimpazne: %Lf \n",similaridadeHC);
    printf("\n");

}

void similaridadeHumDog(int qntPadroes,int *freqHumano, int *freqDog){
    long double resultadoHD = 0.0;
    long double soma1HD = 0.0;
    long double soma2HD = 0.0;
    long double modulo1HD = 0.0;
    long double modulo2HD = 0.0;
    long double similaridadeHD = 0.0;

    for(int i=0;i<qntPadroes;i++){
        resultadoHD += (long double)freqHumano[i] * (long double)freqDog[i];
    }
    for(int i=0;i<qntPadroes;i++){
        soma1HD += pow(freqHumano[i],2);

    }
    modulo1HD = sqrt(soma1HD);

    for(int i=0;i<qntPadroes;i++){
        soma2HD += pow(freqDog[i],2);
        
    }

    modulo2HD = sqrt(soma2HD);

    similaridadeHD = (resultadoHD/(modulo1HD*modulo2HD));

    printf("Similaridade Humano com Cachorro: %Lf \n",similaridadeHD);
    printf("\n");

}

void similaridadeDogChimp(int qntPadroes,int *freqDog, int *freqChimpanze){
    long double resultadoDC = 0.0;
    long double soma1DC = 0.0;
    long double soma2DC = 0.0;
    long double modulo1DC = 0.0;
    long double modulo2DC = 0.0;
    long double similaridadeDC = 0.0;

    for(int i=0;i<qntPadroes;i++){
        resultadoDC += (long double)freqDog[i] * (long double)freqChimpanze[i];
    }
    for(int i=0;i<qntPadroes;i++){
        soma1DC += pow(freqDog[i],2);

    }
    modulo1DC = sqrt(soma1DC);

    for(int i=0;i<qntPadroes;i++){
        soma2DC += pow(freqChimpanze[i],2);
        
    }

    modulo2DC = sqrt(soma2DC);

    similaridadeDC = (resultadoDC/(modulo1DC*modulo2DC));

    printf("Similaridade Cachorro com Chimpanze: %Lf \n",similaridadeDC);
    printf("\n");

}