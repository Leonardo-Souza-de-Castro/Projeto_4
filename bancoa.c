#include "banco.h"
#include <stdio.h>
#include <string.h>

Erro criar(Cliente contas[], int *pos) {
    if (*pos >= TOTAL) {
        return MAX_CLIENTES;
    }

    char cpf[12];

    printf("Digite seu nome: ");
    scanf("%[^\n]", contas[*pos].nome);
    clearBuffer();

    while (strlen(contas[(*pos)].cpf) != 11){
      printf("Digite seu CPF (apenas numeros): ");
      scanf("%[^\n]", contas[*pos].cpf);
      clearBuffer();
      if (strlen(contas[(*pos)].cpf) != 11)
        printf("CPF invalido.\n");
    }

    while (strcmp(contas[(*pos)].tipo_conta, "comum") != 0 && strcmp(contas[(*pos)].tipo_conta, "plus") != 0){
      printf("Digite o tipo de conta (comum ou plus): ");
      scanf("%[^\n]", contas[*pos].tipo_conta);
      clearBuffer();
      if (strcmp(contas[(*pos)].tipo_conta, "comum") != 0 && strcmp(contas[(*pos)].tipo_conta, "plus") != 0)
        printf("Tipo de conta invalido.\n");
    }
    

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