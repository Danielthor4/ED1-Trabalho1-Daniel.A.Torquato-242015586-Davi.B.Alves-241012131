#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct Produto{
    int codigo;
    char *nome;
    float preco;
    struct Produto *prox;
} Produto;

void cadastrarProduto(Produto **lista);
void listarProdutos(Produto *lista);
Produto* buscarProduto(Produto *lista);
void editarProduto(Produto *lista);
void removerProduto(Produto **lista);

#endif