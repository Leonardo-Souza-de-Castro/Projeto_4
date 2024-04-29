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
    printf("Funcao transferencia\n");
    return OK;
}

Erro salvar(Cliente contas[], int *pos){
    FILE *f  = fopen("contas.bin", "wb");

    if (F == NULL) {
        printf("Erro ao salvar o arquivo\n");
        return ABRIR;
    }

    int num = fwrite(contas, TOTAL, sizeof(Cliente), f);
    if (num == 0) {
        printf("Erro para escrever");
        return ESCREVER;
    }

    num = fwrite(pos, 1, sizeof(int), f);
    if (num == 0) {
        
    }

    return OK;
}