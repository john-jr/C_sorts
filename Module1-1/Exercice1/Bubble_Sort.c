#include <stdio.h>
#include <stdlib.h>



void bubbleSortArray(int *p, int tam_array){

   


   int auxiliar_cont,vetor_organizado;
    for (int i = 1; i < tam_array ;i++) {
      vetor_organizado = 1;
      for (int j = 0; j < ((tam_array - i)); j++) {
        if (p[j] > p[j + 1]) {
          auxiliar_cont = p[j];
          p[j] = p[j + 1];
          p[j + 1] = auxiliar_cont;
          vetor_organizado = 0;
             } 
          }
          if(vetor_organizado == 1){
            break;
          }
       }

     printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_array; auxiliar_cont++) {
          printf("%1d ", p[auxiliar_cont]);
        }

      free(p);
}
