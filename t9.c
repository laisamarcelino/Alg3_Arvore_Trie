#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define MAX_PALAVRA 100


// Utiliza *nomeArquivo para abrir arquivo indicado
// Insere as palavras no dicionario atraves da raiz
// Encerra o programa imediatamente em caso de erro
void carregarDicionario(pontNodo raiz, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo de dicionário.\n");
        exit(EXIT_FAILURE);  // Codigo de erro. O programa eh imediatamente abortado.
    }

    char *palavra = (char*) malloc(MAX_PALAVRA * sizeof(char));
    if(palavra == NULL) {

        fprintf(stderr, "Erro ao alocar vetor de palavras.\n");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }


    while (fscanf(arquivo, "%s", palavra) != EOF) {
        insere(raiz, palavra); 
    }

    free(palavra);
    fclose(arquivo);
}


/* -------------------------------------------------- */


// Acessa trie pela sua traiz, processando consultas de entrada
void processarConsultas(pontNodo raiz) {
    char entrada[MAX_PALAVRA];                             
    pontNodo p = NULL;
    int novaSequencia = 1;

    while (scanf("%s", entrada) != EOF) {
        if (strcmp(entrada, "0") == 0) {
            break;
        }

        int i = 0;
        int entradaInvalida = 0;  // verifica validade da entrada

        // Inicia nova sequência se a entrada começar com dígito
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


/* -------------------------------------------------- */


// Valor esperado para argc: 2
// Esperado para *argv[]: nome do arquivo a ser aberto (formato .txt)
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s dicionario.txt < consulta.txt > saida.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    pontNodo raiz = criaNo();

    // argv[1] refere-se ao arquivo de dicionario a ser carregado
    carregarDicionario(raiz, argv[1]);

    processarConsultas(raiz);

    freeArv(raiz);

    return EXIT_SUCCESS;  // indica fim da execucao sem erros
}
