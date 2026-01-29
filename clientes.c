#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void cadastrarCliente(Cliente **lista) {
    Cliente *novo = (Cliente *) malloc(sizeof(Cliente));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("\n--- Cadastro de Cliente ---\n");

    printf("CPF: ");
    scanf(" %14[^\n]", novo->cpf);

    printf("Nome: ");
    scanf(" %99[^\n]", novo->nome);

    printf("Email: ");
    scanf(" %99[^\n]", novo->email);

    printf("Telefone: ");
    scanf(" %19[^\n]", novo->telefone);

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %10[^\n]", novo->dataNascimento);

    novo->prox = *lista;
    *lista = novo;

    printf("\nCliente cadastrado com sucesso!\n");
}

void listarClientes(Cliente **lista) {
    if (*lista == NULL) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    Cliente *atual = *lista;

    printf("\n--- Lista de Clientes ---\n");

    while (atual != NULL) {
        printf("\nCPF: %s", atual->cpf);
        printf("\nNome: %s", atual->nome);
        printf("\nEmail: %s", atual->email);
        printf("\nTelefone: %s", atual->telefone);
        printf("\nData de nascimento: %s\n", atual->dataNascimento);
        printf("--------------------------\n");

        atual = atual->prox;
    }
}

void buscarCliente(Cliente **lista) {
    printf("\n");
    printf("Funcao buscarCliente chamada!\n");
}

void editarCliente(Cliente **lista) {
    printf("\n");
    printf("Funcao editarCliente chamada!\n");
}

void removerCliente(Cliente **lista) {
    printf("\n");
    printf("Funcao removerCliente chamada!\n");
}