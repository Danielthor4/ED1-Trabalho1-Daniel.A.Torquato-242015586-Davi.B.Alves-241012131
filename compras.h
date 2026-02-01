#ifndef COMPRAS_H
#define COMPRAS_H

#include "produtos.h"
typedef struct Cliente Cliente;


typedef struct Compra {
    Produto *produto;
    int quantidade;
    struct Compra *prox;
} Compra;

void incluirCompra(Cliente *cliente, Produto *listaProdutos);
void listarCompras(Cliente *cliente);
void removerCompra(Cliente *cliente);
void liberarCarrinho(Cliente *cliente);


#endif
