#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

void errorMessages(int code){
    switch (code)
    {
    case 1:
        printf("Error #1: Não foi possível alocar memória para o novo dado\nTente novamente mais tarde\n");
        break;
    }
}