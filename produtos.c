#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>


void listarProdutos(Produto *lista){
    if (lista == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    Produto *atual = lista;

    while (atual != NULL){
        printf("\nCodigo: %d", atual->codigo);
        printf("\nNome: %s", atual->nome);
        printf("\nPreco: %.2f\n", atual->preco);

        atual = atual->prox;
    }
 
}
