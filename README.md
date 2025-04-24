# 🔐 Gerenciador de Senhas Local (C)

Um gerenciador de senhas simples feito em linguagem C, com interface personalizada no terminal, focado em armazenar dados localmente com segurança e praticidade. Agora com senha mestre, sistema de tentativas e remoção de senhas, criptografia, sistema de login com tentativas e cooldown, funcionalidade de CRUD, exportação e importação de dados CSV e Logs de Acesso.

---


## 🎯 Objetivo

O objetivo deste projeto é fornecer uma ferramenta simples e eficaz para gerenciar senhas de forma local, evitando o armazenamento em nuvem e garantindo a segurança dos dados.

---


## ⚠️ Aviso

Este projeto não deve ser utilizado em produção. A segurança das senhas depende de muitos fatores e este código não garante proteção adequada.

---


## 📋 Requisitos

- Compilador GCC (GNU Compiler Collection)
- Sistema operacional compatível com C (Linux, Windows, MacOS)

---


## 🚀 Funcionalidades

- ✅ Cadastro de senha mestre.
- ✅ Verificação com 3 tentativas (errou, já era).
- ✅ Armazenamento de senhas localmente em arquivo `.txt`.
- ✅ Adição de novas senhas.
- ✅ Listagem de todas as senhas salvas.
- ✅ Remoção de senha por nome do serviço.
- ✅ Criptografia de senha.
- ✅ Sistema de login com tentativas e cooldown.
- ✅ Funcionalidades de CRUD.
- ✅ Exportação/Importação de dados CSV.
- ✅ Logs de acesso
- ✅ Interface personalizada no terminal

---

## 🛠️ Tecnologias

- Linguagem C
- Manipulação de arquivos (`fopen`, `fscanf`, `fprintf`)
- Entrada de dados via `fgets`, `sscanf`
- Organização modular com `.c` e `.h`

---

## ⚙️ Como compilar

- Abra o terminal na raiz do projeto e digite:

```bash
gcc src/main.c src/senha.c -o build/gerenciador 

./build/gerenciador

```

---

## ⏳ Versão

1.0.0 - 24/04/2025

