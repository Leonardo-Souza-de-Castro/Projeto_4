#include <stdio.h>

int main() {
    int opcao;

    do
    {
        printf("\n");
        printf("Bem vindo ao Banco Quem Poupa Tem\n");
        printf("\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Apagar cliente\n");
        printf("3 - Listar todos os clientes\n");
        printf("4 - Debito\n");
        printf("5 - Deposito\n");
        printf("6 - Extrato\n");
        printf("7 - Transferencia\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        // clearBuffer();
        opcao--;

        if (opcao > 6)
        {
            printf("\nOpcao invalida.\n");
        }
        else if (opcao >= 0) {
            if (opcao == 0)
            {
                printf("Criar uma conta\n");
            }
            else if (opcao == 1)
            {
                printf("Apagar conta\n");
            }
            else if (opcao == 2)
            {
                printf("Listar todos os clientes\n");
            }
            else if (opcao == 3)
            {
                printf("Debito\n");
            }
            else if (opcao == 4)
            {
                printf("Deposito\n");
            }
            else if (opcao == 5)
            {
                printf("Extrato\n");
            }
            else if (opcao == 6)
            {
                printf("Transferencia\n");
            }
            else{
                printf("Saindo...\n");   
                }
        }
        
    } while (opcao >= 0);

    // Salvar aqui
    
}