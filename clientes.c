#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utils.h"

void cadastrarCliente(Cliente **lista) {
    Cliente *novo = (Cliente *) malloc(sizeof(Cliente));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("\n--- Cadastro de Cliente ---\n");

    printf("CPF: ");
    scanf(" %14[^\n]", novo->cpf);
    limparBuffer();

    printf("Nome: ");
    scanf(" %99[^\n]", novo->nome);
    limparBuffer();

    printf("Email: ");
    scanf(" %99[^\n]", novo->email);
    limparBuffer();

    printf("Telefone: ");
    scanf(" %19[^\n]", novo->telefone);
    limparBuffer();

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %10[^\n]", novo->dataNascimento);
    limparBuffer();

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
    if (*lista == NULL) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    char cpfBuscado[20];
    printf("\nDigite o CPF do cliente: ");
    scanf(" %19s", cpfBuscado);
    limparBuffer();

    Cliente *atual = *lista;

    while (atual != NULL) {
        if (strcmp(atual->cpf, cpfBuscado) == 0) {
            printf("\n--- Cliente encontrado ---\n");
            printf("CPF: %s\n", atual->cpf);
            printf("Nome: %s\n", atual->nome);
            printf("Email: %s\n", atual->email);
            printf("Telefone: %s\n", atual->telefone);
            printf("Data de nascimento: %s\n", atual->dataNascimento);
            return;
        }
        atual = atual->prox;
    }

    printf("\nCliente com CPF %s nao encontrado.\n", cpfBuscado);
}

void editarCliente(Cliente **lista) {
    if (*lista == NULL) {
        printf("\nLista de clientes vazia!\n");
        return;
    }

    char cpf[15];
    printf("\nDigite o CPF do cliente que deseja editar: ");
    scanf(" %[^\n]", cpf);
    limparBuffer();

    Cliente *atual = *lista;

    while (atual != NULL && strcmp(atual->cpf, cpf) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\nCliente com CPF %s nao encontrado.\n", cpf);
        return;
    }

    printf("\nCliente encontrado!\n");
    printf("CPF: %s\n", atual->cpf);
    printf("Nome atual: %s\n", atual->nome);
    printf("Email atual: %s\n", atual->email);
    printf("Telefone atual: %s\n", atual->telefone);
    printf("Data de nascimento atual: %s\n", atual->dataNascimento);

    int opcao;
    printf("\nO que deseja editar?\n");
    printf("1. Nome\n");
    printf("2. Email\n");
    printf("3. Telefone\n");
    printf("4. Data de nascimento\n");
    printf("0. Cancelar\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", atual->nome);
            limparBuffer();
            break;

        case 2:
            printf("Digite o novo email: ");
            scanf(" %[^\n]", atual->email);
            limparBuffer();
            break;

        case 3:
            printf("Digite o novo telefone: ");
            scanf(" %[^\n]", atual->telefone);
            limparBuffer();
            break;

        case 4:
            printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
            scanf(" %[^\n]", atual->dataNascimento);
            limparBuffer();
            break;

        case 0:
            printf("Edicao cancelada.\n");
            return;

        default:
            printf("Opcao invalida.\n");
            return;
    }

    printf("\nCliente editado com sucesso!\n");
}

void removerCliente(Cliente **lista) {
    if (*lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    char cpfBusca[15];
    printf("\nDigite o CPF do cliente a remover: ");
    scanf("%s", cpfBusca);
    limparBuffer();

    Cliente *atual = *lista;
    Cliente *anterior = NULL;

    while (atual != NULL && strcmp(atual->cpf, cpfBusca) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\nCliente nao encontrado.\n");
        return;
    }

    printf("\nCliente encontrado!\n");
    printf("CPF: %s\n", atual->cpf);
    printf("Nome: %s\n", atual->nome);
    printf("Email: %s\n", atual->email);
    printf("Telefone: %s\n", atual->telefone);
    printf("Data de nascimento: %s\n", atual->dataNascimento);

    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);

    printf("\nCliente removido com sucesso!\n");
}
