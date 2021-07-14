#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

struct Dado
{
    int dado_interno;
    struct Dado *próximo_nó;
    struct Dado *nó_anterior;
};
typedef struct Dado dado;

struct List
{
    dado *head;
};
typedef struct List linkedList;

dado *createNewDado(int);
dado *addNewDadoAtStart(dado **, dado *);
linkedList *createLinkedList();
bool isLinkedListCreated(linkedList *);
dado *createNewDado(int);
//bool isDadoCreated4(dado *);
dado *findDado(dado *, int);
dado *findDadobyPos(dado *, int);
void printLinkedList(dado *);
void removeDado(dado **, int);
void editDado(dado *, int, int);

void startLinkedList()
{
    linkedList *lista = createLinkedList();
    if (isLinkedListCreated(lista))
    {
        dado *novoDado = NULL;
        dado *dado_atual = NULL;

        int input_user, confirm_linkedlist;
        while (confirm_linkedlist != 2)
        {
            printf("\nDigite um valor: ");
            scanf("%d", &input_user);
            novoDado = createNewDado(input_user);

            if (/*isDadoCreated4(dado) ==*/true)
            {
                if (lista->head == NULL)
                {
                    lista->head = addNewDadoAtStart(&(lista->head), novoDado);
                }
                else
                {
                    addNewDado(dado_atual, novoDado);
                }
                dado_atual = novoDado;
                printf("Dado inserido na lista.\n\n Deseja inserir mais dados?\n1 - Sim, desejo inserir mais dados\n2 - Não,confirmar a lista\nEscolha: ");
                scanf("%d", &confirm_linkedlist);
            }
        }
        printLinkedList(lista->head);
        int escolha;
        while (escolha != 0 || (escolha > 3 && escolha < 0))
        {
            printf("\n\nO que deseja fazer?\n1 - Adicionar um novo Elemento\n2 - Editar um elemento da lista\n3 - Excluir um elemento da lista\n0 - Sair\n(Qualquer Opcao invalida tambem encerrara o programa)\n\nEscolha:");
            scanf("%d", &escolha);
            switch ((escolha))
            {
            case 1:;
                int novo_valor_adicionado, posicao_do_novo_valor;
                do
                {
                    printf("\n1 - Adicionar no ínicio da lista\n2 - Adicionar no Meio da Lista\n\nEscolha:");
                    scanf("%d", &escolha);
                } while (escolha < 0 && escolha > 2);
                printf("\nDigite o novo valor:");
                scanf("%d", &novo_valor_adicionado);
                novoDado = createNewDado(novo_valor_adicionado);
                if (/*isDadoCreated4(dado) ==*/true)
                {
                    if (escolha == 1)
                    {
                        lista->head = addNewDadoAtStart(&(lista->head), novoDado);
                    }
                    else
                    {
                        printf("\nDigite a posição do novo valor:");
                        scanf("%d", &posicao_do_novo_valor);
                        dado *dado_antigo = findDadobyPos(lista->head, posicao_do_novo_valor);
                        if (dado_antigo == NULL)
                        {
                            printf("Posição inválida!");
                            break;
                        }
                        addNewDado(dado_antigo, (createNewDado(novo_valor_adicionado)));
                    }
                }

                break;

            case 2:;
                int valor_antigo, novo_valor;
                printf("\nO sistema editará a primeira aquisição do dado encontrado\nDigite o valor que deseja editar:");
                scanf("%d", &valor_antigo);
                printf("\nDigite o novo valor:");
                scanf("%d", &novo_valor);
                editDado(lista->head, valor_antigo, novo_valor);
                break;

            case 3:;
                int valor_removido;
                printf("\nO sistema removerá a primeira aquisição do dado encontrado\nDigite o valor que deseja remover:");
                scanf("%d", &valor_removido);
                removeDado(&(lista->head), valor_removido);
                break;

            default:;

                break;
            }
            if (escolha != 0 || (escolha > 3 && escolha < 0))
            {
                printLinkedList(lista->head);
            }
        }
    }
}

void printLinkedList(dado *head)
{
    dado *ponteiro_de_busca = head;
    printf("\n\nListagem dos elementos: \n");
    while (ponteiro_de_busca != NULL)
    {
        printf("%d  ", ponteiro_de_busca->dado_interno);
        ponteiro_de_busca = ponteiro_de_busca->próximo_nó;
    }
}

linkedList *createLinkedList()
{
    linkedList *Novalista = (linkedList *)malloc(sizeof(linkedList));
    return Novalista;
};

bool isLinkedListCreated(linkedList *Novalista)
{
    if (Novalista == NULL)
    {
        printf("Error #2: Não foi possível alocar memória para a nova lista encadeada\nTente novamente mais tarde\n");
    }
    else
    {
        Novalista->head = NULL;
        return true;
    }
}

dado *createNewDado(int dado_interno)
{
    dado *Novodado = malloc(sizeof(dado));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó = NULL;
    Novodado->nó_anterior = NULL;
    return Novodado;
}

/*bool isDadoCreated(dado *dado)
{
    if (dado == NULL)
    {
        printf("Error #1: Não foi possível alocar memória para o novo dado\nTente novamente mais tarde\n");
    }
    else
    {
        return true;
    }
}
*/

void addNewDado(dado *dado_antigo, dado *Novodado)
{
    Novodado->próximo_nó = dado_antigo->próximo_nó;
    if (Novodado->próximo_nó != NULL)
    {
        Novodado->próximo_nó->nó_anterior = dado_antigo;
    }
    dado_antigo->próximo_nó = Novodado;
    Novodado->nó_anterior = dado_antigo;
}

dado *addNewDadoAtStart(dado **head, dado *Novodado)
{
    Novodado->próximo_nó = *head;
    if (*head != NULL)
    {
        (*head)->nó_anterior = Novodado;
    }
    *head = Novodado;
    Novodado->nó_anterior = NULL;
    return Novodado;
}

void removeDado(dado **head, int valor_removido)
{
    dado *objeto_auxilar = findDado(*head, valor_removido);
    if ((*head) == objeto_auxilar)
    {
        (*head) = objeto_auxilar->próximo_nó;
        if ((*head) != NULL)
        {
            (*head)->nó_anterior = NULL;
        }
        return;
    }
    else
    {
        objeto_auxilar->nó_anterior->próximo_nó = objeto_auxilar->próximo_nó;
        if (objeto_auxilar->próximo_nó != NULL)
        {
            objeto_auxilar->próximo_nó->nó_anterior = objeto_auxilar->nó_anterior;
        }
    }
    objeto_auxilar->próximo_nó = NULL;
    objeto_auxilar->nó_anterior = NULL;
    printf("Valor %d removido da lista.\n", &valor_removido);
}

void editDado(dado *head, int valor_antigo, int novo_valor)
{
    dado *dadoEditável = findDado(head, valor_antigo);
    if (dadoEditável == NULL)
    {
        printf("Dado não encontrado");
        return;
    }
    dadoEditável->dado_interno = novo_valor;
    printf("Dado Atualizado!\n");
}   

dado *findDado(dado *head, int valor_pesquisado)
{
    dado *objeto_auxiliar = head;

    while (objeto_auxiliar->próximo_nó != NULL)
    {
        if (objeto_auxiliar->dado_interno == valor_pesquisado)
        {
            return objeto_auxiliar;
        }
        objeto_auxiliar = objeto_auxiliar->próximo_nó;
    }
    return NULL;
}

dado *findDadobyPos(dado *head, int posicao_pesquisada)
{
    dado *objeto_auxiliar = head;

    for (int posicao = 0; objeto_auxiliar->próximo_nó != NULL; posicao++)
    {
        if (posicao == posicao_pesquisada)
        {
            return objeto_auxiliar;
        }
        objeto_auxiliar = objeto_auxiliar->próximo_nó;
    }
    return NULL;
}