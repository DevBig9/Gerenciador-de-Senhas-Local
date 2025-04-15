#include <stdio.h>
#include <stdlib.h>
#include "senha.h"

int main () {
    int opcao;
    char buffer[10];

    if (!verificarSenhaMestre()) {
        return 1;
    }

    do { 
        printf("\n*----------------------------*\n");
        printf("   & Gerenciador de Senhas &  \n");
        printf("*----------------------------*\n");

        printf("1) Adicionar Senha\n");
        printf("2) Listar Senhas\n");
        printf("3) Remover Senha\n");
        printf("4) Buscar Senha por Serviço\n");
        printf("5) Editar Senha\n");
        printf("6) Exportar Senhas (CSV)\n");
        printf("0) Sair\n");
        printf("Escolha: ");

        fgets(buffer, sizeof(buffer), stdin);  
        sscanf(buffer, "%d", &opcao);          

        switch(opcao) {
            case 1:
                adicionarSenha();
                break;
            case 2:
                listarSenhas();
                break;
            case 3:
                removerSenha();
                break;
            case 4:
                buscarSenha();
                break;
            case 5:
                editarSenha();
                break;
            case 6:
                exportarSenhas();
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
