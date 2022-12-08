#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void KMP(const char* text, const char* pattern, int m, int n)
{
    printf("aqui");
    int varAux = 0;
    // caso base 1: o padrão é NULL ou vazio
    if (*pattern == '\0' || n == 0) {
        printf("The pattern occurs with shift 0");
    }
 
    // caso base 2: o texto é NULL ou o comprimento do texto é menor que o do padrão
    if (*text == '\0' || n > m) {
        printf("Pattern not found");
    }
 
    // next[i] armazena o índice da próxima melhor correspondência parcial
    int next[n + 1];
 
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }
 
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];
 
        while (j > 0 && pattern[j] != pattern[i]) {
            j = next[j];
        }
 
        if (j > 0 || pattern[j] == pattern[i]) {
            next[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < m; i++) // m é o tamanho do padrão; roda o for com a quantidade de caracteres que tem que buscar
    {
        if (*(text + i) == *(pattern + j)) 
        {
            if (++j == n) {
                varAux++;
                
                //printf("The pattern occurs with shift %d\n", i - j + 1);
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    // já que `i` será incrementado na próxima iteração
        }
    }
    printf("varAux: %d", varAux);

}
 
// Programa para implementar o algoritmo KMP em C
// int main(void)
// {
//     char* text = "ABCABAABCABACAB";
//     char* pattern = "CAB";
 
//     int n = strlen(text);
//     int m = strlen(pattern);
 
//     KMP(text, pattern, n, m);
 
//     return 0;
// }


   