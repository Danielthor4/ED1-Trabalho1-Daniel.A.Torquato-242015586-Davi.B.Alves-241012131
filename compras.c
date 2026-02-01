#include "compras.h"
#include "clientes.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void incluirCompra(Cliente *cliente, Produto *listaProdutos) {

    if (cliente == NULL) {
        printf("Nenhum cliente selecionado.\n");
        return;
    }

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

    Compra *aux = cliente->carrinho;
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
        printf("Erro ao alocar memoria.\n");
        return;
    }

    nova->produto = produtoAtual;
    nova->quantidade = qtd;
    nova->prox = cliente->carrinho;
    cliente->carrinho = nova;

    produtoAtual->quantidade -= qtd;
    printf("Produto adicionado ao carrinho.\n");
}

void listarCompras(Cliente *cliente){
    if (cliente == NULL) {
        printf("Nenhum cliente selecionado.\n");
        return;
    }

    Compra *aux = cliente->carrinho;
    float total = 0.0;

    if (aux == NULL) {
        printf("Carrinho vazio.\n");
        return;
    }

    printf("\n--- CARRINHO DE %s ---\n", cliente->nome);

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

void removerCompra(Cliente *cliente) {
    if (cliente == NULL) {
        printf("Nenhum cliente selecionado.\n");
        return;
    }

    if (cliente->carrinho == NULL) {
        printf("Carrinho vazio.\n");
        return;
    }

    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    Compra *atual = cliente->carrinho;
    Compra *anterior = NULL;

    while (atual != NULL && atual->produto->codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto nao encontrado no carrinho.\n");
        return;
    }

    if (anterior == NULL){
        cliente->carrinho = atual->prox;
    } 
    else{ 
        anterior->prox = atual->prox;
    }
        
    

    atual->produto->quantidade += atual->quantidade;
    free(atual);

    printf("Produto removido do carrinho.\n");
}

void liberarCarrinho(Cliente *cliente) {
    if (cliente == NULL || cliente->carrinho == NULL) {
        return;
    }

    Compra *atual = cliente->carrinho;
    Compra *aux;

    while (atual != NULL) {
        aux = atual;
        atual = atual->prox;

        aux->produto->quantidade += aux->quantidade;
        free(aux);
    }

    cliente->carrinho = NULL;
}


