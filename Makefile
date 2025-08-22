# Nome do projeto
TARGET = t9

# Compilador
CC = gcc

# Flags de compilacao
CFLAGS = -W -Wall -Wextra

# Regra padrao
all: $(TARGET)

# Criando executavel
$(TARGET): t9.o trie.o
	$(CC) $(CFLAGS) -o $(TARGET) t9.o trie.o

# Copiando o README

LEIAME:
	cp LEIAME.md ./$(TARGET)_LEIAME.md

# Regras de compilacao dos objetos
t9.o: t9.c trie.h
	$(CC) $(CFLAGS) -c t9.c

trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

# Limpeza de arquivos
clean:
	rm -f *.o *.gch $(TARGET)
	clear