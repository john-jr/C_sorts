#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct Dado
{
    int dado_interno;
    struct Dado * próximo_nó;
    struct Dado * nó_anterior;
};
typedef struct Dado dado;

dado *createNewDado(int);
dado *addNewDadoAtStart(dado **, dado *);
dado *findDado(dado *, int);
void printLinkedList(dado *);

void startLinkedList(int qnt_elementos){
    dado *head = NULL;
    dado *objeto_auxiliar;
    for(int i = 1;i < qnt_elementos;i++){

        if(i == qnt_elementos){
            objeto_auxiliar = createNewDado(rand() % 10);
           addNewDadoAtStart(&head,objeto_auxiliar);
        }
    }
     printLinkedList(head);
}

void printLinkedList(dado *head){
    dado *ponteiro_de_busca = head;
    while(ponteiro_de_busca != NULL){
        printf("%d - ", ponteiro_de_busca->dado_interno);
        ponteiro_de_busca = ponteiro_de_busca->próximo_nó;
    }

}

dado *createNewDado(int dado_interno){
    dado *Novodado = malloc(sizeof(dado));
    Novodado->dado_interno = dado_interno;
    Novodado->próximo_nó = NULL;
    Novodado->nó_anterior = NULL;
    return Novodado;
}

void addNewDado(dado* dado_antigo ,dado* Novodado ){
    Novodado->próximo_nó = dado_antigo->próximo_nó;
    if(Novodado->próximo_nó != NULL){
        Novodado->nó_anterior->próximo_nó = dado_antigo;
    }
    dado_antigo->próximo_nó = Novodado;
    Novodado->nó_anterior = dado_antigo;
}

dado *addNewDadoAtStart(dado **head, dado *Novodado){
    Novodado->próximo_nó = *head;
    (*head)->nó_anterior = Novodado;
    *head = Novodado;
    return Novodado;
}

void removeDado(dado **head, int valor_removido){
    dado * objeto_auxilar = findDado(head, valor_removido);
    if(*head == objeto_auxilar){
        *head = objeto_auxilar->próximo_nó;
        if(*head != NULL){
            (*head)->nó_anterior = NULL;
        }
        return;
    } else {
        objeto_auxilar->nó_anterior->próximo_nó = objeto_auxilar->próximo_nó;
        if(objeto_auxilar->próximo_nó != NULL){
            objeto_auxilar->próximo_nó->nó_anterior = objeto_auxilar->nó_anterior;
        }
    }
    objeto_auxilar->próximo_nó = NULL;
    objeto_auxilar->nó_anterior = NULL;
}

void editDado(dado *head, int novo_valor){
        dado * dadoEditável = findDado(head, novo_valor);
        if(dadoEditável == NULL){
            printf("Dado não encontrado");
            return;
        }
        dadoEditável->dado_interno = novo_valor;
        printf("Valor Atualizado!");
}

dado *findDado(dado *head, int valor_pesquisado){
    dado *objeto_auxiliar = head;
    while (objeto_auxiliar->próximo_nó != NULL){
        if(objeto_auxiliar->dado_interno = valor_pesquisado){
            return objeto_auxiliar;
        }
        objeto_auxiliar = objeto_auxiliar->próximo_nó;
    }
    return NULL;
}





