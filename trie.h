#ifndef _TRABALHO_H
#define _TRABALHO_H

#include <stdbool.h>

#define N_ALFABETO 10

typedef struct nodo { //todo nó cagarrega ponteiros para potenciais N_ALFABETO subarvores
    struct nodo *filhos[N_ALFABETO]; //ponteiros para os filhos 0-9
    char *palavra; //armazena a palavra, se for o final de uma sequencia
    struct nodo *prox; //ponteiro para a lista encadeada, caso tenha varias palavras com a mesma sequencia
} nodo;

typedef nodo* pontNodo; //ponteiro para a struct nodo

// Cria um no sem filhos 
pontNodo criaNo();

// Libera a memória alocada para a Trie
void freeArv(pontNodo raiz); 

// Converte cada letra de uma palavra em sua sequência T9 correspondentes
int mapeiaCaracter(char c);

void insere(pontNodo raiz, const char *palavra);

//pontNodo busca(pontNodo raiz, const char *palavra);

void busca(pontNodo raiz, const char *sequencia_num);

#endif