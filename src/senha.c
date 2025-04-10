#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "senha.h"

#define DB_PATH "data/senhas.txt"

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
