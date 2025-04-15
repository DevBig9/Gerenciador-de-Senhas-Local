#ifndef SENHA_H
#define SENHA_H

typedef struct {
    char servico [50];
    char login [50];
    char senha [50];
} Registro;

int verificarSenhaMestre();
void cadastrarSenhaMestre();

void adicionarSenha();
void removerSenha();
void listarSenhas();

void criptografar(char *texto);
void descriptografar(char *texto);


#endif