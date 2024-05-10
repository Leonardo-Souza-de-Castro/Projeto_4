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


Erro salvar(Cliente contas[], int *pos) {
  FILE *f = fopen("contas.bin", "wb");

  if (f == NULL) {
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
    printf("Erro para escrever posição\n");
    return ESCREVER;
  }

  if (fclose(f)) {
    printf("Erro ao fechar\n");
    return FECHAR;
  }

  return OK;
}


Erro carregar(Cliente contas[], int *pos) {
  FILE *f = fopen("contas.bin", "rb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return ABRIR;
  }

  int num = fread(contas, TOTAL, sizeof(Cliente), f);
  if (num == 0) {
    printf("Erro ao carregar arquivo\n");
    return LER;
  }

  num = fread(pos, 1, sizeof(int), f);
  if (num == 0) {
    printf("Erro para abrir posição de arquivo\n");
    return LER;
  }

  if (fclose(f)) {
    printf("Erro ao fechar arquivo\n");
    return FECHAR;
  }
}