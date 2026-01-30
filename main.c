#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "clientes.h"
#include "produtos.h"
#include "compras.h"
#include "utils.h"

int main() {
    setlocale(LC_ALL, "");

    Cliente *listaClientes = NULL;
    Produto *listaProdutos = NULL;
    Compra *listaCompras = NULL;

    int funcionalidade;
    int escolha_cliente;
    int escolha_produto;
    int escolha_compra;
    int continuar = 1;

    while (continuar == 1) {
        
        printf("\n");
        printf("===== Sistema de Gerenciamento =====\n");
        printf("Escolha a sua opcao:\n");
        printf("1. Gerenciamento de clientes\n");
        printf("2. Gerenciamento de produtos\n");
        printf("3. Modo compra\n");
        printf("0. Sair\n");

        scanf("%d", &funcionalidade);
        limparBuffer();

        switch (funcionalidade) {

            case 1:
                printf("\n");
                printf("Voce escolheu a opcao 1 - Gerenciamento de clientes\n");
                printf("===== Menu de Clientes =====\n");
                printf("Escolha a sua proxima opcao:\n");
                printf("1. Cadastrar cliente\n");
                printf("2. Listar todos os clientes\n");
                printf("3. Buscar cliente pelo CPF\n");
                printf("4. Editar dados de um cliente\n");
                printf("5. Remover cliente\n");
                printf("6. Voltar ao menu anterior\n");
                printf("0. Sair\n");

                scanf("%d", &escolha_cliente);
                limparBuffer();

                switch (escolha_cliente) {
                    case 1:
                        cadastrarCliente(&listaClientes);
                        break;
                    case 2:
                        listarClientes(&listaClientes);
                        break;
                    case 3:
                        buscarCliente(&listaClientes);
                        break;
                    case 4:
                        editarCliente(&listaClientes);
                        break;
                    case 5:
                        removerCliente(&listaClientes);
                        break;
                    case 6:
                        break;
                    case 0:
                        printf("\n");
                        continuar = 0;
                        break;
                    default:    
                        printf("\n");
                        printf("Opcao invalida! Tente novamente.\n");
                        break;
                }
                break;

            case 2:
                printf("\n");
                printf("Voce escolheu a opcao 2 - Produtos\n");
                printf("===== Menu de Produtos =====\n");
                printf("Escolha a sua proxima opcao:\n");
                printf("1. Cadastrar produto\n");
                printf("2. Listar todos os produtos\n");
                printf("3. Buscar produto pelo codigo\n");
                printf("4. Editar dados de um produto\n");
                printf("5. Remover produto\n");
                printf("6. Voltar ao menu anterior\n");
                printf("0. Sair\n");

                scanf("%d", &escolha_produto);
                limparBuffer();

                switch (escolha_produto) {
                    case 1:
                        cadastrarProduto(&listaProdutos);
                        break;
                    case 2:
                        listarProdutos(listaProdutos);
                        break;
                    case 3: 
                        buscarProduto(listaProdutos);
                        break;
                    case 4:
                        editarProduto(listaProdutos);
                        break;
                    case 5:
                        removerProduto(&listaProdutos);
                        break;
                    case 6:
                        break;
                    case 0:
                        printf("\n");
                        continuar = 0;
                        break;
                    default:
                        printf("\n");
                        printf("Opcao invalida! Tente novamente.\n");
                        break;
                }
                break;

            case 3:
                printf("\n");
                printf("Voce escolheu a opcao 3 - Modo compra\n");
                printf("===== Menu de Compras =====\n");
                printf("Escolha a sua proxima opcao:\n");
                printf("1. Incluir produtos que deseja no carrinho\n");
                printf("2. Listar produtos do carrinho do cliente\n");
                printf("3. Retirar produtos do carrinho do cliente\n");
                printf("4. Voltar ao menu anterior\n");
                printf("0. Sair\n");

                scanf("%d", &escolha_compra);
                limparBuffer();

                switch (escolha_compra) {
                    case 1:
                        incluirCompra(&listaCompras);
                        break;
                    case 2:
                        listarCompras(listaCompras);
                        break;
                    case 3:
                        removerCompra(&listaCompras);
                        break;
                    case 4:
                        break;
                    case 0:
                        printf("\n");
                        continuar = 0;
                        break;
                    default:
                        printf("\n");
                        printf("Opcao invalida! Tente novamente.\n");
                        break;
                }
                break;
            case 0:
                printf("\n");
                continuar = 0;
                break;
            default:
                printf("\n");
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        
        if (continuar == 1) {
            printf("\nDeseja continuar no sistema? (1 - Sim / 0 - Nao): ");
            scanf("%d", &continuar);
            limparBuffer(); 
        }
    }
    printf("Saindo do sistema...\n");
    return 0;
}

