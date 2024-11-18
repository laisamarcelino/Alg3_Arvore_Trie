#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define MAX_PALAVRA 100

// Função para carregar palavras do dicionário na t2rie
void carregarDicionario(pontNodo raiz, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo de dicionário.\n");
        exit(EXIT_FAILURE);
    }

    char palavra[MAX_PALAVRA];
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        insere(raiz, palavra);
    }

    fclose(arquivo);
}

// Função para processar as consultas
void processarConsultas(pontNodo raiz) {
    char consulta[MAX_PALAVRA];
    while (scanf("%s", consulta) != EOF) {
        if (strcmp(consulta, "0") == 0) {
            break; // Termina ao encontrar "0"
        }

        busca(raiz, consulta);
       
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s dicionario.txt < consulta.txt > saida.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Cria a raiz da trie
    pontNodo raiz = criaNo();

    // Carrega palavras do dicionário na trie
    carregarDicionario(raiz, argv[1]);

    // Processa consultas da entrada padrão
    processarConsultas(raiz);

    // Libera memória da trie
    freeArv(raiz);

    return EXIT_SUCCESS;
}
