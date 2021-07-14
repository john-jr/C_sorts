#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

struct Dado2
{
    int dado_interno;
    struct Dado2 * próximo_nó;
    
};
typedef struct Dado2 dado2;
struct Stack
{
    dado2 * topo;
};
typedef struct Stack pilha;

dado2 * createNewDado2(int);
dado2 * EmpilharDado(dado2 *, dado2 *);
dado2 * retirarUltimoDado(dado2 *);
pilha * createNewPilha();
bool isPilhaCreated(pilha*);

void startStack(int qnt_elementos){
    
    pilha * NovaPilha = createNewPilha();
    dado4 * NovoDado;
    if(isPilhaCreated(NovaPilha)){
          int input_user=0, confirm_queue=0;
  
       head = EmpilharDado(head,createNewDado2 (i+1));
  
    printStack(head);
    }

}

pilha * createNewPilha(){
    pilha * NovaPilha = malloc(sizeof(pilha));
    return NovaPilha;
}
bool isPilhaCreated(pilha * novaPilha){
    if(novaPilha == NULL){
         printf("Error #2: Não foi possível alocar memória para a nova pilha\nTente novamente mais tarde\n");
    }
    else{
        return true;
    }
}


dado2 * retirarUltimoDado(dado2* head){
    if(head == NULL){
        return -1;
    }
    head = head->próximo_nó;
    return head;
}

dado2 * EmpilharDado(dado2 * head,dado2 * Novodado){
    Novodado->próximo_nó = head;
    head = Novodado;

   return head;
}

dado2 *createNewDado2(int dado_interno){
    dado2 *Novodado = malloc(sizeof(dado2));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó = NULL;
    return Novodado;
}

void printStack(dado2 *head){
    int dado_interno;
        while(dado_interno != -1){
        printf("%d  ",head->dado_interno);
        head = retirarUltimoDado(head);
        }
}*/