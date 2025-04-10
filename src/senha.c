#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "senha.h"

#define DB_PATH "data/senhas.txt"
#define SENHA_MESTRE_PATH "data/senha_mestra.txt"


void cadastrarSenhaMestre() {
    char senha[50];

    printf("Crie uma senha mestre: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    FILE *arquivo = fopen(SENHA_MESTRE_PATH, "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar a senha mestre!\n");
        exit(1);
    }

    fprintf(arquivo, "%s", senha);
    fclose(arquivo);
    printf("Senha mestre cadastrada com sucesso!\n");
}

int verificarSenhaMestre() {
    FILE *arquivo = fopen(SENHA_MESTRE_PATH, "r");
    if (arquivo == NULL) {
        cadastrarSenhaMestre();
        return 1;
    }

    char senhaSalva[50], senhaDigitada[50];
    int tentativas = 3;

    fgets(senhaSalva, sizeof(senhaSalva), arquivo);
    fclose(arquivo);
    senhaSalva[strcspn(senhaSalva, "\n")] = '\0';

    while (tentativas > 0) {
        printf("Digite a senha mestre (%d tentativa%s restante%s): ",
                tentativas, tentativas == 1 ? "" : "s", tentativas == 1 ? "" : "s");
        fgets(senhaDigitada, sizeof(senhaDigitada), stdin);
        senhaDigitada[strcspn(senhaDigitada, "\n")] = '\0';

        if (strcmp(senhaSalva, senhaDigitada) == 0) {
            printf("Acesso Permitido!\n");
            return 1;
        } else {
            tentativas--;
            printf("Senha incorreta.\n");
        }
    }

    printf("Número Máximo de tentativas excedido. Encerrando....\n");
    return 0;
}

void adicionarSenha() {
    Registro r;

    printf("Nome do serviço: ");
    fgets(r.servico, sizeof(r.servico), stdin);
    r.servico[strcspn(r.servico, "\n")] = '\0'; // remove \n

    printf("Login: ");
    fgets(r.login, sizeof(r.login), stdin);
    r.login[strcspn(r.login, "\n")] = '\0';

    printf("Senha: ");
    fgets(r.senha, sizeof(r.senha), stdin);
    r.senha[strcspn(r.senha, "\n")] = '\0';

    FILE *arquivo = fopen(DB_PATH, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arquivo, "%s;%s;%s\n", r.servico, r.login, r.senha);
    fclose(arquivo);

    printf("Senha salva com sucesso!\n\n");
}

void listarSenhas() {
    FILE *arquivo = fopen(DB_PATH, "r");
    if (arquivo == NULL) {
        printf("Nenhuma senha salva ainda ou erro ao abrir o arquivo.\n");
        return;
    }

    Registro r;
    printf("\n=== Lista de Senhas ===\n");
    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^\n]\n", r.servico, r.login, r.senha) == 3) {
        printf("Serviço: %s | Login: %s | Senha: %s\n", r.servico, r.login, r.senha);
    }

    fclose(arquivo);
}


void removerSenha() {
    char alvo[50];
    Registro r;
    int removido = 0;

    printf("Digite o nome do serviço a ser removido: ");
    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    FILE *arquivo = fopen(DB_PATH, "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^\n]\n", r.servico, r.login, r.senha) == 3) {
        if (strcmp(r.servico, alvo) != 0) {
            fprintf(temp, "%s;%s;%s\n", r.servico, r.login, r.senha);
        } else {
            removido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(DB_PATH);
    rename("data/temp.txt", DB_PATH);

    if (removido) {
        printf("Senha removida com sucesso!\n");
    } else {
        printf("Serviço não encontrado.\n");
    }
}
