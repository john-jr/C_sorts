#include "Dado.h";



struct dado * createNewDado(int dado_interno){
    dado *Novodado = malloc(sizeof(dado));
    Novodado->dado_interno = dado_interno;
    Novodado->proximo_no_esquerda = NULL;
    Novodado->proxino_no_direta = NULL;
    return Novodado;

};

struct dado * createNewDado(int dado_interno,dado* proximo_no_esquerda){
    dado *Novodado = malloc(sizeof(dado));
    Novodado->dado_interno = dado_interno;
    Novodado->proximo_no_esquerda = NULL;
    Novodado->proxino_no_direta = NULL;
    return Novodado;

};

struct dado * createNewDado(int dado_interno,dado* proximo_no_esquerda, dado* proximo_no_direita){
    dado *Novodado = malloc(sizeof(dado));
    Novodado->dado_interno = dado_interno;
    Novodado->proximo_no_esquerda = NULL;
    Novodado->proxino_no_direta = NULL;
    return Novodado;

};




bool isDado_Created(dado * dado){
    if(dado == NULL){
        errorMessages(1);
    }
    else{
        return true;
    }
}




