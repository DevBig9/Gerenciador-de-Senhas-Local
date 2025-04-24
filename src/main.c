#include <stdio.h>
#include <stdlib.h>
#include "senha.h"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

int main () {
    printf("\n");
    system("chcp 65001"); // Unico modo que eu achei para ele ler a formatação bonitinha e com cores do menu
    printf("\n");
    int opcao;
    char buffer[10];

    if (!verificarSenhaMestre()) {
        return 1;
    }

    do { 
        printf(CYAN "\n╔═══════════════════════════════╗\n");
        printf("║      Gerenciador de Senhas     ║\n");
        printf("╚═══════════════════════════════╝\n" RESET);

        printf(YELLOW "1" RESET ") Adicionar Senha\n");
        printf(YELLOW "2" RESET ") Listar Senhas\n");
        printf(YELLOW "3" RESET ") Remover Senha\n");
        printf(YELLOW "4" RESET ") Buscar por Serviço\n");
        printf(YELLOW "5" RESET ") Editar Senha\n");
        printf(YELLOW "6" RESET ") Exportar Senhas (CSV)\n");
        printf(YELLOW "7" RESET ") Importar Senhas (CSV)\n");
        printf(YELLOW "8" RESET ") Gerar Senha Forte\n");
        printf(YELLOW "0" RESET ") Sair\n");
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
            case 7:
                importarSenhas();
                break;
            case 8: {
                int tamanho;
                char senhaGerada[100];

                printf("Tamanho da senha desejada: ");
                scanf("%d", &tamanho);
                getchar();

                gerarSenhaForte(tamanho, senhaGerada);
                printf("Senha gerada: %s\n", senhaGerada);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
            }
                
        }

    } while(opcao != 0);

    return 0;
}
