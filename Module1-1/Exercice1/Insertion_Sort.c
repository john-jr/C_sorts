#include <stdio.h>
#include <stdlib.h>


void insertionSortArray(int *p, int tam_array){
   int auxiliar_cont,i,j;

    printf("\n\n--ORDENANDO--");

         for(i = 1; i < tam_array; i++){
            auxiliar_cont = p[i];
            j = i - 1;
               while (j >= 0 && p[j] > auxiliar_cont)
                  {
                  p[j+1] = p[j];
                  j--;
                  }
            p[j+1] = auxiliar_cont;
         }

  

     printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_array; auxiliar_cont++) {
          printf("%1d ", p[auxiliar_cont]);
        }

      free(p);
     
    
}
