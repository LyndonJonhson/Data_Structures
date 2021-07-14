#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedlist {
    struct no* cabeca;
    int qtdade;
};

struct linkedlist* inicializar() {
    struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    lista->cabeca = NULL;
    lista->qtdade = 0;
    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
    if (lista->cabeca == 0) {
        lista->cabeca = alocarNovoNo(valor);
        lista->qtdade++;
    }
    else {
        struct no* aux, * novoNo;
        aux = lista->cabeca;
        novoNo = alocarNovoNo(valor);
        for (int i = 0; i < lista->qtdade - 1; i++) {
            aux = aux->prox;
        }
        aux->prox = novoNo;
        lista->qtdade++;
    }
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    if (lista->cabeca == 0) {
        lista->cabeca = alocarNovoNo(valor);
        lista->qtdade++;
    }
    else {
        struct no* aux;
        aux = lista->cabeca;
        lista->cabeca = alocarNovoNo(valor);
        lista->cabeca->prox = aux;
        lista->qtdade++;
    }
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    if (posicao >= 0 && posicao <= lista->qtdade) {
        if (posicao == 0) {
            inserirElementoNoInicio(lista, valor);
        }
        else if (posicao == lista->qtdade) {
            inserirElementoNoFim(lista, valor);
        }
        else {
            struct no* aux1 = lista->cabeca;
            struct no* aux2 = alocarNovoNo(valor);
            for (int i = 0; i < posicao - 1; i++) {
                aux1 = aux1->prox;
            }
            aux2->prox = aux1->prox;
            aux1->prox = aux2;
            lista->qtdade++;
        }
    }
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
    struct no* aux = lista->cabeca;
    for (int i = 0; i < posicao; i++) {
        aux = aux->prox;
    }
    return aux->val;
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade) {
        struct no* aux1, * aux2, * aux3;
        if (posicao == 0) {
            aux1 = lista->cabeca;
            lista->cabeca = lista->cabeca->prox;
            free(aux1);
        }
        else if (posicao == 1) {
            aux1 = lista->cabeca->prox;
            aux2 = aux1->prox;
            lista->cabeca->prox = aux2;
            free(aux1);
        }
        else {
            aux1 = lista->cabeca;
            for (int i = 0; i < posicao - 1; i++) {
                aux1 = aux1->prox;                
            }
            aux2 = aux1->prox;
            aux2 = aux2->prox;
            aux3 = aux1->prox;
            aux1->prox = aux2;
            free(aux3);
        }
        lista->qtdade--;
    }
}

void imprimirLista(struct linkedlist* lista) {
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista está vazia!");
    }
}
