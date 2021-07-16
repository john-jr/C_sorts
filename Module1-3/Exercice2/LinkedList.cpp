#include "Dado.cpp"

// Note: Modificar dado para nó
class Lista
{
private:
    Dado *head;

public:
    Lista()
    {
        head = NULL;
    }

    Dado *getHead()
    {
        return head;
    }

    void PushHead(Dado *Novahead)
    {
        Dado *dado_auxiliar = this->head;
        this->head = Novahead;
        this->head->setProximo_no(dado_auxiliar);
        dado_auxiliar->setNo_anterior(this->head);
    }
};

void startLinkedList();
Lista *createLinkedList();
bool isLinkedListCreated(Lista *);
void receiveInputFromUserToInsertIntoList(Lista *);
void printLinkedList(Lista *);
void addNewDadoAfterElemnt(Dado *, Dado *);
Dado *findDado(Dado *, int);
Dado *findDadobyPos(Dado *, int);
void ListOptionsMenu(Lista *);
void editDado(Dado *, int, int);
void removeDado(Dado *, int);

void startLinkedList()
{
    Lista *Novalista = createLinkedList();
    if (isLinkedListCreated(Novalista) == true)
    {
        receiveInputFromUserToInsertIntoList(Novalista);
    }
    printLinkedList(Novalista);
    ListOptionsMenu(Novalista);
}

Lista *createLinkedList()
{
    Lista *Novalista = new Lista();
    return Novalista;
};

bool isLinkedListCreated(Lista *Novalista)
{
    if (Novalista == NULL)
    {
        printf("Error #2: Não foi possível alocar memória para a nova lista encadeada\nTente novamente mais tarde\n");
        return false;
    }
    else
    {
        Novalista->PushHead(NULL);
        return true;
    }
}

void receiveInputFromUserToInsertIntoList(Lista *Novalista)
{
    int input_user, confirm_linkedlist;

    Dado *dado_atual = NULL;
    while (confirm_linkedlist != 2)
    {
        printf("\nDigite um valor: ");
        scanf("%d", &input_user);
        Dado *novoDado = createNewDado(input_user);
        if (isDadoCreated(novoDado) == true)
        {
            Novalista->PushHead(novoDado);
            printf("Dado inserido na lista.\n\n Deseja inserir mais dados?\n1 - Sim, desejo inserir mais dados\n2 - Não,confirmar a lista\nEscolha: ");
            scanf("%d", &confirm_linkedlist);
        }
    }
}

void printLinkedList(Lista *novaLista)
{
    Dado *ponteiro_de_busca = novaLista->getHead();
    printf("\n\nListagem dos elementos: \n");
    while (ponteiro_de_busca != NULL)
    {
        printf("%d  ", ponteiro_de_busca->getDado_interno());
        ponteiro_de_busca = ponteiro_de_busca->getProximo_no();
    }
}

void addNewDadoAfterElement(Dado *dado_antigo, Dado *Novodado)
{
    Novodado->setProximo_no(dado_antigo->getProximo_no());
    dado_antigo->setProximo_no(Novodado);
    Novodado->setNo_anterior(dado_antigo);
    Novodado->getProximo_no()->setNo_anterior(Novodado);
}

Dado *findDado(Dado *head, int valor_pesquisado)
{
    Dado *objeto_auxiliar = head;

    while (objeto_auxiliar->getProximo_no() != NULL)
    {
        if (objeto_auxiliar->getDado_interno() == valor_pesquisado)
        {
            return objeto_auxiliar;
        }
        objeto_auxiliar = objeto_auxiliar->getProximo_no();
    }
    return NULL;
}

Dado *findDadobyPos(Dado *head, int posicao_pesquisada)
{
    Dado *objeto_auxiliar = head;

    for (int posicao = 0; objeto_auxiliar->getProximo_no() != NULL; posicao++)
    {
        if (posicao == posicao_pesquisada)
        {
            return objeto_auxiliar;
        }
        objeto_auxiliar = objeto_auxiliar->getProximo_no();
    }
    return NULL;
}

void ListOptionsMenu(Lista *Novalista)
{
    int escolha;

    while (escolha != 0 || (escolha > 3 && escolha < 0))
    {
        printf("\n\nO que deseja fazer?\n1 - Adicionar um novo Elemento\n2 - Editar um elemento da lista\n3 - Excluir um elemento da lista\n0 - Sair\n(Qualquer Opcao invalida tambem encerrara o programa)\n\nEscolha:");
        scanf("%d", &escolha);
        switch ((escolha))
        {
        case 1:
        {
            int novo_valor_adicionado, posicao_do_novo_valor;
            do
            {
                printf("\n1 - Adicionar no ínicio da lista\n2 - Adicionar no Meio da Lista\n\nEscolha:");
                scanf("%d", &escolha);
            } while (escolha < 0 && escolha > 2);
            printf("\nDigite o novo valor:");
            scanf("%d", &novo_valor_adicionado);
            Dado *novoDado = createNewDado(novo_valor_adicionado);
            if (isDadoCreated(novoDado) == true)
            {
                if (escolha == 1)
                {
                    Novalista->PushHead(novoDado);
                }
                else
                {
                    printf("\nDigite a posição do novo valor:");
                    scanf("%d", &posicao_do_novo_valor);
                    Dado *dado_antigo = findDadobyPos(Novalista->getHead(), posicao_do_novo_valor);
                    if (dado_antigo == NULL)
                    {
                        printf("Posição inválida!");
                        break;
                    }
                    addNewDadoAfterElement(dado_antigo, novoDado);
                }
            }
            break;
        }

        case 2:
        {
            int valor_antigo, novo_valor;
            printf("\nO sistema editará a primeira aquisição do dado encontrado\nDigite o valor que deseja editar:");
            scanf("%d", &valor_antigo);
            printf("\nDigite o novo valor:");
            scanf("%d", &novo_valor);
            editDado(Novalista->getHead(), valor_antigo, novo_valor);
            break;
        }

        case 3:
        {
            int valor_removido;
            printf("\nO sistema removerá a primeira aquisição do dado encontrado\nDigite o valor que deseja remover:");
            scanf("%d", &valor_removido);
            removeDado((Novalista->getHead()), valor_removido);
            break;
        }
        }

        if (escolha != 0 || (escolha > 3 && escolha < 0))
        {
            printLinkedList(Novalista);
        }
    }
}

void editDado(Dado *head, int valor_antigo, int novo_valor)
{
    Dado *dadoEditável = findDado(head, valor_antigo);
    if (dadoEditável == NULL)
    {
        printf("Dado não encontrado");
        return;
    }
    dadoEditável->setDado_interno(novo_valor);
    printf("Dado Atualizado!\n");
}

void removeDado(Dado *head, int valor_removido)
{
    Dado *objeto_auxilar = findDado(head, valor_removido);
    if (head->getDado_interno() == objeto_auxilar->getDado_interno())
    {
        (head) = objeto_auxilar->getProximo_no();
        if ((head) == NULL)
        {
            head->setNo_anterior(NULL);
        }
    }
    else
    {
        objeto_auxilar = objeto_auxilar->getProximo_no();
        objeto_auxilar->getNo_anterior()->setProximo_no(objeto_auxilar->getProximo_no());
        if (objeto_auxilar->getProximo_no() != NULL)
        {
            objeto_auxilar->getProximo_no()->setNo_anterior(objeto_auxilar->getNo_anterior());
        }
    }
    objeto_auxilar->setProximo_no(NULL);
    objeto_auxilar->setDado_interno(NULL);
    objeto_auxilar->setNo_anterior(NULL);
    printf("Valor %d removido da lista.\n", &valor_removido);
}