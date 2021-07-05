#include <stdio.h>
#include <stdlib.h>
#define tam_Array 10000000

int WinMain(){
   int array_Num[tam_Array];
   int auxiliar_cont,i,j;

    printf("Pressione ENTER para iniciar!" );
    getchar();    
    printf("\nStart!\n\n" );
    srand(time(NULL)); 

    for (auxiliar_cont = 0; auxiliar_cont < tam_Array; auxiliar_cont++)
    {
       array_Num[auxiliar_cont] = rand() % 11;
    }
    
    printf("Vetor Criado:\n");
    for (auxiliar_cont = 0;  auxiliar_cont < tam_Array; auxiliar_cont++) {
        printf("%1d ", array_Num[auxiliar_cont]);
    }
    
    /* Início do Algoritmo Bubble Sort */
    for (i = 1; i < tam_Array; i++) {
      for (j = 0; j < tam_Array - 1; j++) {
        if (array_Num[j] > array_Num[j + 1]) {
          auxiliar_cont = array_Num[j];
         array_Num[j] = array_Num[j + 1];
         array_Num[j + 1] = auxiliar_cont;
        }
    }
 }
  /*Fim do Algoritmo Bubble Sort */ 

     printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_Array; auxiliar_cont++) {
          printf("%1d ", array_Num[auxiliar_cont]);
        }
}
