#include "banco.h"
#include <stdio.h>
#include <string.h>

Erro criar(Cliente contas[], int *pos) {
    // if (*pos >= TOTAL) {
    //     return MAX_CLIENTES;
    // }

    printf("Digite seu nome: ");
    scanf("%[^\n]", contas[*pos].nome);
    clearBuffer();

    printf("Digite seu CPF (apenas numeros): ");
    scanf("%[^\n]", contas[*pos].cpf);
    clearBuffer();
    // if (strlen(contas[(*pos)].cpf) != 11)
    //   return CPF_INVALIDO;
  
    printf("Digite o tipo de conta (comum ou plus): ");
    scanf("%[^\n]", contas[*pos].tipo_conta);
    clearBuffer();
    // if (strcmp(contas[(*pos)].tipo_conta, "comum") != 0 || strcmp(contas[(*pos)].tipo_conta, "plus") != 0)
    //   return TIPO_CONTA_INVALIDO;

    printf("Digite seu saldo: ");
    scanf("%f", &contas[*pos].saldo);
    clearBuffer();

    printf("Digite sua senha: ");
    scanf("%[^\n]", contas[*pos].senha);
    clearBuffer();

    *pos = *pos + 1;


  
    return OK;
}

Erro apagar(Cliente contas[], int *pos) {
    printf("Funcao apagar\n");
    return OK;
}

Erro listar(Cliente contas[], int *pos) {
    printf("Funcao listar\n");
    return OK;
}

Erro extrato(Cliente contas[], int *pos) {
    printf("Funcao extrato\n");
    return OK;
}

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}