#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

struct Dado3
{
    int dado_interno;
    struct Dado3 *próximo_nó;
};
typedef struct Dado3 dado3;
struct Fila
{
    dado3 *head;
    dado3 *tail;
};
typedef struct Fila fila;

dado3 *createNewDado3(int);
fila *AdicionarUltimoDaFila(fila *, dado3 *);
void printQueue(fila*);
fila * createNewFila();
bool isFilaCreated(fila*);
bool isDado3Created(dado3*);

void StartQueue()
{
    fila * novaFila = createNewFila();
    dado3* novoDado;
    if(isFilaCreated(novaFila)){
        int input_user=0, confirm_queue=0;
        while (confirm_queue != 2)
        {
           printf("Digite um valor:");
           scanf("%d",&input_user);
           novoDado = createNewDado3(input_user);
           if(isDado3Created(novoDado) == true){
            novaFila = AdicionarUltimoDaFila(novaFila, novoDado);
            printf("\nDado inserido na fila.\n Deseja inserir mais dados?\n1 - Sim, desejo inserir mais dados\n2 - Não,confirmar a fila\nEscolha: ");
            scanf("%d", &confirm_queue);
           }

        }
             printQueue(novaFila);
    }
}

fila *AdicionarUltimoDaFila(fila *fila, dado3 *Novodado)
{
    if (fila->tail != NULL)
    {
        fila->tail->próximo_nó = Novodado;
    }
    fila->tail = Novodado;
    if (fila->head == NULL)
    {
        fila->head = Novodado;
    }
    return fila;
}

dado3 *RemoverProximoDaFila(fila *fila)
{
    fila->head = fila->head->próximo_nó;
    if (fila->head == NULL)
    {
        fila->tail = NULL;
        return fila->head;
    }
    return fila->head;
}

dado3 *createNewDado3(int dado_interno)
{
    dado3 *Novodado = malloc(sizeof(dado3));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó = NULL;
    return Novodado;
}

bool isDado3Created(dado3 * novoDado){
    if (novoDado == NULL)
    {
          printf("Error #2: Não foi possível alocar memória para o novo dado\nTente novamente mais tarde\n");
    }
    else
    {
        return true;
    }
    
}

void printQueue(fila *fila)
{
    while (fila->head != NULL)
    {
        printf("%d  ", fila->head->dado_interno);
        fila->head = RemoverProximoDaFila(fila);
    }
}

fila * createNewFila(){
    fila * novaFila = malloc(sizeof(fila));
    return novaFila;
}

bool isFilaCreated(fila * novaFila){
    if(novaFila == NULL){
        printf("Error #2: Não foi possível alocar memória para a nova fila\nTente novamente mais tarde\n");
    }
    else{
        novaFila->head = NULL;
        novaFila->tail = NULL;
        return true;
    }
}