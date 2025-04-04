#include <stdio.h>
#include <stdlib.h>
#include "senha.h"

int main () {
    int opcao;

    do { 
        printf("\n*----------------------------*\n");
        printf("   & Gerenciador de Senhas &  \n");
        printf("*----------------------------*\n");

        printf("1) Adicionar Senha\n");
        printf("2) Listar Senhas\n");
        printf("3) Remover Senha\n");
        printf("0) Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarSenha();
                break;
            case 2:
                listarSenhas();
                break;
            case 3:
                removerSenhas();
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while(opcao != 0);

    return 0;

}