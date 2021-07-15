#include <stdio.h>
#include <stdlib.h>

void errorMessages(int code){
    switch (code)
    {
    case 1:
        printf("Error #1: Não foi possível alocar memória para o novo dado\nTente novamente mais tarde\n");
        break;
    case 2:
        printf("Error #2: Não foi possível alocar memória para a nova árvore\nTente novamente mais tarde\n");
        break;

    }
}