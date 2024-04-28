#include "banco.h"
#include <stdio.h>
#include <string.h>

Erro criar(Cliente contas[], int *pos) {
    printf("Funcao criar\n");
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