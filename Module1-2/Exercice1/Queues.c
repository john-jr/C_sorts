#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

void StartQueue(int qnt_elementos)
{
    fila filaReal, *fila;
    fila = &filaReal;
    fila->head = NULL;
    fila->tail = NULL;
    for (int i = 0; i < qnt_elementos; i++)
    {
        fila = AdicionarUltimoDaFila(fila, createNewDado3(i + 1));
    }
    printQueue(fila);
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

void printQueue(fila *fila)
{
    while (fila->head != NULL)
    {
        printf("%d  ", fila->head->dado_interno);
        fila->head = RemoverProximoDaFila(fila);
    }
}
