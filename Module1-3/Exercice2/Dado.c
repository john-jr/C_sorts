#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#include "../../Module1-3/Errors.c";

bool isDadoCreated(dado*);
bool findDado(dado*,int);

typedef struct dado_satelite{
    int dado_interno;
    dado * proximo_no_esquerda;
    dado * proxino_na_direta;
} dado;

struct dado * createNewDado(int dado_interno){
    dado * Novodado = malloc(sizeof(dado)); 
    if(isDadoCreated(Novodado) == true){
        Novodado->dado_interno = dado_interno;

}

bool isDadoCreated(dado * dado){
    if(dado == NULL){
        errorMessages(1);
    }
    else{
        return true
    }
}

struct bool findDado(dado* dado, int valor_pesquisado){
    if(dado == NULL){

    }
    if(dado)
}




