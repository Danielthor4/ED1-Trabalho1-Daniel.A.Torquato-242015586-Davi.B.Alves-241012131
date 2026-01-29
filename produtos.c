#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

void cadastrarProduto(Produto **Lista){
    Produto *novo = malloc(sizeof(Produto));
    if (novo == NULL){
        printf("Erro ao alocar memoria para novo produto.\n");
        return;
    }

    printf("digite o codigo do produto: ");
    scanf("%d", &novo->codigo);

    if (codigoExiste(*Lista, novo->codigo)){
        printf("Erro: Codigo ja cadastrado!.\n");
        free(novo);
        return;
    }

    printf("digite o nome do produto: ");
    scanf(" %99[^\n]", novo->nome); 

    printf("digite o preco do produto: ");
    scanf("%f", &novo->preco);

    printf("digite a quantidade do produto: ");
    scanf("%d", &novo->quantidade);

    novo->prox = *Lista;
    *Lista = novo;

    printf("Produto cadastrado com sucesso!\n");
}

int codigoExiste(Produto *lista, int codigo){
    Produto *atual = lista;
    while (atual != NULL){
        if (atual->codigo == codigo){
            return 1; 
        }
        atual = atual->prox;
    }
    return 0; 
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
        printf("Quantidade: %d\n", atual->quantidade);

        atual = atual->prox;
    }
 
}

Produto* buscarProduto(Produto *lista){
    int codigo;
    printf("\nDigite o codigo do produto que deseja buscar: ");
    scanf("%d", &codigo);
    
    Produto *atual = lista;

    while (atual != NULL){
        if (atual->codigo == codigo){
            printf("\nProduto encontrado!");
            printf("\nCodigo: %d", atual->codigo);
            printf("\nNome: %s", atual->nome);
            printf("\nPreco: %.2f\n", atual->preco);
            printf("Quantidade: %d\n", atual->quantidade);
            return atual;
        }
        atual = atual->prox;
    }
    printf("\nProduto nao encontrado!\n");

    return NULL;
}

void editarProduto(Produto *lista){
    if (lista == NULL){
        printf("\nNenhum produto cadastrado para editar.\n");
        return;
    }

    Produto *produto = buscarProduto(lista);

    if (produto == NULL){
        printf("\nProduto nao encontrado para editar.\n");
        return;
    }

    printf("\nDigite o novo nome do produto");
    scanf(" %99[^\n]", produto->nome);

    printf("Digite o novo preco do produto: ");
    scanf("%f", &produto->preco);

    printf("Digite a nova quantidade do produto: ");
    scanf("%d", &produto->quantidade);

    printf("\nProduto editado com sucesso!\n");
}

void removerProduto(Produto **lista){
    if (*lista == NULL){
        printf("\nNenhum produto cadastrado para remover.\n");
        return;
    }

    int codigo;
    printf("\nDigite o codigo do produto que deseja remover: ");
    scanf("%d", &codigo);

    Produto *atual = *lista;
    Produto *anterior = NULL;

    while (atual != NULL && atual->codigo != codigo){
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL){
        printf("\nProduto nao encontrado para remover.\n");
        return;
    }

    if (anterior == NULL){
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("\nProduto removido com sucesso!\n");
}
