# 🔐 Gerenciador de Senhas Local (C)

Um gerenciador de senhas simples feito em linguagem C, focado em armazenar dados localmente com segurança e praticidade. Agora com senha mestre, sistema de tentativas e remoção de senhas.

---

## 🚀 Funcionalidades

- ✅ Cadastro de senha mestre
- ✅ Verificação com 3 tentativas (errou, já era)
- ✅ Armazenamento de senhas localmente em arquivo `.txt`
- ✅ Adição de novas senhas
- ✅ Listagem de todas as senhas salvas
- ✅ Remoção de senha por nome do serviço

---

## 🛠️ Tecnologias

- Linguagem C
- Manipulação de arquivos (`fopen`, `fscanf`, `fprintf`)
- Entrada de dados via `fgets`, `sscanf`
- Organização modular com `.c` e `.h`

---


## 📦 Compilação

```bash
gcc src/main.c src/senha.c -o build/gerenciador
./build/gerenciador


