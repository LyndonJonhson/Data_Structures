#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedstack {
    struct no* topo;
    int qtdade;
};

struct linkedstack* inicializar() {
    struct linkedstack* pilha = (struct linkedstack*)malloc(sizeof(struct linkedstack));
    pilha->topo = 0;
    pilha->qtdade = 0;
    return pilha;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->prox = 0;
    return novoNo;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct linkedstack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return true;
    }
    else {
        return false;
    }
}

//se a pilha estiver nula, instancie a pilha/
void empilhar(struct linkedstack** pilha, int valor) {
    if (*pilha == NULL) {
        *pilha = inicializar();
    }
    if ((*pilha)->topo == 0) {
        (*pilha)->topo = alocarNovoNo(valor);
        (*pilha)->qtdade++;
    }
    else {
        struct no* inicio;
        inicio = (*pilha)->topo;
        (*pilha)->topo = alocarNovoNo(valor);
        (*pilha)->topo->prox = inicio;
        (*pilha)->qtdade++;
    }
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct linkedstack* pilha) {
    if (pilha == NULL) {
        pilha = inicializar();
    }
    struct no* aux = pilha->topo;
    if (pilha->qtdade > 0) {
        pilha->topo = pilha->topo->prox;
        free(aux);
        pilha->qtdade--;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct linkedstack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return INT_MIN;
    }
    else {
        int aux;
        aux = pilha->topo->val;
        desempilhar(pilha);
        return aux;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct linkedstack* pilha) {
    if (pilha == NULL || pilha->qtdade == 0) {
        return INT_MIN;
    }
    else {
        return pilha->topo->val;
    }
}

void exibirPilha(struct linkedstack* pilha) {
    //usamos o aux para percorrer a lista
    if (!vazia(pilha)) {
        struct no* aux = pilha->topo;
        //navega partindo do topo até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A pilha está vazia!");
    }
}
