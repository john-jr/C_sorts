#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


struct Dado4
{
    int dado_interno;
    struct Dado4 * próximo_nó_esquerdo;
    struct Dado4 * próximo_nó_direito;
    
};
typedef struct Dado4 dado4;

struct PaiFilho
{
    dado4 DadoPai;
    dado4 DadoAtual;
};


dado4 * createNewDado4(int);

void startBinaryTree(int qnt_elementos){
    dado4 * dado_raiz = NULL;
  for (int i = qnt_elementos;i > 0;i--){
     if(i == qnt_elementos ){
           mountBinaryTree(&dado_raiz,i);
     }
     else{
         mountBinaryTree(&dado_raiz,rand() % (qnt_elementos+5));
     }
  }
}

dado4 *createNewDado4(int dado_interno){
    dado4 *Novodado = malloc(sizeof(dado4));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó_esquerdo = NULL;
    Novodado->próximo_nó_direito = NULL;
    return Novodado;
}

int mountBinaryTree(dado4 ** dado_raiz,int dado_interno){
    dado4 * raiz = *dado_raiz;
    if(raiz == NULL){
        (*dado_raiz) = createNewDado4(dado_interno);
        return -1;
    }
    if(dado_interno < raiz->dado_interno){
        return mountBinaryTree(&(raiz->próximo_nó_esquerdo),dado_interno);
    } else{
        return mountBinaryTree(&(raiz->próximo_nó_direito),dado_interno);
    }
}

int findDado4(dado4 * dado_raiz, int valor_pesquisado){
    if(dado_raiz == NULL){
        return 0;
    }
    if(dado_raiz->dado_interno = valor_pesquisado){
        return 1;
    }
    if(valor_pesquisado < dado_raiz->dado_interno){
        return findDado4(dado_raiz->próximo_nó_esquerdo, valor_pesquisado);
    } else{
         return findDado4(dado_raiz->próximo_nó_direito, valor_pesquisado);
    }

}

void printInOrder(dado4 * dado_raiz){
    if(dado_raiz != NULL){
        printInOrder(dado_raiz->próximo_nó_esquerdo);
        printf("%d ",dado_raiz->dado_interno);
          printInOrder(dado_raiz->próximo_nó_direito);
    }
}
void printPostOrder(dado4 * dado_raiz){
  if(dado_raiz != NULL){
        printPostOrder(dado_raiz->próximo_nó_esquerdo);
        printPostOrder(dado_raiz->próximo_nó_direito);  
        printf("%d ",dado_raiz->dado_interno);
  }
      
}
void printPreOrder(dado4 * dado_raiz){
      if(dado_raiz != NULL){
        printf("%d ",dado_raiz->dado_interno);
        printPreOrder(dado_raiz->próximo_nó_esquerdo);
        printPreOrder(dado_raiz->próximo_nó_direito);
    }
}