#include "BinaryTree.h"

void startBinaryTree()
{
    arvore * Novaarvore = createNewArvore();
    if (isArvoreCreated(Novaarvore))
    {
        int escolha, numero_pesquisado;
        receiveDataFromUserToInsertIntoTree(Novaarvore);
        while (escolha != 0)
        {
            printf("\nEscolha um modelo de listagem:\n\n1 - Pre-ordem\n2 - Pos-ordem\n3- Em Ordem\n0 - Cancelar e sair\n\nEscolha: ");
            scanf("%d", &escolha);
            switch (escolha)
            {
            case 1:
                printPreOrder(Novaarvore->raiz);
                break;

            case 2:
                printPostOrder(Novaarvore->raiz);
                break;
            case 3:
                printInOrder(Novaarvore->raiz);
                break;

            default:

                break;
            }

            if (escolha != 0)
            {
                printf("\n\nO que deseja fazer agora?\n1 - Encontrar número\n2 - Excluir Número\n3 - Listar árvore novamente\n4 - Adicionar um novo numero\n0 - Sair\n\nEscolha:");
                scanf("%d", &escolha);
                switch (escolha)
                {
                case 1:
                    printf("\nDigite o número a ser pesquisado: ");
                    scanf("%d", &numero_pesquisado);
                    if (findDado4((Novaarvore->raiz), numero_pesquisado) == 0)
                    {
                        printf("%d não existe na árvore\n\n", numero_pesquisado);
                    }
                    else
                    {
                        printf("%d existe na árvore\n\n", numero_pesquisado);
                    }
                    break;
                case 2:
                    printf("\nDigite o número a ser excluído: ");
                    scanf("%d", &numero_pesquisado);
                    if(numero_pesquisado == Novaarvore->raiz){
                        Novaarvore->raiz = removeDadoFromThisTree((Novaarvore->raiz), numero_pesquisado);
                         printf("A raiz %d foi encontrada e excluída da árvore", numero_pesquisado);
                    }
                    else if (removeDadoFromThisTree((Novaarvore->raiz), numero_pesquisado))
                    {
                        printf("%d não existe na árvore", numero_pesquisado);
                    }
                    else
                    {
                        printf("O primeiro %d encontrado foi excluído da árvore", numero_pesquisado);
                    }
                    break;
                case 4:
                   receiveDataFromUserToInsertIntoTree(Novaarvore->raiz);
                    break;
                }
            }
        }
    }
}
