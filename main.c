#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#include <stdio.h>
#include <string.h>

#define MAX_SEQ 100  // Tamanho máximo da sequência de dígitos para exibir

// Função recursiva para imprimir a trie
void imprimirTrie(nodo *node, char *prefixo, int profundidade) {
    if (node == NULL) return;

    // Se o nó contém uma palavra, imprime o prefixo e a palavra
    if (node->palavra != NULL) {
        prefixo[profundidade] = '\0';  // Termina a string prefixo
        printf("Sequência: %s - Palavra: %s\n", prefixo, node->palavra);
    }

    // Percorre todos os filhos de 0 a 9
    for (int i = 0; i < N_ALFABETO; i++) {
        if (node->filhos[i] != NULL) {
            prefixo[profundidade] = '0' + i;  // Adiciona o dígito correspondente ao prefixo
            imprimirTrie(node->filhos[i], prefixo, profundidade + 1);
        }
    }

    // Imprime todas as palavras adicionais ligadas pelo nó `proximo`, se existirem
    nodo *aux = node->prox;
    while (aux != NULL) {
        printf("Sequência: %s - Palavra (alternativa): %s\n", prefixo, aux->palavra);
        aux = aux->prox;
    }
}

// Função auxiliar para iniciar a impressão da trie a partir da raiz
void imprimirArvoreTrie(nodo *raiz) {
    char prefixo[MAX_SEQ];
    imprimirTrie(raiz, prefixo, 0);
}


int main() {
    // Cria a raiz da trie
    nodo *raiz = criaNo();

    // Palavras de teste para adicionar na trie
    const char *palavras[] = {"jello", "rocks", "socks", "sock", "rock", "pock"};
    int num_palavras = sizeof(palavras) / sizeof(palavras[0]);

    // Inserindo palavras na trie
    for (int i = 0; i < num_palavras; i++) {
        insere(raiz, palavras[i]);
        //printf("Palavra '%s' inserida na trie.\n", palavras[i]);
    }

    // Aqui poderia adicionar mais testes para percorrer e verificar as palavras inseridas
    imprimirArvoreTrie(raiz);

    // Libera a memória usada pela trie
    freeArv(raiz);
    return 0;
}
