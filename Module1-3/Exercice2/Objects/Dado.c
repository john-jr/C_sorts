#include "Dado.h";

struct dado * createNewDado(int dado_interno){
    dado * Novodado = malloc(sizeof(dado)); 
    if(isDadoCreated(Novodado) == true){
        Novodado->dado_interno = dado_interno;
        return Novodado;
    }
    return NULL;

};

bool isDado_Created(dado * dado){
    if(dado == NULL){
        errorMessages(1);
    }
    else{
        return true;
    }
}




