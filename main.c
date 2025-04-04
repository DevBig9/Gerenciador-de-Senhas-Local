#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char nome_servico [50];
    char login [50];
    int senha;


    printf("*----------------------------*\n");
    printf("   &Gerenciador de Senhas&       ");
    printf("*----------------------------*\n");

    printf("1) Nome do serviço (EX: GMAIL, NETFLIX, YOUTUBE, etc...): \n");
    scanf("%s", &nome_servico);
    printf("2) Digite seu login(EX: cleitonrasta@gmail.com): \n");
    scanf("%s", &login);
    printf("3) Digite sua senha: \n");
    scanf("%d", &senha);
}