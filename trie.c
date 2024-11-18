#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

pontNodo criaNo(){
    pontNodo no = (pontNodo)malloc(sizeof(nodo));
    if (no == NULL){
        fprintf(stderr, "Erro ao alocar memoria para o no.\n");
        return NULL;
    }

    // Inicializa os filhos e o proximo como NULL
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
    int indice;
    pontNodo p = raiz;

    // Converte cada letra da palavra para seu número correspondente e navega pela trie
    for(int nivel = 0; nivel < strlen(palavra); nivel++){
        indice = mapeiaCaracter(palavra[nivel]);

        if (indice == -1){
            fprintf(stderr, "entrada invalida");
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
    } 
    else {
        // Se já houver uma palavra com essa sequência, cria a lista encadeada
        nodo *novoNo = criaNo();
        novoNo->palavra = strdup(palavra);
        novoNo->prox = p->prox;
        p->prox = novoNo;
    }
}
/*
pontNodo busca(pontNodo raiz, const char *palavra) {

    int indice;
    int compr = strlen(palavra);
    pontNodo p = raiz;

    for (int nivel = 0; nivel < compr; nivel++) {

        indice = mapeiaCaracter(palavra[nivel]);

        if (indice == -1) {

            fprintf(stderr, "Caractere inválido na palavra buscada %s\n", palavra);
            return NULL;
        }

        // se o caminho nao existir, a palavra nao existe

        if(p->filhos[indice] == NULL) {

            printf("A palavra %s nao esta na Trie. \n", palavra);
            return NULL;
        }

        p = p->filhos[indice]; // indo para o proximo nivel
    }

    /* a parte a seguir eu nao tenho crtz, to com duvida e quero
    conversar sobre isso com você amanhã, ai eu ajeito. */

    // Duvidas: uso do booleano e qual deve ser o retorno dessa função
    /*
    if (p->fim == true) {

        printf("%s foi encontrado na arvore.\n", palavra);
        return indice; // por enquanto, vou retornar o indice do ultimo caractere
    }

    // isso pode ser um else tmb, eh que eu nao gosto de if-else mas tu que sabes
    
    printf("A palavra %s nao esta na Trie.\n", palavra);
    return NULL;

}
*/

// Busca na trie com suporte ao '#' para múltiplas palavras
void busca(pontNodo raiz, const char *sequencia) {
    pontNodo p = raiz;

    // Navega conforme a sequência numérica
    for (int i = 0; i < strlen(sequencia); i++) {
        char c = sequencia[i];
        if (c == '#') {
            if (p->prox) {
                p = p->prox;
                printf("%s\n", p->palavra);
                return;
            } else {
                printf("palavra nao encontrada\n");
                return;
            }
        } else if (c >= '2' && c <= '9') {
            int indice = c - '0';
            if (!p->filhos[indice]) {
                printf("palavra nao encontrada\n");
                return;
            }
            p = p->filhos[indice];
        } else {
            printf("entrada invalida\n");
            return;
        }
    }

    // Exibe a palavra encontrada ou mensagem de erro
    if (p && p->palavra) {
        printf("%s\n", p->palavra);
    } else {
        printf("palavra nao encontrada\n");
    }
}