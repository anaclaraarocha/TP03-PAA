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

   int s = 0;  
   while(s <= (n - m)){
      int indiceBusca = m-1;
      while(indiceBusca >= 0 && padraoDeBusca[indiceBusca] == textoCompleto[s+indiceBusca]){
         indiceBusca--;
      }
      if (indiceBusca < 0){
         frequenciaPadrao++;
         s += (s+m < n)? m-charNaoCompativel[textoCompleto[s+m]] : 1;
      }
      else
         if(indiceBusca - charNaoCompativel[textoCompleto[s+indiceBusca]] < 1){
            s++;
         }else{
            s+=indiceBusca - charNaoCompativel[textoCompleto[s+indiceBusca]];
         }
   }
   return frequenciaPadrao;
}