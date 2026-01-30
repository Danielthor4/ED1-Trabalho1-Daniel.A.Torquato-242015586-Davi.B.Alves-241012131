# Trabalho Prático — Estruturas de Dados I (ED1)

## CRUD de Clientes e Produtos usando Listas Encadeadas em C

**Autores:**
- Daniel Almeida Torquato — 242015586  
- Davi Barbosa Alves — 241012131  

---

## 📄 Descrição

O objetivo deste trabalho é desenvolver um sistema na linguagem **C**, utilizando **listas simplesmente encadeadas** para armazenar e manipular os dados de forma dinâmica, implementando operações completas de **CRUD** (Create, Read, Update e Delete).

---

## ⚙️ Funcionalidades

O sistema possui um **menu principal** com três módulos:

### 1️⃣ Gerenciamento de Clientes
Permite:
- Cadastrar cliente (CPF, nome, email, telefone e data de nascimento);
- Listar todos os clientes;
- Buscar cliente pelo CPF;
- Editar dados de um cliente;
- Remover cliente;

### 2️⃣ Gerenciamento de Produtos
Permite:
- Cadastrar produto (código único, nome, preço e quantidade);
- Listar todos os produtos;
- Buscar produto pelo código;
- Editar dados de um produto;
- Remover produto;

### 3️⃣ Modo Compra
Permite:
- Incluir produtos no carrinho de um cliente;
- Listar os produtos do carrinho, informando quantidade total de itens e valor final da compra;
- Remover produtos do carrinho do cliente.

---

## ▶️ Como Compilar e Executar

### 🔹 Compilação

Utilize o comando abaixo no terminal, dentro da pasta do projeto:

```bash
gcc -Wall -Wextra -g3 main.c clientes.c produtos.c compras.c utils.c -o main.exe
```

### 🔹 Execução

Após a compilação, execute:

```bash
./main.exe
```

### 🔹 Makefile

Também existem comandos Makefile disponíveis:

```bash
build — Compilar o projeto

run — Executar o projeto

build-run — Compilar e executar

clean — Apagar o executável

rebuild — Apagar, compilar e executar
```