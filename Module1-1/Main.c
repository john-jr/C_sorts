#include "Exercice1/Bubble_Sort.c"
#include "Exercice1/Insertion_Sort.c"
#include "Exercice1/Selection_Sort.c"
#include "Exercice2/Merge_Sort.c"
#include "Exercice3/Quick_Sort.c"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int * createArray(int *, int);

void WinMain(){
    int *p, escolha_Intmodord, tam_Intarray; 
    char tam_array,escolha_modOrd;
    float tempo_execucao;
  

//do{
     
    //if(isalpha(tam_array)){
    //  printf("\nPor Favor, digite um numero\n");
     // tam_array = getchar();
   // }
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d",&tam_Intarray);
//}while(isalpha(tam_array));
    
    
   
    //  do{
    printf("Escolha um modelo de ordenacao: \n1 - Bubble Sort \n2 - Selection Sort \n3 - Insertion Sort\n4 - Merge Sort\n5- Quick Sort\n0 - Cancelar e Sair\n\nEscolha: ");
    scanf("%d",&escolha_Intmodord);
    //  }while(escolha_Intmodord > 5 && escolha_Intmodord < 0 || isalpha(escolha_modOrd));

  
    switch (escolha_Intmodord)
    {
    case 1:
    bubbleSortArray(createArray(&p, tam_Intarray), tam_Intarray);  
        break;

    case 2:
     selectionSortArray(createArray(&p, tam_Intarray), tam_Intarray);
        break;

    case 3:
     insertionSortArray(createArray(&p, tam_Intarray), tam_Intarray);
        break;

    case 4:
    mergeSort(createArray(&p, tam_Intarray), tam_Intarray);
        break;    
    
    case 5:
    quickSort(createArray(&p, tam_Intarray), tam_Intarray);
        break;
    }


   system("\n\npause");
    exit(1);

}



int* createArray(int *p, int tam_array){
   int i;
   p = (int *)(calloc(tam_array , (sizeof(int))));
      if (p == NULL){
         printf("Memória Insuficiente, encerrando o programa...\n");
         system("pause");
         exit(1);
         }
   
      for (i = 0; i < tam_array; i++){
         p[i] = rand() % 10;
        
      }
    printf("\n\nVetor Criado:\n");
      for (int i = 0;  i < tam_array; i++){
        printf("%1d ", p[i]);
      }
   return p;
}
