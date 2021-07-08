#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void quickSort(int *p, int tam_array){
 startSorting(p, (0), tam_array-1);

}


void startSorting(int *p , int comeco, int final){
  int elemento_central;
  if(comeco < final){
    elemento_central = startDiividing(p, comeco,final);
    startSorting(p, comeco,elemento_central-1);
    startSorting(p, elemento_central+1,final);
  }
 
   printf("\n\nVetor Ordenado:\n");
      for (int i = 0;  i < final -1; i++){
        printf("%1d ", p[i]);
      }
}

int startDiividing(int* p, int comeco, int final){
     int elemento_central = p[comeco];
      int variavel_auxiliar;
      int ponteiro_da_esquerda = comeco;
      int ponteiro_da_direita = final;     
      while(ponteiro_da_esquerda < ponteiro_da_direita){
        while(p[ponteiro_da_esquerda] <= elemento_central){
          ponteiro_da_esquerda++;
        }
        while(p[ponteiro_da_direita] > elemento_central){
          ponteiro_da_direita--;
        }
        if(ponteiro_da_esquerda < ponteiro_da_direita){
          variavel_auxiliar = p[ponteiro_da_esquerda];
          p[ponteiro_da_esquerda] = p[ponteiro_da_direita];
          p[ponteiro_da_direita] = variavel_auxiliar;
        }
      }
      p[comeco] = p[ponteiro_da_direita];
      p[ponteiro_da_direita] = elemento_central;
   
     return ponteiro_da_direita;
  }
   

