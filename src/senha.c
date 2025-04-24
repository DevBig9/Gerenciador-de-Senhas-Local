#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "senha.h"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"


#define DB_PATH "data/senhas.txt"
#define SENHA_MESTRE_PATH "data/senha_mestra.txt"


void cadastrarSenhaMestre() {
    char senha[50];

    printf("Crie uma senha mestre: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    FILE *arquivo = fopen(SENHA_MESTRE_PATH, "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar a senha mestre!\n");
        exit(1);
    }

    fprintf(arquivo, "%s", senha);
    fclose(arquivo);
    printf("Senha mestre cadastrada com sucesso!\n");
}


int verificarSenhaMestre() {
    FILE *arquivo = fopen(SENHA_MESTRE_PATH, "r");
    if (arquivo == NULL) {
        cadastrarSenhaMestre();
        return 1;
    }

    char senhaSalva[50], senhaDigitada[50];
    int tentativas = 3;

    fgets(senhaSalva, sizeof(senhaSalva), arquivo);
    fclose(arquivo);
    senhaSalva[strcspn(senhaSalva, "\n")] = '\0';

    while (tentativas > 0) {
        printf("Digite a senha mestre (%d tentativa%s restante%s): ",
               tentativas, tentativas == 1 ? "" : "s", tentativas == 1 ? "" : "s");
        fgets(senhaDigitada, sizeof(senhaDigitada), stdin);
        senhaDigitada[strcspn(senhaDigitada, "\n")] = '\0';

        if (strcmp(senhaSalva, senhaDigitada) == 0) {
            printf("✅ Acesso permitido!\n");
            registrarLog("Login realizado com sucesso");
            return 1;
        } else {
            tentativas--;
            printf("❌ Senha incorreta.\n");

            if (tentativas == 0) {
                printf("⛔ Número máximo de tentativas excedido. Aguarde 30 segundos...\n");
                Sleep(30000);  // Se for Windows, usar Sleep(30000)
                return 0;
            }
        }
    }

    return 0;
}


void adicionarSenha() {
    Registro r;

    printf("Categoria: ");
    fgets(r.categoria, sizeof(r.categoria), stdin);
    r.categoria[strcspn(r.categoria, "\n")] = '\0';


    printf("Nome do serviço: ");
    fgets(r.servico, sizeof(r.servico), stdin);
    r.servico[strcspn(r.servico, "\n")] = '\0'; 

    printf("Login: ");
    fgets(r.login, sizeof(r.login), stdin);
    r.login[strcspn(r.login, "\n")] = '\0';

    printf("Senha: ");
    fgets(r.senha, sizeof(r.senha), stdin);
    r.senha[strcspn(r.senha, "\n")] = '\0';

    criptografar(r.senha);

    FILE *arquivo = fopen(DB_PATH, "a");
    if (arquivo == NULL) {
        printf(RED "Erro ao abrir o arquivo!\n" RESET);
        return;
    }

    fprintf(arquivo, "%s;%s;%s;%s\n", r.categoria, r.servico, r.login, r.senha);
    fclose(arquivo);

    registrarLog("Senha Adicionada");
    printf(GREEN "Senha salva com sucesso!\n\n" RESET);
}

void listarSenhas() {
    
    FILE *arquivo = fopen(DB_PATH, "r");
    if (arquivo == NULL) {
        printf("Nenhuma senha salva ainda ou erro ao abrir o arquivo.\n");
        return;
    }

    Registro r;
    

    printf(CYAN "\n📦 Lista de Senhas\n" RESET);
    printf("─────────────────────────────────────────────\n");
    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^;];%49[^\n]\n",
        r.categoria, r.servico, r.login, r.senha) == 4) {
        descriptografar(r.senha);
        printf("🔐 [%s] %s | 👤 %s | 🔑 %s\n", r.categoria, r.servico, r.login, r.senha);

    }

    fclose(arquivo);
}


void removerSenha() {
    char alvo[50];
    Registro r;
    int removido = 0;

    printf("Digite o nome do serviço a ser removido: ");
    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    FILE *arquivo = fopen(DB_PATH, "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^;];%49[^\n]\n",
        r.categoria, r.servico, r.login, r.senha) == 4) {
        if (strcmp(r.servico, alvo) != 0) {
            fprintf(temp, "%s;%s;%s;%s\n", r.categoria, r.servico, r.login, r.senha);
        } else {
            removido = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(DB_PATH);
    rename("data/temp.txt", DB_PATH);

    if (removido) {
        printf("Senha removida com sucesso!\n");
        registrarLog("Senha removida");
    } else {
        printf("Serviço não encontrado.\n");
        registrarLog("Tentativa de remover senha falhou (serviço não encontrado)");
    }
}

void criptografar(char *texto) {
    for (int i = 0; texto [i] != '\0'; i++) {
        texto[i] += 3;
    }
}

void descriptografar(char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] -= 3; 
    }
}

void buscarSenha() {
    char alvo[50];
    Registro r;
    int encontrado = 0;

    printf("Digite o nome do serviço a buscar: ");
    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    FILE *arquivo = fopen(DB_PATH, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de senhas!\n");
        return;
    }

    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^;];%49[^\n]\n",
        r.categoria, r.servico, r.login, r.senha) == 4) {
        if (strcmp(r.servico, alvo) == 0) {
            descriptografar(r.senha);
            printf("\n🔎 Serviço encontrado!\n");
            printf("Categoria: %s\nServiço: %s\nLogin: %s\nSenha> %s\n", r.categoria, r.servico, r.login, r.senha);
            encontrado = 1;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("❌ Serviço '%s' não encontrado.\n", alvo);
    }
}

void editarSenha() {
    char alvo[50];
    char novaSenha[50];
    Registro r;
    int alterado = 0;

    printf("Digite o nome do serviço que deseja editar: ");
    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    FILE *arquivo = fopen(DB_PATH, "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^;];%49[^\n]\n",
        r.categoria, r.servico, r.login, r.senha) == 4) {
        if (strcmp(r.servico, alvo) == 0) {
            printf("Categoria: %s | Serviço: %s | Login: %s | Senha atual: [oculta]\n", r.servico, r.login);

            printf("Digite a nova senha: ");
            fgets(novaSenha, sizeof(novaSenha), stdin);
            novaSenha[strcspn(novaSenha, "\n")] = '\0';
            criptografar(novaSenha);

            fprintf(temp, "%s;%s;%s;%s\n", r.categoria, r.servico, r.login, novaSenha);
            alterado = 1;
        } else {
            fprintf(temp, "%s;%s;%s;%s\n", r.categoria,  r.servico, r.login, r.senha);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(DB_PATH);
    rename("data/temp.txt", DB_PATH);

    if (alterado) {
        printf("Senha atualizada com sucesso!\n");
        registrarLog("Senha editada");
    } else {
        printf("Serviço não encontrado.\n");
    }
}

void exportarSenhas() {
    Registro r;

    FILE *arquivo = fopen(DB_PATH, "r");
    FILE *csv = fopen("data/exportado.csv", "w");

    if (arquivo == NULL || csv == NULL) {
        printf("Erro ao abrir os arquivos para exportação.\n");
        return;
    }

    fprintf(csv, "Serviço,Login,Senha\n"); 

    while (fscanf(arquivo, "%49[^;];%49[^;];%49[^;];%49[^\n]\n",
        r.categoria, r.servico, r.login, r.senha) == 4) {
        
        fprintf(csv, "%s;%s,%s,%s\n", r.categoria, r.servico, r.login, r.senha);
    }

    fclose(arquivo);
    fclose(csv);

    printf("Senhas exportadas com sucesso para 'data/exportado.csv'!\n");
    registrarLog("Senhas exportadas para CSV");
}

void importarSenhas() {
    char linha[200];
    Registro r;

    FILE *csv = fopen("data/importar.csv", "r");
    FILE *arquivo = fopen(DB_PATH, "a");

    if (csv == NULL || arquivo == NULL) {
        printf("Erro ao abrir os arquivos para importação.\n");
        return;
    }

    fgets(linha, sizeof(linha), csv); // pula cabeçalho

    while (fgets(linha, sizeof(linha), csv)) {
        sscanf(linha, "%49[^;];%49[^;];%49[^;];%49[^\n]\n", r.categoria, r.servico, r.login, r.senha);
        criptografar(r.senha);
        fprintf(arquivo, "%s;%s;%s;%s\n", r.categoria, r.servico, r.login, r.senha);
    }

    fclose(csv);
    fclose(arquivo);

    printf("Senhas importadas com sucesso de 'data/importar.csv'!\n");
    registrarLog("Senhas importadas de CSV");
}

void gerarSenhaForte(int tamanho, char *destino) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}";
    int charsetSize = strlen(charset);

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        int index = rand() % charsetSize;
        destino[i] = charset[index];
    }

    destino[tamanho] = '\0';
}   

void registrarLog(const char *acao) {
    FILE *log = fopen("data/logs.txt", "a");
    if (log == NULL) return;


    time_t agora;
    time(&agora);
    struct tm *info = localtime(&agora);

    fprintf(log, "[%02d/%02d/%04d %02d:%02d:%02d] %s\n",
        info->tm_mday, info->tm_mon + 1, info->tm_year + 1900,
        info->tm_hour, info->tm_min, info->tm_sec,
        acao);

        fclose(log);
}
    