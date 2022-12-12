# include <limits.h>
# include <string.h>
# include <stdio.h>
#include "comparacao.h"
 
int busca( char *textoCompleto,  char *padraoDeBusca){
   
   int frequenciaPadrao = 0;
   int m = strlen(padraoDeBusca);
   int n = strlen(textoCompleto);
 
   int charNaoCompativel[256] = {};
   int i;
   
   for (i = 0; i < 256; i++){
      charNaoCompativel[i] = -1;
   }
   
   for (i = 0; i < m; i++){
      charNaoCompativel[(int) padraoDeBusca[i]] = i;

   }

   int deslocamento = 0;  
   while(deslocamento <= (n - m)){
      int indiceBusca = m-1;
      while(indiceBusca >= 0 && padraoDeBusca[indiceBusca] == textoCompleto[deslocamento+indiceBusca]){
         indiceBusca--;
      }
      if (indiceBusca < 0){
         frequenciaPadrao++;
         deslocamento += (deslocamento+m < n)? m-charNaoCompativel[textoCompleto[deslocamento+m]] : 1;
      }
      else
         if(indiceBusca - charNaoCompativel[textoCompleto[deslocamento+indiceBusca]] < 1){
            deslocamento++;
         }else{
            deslocamento+=indiceBusca - charNaoCompativel[textoCompleto[deslocamento+indiceBusca]];
         }
   }
   return frequenciaPadrao;
}
