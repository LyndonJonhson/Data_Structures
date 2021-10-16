#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct noBst {
    int val;
    struct noBst* esq;
    struct noBst* dir;
};

/**
 * Funcao que aloca um novo noBst, e
 * ajusta os ponteiros esq e dir para NULL.
 **/
struct noBst* alocarNovoNo(int val) {
    struct noBst* novoNo = (struct noBst*)malloc(sizeof(struct noBst));
    novoNo->val = val;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    return novoNo;
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * insere um novo valor na BST. Tamanho deve
 * ser incrementado.
 * Ambos tamanho e raiz s�o passados por refer�ncia.
 **/
void inserir(struct noBst** raiz, int val, int* tamanho) {
    if ((*raiz) == NULL) {
        (*raiz) = alocarNovoNo(val);
        *tamanho += 1;
        return;
    }
    else if (val < (*raiz)->val) {
        inserir(&(*raiz)->esq, val, tamanho);
    }
    else {
        inserir(&(*raiz)->dir, val, tamanho);
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * verifica se a mesma cont�m um dado valor.
 **/
bool buscar(struct noBst* raiz, int val) {
    if (raiz == NULL) {
        return false;
    }
    else if (raiz->val == val) {
        return true;
    }
    else if (val < raiz->val) {
        buscar(raiz->esq, val);
    }
    else {
        buscar(raiz->dir, val);
    }
}

/**
 * Funcao que retorna o maior valor de uma BST.
 **/
int max(struct noBst* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    else if (raiz->dir != NULL) {
        return max(raiz->dir);
    }
    return raiz->val;
}

/**
 * Funcao que retorna o menor valor de uma BST.
 **/
int min(struct noBst* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    else if (raiz->esq != NULL) {
        return min(raiz->esq);
    }
    return raiz->val;
}

/**
 * Funcao que retorna a altura de uma BST.
 * A altura de uma BST � dada pela quantidade
 * de arestas entre a raiz e a folha mais distante.
 **/
int altura(struct noBst* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    else {
        int esq = -1;
        int dir = -1;
        if (raiz->esq != NULL) {
            esq = altura(raiz->esq);
        }
        if (raiz->dir != NULL) {
            dir = altura(raiz->dir);
        }
        int maior = (esq > dir) ? esq : dir;
        return (maior + 1);
    }
}

/**
 * Funcao que navega em-ordem na BST e
 * imprime seus elementos.
 **/
void emOrdem(struct noBst* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf(" %d ", raiz->val);
        emOrdem(raiz->dir);
    }
}

/**
 * Funcao que navega pre-ordem na BST e
 * imprime seus elementos.
 **/
void preOrdem(struct noBst* raiz) {
    if (raiz != NULL) {
        printf(" %d ", raiz->val);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

/**
 * Funcao que navega pos-ordem na BST e
 * imprime seus elementos.
 **/
void posOrdem(struct noBst* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf(" %d ", raiz->val);
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * remove o no que contem o valor passado como
 * argumento. Tamanho deve ser decrementado.
 * Tamanho � passado por refer�ncia.
 **/
struct noBst* remover(struct noBst* raiz, int val, int* tamanho) {
    if (raiz == NULL) {
        return NULL;
    }
    if (val < raiz->val) {
        raiz->esq = remover(raiz->esq, val, tamanho);
    }
    else if (val > raiz->val) {
        raiz->dir = remover(raiz->dir, val, tamanho);
    }
    else {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            *tamanho -= 1;
            return NULL;
        }
        else if (raiz->esq == NULL || raiz->dir == NULL) {
            struct noBst* aux;
            if (raiz->esq == NULL) {
                aux = raiz->dir;
            }
            else {
                aux = raiz->esq;
            }
            free(raiz);
            *tamanho -= 1;
            return aux;
        }
        else {
            int aux;
            aux = min(raiz->dir);
            raiz->val = aux;
            raiz->dir = remover(raiz->dir, aux, tamanho);
        }
    }
    return raiz;
}