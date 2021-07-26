#include "Dado.cpp"

class Pilha
{
private:
    Dado *top;
       
public:
    Pilha(){
        this->top = NULL;
    }

    Dado *  ApresentarTopo()
    {
        return this->top;
    }

    void Empilhar(Dado *Novotop)
    {
        Dado *dado_auxiliar = this->top;
        this->top = Novotop;
        Novotop->setProximo_no(dado_auxiliar);
    }


};

void startStack(){

}


Pilha *createNewPilha(){
    Pilha * NovaPilha = new Pilha();
    return NovaPilha;
}

bool isPilhaCreated(Pilha * novaPilha){
    if(novaPilha == NULL)
    {
        printf("Error #2: Não foi possível alocar memória para a nova pilha\nTente novamente mais tarde\n");
        return false;
    }
    else
    {
        return true;
    }
}

void printStack(Pilha novaPilha)
{
    novaPilha->

    while (novaPilh)
    {
        /* code */
    }
    

   
}
