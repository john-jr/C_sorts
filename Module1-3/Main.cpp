
#include "Exercice2/LinkedList.cpp"
#include <stdio.h>
#include <stdlib.h>

void WinMain(){
    int qnt_elementos,escolha_modeloEstrutura; 
    printf("Escolha um modelo de estrutura: \n1 - Lista Concatenada \n2 - Pilha \n3- Fila\n\n0 - Cancelar e Sair\n\nEscolha: ");
    scanf("%d",&escolha_modeloEstrutura);

     switch (escolha_modeloEstrutura)
    {
         case 1:
            startLinkedList();
        break;

    case 2:
      
        break;

    case 3:
    
        break;

    case 4:
     
    break;
    }


    printf("\n\n");
   system("pause");
    exit(1);
}