#ifndef COMPRAS_H
#define COMPRAS_H

typedef struct Compra {
    int cpfCliente;
    int codigoProduto;
    int quantidade;
    struct Compra *prox;
} Compra;

void incluirCompra(Compra **lista);
void listarCompras(Compra *lista);
void removerCompra(Compra **lista);

#endif
