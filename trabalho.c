#include "trie.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

pontNodo criaNo(){
    pontNodo no = NULL;

    no = (pontNodo)malloc(sizeof(nodo));
    if (no == NULL)
        return 0;

    //no->fim = false;

    // Inicializa os filhos e o proximo como null
    for (int i = 0; i < N_ALFABETO; i++)
        no->filhos[i] = NULL;
    
    no->palavra = NULL;
    no->prox = NULL;

    return no;
}

void freeArv(pontNodo raiz){
    if (raiz == NULL)
        return;
    
    for (int i = 0; i < N_ALFABETO; i++)
        freeArv(raiz->filhos[i]);

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
    int indice, compr = strlen(palavra);
    pontNodo p = raiz;

    // Converte cada letra da palavra para seu número correspondente e navega pela trie
    for(int nivel = 0; nivel < compr; nivel++){
        indice = mapeiaCaracter(palavra[nivel]);

        if (indice == -1){
            fprintf(stderr, "Caractere inválido na palavra %s\n", palavra);
            return;
        }

        // Cria o nó se não existir
        if (p->filhos[indice] == NULL)
            p->filhos[indice] = criaNo();

        p = p->filhos[indice];
    }

    //p->fim = true

    //precisa disso? entender melhor
    // Chegamos ao final da sequência, atribui a palavra 
    if (p->palavra == NULL) {
        p->palavra = strdup(palavra);
    } else {
        // Se já houver uma palavra com essa sequência, cria a lista encadeada
        nodo *novoNo = criaNo();
        novoNo->palavra = strdup(palavra);
        novoNo->prox = p->prox;
        p->prox = novoNo;
    }
}

/*
int mapearIndice(char c){
    return (int)c - (int)'a';
}

bool busca(pontNodo raiz, char *chave){
    int i, compr = srtlen(chave);
    pontNodo p = raiz;

    for (int nivel = 0; nivel < compr; nivel++){
        i = mapearIndice(chave[nivel]);
        if (!p->filhos[i])
            return false;
        p = p->filhos[i];
    }
    return p->fim;
}
*/