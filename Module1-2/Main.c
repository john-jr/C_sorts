#include "Exercice1/LinkedList.c"
#include "Exercice1/Stack.c"
#include "Exercice1/Queues.c"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void WinMain(){
    int qnt_elementos,escolha_modeloEstrutura; 

      printf("Digite a quantidade de elementos a ser criada: ");
        scanf("%d",&qnt_elementos);


    printf("Escolha um modelo de estrutura: \n1 - Lista Concatenada \n2 - Pilha \n3- Fila \n\n0 - Cancelar e Sair\n\nEscolha: ");
    scanf("%d",&escolha_modeloEstrutura);

     switch (escolha_modeloEstrutura)
    {
         case 1:
        startLinkedList(qnt_elementos);
        break;

    case 2:
        startStack(qnt_elementos);
        break;

    case 3:
        StartQueue(qnt_elementos);
        break;
    }


    printf("\n\n");
   system("pause");
    exit(1);

}