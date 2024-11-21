#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define MAX_PALAVRA 100

// Função para carregar palavras do dicionário na trie
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
    char entrada[MAX_PALAVRA];
    pontNodo p = NULL;
    int novaSequencia = 1;

    while (scanf("%s", entrada) != EOF) {
        if (strcmp(entrada, "0") == 0) {
            break;
        }

        int i = 0;
        int entradaInvalida = 0;
        int avancouComCerquilha = 0;

        // Iniciar nova sequência se a entrada começar com dígito
        if (entrada[0] >= '2' && entrada[0] <= '9') {
            p = raiz;
            novaSequencia = 0;
        } else if (entrada[0] == '#') {
            if (novaSequencia) {
                printf("palavra nao encontrada\n");
                continue;
            }
            // Continuar a partir do estado atual
        } else {
            printf("entrada invalida\n");
            p = NULL;
            novaSequencia = 1;
            continue;
        }

        while (entrada[i] != '\0') {
            char c = entrada[i];
            if (c >= '2' && c <= '9') {
                int indice = c - '0';
                if (p != NULL && p->filhos[indice] != NULL) {
                    p = p->filhos[indice];
                } else {
                    printf("palavra nao encontrada\n");
                    p = NULL;
                    novaSequencia = 1;
                    entradaInvalida = 1;
                    break;
                }
            } else if (c == '#') {
                if (p != NULL && p->prox != NULL) {
                    p = p->prox;
                    avancouComCerquilha = 1;
                } else {
                    printf("palavra nao encontrada\n");
                    p = NULL;
                    novaSequencia = 1;
                    entradaInvalida = 1;
                    break;
                }
            } else {
                printf("entrada invalida\n");
                p = NULL;
                novaSequencia = 1;
                entradaInvalida = 1;
                break;
            }
            i++;
        }

        // Se não houve erro e a palavra é válida, imprime
        if (!entradaInvalida && p != NULL && p->palavra != NULL) {
            printf("%s\n", p->palavra);
        }
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
