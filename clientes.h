#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct Cliente {
    char cpf[15];
    char nome[100];
    char email[100];
    char telefone[20];
    char dataNascimento[11]; 
    struct Cliente *prox;
} Cliente;

void cadastrarCliente(Cliente **lista);
void listarClientes(Cliente **lista);
void buscarCliente(Cliente **lista);
void editarCliente(Cliente **lista);
void removerCliente(Cliente **lista);

#endif
