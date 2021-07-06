#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam_Array 10

void WinMain(){
    int array_Num[tam_Array], meio, *p;
    int auxiliar_cont,i,j;

    meio = floor(tam_Array/2);

     srand(time(NULL)); 
    for (auxiliar_cont = 0; auxiliar_cont < tam_Array; auxiliar_cont++){
       array_Num[auxiliar_cont] = rand() % 11;
    }

    *p = mergeSort(array_Num);
    
    printf("\n\nVetor Ordenado:\n");
     for (auxiliar_cont = 0;  auxiliar_cont < tam_Array; auxiliar_cont++) {
          printf("%1d ", p[auxiliar_cont]);
        }

}

int*mergeSort(int * p){

    return p;
}