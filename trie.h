#ifndef TRIE_H
#define TRIE_H

#define NUMLETRA 10  // Filhos de 0 a 9

typedef struct Nodo {
    char *palavra;
    struct Nodo *filhos[NUMLETRA];
    struct Nodo *prox;
} Nodo;

typedef Nodo* pontNodo;

pontNodo criaNo();
void freeArv(pontNodo raiz);
void insere(pontNodo raiz, const char *palavra);

#endif
