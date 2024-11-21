#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

pontNodo criaNo(){
    pontNodo no = (pontNodo)malloc(sizeof(Nodo));
    if (no == NULL){
        fprintf(stderr, "Erro ao alocar memoria para o no.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa os filhos e o prox como NULL
    for (int i = 0; i < NUMLETRA; i++)
        no->filhos[i] = NULL;

    no->palavra = NULL;
    no->prox = NULL;

    return no;
}

void freeArv(pontNodo raiz){
    if (raiz == NULL)
        return;

    for (int i = 0; i < NUMLETRA; i++)
        freeArv(raiz->filhos[i]);

    freeArv(raiz->prox);

    free(raiz->palavra);
    free(raiz);
}

int mapeiaCaracter(char c){
    if (c >= 'a' && c <= 'c') return 2;
    if (c >= 'd' && c <= 'f') return 3;
    if (c >= 'g' && c <= 'i') return 4;
    if (c >= 'j' && c <= 'l') return 5;
    if (c >= 'm' && c <= 'o') return 6;
    if (c >= 'p' && c <= 's') return 7;
    if (c >= 't' && c <= 'v') return 8;
    if (c >= 'w' && c <= 'z') return 9;
    return -1;
}

void insere(pontNodo raiz, const char *palavra){
    int indice;
    pontNodo p = raiz;

    // Converte cada letra da palavra para seu número correspondente e navega pela trie
    for(int nivel = 0; palavra[nivel] != '\0'; nivel++){
        indice = mapeiaCaracter(palavra[nivel]);

        if (indice == -1){
            fprintf(stderr, "entrada invalida\n");
            return;
        }

        // Cria o nó se não existir
        if (p->filhos[indice] == NULL)
            p->filhos[indice] = criaNo();

        p = p->filhos[indice];
    }

    // Chegamos ao final da sequência, atribui a palavra
    if (p->palavra == NULL) {
        p->palavra = strdup(palavra);
        if (p->palavra == NULL) {
            fprintf(stderr, "Erro ao alocar memoria para a palavra.\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        // Se já houver uma palavra com essa sequência, adiciona à lista encadeada
        pontNodo atual = p;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        pontNodo novoNo = criaNo();
        novoNo->palavra = strdup(palavra);
        if (novoNo->palavra == NULL) {
            fprintf(stderr, "Erro ao alocar memoria para a palavra.\n");
            exit(EXIT_FAILURE);
        }
        atual->prox = novoNo;
    }
}
