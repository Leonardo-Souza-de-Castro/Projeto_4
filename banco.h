#define TOTAL 1000

typedef struct Cliente {
    char nome[100];
    char cpf[12];
    char tipo_conta[6];
    float saldo;
    char senha[100];
} Cliente;

typedef enum Erros {
    OK,
    SALDO_INSUFICIENTE,
    NAO_ENCONTRADO,
    SENHA_INVALIDA,
    CPF_INVALIDO,
    TIPO_CONTA_INVALIDO,
    SEM_CLIENTES,
    ESCREVER,
    LER,
    ABRIR,
    FECHAR,
    SEM_TRANSACOES,
    MAX_CLIENTES,
} Erro;

typedef Erro (*funcao)(Cliente[], int*);