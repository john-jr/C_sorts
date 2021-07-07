#include <stdio.h>
#include <stdlib.h>


void selectionSortArray(int *p, int tam_array){
   int auxiliar_cont,i,j,pos_menor;

     printf("\n\n--ORDENANDO--");

      for(i = 0; i < tam_array; i++){
      pos_menor = i;
        for(int j = i+1; j < tam_array ; j++){
          if(p[j] < p[pos_menor]){
              pos_menor = j;
          }
      }
       auxiliar_cont = p[pos_menor];
       p[pos_menor] = p[i];
      p[i] = auxiliar_cont;
      
    }

     printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_array; auxiliar_cont++) {
          printf("%1d ", p[auxiliar_cont]);
        }

      free(p);
     
}
