#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int qtd;
    struct Celula *primeiro;
}Lista;

typedef struct Celula{
    int valor;
    struct Celula *proximo;
}Celula;

Lista *inicializa(){
    Lista *lde = malloc(sizeof(Lista));
    lde -> qtd = 0;
    lde -> primeiro = NULL;
    return lde;
}

void inserir(Lista *lde, int valor){
    Celula *novo = malloc(sizeof(Celula));
    novo -> valor = valor;
    novo -> proximo = NULL; //apontando pro 0

    Celula *anterior = NULL; //criando outra celular
    Celula *atual = lde -> primeiro;

    while(atual != NULL && atual -> valor < valor){
        anterior = atual;
        atual = atual -> proximo;
    }
    if (anterior == NULL){
        //inicio da lista
    novo -> proximo = lde -> primeiro; //apontando para a mesma coisa que o lde esta apontando (pro 0)
    lde -> primeiro = novo; //lde apontar para a celula novo
    }
    else{
        //meio da lista
        anterior -> proximo = novo;
        novo -> proximo = atual;
    }

     lde -> qtd++;
}

void imprimir(Lista *lde){
    Celula *atual = lde -> primeiro;  //um ponteiro que aponta para o ponteiro da lde
    printf("[");
    while(atual != NULL){
        printf("%d ", atual -> valor);
        atual = atual -> proximo;
    } 
    printf("] - %d\n", lde -> qtd); //saber quantidade de elementos
}

int main(){
    printf("Lista Dinamicamente encadeada\n");
    Lista *lde = inicializa();
    inserir(lde,56);
    imprimir(lde);
    inserir(lde,50);
    imprimir(lde);
    inserir(lde,30);
    imprimir(lde);
    inserir(lde,80);
    imprimir(lde);
    inserir(lde,52);
    imprimir(lde);

    return 0;
}