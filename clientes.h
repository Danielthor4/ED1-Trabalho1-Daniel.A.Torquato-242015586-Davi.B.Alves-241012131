#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct Cliente {
    int cpf;
    char nome[100];
    int telefone;
    struct Cliente *prox;
} Cliente;

void cadastrarCliente(Cliente **lista);
void listarClientes(Cliente **lista);
void buscarCliente(Cliente **lista);
void editarCliente(Cliente **lista);
void removerCliente(Cliente **lista);

#endif
