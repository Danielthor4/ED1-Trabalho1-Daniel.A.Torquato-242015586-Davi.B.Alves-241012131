#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct Produto{
    int codigo;
    int quantidade;
    char nome[100];
    float preco;
    struct Produto *prox;
} Produto;

void cadastrarProduto(Produto **lista);
void listarProdutos(Produto *lista);
Produto* buscarProduto(Produto *lista);
int codigoExiste(Produto *lista, int codigo);
void editarProduto(Produto *lista);
void removerProduto(Produto **lista);

#endif