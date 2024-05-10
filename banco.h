#define TOTAL 1000
#define TOTAL_TRANSACOES 100

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

Erro criar(Cliente[], int *pos);
Erro apagar(Cliente[], int *pos);
Erro listar(Cliente[], int *pos);
Erro debitar(Cliente[], int *pos);
Erro depositar(Cliente[], int *pos);
Erro transferir(Cliente[], int *pos);
Erro extrato(Cliente[], int *pos);
Erro salvar(Cliente[], int *pos);
Erro carregar(Cliente[], int *pos);
void criar_extrato(char nome[], char transacao[]);
void clearBuffer();