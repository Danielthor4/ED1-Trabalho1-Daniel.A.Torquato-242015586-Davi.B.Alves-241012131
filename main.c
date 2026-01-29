#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "clientes.h"
#include "produtos.h"
#include "compras.h"

int main() {
    setlocale(LC_ALL, "");

    Cliente *listaClientes = NULL;
    Produto *listaProdutos = NULL;
    Compra *listaCompras = NULL;

    int funcionalidade;
    int escolha_cliente;
    int escolha_produto;
    int escolha_compra;

    printf("Escolha a sua opcao:\n");
    printf("1. Gerenciamento de clientes\n");
    printf("2. Gerenciamento de produtos\n");
    printf("3. Modo compra\n");

    scanf("%d", &funcionalidade);

    switch (funcionalidade) {

        case 1:
            printf("\n");
            printf("Voce escolheu a opcao 1 - Gerenciamento de clientes\n");
            printf("Escolha a sua proxima opcao:\n");
            printf("1. Cadastrar cliente\n");
            printf("2. Listar todos os clientes\n");
            printf("3. Buscar cliente pelo CPF\n");
            printf("4. Editar dados de um cliente\n");
            printf("5. Remover cliente\n");

            scanf("%d", &escolha_cliente);

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
                default:
                    break;
            }
            break;

        case 2:
            printf("\n");
            printf("Voce escolheu a opcao 2 - Produtos\n");
            printf("Escolha a sua proxima opcao:\n");
            printf("1. Cadastrar produto\n");
            printf("2. Listar todos os produtos\n");
            printf("3. Buscar produto pelo codigo\n");
            printf("4. Editar dados de um produto\n");
            printf("5. Remover produto\n");

            scanf("%d", &escolha_produto);

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
                default:
                    break;
            }
            break;

        case 3:
            printf("\n");
            printf("Voce escolheu a opcao 3 - Modo compra\n");
            printf("Escolha a sua proxima opcao:\n");
            printf("1. Incluir produtos que deseja no carrinho\n");
            printf("2. Listar produtos do carrinho do cliente\n");
            printf("3. Retirar produtos do carrinho do cliente\n");

            scanf("%d", &escolha_compra);

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
                default:
                    break;
            }
            break;

        default:
            break;
    }

    return 0;
}
