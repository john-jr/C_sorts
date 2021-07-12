#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void mergeSort(int * p, int tam_array){ 
startDividing(p, (0), tam_array-1);
}


void startDividing(int *p , int comeco, int final){
  int meio_array;

  if(comeco < final){
    meio_array = floor((comeco+final)/2);
     printf("\nMeio: %d\n",meio_array);
   system("pause");
    startDividing(p, comeco,meio_array);
    startDividing(p, meio_array+1, final);
    startOrganizing(p, comeco, meio_array, final);
  }
   

    
}

void startOrganizing (int *p,int comeco, int meio_array, int final){

  printf("\nIncio: %d - Meio: %d - Fim: %d\n",comeco,meio_array,final);
    int tam_array = final - comeco +1;
    int pont_esquerdo = comeco;
    int pont_direito = meio_array+1;
    int fim_esquerdo = 0, fim_direito = 0;

   // printf("\n\nVetor Criado:\n");
   //  for (int i = 0;  i < tam_array; i++){
    //    printf("%1d ", p[i]);
    //  }
     // system("pause");

    int * pOrd = (int *)(malloc(tam_array *(sizeof(int))));
      if (pOrd == NULL){
         printf("Memória Insuficiente, encerrando o programa...\n");
         system("pause");
         exit(1);
         }

      for(int i = 0; i < tam_array; i++){
        if(fim_esquerdo == 0 && fim_direito == 0){
          if(p[pont_esquerdo] < p[pont_direito]){
            pOrd[i] = p[pont_esquerdo++];
          } else {
            pOrd[i] = p[pont_direito++];
          }
        if(pont_esquerdo > meio_array){
          fim_esquerdo = 1;
        }
        if(pont_direito > final){
          fim_direito = 1;
        }
        } else {
          if(fim_esquerdo == 0){
            pOrd[i] = p[pont_esquerdo++];
          } else {
            pOrd[i] = p[pont_direito++];
          }
        }
      }

      for (int i = 0,j = comeco;  i < tam_array; i++, j++){
       p[j] = pOrd[i];
      }

    printf("\n\nVetor Criado:\n");
      for (int i = 0;  i < tam_array; i++){
        printf("%1d ", p[i]);
      }

      free(pOrd);

}

