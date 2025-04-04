#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char nome_servico [50];
    char login [50];
    int senha;
    int opcao;


    printf("*----------------------------*\n");
    printf("   &Gerenciador de Senhas&       ");
    printf("*----------------------------*\n");

    printf("Escolha alguma das opçoes abaixo para continuar: \n");
    printf("1) Adicionar Senha.\n");
    printf("2) Listar Senhas Salvas.\n");
    printf("3) Remover Senhas.\n");
    
    if (opcao == 1) {
        printf("1) Nome do serviço (EX: GMAIL, NETFLIX, YOUTUBE, etc...): \n");
        scanf("%s", &nome_servico);
        printf("2) Digite seu login(EX: cleitonrasta@gmail.com): \n");
        scanf("%s", &login);
        printf("3) Digite sua senha: \n");
        scanf("%d", &senha);
    } 
    if (opcao == 2) {
        printf("Lista de Senhas Salvas.\n");
        printf("1) \n");
        printf("2) \n");
        printf("3) \n");
    }
    if (opcao == 3) {
        printf("Remover senhas\n");
    }
    
    
   


}