#include "Arvore.h";

struct Arvore
{
    dado* dado;
    int tamanho_arvore;
    dado * proximo_no_esquerda;
    dado * proxino_no_direta;
};
typedef struct Arvore arvore; 


struct arvore * createNewArvore(){
    arvore * Novaarvore = malloc(sizeof(arvore)); 
    if(isArvoreCreatedNovaarvore(Novaarvore) == true){
        return Novaarvore;
    }
    return NULL;

};

bool isArvoreCreated(arvore * Novaarvore){
    if(Novaarvore == NULL){
        errorMessages(2);
    }
    else{
        return true;
    }
}

/*bool findDado(dado* dado, int valor_pesquisado){
    if(dado == NULL){
        return false;
    }
    if(dado->dado_interno == valor_pesquisado){
        return true;
    }

      if (valor_pesquisado < dado->dado_interno)
    {
        return findDado4(dado->proximo_no_esquerda, valor_pesquisado);
    }
    else
    {
        return findDado4(dado->proxino_no_direta, valor_pesquisado);
    }
}*/


/* 
bool removeDado(dado *dado_raiz, int valor_pesquisado)
{
    dado *dado_pai = NULL;
    dado *dado_substituto = NULL;
    dado *dado_paisubstituto = NULL;
    if (dado_raiz == NULL)
    {
        return false;
    }

    // While realiza a pesquisa dos valores até encontrar o dado pesquisa ou não encontrar nada
    while (dado_raiz != NULL)
    {
        // Remoção acontece a partir daqui
        if (dado_raiz->dado_interno == valor_pesquisado)
        {
            if (dado_raiz->proximo_no_esquerda!= NULL) // Caso o dado raiz tenha apenas filhos maiores que ele
            {
                dado_substituto = dado_raiz->proximo_no_esquerda;
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

            return true;
        }


        if (dado_raiz->dado_interno < valor_pesquisado)
        {
            dado_pai = dado_raiz;
            dado_raiz = dado_raiz->proximo_no_esquerda;
        }
        else
        {
            dado_pai = dado_raiz;
            dado_raiz = dado_raiz->proxino_no_direta;
        }
    }
}*/



