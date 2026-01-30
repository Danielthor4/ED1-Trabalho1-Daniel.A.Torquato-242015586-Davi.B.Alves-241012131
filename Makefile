# =========================
# Configuração do projeto
# =========================

EXEC = main
SRC = main.c clientes.c produtos.c compras.c utils.c
CFLAGS = -Wall -Wextra -g3

# =========================
# Detecção de sistema
# =========================

ifeq ($(OS),Windows_NT)
    EXEC_EXT = .exe
    RM = del
    RUN = $(EXEC)$(EXEC_EXT)
else
    EXEC_EXT =
    RM = rm -f
    RUN = ./$(EXEC)
endif

# =========================
# Regras
# =========================

# Compilar
build:
	gcc $(CFLAGS) $(SRC) -o $(EXEC)$(EXEC_EXT)

# Executar
run:
	$(RUN)

# Compilar e executar
build-run: build
	$(RUN)

# Apagar executável
clean:
	$(RM) $(EXEC)$(EXEC_EXT)

# Apagar, compilar e executar
rebuild: clean build
	$(RUN)