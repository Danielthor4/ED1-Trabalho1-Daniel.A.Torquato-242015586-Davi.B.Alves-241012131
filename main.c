#include <stdio.h>

int main() {
    printf("Escolha a sua opção:\n");
    printf("1. Gerenciamento  de clientes\n");
    printf("2. Gerenciamento de produtos\n");
    printf("3. Modo compra\n");

    int funcionalidade;
    int escolha_cliente;
    int escolha_produto;
    int escolha_compra;
    int cpf_cliente;
    char nome_cliente[100];
    int telefone_cliente;

    scanf("%d", &funcionalidade);

    switch (funcionalidade) {
    case 1:
        printf("Você escolheu a opção 1 - Gerenciamento de clientes\n");
        printf("Escolha a sua próxima opção:\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar todos os clientes\n");
        printf("3. Buscar cliente pelo CPF\n");
        printf("4. Editar dados de um cliente\n");
        printf("5. Remover cliente\n");

        scanf("%d", &escolha_cliente);
        switch (escolha_cliente) {
        case 1:
            printf("Você escolheu a opção 1 - Gerenciamento de clientes\n");
            break;
        case 2:
            printf("Você escolheu a opção 2 - Listar todos os clientes\n");
            break;
        case 3:
            printf("Você escolheu a opção 3 - Buscar cliente pelo CPF\n");
            break;
        case 4:
            printf("Você escolheu a opção 4 - Editar dados de um cliente\n");
            break;
        case 5:
            printf("Você escolheu a opção 5 - Remover cliente\n");
            break;
        default:
            break;
        }
        break;
    case 2:
        printf("Você escolheu a opção 2 - Produtos\n");
        printf("Escolha a sua próxima opção:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar todos os produtos\n");
        printf("3. Buscar produto pelo código\n");
        printf("4. Editar dados de um produto\n");
        printf("5. Remover produto\n");

        scanf("%d", &escolha_produto);
        switch (escolha_produto) {
        case 1:
            printf("Você escolheu a opção 1 - Cadastrar produto\n");
            break;
        case 2:
            printf("Você escolheu a opção 2 - Listar todos os produtos\n");
            break;
        case 3:
            printf("Você escolheu a opção 3 - Buscar produto pelo código\n");
            break;
        case 4:
            printf("Você escolheu a opção 4 - Editar dados de um produto\n");
            break;
        case 5:
            printf("Você escolheu a opção 5 - Remover produto\n");
            break;
        default:
            break;
        }
        break;
    case 3:
        printf("Você escolheu a opção 3 - Modo compra\n");
        printf("Escolha a sua próxima opção:\n");
        printf("1. Incluir produtos que deseja no carrinho\n");
        printf("2. Listar produtos do carrinho do cliente\n");
        printf("3. Retirar produtos do carrinho do cliente\n");

        scanf("%d", &escolha_compra);
        switch (escolha_compra) {
        case 1:
            printf("Você escolheu a opção 1 - Incluir produtos que deseja no carrinho\n");
            break;
        case 2:
            printf("Você escolheu a opção 2 - Listar produtos do carrinho do cliente\n");
            break;
        case 3:
            printf("Você escolheu a opção 3 - Retirar produtos do carrinho do cliente\n");
            break;
    }
        break;
    default:
        break;  
    return 0;
}
