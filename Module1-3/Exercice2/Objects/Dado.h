#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dado_satelite
{
    int dado_interno;
    dado * proximo_no_esquerda;
    dado * proxino_no_direta;
};
typedef struct dado_satelite dado;

bool isDado_Created(dado*);
bool findDado(dado*,int);
bool removeDado(dado*,int);

