#include <stdio.h>
#include <stdlib.h>

int * createArray(int *, int);
void bubbleSortArray(int *, int tam_array);

void WinMain(){
   int tam_array;\
   int *p; 
      printf("Digite a quantidade de elementos do vetor: ");
      scanf("%d",&tam_array);
   bubbleSortArray(createArray(&p, tam_array), tam_array);
}

int * createArray(int *p, int tam_array){
   int i;
   p = (int *)(calloc(tam_array , (sizeof(int))));
      if (p == NULL){
         printf("Memória Insuficiente, encerrando o programa...");
         system("pause");
         exit(1);
         }
   srand((unsigned)time(NULL)); 
      for (i = 0; i < tam_array; i++){
         p[i] = rand() % 11;
      }
    printf("Vetor Criado:\n");
      for (int i = 0;  i < tam_array; i++){
        printf("%1d ", p[i]);
      }
   return p;
}

void bubbleSortArray(int *p, int tam_array){
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
