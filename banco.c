#include "banco.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

Erro debitar(Cliente contas[], int *pos) {
    char cpf[12];
    char senha[100];
    float valor_debito;
    float taxa;
    int contador_erro = 0;
    char transacao[100];

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
            if (strcmp(contas[i].tipo_conta, "comum") == 0)
            {
                taxa = 0.5*valor_debito;
                if (contas[i].saldo - (valor_debito + taxa) < -1000)
                {
                    printf("Limite de saldo negativo atingido");
                }else
                {
                    contas[i].saldo = contas[i].saldo - (valor_debito + taxa);
                    sprintf(transacao, "Debito: -%.2f$ | Tarifa: %.2f$ | Saldo: %.2f$", valor_debito + taxa, taxa, contas[i].saldo);
                    criar_extrato(contas[i].nome, transacao);
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
                    FILE *f = fopen(contas[i].nome, "a");
                    int qtd = fprintf(f, "Debito: -%.2f$ | Tarifa: %.2f$ | Saldo: %.2f$\n", valor_debito + taxa, taxa, contas[i].saldo);
                    fclose(f); 
                }

            }


        } else {
        contador_erro++;
        }
    }

    if (contador_erro >= *pos) {
        return NAO_ENCONTRADO;
    }


    return OK;
}


Erro depositar(Cliente contas[], int *pos) {

  char cpf[12];
  float valor_depos;
  int contador_erro = 0;

  printf("Insira o CPF que irá receber este depósito: \n");
  fgets(cpf, 12, stdin);

  cpf[strcspn(cpf, "\n")] = 0;

  while (strlen(cpf) != 11) {
    printf("Insira um valor valido para CPF \n");
    fgets(cpf, 12, stdin);
  }
  clearBuffer();

  printf("Insira o valor que gostaria de depositar para esta conta \n");
  scanf("%f", &valor_depos);

  while (valor_depos <= 0) {
    printf("Insira um valor valido para depósito (maior que 0) \n");
    scanf("%f", &valor_depos);
  }

  for (int i = 0; i < *pos; i++) {
    if (strcmp(contas[i].cpf, cpf) == 0) {
      contas[i].saldo = contas[i].saldo + valor_depos;
      char transacao[100];
      sprintf(transacao, "Deposito: +%.2f$ | Tarifa: 0.0$ | Saldo: %.2f$", valor_depos, contas[i].saldo);
      criar_extrato(contas[i].nome, transacao);
    } else {
      contador_erro++;
    }
  }

  if (contador_erro >= *pos) {
    return NAO_ENCONTRADO;
  }

  return OK;
}


Erro transferir(Cliente contas[], int *pos) {
    char cpf_dest[12];
    char cpf_orig[12];
    char senha_origem[100];
    int limite_atng = 0;
    float valor;
    float taxa;
    int contador_erro = 0;
    char transacao[100];

    printf("Insira o CPF de origem da conta: \n");
    fgets(cpf_orig, 12, stdin);

    cpf_orig[strcspn(cpf_orig, "\n")] = 0;

    while (strlen(cpf_orig) != 11) {
        printf("Insira um valor valido para CPF \n");
        fgets(cpf_orig, 12, stdin);
    }
    clearBuffer();

    printf("Insira a senha da conta: \n");
    fgets(senha_origem, 100, stdin);

    senha_origem[strcspn(senha_origem, "\n")] = 0;

    printf("Insira o CPF de destino da transferencia: \n");
    fgets(cpf_dest, 12, stdin);

    cpf_dest[strcspn(cpf_dest, "\n")] = 0;

    while (strlen(cpf_dest) != 11) {
        printf("Insira um valor valido para CPF \n");
        fgets(cpf_dest, 12, stdin);
    }

    printf("Insira o valor que gostaria de transferir: \n");
    scanf("%f", &valor);

    while (valor <= 0) {
        printf("Insira um valor valido para transferir (maior que 0) \n");
        scanf("%f", &valor);
    }
    int i = 0;
    for (i; i < *pos; i++) {
        if (strcmp(contas[i].cpf, cpf_orig) == 0 && strcmp(contas[i].senha, senha_origem) == 0) {
            if (strcmp(contas[i].tipo_conta, "comum") == 0)
            {
                taxa = 0.5*valor;
                if (contas[i].saldo - (valor + taxa) < -1000)
                {
                    limite_atng++;
                    printf("Limite de saldo negativo atingido");
                }else
                {
                    contas[i].saldo = contas[i].saldo - (valor + taxa);
                    sprintf(transacao, "Debito: -%.2f$ | Tarifa: %.2f$ | Saldo: %.2f$", valor + taxa, taxa, contas[i].saldo);
                    criar_extrato(contas[i].nome, transacao);
                }

            }else
            {
                taxa = 0.3*valor;

                if (contas[i].saldo - (valor + taxa) < -5000)
                {
                    limite_atng++;
                    printf("Limite de saldo negativo atingido");
                }else
                {
                    contas[i].saldo = contas[i].saldo - (valor + taxa);
                    sprintf(transacao, "Debito: -%.2f$ | Tarifa: %.2f$ | Saldo: %.2f$", valor + taxa, taxa, contas[i].saldo);
                    criar_extrato(contas[i].nome, transacao);
                }

            }


        }
        else if (strcmp(contas[i].cpf, cpf_dest) == 0 && limite_atng == 0)
        {
            contas[i].saldo = contas[i].saldo + valor;
            sprintf(transacao, "Deposito: +%.2f$ | Tarifa: 0.0$ | Saldo: %.2f$", valor, contas[i].saldo);
            criar_extrato(contas[i].nome, transacao);
        }
        else{
          return NAO_ENCONTRADO;
        }
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

void criar_extrato(char nome[], char transacao[]) {
    FILE *f, *f_temp;
    char linha[100];
    int primeira_linha = 1;
    char nome_arq[100];

    strcpy(nome_arq, nome);
    strcat(nome_arq, ".txt");

    f = fopen(nome_arq, "r+");

    if (f == NULL) {
        f = fopen(nome_arq, "w+");
        if (f == NULL) {
            printf("Erro ao criar o arquivo.\n");
            exit(1);
        }
    }

    int cont = 0;
    while (fgets(linha, sizeof(linha), f) != NULL) {
        cont++;
    }

    rewind(f);

    if (cont >= TOTAL_TRANSACOES) {
        f_temp = fopen("temp.txt", "w");
        if (f_temp == NULL) {
            printf("Erro ao criar o arquivo temp.\n");
            exit(1);
        }

        while (fgets(linha, sizeof(linha), f) != NULL) {
            if (primeira_linha == 1) {
                primeira_linha = 0;
                continue;
            }
            fprintf(f_temp, "%s", linha);
        }
        fprintf(f_temp, "%s\n", transacao);

        fclose(f_temp);
        fclose(f);

        remove(nome_arq);
        rename("temp.txt", nome_arq);

        return; 
    }

    fseek(f, 0, SEEK_END);

    fprintf(f, "%s\n", transacao);

    fclose(f);
}

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}