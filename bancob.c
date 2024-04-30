#include "banco.h"
#include <stdio.h>
#include <string.h>

Erro debitar(Cliente contas[], int *pos) {
    char cpf[12];
    char senha[100];
    float valor_debito;
    float taxa;
    int contador_erro = 0;

    printf("Insira o CPF do titular da conta: \n");
    fgets(cpf, 12, stdin);

    cpf[strcspn(cpf, "\n")] = 0;

    while (strlen(cpf) != 11) {
        printf("Insira um valor valido para CPF \n");
        fgets(cpf, 12, stdin);
    }
    clearBuffer();

    printf("Insira a senha da conta: \n");
    fgets(senha, 100, stdin);

    senha[strcspn(senha, "\n")] = 0;

    printf("Insira o valor que gostaria de debitar desta conta: \n");
    scanf("%f", &valor_debito);

    while (valor_debito <= 0) {
        printf("Insira um valor valido para debito (maior que 0) \n");
        scanf("%f", &valor_debito);
    }
    int i = 0;
    for (i; i < *pos; i++) {
        if (strcmp(contas[i].cpf, cpf) == 0 && strcmp(contas[i].senha, senha) == 0) {
            if (strcmp(contas[i].tipo_conta, "Comum") == 0)
            {
                taxa = 0.5*valor_debito;
                if (contas[i].saldo - (valor_debito + taxa) < -1000)
                {
                    printf("Limite de saldo negativo atingido");
                }else
                {
                    contas[i].saldo = contas[i].saldo - (valor_debito + taxa);
                }
                
            }else
            {
                taxa = 0.3*valor_debito;
                
                if (contas[i].saldo - (valor_debito + taxa) < -5000)
                {
                    printf("Limite de saldo negativo atingido");
                }else
                {
                    contas[i].saldo = contas[i].saldo - (valor_debito + taxa);
                }
                
            }
        
        
        } else {
        contador_erro++;
        }
    }

    if (contador_erro >= pos) {
        return NAO_ENCONTRADO;
    }

    return OK;
}

Erro depositar(Cliente contas[], int *pos) {
    printf("Funcao deposito\n");
    return OK;
}

Erro transferir(Cliente contas[], int *pos) {
    printf("Funcao transferencia\n");
    return OK;
}