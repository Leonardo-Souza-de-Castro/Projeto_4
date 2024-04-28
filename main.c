#include "banco.h"
#include <stdio.h>

int main() {
    funcao fs[] = {criar, apagar, listar, debitar, depositar, extrato, transferir};

    int pos;
    Cliente contas[TOTAL];

    Erro erro = OK;

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
        clearBuffer();
        opcao--;

        if (opcao > 6)
        {
            printf("\nOpcao invalida.\n");
        }
        else if (opcao >= 0) {
            erro = fs[opcao] (contas, &pos);
            if (opcao == 0)
            {
                printf("\n");
            }
            else if (opcao == 1)
            {
                printf("\n");
            }
            else if (opcao == 2)
            {
                printf("\n");
            }
            else if (opcao == 3)
            {
                printf("\n");
            }
            else if (opcao == 4)
            {
                printf("\n");
            }
            else if (opcao == 5)
            {
                printf("\n");
            }
            else if (opcao == 6)
            {
                printf("\n");
            }
            else{
                printf("Saindo...\n");   
                }
        }
        
    } while (opcao >= 0);

    // Salvar aqui
    
}