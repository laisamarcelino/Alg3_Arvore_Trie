
#ifndef _TRABALHO_H
#define _TRABALHO_H

#define NUMLETRA 10
#define ITEMNULO ""
#define indC(c) (c- 'a')


typedef int TipoItem;


typedef struct Nodo *ApNodo;
typedef struct Nodo {

    TipoItem item;
    ApNodo prox[NUMLETRA];
}Nodo;

Nodo* criaNo(); //laisa

void criaArv(ApNodo *raiz); //laisa
 
//Esta função libera a memória alocada para o Trie.
void freeArv(ApNodo raiz); //laisa

//A função de busca verifica se uma sequência de números corresponde a 
//uma palavra no Trie.
ApNodo busca(TipoItem v, ApNodo raiz); //andy

//Esta função insere uma palavra no Trie, convertendo cada caractere em seu número 
//correspondente e criando os nós necessários.
ApNodo insere(TipoItem v, ApNodo raiz); //andy

void escreve(ApNodo raiz); //laisa

//  converte letras para os números correspondentes no teclado T9.
int mapeiaCaracter(char c); //juntes

//main - andy


#endif
