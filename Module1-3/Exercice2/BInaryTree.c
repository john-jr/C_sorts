#include "BinaryTree.h"

void startBinaryTree(int qnt_elemtentos){
    printf("\nInicializando árvore...\n");
    arvore * Novarvore = createNewArvore();
    if(Novarvore == NULL){
        printf("\nErro ao criar árvore...\n");
     
    }else{
        printf("\nInicializando e alocando elementos...\n");
    for(int i = qnt_elemtentos; i > 0 ;i--){
          if(i == qnt_elemtentos){
              if(createNewDado(i) != NULL){
                  
              }
          }
          else{

          }
    
    }
    }


}
