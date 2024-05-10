#include "banco.h"
#include <stdio.h>

int main() {
    funcao fs[] = {criar, apagar, listar, debitar, depositar, extrato, transferir};

    int pos = 0;
    Cliente contas[TOTAL];

    Erro erro = OK;

    int opcao;
  
  do {
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

    erro = fs[8](contas, &pos);
    if (erro != OK)
            printf("Erro ao carregar os clientes!%d\n", erro);

        if (opcao > 6)
        {
            printf("\nOpcao invalida.\n");
        }
        else if (opcao >= 0) {
            erro = fs[opcao](contas, &pos);
            if (opcao == 0)
            {
                if (erro == MAX_CLIENTES)
                    printf("Numero maximo de clientes atingido.\n"); 
                else
                    printf("Cliente cadastrado com sucesso!\n");
            }
            else if (opcao == 1)
            {
                if (erro == SEM_CLIENTES)
                    printf("Sem clientes para apagar.\n");
                else if (erro == NAO_ENCONTRADO)
                    printf("Cliente nao encontrado.\n");
                else
                    printf("Cliente apagado com sucesso!\n");
            }
            else if (opcao == 2)
            {
                if (erro == SEM_CLIENTES)
                    printf("Sem clientes para listar.\n");      
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
        erro = fs[7](contas, &pos);
        if (erro != OK)
            printf("Erro ao salvar os clientes!%d\n", erro);
        
    } while (opcao >= 0);

  // Salvar aqui
}