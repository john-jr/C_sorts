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

int retirarUltimoDado(dado2 *);
dado2 * createNewDado2(int);

void startStack(int qnt_elementos){
    dado2 * head = NULL;
    for(int i = 0; i < qnt_elementos; i++){
        EmpilharDado(head,createNewDado (i+1));
    }
    printStack(head);

}

int retirarUltimoDado(dado2* head){
    if(head == NULL){
        return -1;
    }
    int dado_interno = head->dado_interno;
    head = head->próximo_nó;
    return dado_interno;
}

void EmpilharDado(dado2 * head,dado2 * Novodado){
    Novodado->próximo_nó = head;
    head = Novodado;
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
        dado_interno = retirarUltimoDado(head);
        printf("%d  ",dado_interno);
        }
}