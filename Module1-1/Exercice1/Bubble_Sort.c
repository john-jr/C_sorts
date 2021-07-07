#include <stdio.h>
#include <stdlib.h>



void bubbleSortArray(int *p, int tam_array){

    printf("\n\n--ORDENANDO--");


   int auxiliar_cont,i,j;
     for (i = 1; i < tam_array; i++) {
      for (j = 0; j < tam_array - 1; j++) {
        if (p[j] > p[j + 1]) {
          auxiliar_cont = p[j];
         p[j] = p[j + 1];
         p[j + 1] = auxiliar_cont;
               }
            }
       }

     printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_array; auxiliar_cont++) {
          printf("%1d ", p[auxiliar_cont]);
        }

      free(p);
}
