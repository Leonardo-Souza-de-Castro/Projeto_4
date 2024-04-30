#include "banco.h"
#include <stdio.h>
#include <string.h>

Erro debitar(Cliente contas[], int *pos) {
    printf("Funcao debito\n");
    return OK;
}

Erro depositar(Cliente contas[], int *pos) {
    printf("Funcao deposito\n");
    return OK;
}

Erro transferir(Cliente contas[], int *pos) {
    char cpf_dest[12];
    char cpf_orig[12];
    char senha_destino[100];
    float valor;
    float taxa;
    int contador_erro = 0;

    printf("Insira o CPF de origem da conta: \n");
    fgets(cpf_orig, 12, stdin);

    cpf_orig[strcspn(cpf_orig, "\n")] = 0;

    while (strlen(cpf_orig) != 11) {
        printf("Insira um valor valido para CPF \n");
        fgets(cpf_orig, 12, stdin);
    }
    clearBuffer();

    printf("Insira a senha da conta: \n");
    fgets(senha_destino, 100, stdin);

    senha_destino[strcspn(senha_destino, "\n")] = 0;

    printf("Insira o valor que gostaria de transferir: \n");
    scanf("%f", &valor);

    while (valor <= 0) {
        printf("Insira um valor valido para transferir (maior que 0) \n");
        scanf("%f", &valor);
    }
    int i = 0;
    for (i; i < *pos; i++) {
        if (strcmp(contas[i].cpf, cpf_dest) == 0 && strcmp(contas[i].senha, senha_destino) == 0) {
            if (strcmp(contas[i].tipo_conta, "Comum") == 0)
            {
                taxa = 0.5*valor;
                if (contas[i].saldo - (valor + taxa) < -1000)
                {
                    printf("Limite de saldo negativo atingido");
                }else
                {
                    contas[i].saldo = contas[i].saldo - (valor + taxa);
                }
                
            }else
            {
                taxa = 0.3*valor;
                
                if (contas[i].saldo - (valor + taxa) < -5000)
                {
                    printf("Limite de saldo negativo atingido");
                }else
                {
                    contas[i].saldo = contas[i].saldo - (valor + taxa);
                }
                
            }
        
        
        }
        else if (strcmp(contas[i].cpf, cpf_dest) == 0)
        {
            contas[i].saldo = contas[i].saldo + valor;
        }
        else {
        contador_erro++;
        }
    }

    if (contador_erro >= pos) {
        return NAO_ENCONTRADO;
    }

    return OK;
}