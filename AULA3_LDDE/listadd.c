#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

typedef struct Lista{
    int qtde;
    struct Celula *primeiro; //ponteiro para a primeira celula
} Lista;

typedef struct Celula{
    int valor;
    struct Celula *proximo;
    struct Celula *anterior;
} Celula;

Lista *inicializa(){
    Lista *ldde = malloc(sizeof(Lista));
    ldde -> qtde = 0;
    ldde -> primeiro = NULL;
    return ldde;
}

void inserir(Lista *ldde, int valor){
    Celula *novo = malloc(sizeof(Celula));
    novo -> valor = valor;
    novo -> proximo = NULL;
    novo -> anterior = NULL;

    Celula *anterior = NULL;
    Celula *atual =  ldde -> primeiro;

    while(atual!= NULL && atual -> valor < valor){
        anterior = atual;
        atual = atual -> proximo;
    }

    //1) lista vazia
    if(atual == NULL && anterior  == NULL){
        ldde -> primeiro = novo;
    } 
    
    //2) inicio da lista
    else if(atual != NULL && anterior == NULL){
        ldde -> primeiro = novo;
        novo -> proximo = atual;
        atual -> anterior = novo;
    }

    //3) ultimo da lista
    else if(atual == NULL && anterior != NULL){
        anterior -> proximo = novo;
        novo -> anterior = anterior;
    }

    //4) meio da lista
    else{
        anterior -> proximo = novo;
        novo -> anterior = anterior;
        atual -> anterior = novo;
        novo -> proximo = atual;
    }

    ldde -> qtde++;
}
 
void inverso(Lista *ldde){
    Celula *anterior = NULL;
    Celula *atual =  ldde -> primeiro;

    while(atual!= NULL){
        anterior = atual;
        atual = atual -> proximo;
    }
    while(anterior != NULL){
        
    }
}

void imprimir(Lista *ldde){
    printf("[ ");
    Celula *atual = ldde -> primeiro;
    while(atual!= NULL){
        printf("%d ", atual -> valor);
        atual = atual -> proximo;
    }
    printf("] - %d\n", ldde -> qtde);
}

int main(){
    printf("Lista Dinâmica Duplamente Encadeada\n");
    //srand(time(NULL));
    Lista *ldde = inicializa();
    inserir(ldde, 10);
    imprimir(ldde);
    inserir(ldde, 20);
    imprimir(ldde);
    inserir(ldde, 15);
    imprimir(ldde);
    inserir(ldde, 30);
    imprimir(ldde);
    inserir(ldde, 25);
    imprimir(ldde);

    // for(int i = 0; i < 10; i++){
    //     inserir(ldde, rand()%100);
    // }

    // imprimir(ldde);

    return 0;
}