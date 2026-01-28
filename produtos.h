#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct Produto {
    int codigo;
    char nome[100];
    float preco;
    struct Produto *prox;
} Produto;

#endif
