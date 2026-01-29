#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

void cadastrarProduto(Produto **Lista){
    printf("\n");
    printf("Funcao cadastrarProduto chamada!\n");
}

void listarProdutos(Produto *lista){
    printf("\n");
    printf("Funcao listarProdutos chamada!\n");
    
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

Produto* buscarProduto(Produto *lista, int codigo){
    printf("\n");
    printf("Funcao buscarProduto chamada!\n");
    return NULL;
}

void editarProduto(Produto *lista){
    printf("\n");
    printf("Funcao editarProduto chamada!\n");
}

void removerProduto(Produto **lista){
    printf("\n");
    printf("Funcao removerProduto chamada!\n");
}
