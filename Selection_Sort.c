#include <stdio.h>
#include <stdlib.h>
#define tam_Array 10

int WinMain(){
     int array_Num[tam_Array];
    int auxiliar_cont,pos_menor,i,j;

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

  /* Início do Algoritmo Selection Sort */
    for(i = 0; i < tam_Array; i++){
      pos_menor = i;
        for(int j = i+1; j < tam_Array ; j++){
          if(array_Num[j] < array_Num[pos_menor]){
              pos_menor = j;
          }
      }
    auxiliar_cont = array_Num[pos_menor];
    array_Num[pos_menor] =  array_Num[i];
    array_Num[i] = auxiliar_cont;
      
    }
    /*Fim do Algoritmo Selection Sort */ 

    printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_Array; auxiliar_cont++) {
          printf("%1d ", array_Num[auxiliar_cont]);
        }

}