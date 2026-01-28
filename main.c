#include <stdio.h>

int main() {
    printf("Escolha a sua opção:\n");
    printf("1. Gerenciamento  de clientes\n");
    printf("2. Gerenciamento de produtos\n");
    printf("3. Modo compra\n");

    int funcionalidade;
    scanf("%d");
    printf("Você escolheu a opção %d\n", funcionalidade);

    switch (funcionalidade) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
    
    return 0;
}
