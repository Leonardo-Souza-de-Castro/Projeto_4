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

    do {
      printf("Digite seu CPF (apenas numeros): ");
      scanf("%[^\n]", contas[*pos].cpf);
      clearBuffer();
      if (strlen(contas[(*pos)].cpf) != 11)
        printf("CPF invalido.\n");
    } while (strlen(contas[(*pos)].cpf) != 11);

    do {
      printf("Digite o tipo de conta (comum ou plus): ");
      scanf("%[^\n]", contas[*pos].tipo_conta);
      clearBuffer();
      if (strcmp(contas[(*pos)].tipo_conta, "comum") != 0 && strcmp(contas[(*pos)].tipo_conta, "plus") != 0)
        printf("Tipo de conta invalido.\n");
    } while (strcmp(contas[(*pos)].tipo_conta, "comum") != 0 && strcmp(contas[(*pos)].tipo_conta, "plus") != 0);
    

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
    if (*pos == 0) {
        return SEM_CLIENTES;
    }

    int pos_deletar = -1;
    char cpf[12];

    while (strlen(cpf) != 11){
      printf("Digite seu CPF (apenas numeros): ");
      scanf("%[^\n]", cpf);
      clearBuffer();
      if (strlen(cpf) != 11)
        printf("CPF invalido.\n");
    }

    for (int i = 0; i < *pos; i++) {
        if (strcmp(cpf, contas[i].cpf) == 0) {
            pos_deletar = i;
            break;
        }
    }

    if (pos_deletar < 0 || pos_deletar >= *pos) {
        return NAO_ENCONTRADO;
    }

    for (int i = pos_deletar; i < *pos - 1; i++) {
        strcpy(contas[i].nome, contas[i + 1].nome);
        strcpy(contas[i].cpf, contas[i + 1].cpf);
        strcpy(contas[i].tipo_conta, contas[i + 1].tipo_conta);
        contas[i].saldo = contas[i + 1].saldo;
        strcpy(contas[i].senha, contas[i + 1].senha);
    }

    *pos = *pos - 1;

    return OK;
}

Erro listar(Cliente contas[], int *pos) {
    if (*pos == 0) {
        return SEM_CLIENTES;
    }
  
    for (int i = 0; i < *pos; i++) {
      printf("Nome: %s\t", contas[i].nome);
      printf("CPF: %c%c%c.%c%c%c.%c%c%c-%c%c\t", contas[i].cpf[0], contas[i].cpf[1], contas[i].cpf[2], contas[i].cpf[3], contas[i].cpf[4], contas[i].cpf[5], contas[i].cpf[6], contas[i].cpf[7], contas[i].cpf[8], contas[i].cpf[9], contas[i].cpf[10]);
      printf("Tipo de conta: %s\t", contas[i].tipo_conta);
      printf("Saldo: %.2f$\n", contas[i].saldo);
    }
    return OK;
}

Erro extrato(Cliente contas[], int *pos) {
    char cpf[12];
    char senha[100];
    char nome[100];
    int cont_erro = 0;

    if (*pos == 0) {
        return SEM_CLIENTES;
    }

    while (strlen(cpf) != 11){
      printf("Digite seu CPF (apenas numeros): ");
      scanf("%[^\n]", cpf);
      clearBuffer();
      if (strlen(cpf) != 11)
        printf("CPF invalido.\n");
    }

    printf("Digite sua senha: ");
    scanf("%[^\n]", senha);
    clearBuffer();

    int i = 0;
    for (i; i < *pos; i++) {
        if (strcmp(cpf, contas[i].cpf) == 0 && strcmp(senha, contas[i].senha) == 0) {
            strcpy(nome, contas[i].nome);
            strcat(nome, ".txt");

            FILE *f = fopen(nome, "r");
            char linha[100];

            while (fgets(linha, 100, f) != NULL) {
                printf("%s", linha);
            }

            fclose(f);
            cont_erro = 1;
        }
    }

    if (cont_erro == 0) {
        return NAO_ENCONTRADO;
    }

    return OK;
}

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}