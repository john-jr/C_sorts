#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct Dado2
{
    int dado_interno;
    struct Dado2 * próximo_nó;
    
};
typedef struct Dado2 dado2;


dado2 * createNewDado2(int);
dado2 * EmpilharDado(dado2 *, dado2 *);
dado2 * retirarUltimoDado(dado2 *);

void startStack(int qnt_elementos){
    dado2 * head = NULL;
    for(int i = 0; i < qnt_elementos; i++){
       head = EmpilharDado(head,createNewDado (i+1));
    }
    printStack(head);

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
}