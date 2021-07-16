#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class Dado
{
private:
    int dado_interno;
    Dado *proximo_no;
    Dado *no_anterior;
public:
    Dado(int data){
        dado_interno = data;
        proximo_no = NULL;
        no_anterior = NULL;
    }


    int getDado_interno()
    {
        return dado_interno;
    }

    void setDado_interno(int dado_interno){
        this->dado_interno = dado_interno;
    }

    Dado*getProximo_no()
    {
        return proximo_no;
    }

    void setProximo_no(Dado*proximo_no)
    {
       this->proximo_no = proximo_no;
    }

    Dado*getNo_anterior()
    {
        return no_anterior;
    }


    void setNo_anterior(Dado*no_anterior)
    {
        this->no_anterior = no_anterior;
    }
};

Dado * createNewDado(int dado_interno){
    Dado * Novodado = new Dado(dado_interno);
    return Novodado;
}

bool isDadoCreated(Dado *dado)
{
    if (dado == NULL)
    {
        printf("Error #1: Não foi possível alocar memória para o novo dado\nTente novamente mais tarde\n");
        return false;
    }
    else
    {
        dado->setNo_anterior(NULL);
        dado->setProximo_no(NULL);
        return true;
    }
}

