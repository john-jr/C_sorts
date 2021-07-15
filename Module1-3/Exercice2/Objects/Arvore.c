#include "Arvore.h";

struct Arvore
{
    dado* raiz;
    int tamanho_arvore;
   
};
typedef struct Arvore arvore; 




arvore *createNewArvore()
{
    arvore *Novaarvore = (arvore *)malloc(sizeof(arvore));
    return Novaarvore;
};

bool isArvoreCreated(arvore * Novaarvore){
    if(Novaarvore == NULL){
        errorMessages(2);
    }
    else{
        return true;
    }
}

int insertIntoTree(dado **dado_raiz_atual, dado *NovoDado)
{
    dado *objeto_auxiliar = *dado_raiz_atual;
    if (objeto_auxiliar == NULL)
    {
        (*dado_raiz_atual) = NovoDado;
        return -1;
    }
    if (NovoDado->dado_interno < objeto_auxiliar->dado_interno)
    {
        return insertIntoTree(&(objeto_auxiliar->proximo_no_esquerda), NovoDado);
    }
    else
    {
        return insertIntoTree(&(objeto_auxiliar->proxino_no_direta), NovoDado);
    }
}

void receiveDataFromUserToInsertIntoTree(arvore *NovaArvore)
{
    dado *dado = NULL;
    int input_user, confirm_tree;
    while (confirm_tree != 2)
    {
        printf("\nDigite o nó: ");
        scanf("%d", &input_user);
        dado = createNewDado(input_user);
        if (isDado4Created(dado) == true)
        {
            if (NovaArvore->raiz == NULL)
            {
               NovaArvore->raiz = dado;
            }
            else
            {
                insertIntoTree(&(NovaArvore->raiz), dado);
            }
            printf("Dado inserido na árvore.\n\n Deseja inserir mais dados?\n1 - Sim, desejo inserir mais dados\n2 - Não,confirmar a árvore\nEscolha: ");
            scanf("%d", &confirm_tree);
        }
    }
}

int findDadoInThisTree(dado *dado_raiz_atual, int valor_pesquisado)
{
    if (dado_raiz_atual == NULL)
    {
        return 0;
    }
    if (dado_raiz_atual->dado_interno == valor_pesquisado)
    {
        return 1;
    }
    if (valor_pesquisado < dado_raiz_atual->dado_interno)
    {
        return findDado4(dado_raiz_atual->proximo_no_esquerda, valor_pesquisado);
    }
    else
    {
        return findDado4(dado_raiz_atual->proxino_no_direta, valor_pesquisado);
    }
}

void printTreeInOrder(dado *dado_raiz) //In order is left -> top -> right
{
    if (dado_raiz != NULL)
    {
        printInOrder(dado_raiz->proximo_no_esquerda);
        printf("%d ", dado_raiz->dado_interno);
        printInOrder(dado_raiz->proxino_no_direta);
    }
}
void printTreeInPostOrder(dado *dado_raiz) //Post Order is right -> left -> top
{
    if (dado_raiz != NULL)
    {
        printPostOrder(dado_raiz->proximo_no_esquerda);
        printPostOrder(dado_raiz->proxino_no_direta);
        printf("%d ", dado_raiz->dado_interno);
    }
}
void printTreeInPreOrder(dado *dado_raiz) //Pre-order is top -> left -> right
{
    if (dado_raiz != NULL)
    {
        printf("%d ", dado_raiz->dado_interno);
        printPreOrder(dado_raiz->proximo_no_esquerda);
        printPreOrder(dado_raiz->proxino_no_direta);
    }
}

int removeDadoFromThisTree(dado *dado_raiz, int valor_pesquisado)
{
    dado *dado_pai = NULL;
    dado *dado_substituto = NULL;
    dado *dado_paisubstituto = NULL;
    if (dado_raiz == NULL)
    {
        return 0;
    }
    while (dado_raiz != NULL)
    {
        if (dado_raiz->dado_interno == valor_pesquisado)
        {
            if (dado_raiz->proxino_no_direta != NULL) // Caso o próxino nó do dado raiz tenha apenas filhos maiores que ele
            {
                dado_substituto = dado_raiz->proxino_no_direta;
                dado_paisubstituto = dado_raiz;
                while (dado_substituto->proximo_no_esquerda != NULL) // <-- Busca o menor dado a partir do dado substituto
                {
                    dado_paisubstituto = dado_substituto;
                    dado_substituto = dado_substituto->proximo_no_esquerda;
                }

                if (dado_pai != NULL)
                {
                    if (dado_raiz->dado_interno > dado_pai->dado_interno)
                    {
                        dado_pai->proxino_no_direta = dado_substituto;
                    }
                    else
                    {
                        dado_pai->proximo_no_esquerda = dado_substituto;
                    }
                }
                else
                {
                    dado_raiz = dado_substituto;
                  
                }

                if (dado_substituto->dado_interno > dado_paisubstituto->dado_interno)
                {
                    dado_paisubstituto->proxino_no_direta = NULL;
                }
                else
                {
                    dado_paisubstituto->proximo_no_esquerda = NULL;
                }
                  return dado_raiz;
            }
            else if (dado_raiz->proximo_no_esquerda != NULL) // Caso o dado raiz tenha apenas filhos menores que ele
            {
                dado_substituto = dado_raiz->proximo_no_esquerda;
                dado_paisubstituto = dado_raiz;
                while (dado_substituto->proxino_no_direta != NULL) // <-- Busca o maior dado a partir do dado substituto
                {
                    dado_paisubstituto = dado_substituto;
                    dado_substituto = dado_substituto->proxino_no_direta;
                }

                if (dado_pai != NULL)
                {
                    if (dado_raiz->dado_interno > dado_pai->dado_interno)
                    {
                        dado_pai->proxino_no_direta = dado_substituto;
                    }
                    else
                    {
                        dado_pai->proximo_no_esquerda = dado_substituto;
                    }
                }
                else
                {
                    dado_raiz = dado_substituto;
                    return dado_raiz;
                }

                if (dado_substituto->dado_interno > dado_paisubstituto->dado_interno)
                {
                    dado_paisubstituto->proxino_no_direta = NULL;
                }
                else
                {
                    dado_paisubstituto->proximo_no_esquerda = NULL;
                }
            }
            else // Caso o dado raiz não tenha nó filhos..
            {
                if (dado_pai != NULL)
                {
                    if (dado_raiz->dado_interno > dado_pai->dado_interno)
                    {
                        dado_pai->proxino_no_direta = NULL;
                    }
                    else
                    {
                        dado_pai->proximo_no_esquerda = NULL;
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
            dado_raiz = dado_raiz->proxino_no_direta;
        }
        else
        {
            dado_pai = dado_raiz;
            dado_raiz = dado_raiz->proximo_no_esquerda;
        }
        if (dado_raiz == NULL)
        {
            return 0;
        }
    }
}