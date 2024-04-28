#define TOTAL = 1000

typedef struct Cliente {
    char nome[100];
    char cpf[12];
    char tipo_conta[6];
    float saldo;
    char senha[100];
} Cliente;