#include "banco.h"
#include <stdio.h>
#include <string.h>

Erro debitar(Cliente contas[], int *pos) {
    printf("Funcao debito\n");
    return OK;
}

Erro depositar(Cliente contas[], int *pos) {

    char CPF[12];
    float valor_depos;
    int contador_erro = 0;

    printf("Insira o CPF que irá receber este depósito: \n");
    fgets(CPF, 12, stdin);
    printf("Insira o valor que gostaria de depositar para esta conta \n");
    scanf("%d", &valor_depos);

    while (strlen(CPF) != 12)
    {
        printf("Insira um valor valido para CPF \n");
        fgets(CPF, 12, stdin);
    }

    while (valor_depos <= 0)
    {
        printf("Insira um valor valido para depósito (maior que 0) \n");
        scanf("%d", &valor_depos);
    }
    
    for (int i = 0; i < *pos; i++)
    {
        if (strcmp(contas[i].cpf, CPF) == 0)
        {
            contas[i].saldo = contas[i].saldo + valor_depos;
        }
        else
        {
            contador_erro++;
        }
        
    }

    if (contador_erro >= pos)
    {
        return NAO_ENCONTRADO;
    }

    return OK;
}

Erro transferir(Cliente contas[], int *pos) {
    printf("Funcao transferencia\n");
    return OK;
}