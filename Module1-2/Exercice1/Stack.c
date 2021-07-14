#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

struct Dado2
{
    int dado_interno;
    struct Dado2 *próximo_nó;
};
typedef struct Dado2 dado2;
struct Stack
{
    dado2 *topo;
};
typedef struct Stack pilha;

dado2 *createNewDado2(int);
dado2 *EmpilharDado(dado2 *, dado2 *);
dado2 *retirarUltimoDado(dado2 *);
pilha *createNewPilha();
bool isPilhaCreated(pilha *);
bool isDado2Created(dado2 *);

void startStack()
{

    pilha *NovaPilha = createNewPilha();
    dado2 *novoDado;
    if (isPilhaCreated(NovaPilha))
    {
        int input_user = 0, confirm_queue = 0;

        while (confirm_queue != 2)
        {
            printf("Digite um valor:");
            scanf("%d", &input_user);
            novoDado = createNewDado2(input_user);
            if (isDado2Created(novoDado) == true)
            {
                NovaPilha->topo = EmpilharDado(NovaPilha->topo, novoDado);
                printf("\nDado inserido na pilha.\n Deseja inserir mais dados?\n1 - Sim, desejo inserir mais dados\n2 - Não,confirmar a pilha\nEscolha: ");
                scanf("%d", &confirm_queue);
            }
        }
        printStack(NovaPilha->topo);
    }
}

pilha *createNewPilha()
{
    pilha *NovaPilha = malloc(sizeof(pilha));
    return NovaPilha;
}
bool isPilhaCreated(pilha *novaPilha)
{
    if (novaPilha == NULL)
    {
        printf("Error #2: Não foi possível alocar memória para a nova pilha\nTente novamente mais tarde\n");
    }
    else
    {
        novaPilha->topo = NULL;
        return true;
    }
}

dado2 *retirarUltimoDado(dado2 *head)
{
    if (head->próximo_nó == NULL)
    {
        return NULL;
    }
    head = head->próximo_nó;
    return head;
}

dado2 *EmpilharDado(dado2 *head, dado2 *Novodado)
{
    Novodado->próximo_nó = head;
    head = Novodado;
    return head;
}

dado2 *createNewDado2(int dado_interno)
{
    dado2 *Novodado = malloc(sizeof(dado2));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó = NULL;
    return Novodado;
}

bool isDado2Created(dado2 *novoDado)
{
    if (novoDado == NULL)
    {
        printf("Error #2: Não foi possível alocar memória para o novo dado\nTente novamente mais tarde\n");
    }
    else
    {
        return true;
    }
}

void printStack(dado2 *head)
{
    while (head != NULL)
    {
        printf("%d  ", head->dado_interno);
        head = retirarUltimoDado(head);
    }
}