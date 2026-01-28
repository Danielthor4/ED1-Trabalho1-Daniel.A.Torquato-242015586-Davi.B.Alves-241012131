#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct Cliente {
    int cpf;
    char nome[100];
    int telefone;
    struct Cliente *prox;
} Cliente;

/* protótipo da função */
void cadastrarCliente(Cliente **lista);

#endif
