#include <stdio.h>
#include <stdlib.h>
#include "senha.h"

int main () {
    int opcao;
    char buffer[10];

    do { 
        printf("\n*----------------------------*\n");
        printf("   & Gerenciador de Senhas &  \n");
        printf("*----------------------------*\n");

        printf("1) Adicionar Senha\n");
        printf("2) Listar Senhas\n");
        printf("0) Sair\n");
        printf("Escolha: ");

        fgets(buffer, sizeof(buffer), stdin);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarSenha();
                break;
            case 2:
                listarSenhas();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while(opcao != 0);

    return 0;

}