#include <stdio.h>
#include <stdlib.h>
#define tam_Array 10

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

  /* Início do Algoritmo Insertion Sort */
    for(i = 1; i < tam_Array; i++){
        auxiliar_cont = array_Num[i];
        j = i - 1;
            while (j >= 0 && array_Num[j] > auxiliar_cont)
            {
                array_Num[j+1] = array_Num[j];
                j--;
            }
            array_Num[j+1] = auxiliar_cont;
    }
    /*Fim do Algoritmo Insertion Sort */ 

    printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_Array; auxiliar_cont++) {
          printf("%1d ", array_Num[auxiliar_cont]);
        }

}