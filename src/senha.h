#ifndef SENHA_H
#define SENHA_H

typedef struct {
    char servico [50];
    char login [50];
    char senha [50];
} Registro;

void adicionarSenha();
void listarSenhas();


#endif