#include "compras.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void incluirCompra(Compra **lista, Produto *listaProdutos) {
    int qtd;
    Produto *produtoAtual = buscarProduto(listaProdutos);

    if (produtoAtual == NULL) return;

    printf("Digite a quantidade: ");
    scanf("%d", &qtd);
    limparBuffer();

    if (qtd <= 0 || qtd > produtoAtual->quantidade) {
        printf("Quantidade invalida ou estoque insuficiente.\n");
        return;
    }

    Compra *aux = *lista;
    while (aux != NULL) {
        if (aux->produto->codigo == produtoAtual->codigo) {
            aux->quantidade += qtd;
            produtoAtual->quantidade -= qtd;
            printf("Quantidade atualizada no carrinho.\n");
            return;
        }
        aux = aux->prox;
    }

    Compra *nova = malloc(sizeof(Compra));
    if (nova == NULL) {
        printf("Erro ao alocar memoria para nova compra.\n");
        return;
    }
    nova->produto = produtoAtual;
    nova->quantidade = qtd;
    nova->prox = *lista;
    *lista = nova;

    produtoAtual->quantidade -= qtd;
    printf("Produto adicionado ao carrinho.\n");
}

void listarCompras(Compra *lista)
{
    Compra *aux = lista;
    float total = 0.0;

    if (aux == NULL) {
        printf("Carrinho vazio.\n");
        return;
    }

    printf("\n--- CARRINHO DE COMPRAS ---\n");

    while (aux != NULL) {
        float subtotal = aux->quantidade * aux->produto->preco;

        printf("Codigo: %d\n", aux->produto->codigo);
        printf("Produto: %s\n", aux->produto->nome);
        printf("Quantidade: %d\n", aux->quantidade);
        printf("Preco unitario: R$ %.2f\n", aux->produto->preco);
        printf("Subtotal: R$ %.2f\n", subtotal);
        printf("--------------------------\n");

        total += subtotal;
        aux = aux->prox;
    }

    printf("TOTAL DA COMPRA: R$ %.2f\n", total);
}

void removerCompra(Compra **lista)
{
    if (*lista == NULL){
        printf("\nNenhum produto no carrinho para remover.\n");
        return;
    }

    int codigo;
    printf("\nDigite o codigo do produto que deseja remover do carrinho: ");
    scanf("%d", &codigo);
    limparBuffer();

    Compra *atual = *lista;
    Compra *anterior = NULL;

    while (atual != NULL && atual->produto->codigo != codigo){
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL){
        printf("\nProduto nao encontrado no carrinho para remover.\n");
        return;
    }

    if (anterior == NULL){
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    atual->produto->quantidade += atual->quantidade;
    free(atual);

    printf("\nProduto removido do carrinho com sucesso!\n");
}

