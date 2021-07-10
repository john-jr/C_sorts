#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct Dado3
{
    int dado_interno;
    struct Dado3 * próximo_nó;
    
};
typedef struct Dado3 dado3;