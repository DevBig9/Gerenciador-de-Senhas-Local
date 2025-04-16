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
void editarSenha();

void criptografar(char *texto);
void descriptografar(char *texto);

void buscarSenha();

void exportarSenhas();
void importarSenhas();


#endif