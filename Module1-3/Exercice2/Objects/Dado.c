#include "Arvore.c";
#include "../Errors.c";


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>



bool isDadoCreated(dado*);
bool findDado(dado*,int);

struct dado_satelite
{
    int dado_interno;
    dado_da_arvore * proximo_no_esquerda;
    dado_da_arvore * proxino_no_direta;
};
typedef struct dado_satelite dado_da_arvore;

struct dado_da_arvore * createNewDado(int dado_interno){
   dado_da_arvore * Novodado = malloc(sizeof(dado)); 
    if(isDadoCreated(Novodado) == true){
        Novodado->dado_interno = dado_interno;
    }

};

bool isDadoCreated(dado * dado){
    if(dado == NULL){
        errorMessages(1);
    }
    else{
        return true;
    }
}

bool findDado(dado* dado, int valor_pesquisado){
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
}




