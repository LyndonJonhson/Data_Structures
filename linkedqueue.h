#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedqueue {
    struct no* frente;
    struct no* tras;
    int qtdade;
};

struct linkedqueue* inicializar() {
    struct linkedqueue* fila = (struct linkedqueue*)malloc(sizeof(struct linkedqueue));
    fila->qtdade = 0;
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->prox = NULL;
    return novoNo;
}

bool vazia(struct linkedqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return true;
    }
    else {
        return false;
    }
}

void enfileirar(struct linkedqueue** fila, int val) {
    if (*fila == NULL) {
        *fila = inicializar();
    }
    struct no* novoNo = alocarNovoNo(val);
    if ((*fila)->qtdade == 0) {
        (*fila)->frente = novoNo;
        (*fila)->tras = novoNo;
        (*fila)->qtdade++;
    }
    else {
        (*fila)->tras->prox = novoNo;
        (*fila)->tras = novoNo;
        (*fila)->qtdade++;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct linkedqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return INT_MIN;;
    }
    struct no* aux = fila->frente;
    int val = fila->frente->val;
    fila->frente = fila->frente->prox;
    fila->qtdade--;
    free(aux);
    return val;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct linkedqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return INT_MIN;;
    }
    else {
        return fila->frente->val;
    }
}