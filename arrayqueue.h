#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arrayqueue {
    int frente;
    int tras;
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arrayqueue* inicializar(int tamArray) {
    struct arrayqueue* fila = (struct arrayqueue*)malloc(sizeof(struct arrayqueue));
    fila->elementos = (int*)calloc(tamArray, sizeof(int));
    fila->qtdade = 0;
    fila->tamanho = tamArray;
    fila->frente = -1;
    fila->tras = -1;
    return fila;
}

void enfileirar(struct arrayqueue** fila, int val) {
    if (*fila == NULL) {
        *fila = inicializar(10);
    }
    if (((*fila)->tras + 1) % (*fila)->tamanho != (*fila)->frente) {
        if ((*fila)->qtdade == 0) {
            (*fila)->elementos[(*fila)->qtdade] = val;
            (*fila)->frente++;
            (*fila)->tras++;
            (*fila)->qtdade++;
        }
        else {
            (*fila)->tras = ((*fila)->tras + 1) % (*fila)->tamanho;
            (*fila)->qtdade++;
            (*fila)->elementos[(*fila)->tras] = val;
        }
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct arrayqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return INT_MIN;
    }
    else {
        if (fila->qtdade == 1) {
            int aux = fila->frente;
            fila->tras = -1;
            fila->frente = -1;
            fila->qtdade--;
            return fila->elementos[aux];
        }
        else {
            fila->frente = (fila->frente + 1) % fila->tamanho;
            fila->qtdade--;
            return fila->elementos[(fila->frente - 1) % fila->tamanho];
        }
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct arrayqueue* fila) {
    if (fila == NULL || fila->qtdade == 0) {
        return INT_MIN;
    }
    else {
        return fila->elementos[fila->frente];
    }
}
