#include "Exercice1/LinkedList.c"
#include "Exercice1/Stack.c"
#include "Exercice1/Queues.c"
#include "Exercice2/BinaryTree.c"


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void WinMain(){
    int qnt_eleme6ntos,escolha_modeloEstrutura; 

    printf("Escolha um modelo de estrutura: \n1 - Lista Concatenada \n2 - Pilha \n3- Fila\n4 - Arvore Binaria de Busca \n\n0 - Cancelar e Sair\n\nEscolha: ");
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
        startBinaryTree();
    break;
    }


    printf("\n\n");
   system("pause");
    exit(1);

}