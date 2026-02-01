#ifndef COMPRAS_H
#define COMPRAS_H

#include "produtos.h"

typedef struct Compra {
    Produto *produto;
    int quantidade;
    struct Compra *prox;
} Compra;

void incluirCompra(Compra **lista, Produto *listaProdutos);
void listarCompras(Compra *lista);
void removerCompra(Compra **lista);

#endif
