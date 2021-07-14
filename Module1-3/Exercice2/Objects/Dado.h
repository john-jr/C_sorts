#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isDado_Created(dado*);
bool findDado(dado*,int);
bool removeDado(dado*,int);

struct dado_satelite
{
    int dado_interno;
    int nivel_dado;
 
};
typedef struct dado_satelite dado;