#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

struct Dado4
{
    int dado_interno;
    int nivel;
    struct Dado4 *próximo_nó_esquerdo;
    struct Dado4 *próximo_nó_direito;
};
typedef struct Dado4 dado4;

struct Tree
{
    dado4 *raiz;
    int altura;
};
typedef struct Tree binaryTree;

dado4 *createNewDado4(int);

void startBinaryTree(int qnt_elementos)
{
    dado4 *dado = NULL;
    binaryTree *arvore = createNewArvore();

    if (isArvoreCreated(arvore))
    {
        int escolha, numero_pesquisado, input_user;
        printf("\nDigite o nó: ");
        scanf("%d", input_user);
        dado = createNewDado4(input_user);
        if (isDadoCreated(dado))
        {

            if (arvore->raiz == NULL)
            {
                arvore->raiz = dado;
            }
            else
            {
                insertIntoTree(arvore->raiz, dado);
            }
        }

        /*while (escolha != 0)
        {
            printf("\nEscolha um modelo de listagem:\n\n1 - Pre-ordem\n2 - Pos-ordem\n3- Em Ordem\n4 - Apenas a esquerda\n0 - Cancelar e sair\n\nEscolha: ");
            scanf("%d", &escolha);
            switch (escolha)
            {
            case 1:
                printPreOrder(dado_raiz);
                break;

            case 2:
                printPostOrder(dado_raiz);
                break;
            case 3:
                printInOrder(dado_raiz);
                break;
            case 4:
                printLeftLook(dado_raiz);
                break;

            default:

                break;
            }

            if (escolha != 0)
            {
                printf("\nO que deseja fazer agora?\n1 - Encontrar número\n2 - Excluir Número\n3 - Listar árvore novamente\n0 - Sair");
                scanf("%d", &escolha);
                if (escolha == 1)
                {
                    printf("\nDigite o número a ser pesquisado: ");
                    scanf("%d", &numero_pesquisado);
                    if (findDado4(dado, numero_pesquisado) == 0)
                    {
                        printf("%d não existe na árvore", numero_pesquisado);
                    }
                    else
                    {
                        printf("%d existe na árvore", numero_pesquisado);
                    }
                }
                else if (escolha == 2)
                {
                    printf("\nDigite o número a ser excluído: ");
                    scanf("%d", &numero_pesquisado);
                    if (RemoveDado4(dado, numero_pesquisado) == 0)
                    {
                        printf("%d não existe na árvore", numero_pesquisado);
                    }
                    else
                    {
                        printf("O primeiro %d encontrado foi excluído da árvore", numero_pesquisado);
                    }
                }
            }
        }*/
    }
}

dado4 *createNewDado4(int dado_interno)
{
    dado4 *Novodado = malloc(sizeof(dado4));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó_esquerdo = NULL;
    Novodado->próximo_nó_direito = NULL;
    return Novodado;
}

bool isDadoCreated(dado *dado)
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

binaryTree *createNewArvore()
{
    binaryTree *Novaarvore = (binaryTree *)malloc(sizeof(binaryTree));
    return Novaarvore;
};

bool isArvoreCreated(binaryTree *Novaarvore)
{
    if (Novaarvore == NULL)
    {
        printf("Error #2: Não foi possível alocar memória para a nova árvore\nTente novamente mais tarde\n");
    }
    else
    {
        Novaarvore->raiz = NULL;
        Novaarvore->altura = 0;
        return true;
    }
}

int insertIntoTree(dado4 ** dado_raiz, dado4 *dado)
{

    if (dado_raiz == NULL)
    {
      dado_raiz = dado;
        return -1;
    }
    if (dado->dado_interno < dado_raiz->dado_interno)
    {
        return insertIntoTree(&(dado_raiz->próximo_nó_esquerdo), dado);
    }
    else
    {
        return insertIntoTree(&(dado_raiz->próximo_nó_direito), dado);
    }
}

int findDado4(dado4 *dado_raiz, int valor_pesquisado)
{
    if (dado_raiz == NULL)
    {
        return 0;
    }
    if (dado_raiz->dado_interno == valor_pesquisado)
    {
        return 1;
    }
    if (valor_pesquisado < dado_raiz->dado_interno)
    {
        return findDado4(dado_raiz->próximo_nó_esquerdo, valor_pesquisado);
    }
    else
    {
        return findDado4(dado_raiz->próximo_nó_direito, valor_pesquisado);
    }
}

int RemoveDado4(dado4 *dado_raiz, int valor_pesquisado)
{
    dado4 *dado_pai = NULL;
    dado4 *dado_substituto = NULL;
    dado4 *dado_paisubstituto = NULL;
    if (dado_raiz == NULL)
    {
        return 0;
    }
    while (dado_raiz != NULL)
    {
        if (dado_raiz->dado_interno == valor_pesquisado)
        {
            if (dado_raiz->próximo_nó_direito != NULL) // Caso o dado raiz tenha apenas filhos maiores que ele
            {
                dado_substituto = dado_raiz->próximo_nó_direito;
                dado_paisubstituto = dado_raiz;
                while (dado_substituto->próximo_nó_esquerdo != NULL) // <-- Busca o menor dado a partir do dado substituto
                {
                    dado_paisubstituto = dado_substituto;
                    dado_substituto = dado_substituto->próximo_nó_esquerdo;
                }

                if (dado_pai != NULL)
                {
                    if (dado_raiz->dado_interno > dado_pai->dado_interno)
                    {
                        dado_pai->próximo_nó_direito = dado_substituto;
                    }
                    else
                    {
                        dado_pai->próximo_nó_esquerdo = dado_substituto;
                    }
                }
                else
                {
                    dado_raiz = dado_substituto;
                }

                if (dado_substituto->dado_interno > dado_paisubstituto->dado_interno)
                {
                    dado_paisubstituto->próximo_nó_direito = NULL;
                }
                else
                {
                    dado_paisubstituto->próximo_nó_esquerdo = NULL;
                }
            }
            else if (dado_raiz->próximo_nó_esquerdo != NULL) // Caso o dado raiz tenha apenas filhos menores que ele
            {
                dado_substituto = dado_raiz->próximo_nó_esquerdo;
                dado_paisubstituto = dado_raiz;
                while (dado_substituto->próximo_nó_direito != NULL) // <-- Busca o maior dado a partir do dado substituto
                {
                    dado_paisubstituto = dado_substituto;
                    dado_substituto = dado_substituto->próximo_nó_direito;
                }

                if (dado_pai != NULL)
                {
                    if (dado_raiz->dado_interno > dado_pai->dado_interno)
                    {
                        dado_pai->próximo_nó_direito = dado_substituto;
                    }
                    else
                    {
                        dado_pai->próximo_nó_esquerdo = dado_substituto;
                    }
                }
                else
                {
                    dado_raiz = dado_substituto;
                }

                if (dado_substituto->dado_interno > dado_paisubstituto->dado_interno)
                {
                    dado_paisubstituto->próximo_nó_direito = NULL;
                }
                else
                {
                    dado_paisubstituto->próximo_nó_esquerdo = NULL;
                }
            }
            else // Caso o dado raiz não tenha nó filhos..
            {
                if (dado_pai != NULL)
                {
                    if (dado_raiz->dado_interno > dado_pai->dado_interno)
                    {
                        dado_pai->próximo_nó_direito = NULL;
                    }
                    else
                    {
                        dado_pai->próximo_nó_esquerdo = NULL;
                    }
                }
                else
                {
                    dado_raiz = NULL;
                }
            }

            return 1;
        }

        if (dado_raiz->dado_interno < valor_pesquisado)
        {
            dado_pai = dado_raiz;
            dado_raiz = dado_raiz->próximo_nó_esquerdo;
        }
        else
        {
            dado_pai = dado_raiz;
            dado_raiz = dado_raiz->próximo_nó_direito;
        }
        if (dado_raiz == NULL)
        {
            return 0;
        }
    }
}

void printInOrder(dado4 *dado_raiz) //In order is left -> top -> right
{
    if (dado_raiz != NULL)
    {
        printInOrder(dado_raiz->próximo_nó_esquerdo);
        printf("%d ", dado_raiz->dado_interno);
        printInOrder(dado_raiz->próximo_nó_direito);
    }
}
void printPostOrder(dado4 *dado_raiz) //Post Order is right -> left -> top
{
    if (dado_raiz != NULL)
    {
        printPostOrder(dado_raiz->próximo_nó_esquerdo);
        printPostOrder(dado_raiz->próximo_nó_direito);
        printf("%d ", dado_raiz->dado_interno);
    }
}
void printPreOrder(dado4 *dado_raiz) //Pre-order is top -> left -> right
{
    if (dado_raiz != NULL)
    {
        printf("%d ", dado_raiz->dado_interno);
        printPreOrder(dado_raiz->próximo_nó_esquerdo);
        printPreOrder(dado_raiz->próximo_nó_direito);
    }
}

void printLeftLook(dado4 *dado_raiz)
{
    if (dado_raiz != NULL)
    {
        printf("%d ", dado_raiz->dado_interno);
        printLeftLook(dado_raiz->próximo_nó_esquerdo);
    }
}