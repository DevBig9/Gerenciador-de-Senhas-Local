#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "senha.h"

void adicionarSenha() {
    Registro r;

    printf("Nome do serviço: ");
    scanf(" %[^\n]", r.servico);

    printf("Login: ");
    scanf(" %[^\n]", r.login);

    printf("Senha: ");
    scanf(" %[^\n]", r.senha);

    FILE *arquivo = fopen("senhas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;

    }

    fprintf(arquivo, "%s;%s;%s\n", r.servico, r.login, r.senha);
    fclose(arquivo);

    printf("Senha salva com sucesso!\n\n");
}

void listarSenhas() {
    FILE *arquivo = fopen("senhas.txt", "r");
    if (arquivo = NULL) {
        printf("nenhuma senha salva ainda.\n");
        return;
    }

    Registro r;
    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^\n]\n", r.servico, r.login, r.senha) != EOF) {
        printf("Serviço: %s | Login: %s | Senha: %s\n", r.servico, r.login, r.senha);
    }

    fclose(arquivo);
}

void removerSenha() {
    printf("Função de remover ainda não implementada.\n");
}

    
