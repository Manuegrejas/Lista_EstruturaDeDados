#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior; //ponteiro
    int valor;
    struct Celula *proximo; //ponteiro
} Celula;

typedef struct Fila{
    int qtd;
    Celula *head;
    Celula *tail;
} Fila;

Celula *criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova -> anterior = NULL;
    nova -> proximo = NULL;
    nova -> valor = valor;
    return nova;
}

Fila *criar_fila(){
    Fila *fila = malloc(sizeof(Fila));
    fila -> head = NULL;
    fila -> tail = NULL;
    fila -> qtd = 0;
    return fila;
}

void enqueue(Fila *fila, int valor){
    Celula *nova = criar_celula(valor);
    if(fila -> qtd == 0){
        fila -> head = nova;
    } else{
        nova -> anterior = fila -> tail;
        fila -> tail -> proximo = nova;
    }
    fila -> tail = nova;
    fila -> qtd++;
}

int dequeue(Fila *fila){
    if(fila -> qtd == 0){
        return -1;
    }
    int valor = fila -> head -> valor;
    Celula *aux = fila -> head;
    if(fila -> qtd == 1){ //so um valor
        fila -> head = NULL;
        fila -> tail = NULL;
    } else{ //o primeiro valor
        fila -> head -> proximo = NULL;
        fila -> head = fila -> head -> proximo;
    }
    fila -> qtd--;
    free(aux);
    return valor;
}

void mostrar(Fila *fila){
    Celula *atual = fila -> head;
    printf("HEAD -> ");
    while(atual != NULL){
        printf("%d ", atual -> valor);
        atual = atual -> proximo;
    }
    printf("<- TAIL\n");
}

int main(){
    Fila *fila = criar_fila();
    enqueue(fila, 12);
    mostrar(fila);
    enqueue(fila, 8);
    mostrar(fila);
    return 1;
}