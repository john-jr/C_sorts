#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct Dado4
{
    int dado_interno;
    struct Dado4 *próximo_nó_esquerdo;
    struct Dado4 *próximo_nó_direito;
};
typedef struct Dado4 dado4;

/*struct Tree
{
    dado4 * dado;
    int nivel;
    int tamanho_total;
};
typedef struct Tree binaryTree;*/


dado4 *createNewDado4(int);

void startBinaryTree(int qnt_elementos)
{
    dado4 *dado_raiz = NULL;
    int escolha;
    for (int i = qnt_elementos; i > 0; i--)
    {
        if (i == qnt_elementos)
        {
            mountBinaryTree(&dado_raiz, i);
        }
        else
        {
            mountBinaryTree(&dado_raiz, rand() % (qnt_elementos + 5));
        }
    }

    printf("%d", dado_raiz->dado_interno);
    printf("\nEscolha um modelo de listagem:\n\n1 - Pre-ordem\n2 - Pós-ordem\n3- Em Ordem\n4 - Apenas a esquerda\n0 - Cancelar e sair\n\nEscolha: ");
    scanf("%d",&escolha);
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

    printf("O que deseja fazer agora?\n1 - Encontrar número\n2 - Excluir Número\n3 - Listar árvore novamente\n0 - Sair");
    scanf("%d",&escolha);




}

dado4 *createNewDado4(int dado_interno)
{
    dado4 *Novodado = malloc(sizeof(dado4));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó_esquerdo = NULL;
    Novodado->próximo_nó_direito = NULL;
    return Novodado;
}

int mountBinaryTree(dado4 **dado_raiz, int dado_interno)
{
    dado4 *raiz = *dado_raiz;
    if (raiz == NULL)
    {
        (*dado_raiz) = createNewDado4(dado_interno);
        return -1;
    }
    if (dado_interno < raiz->dado_interno)
    {
        return mountBinaryTree(&(raiz->próximo_nó_esquerdo), dado_interno);
    }
    else
    {
        return mountBinaryTree(&(raiz->próximo_nó_direito), dado_interno);
    }
}

int findDado4(dado4 *dado_raiz, int valor_pesquisado)
{
    if (dado_raiz == NULL)
    {
        return 0;
    }
    if (dado_raiz->dado_interno = valor_pesquisado)
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
        if (dado_raiz->dado_interno = valor_pesquisado)
        {
            if (dado_raiz->próximo_nó_direito != NULL)    // Caso o dado raiz tenha apenas filhos maiores que ele
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
                while (dado_substituto->próximo_nó_direito != NULL)  // <-- Busca o maior dado a partir do dado substituto
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

            return 0;
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
            return 1;
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
void printPostOrder(dado4 *dado_raiz)//Post Order is right -> left -> top
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