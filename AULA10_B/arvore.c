#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
    struct No *pai;
}No;

typedef struct Arvore{
    int qtde;
    No *raiz;
}Arvore;

No *cria_no(int valor){
    No *vertice = malloc(sizeof(No));
    vertice -> esq = NULL;
    vertice -> dir = NULL;
    vertice -> pai = NULL;
    vertice -> valor = valor;
    return vertice;
}

Arvore *cria_arvore(){
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore -> raiz = NULL;
    arvore -> qtde = 0;
    return arvore;
}

//inserir
No *inserir(No *raiz, int valor){
    //se não tiver nenhum numero
    if(raiz == NULL){               
        return cria_no(valor);
    }                 
    //se tiver um numero
    if(valor < raiz -> valor){
        raiz -> esq = inserir(raiz -> esq, valor);
    } else if (valor > raiz -> valor){
        raiz -> dir = inserir(raiz -> dir, valor);
    }
    return raiz;
}

No* minimo(No* raiz) { //enocntrar menor valor (esquerda)
    while (raiz != NULL && raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

No* remover(No* raiz, int valor) {
    // arvore vazia
    if (raiz == NULL){ 
        return NULL;
    }

    if (valor < raiz->valor) { //valor menor, para esquerda
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->valor) { //valor maior, para direita
        raiz->dir = remover(raiz->dir, valor);
    } else { //valor encontrado
        // sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) { //apenas remove
            free(raiz);
            return NULL;
        }
        // apenas um filho
        else if (raiz->esq == NULL || raiz->dir == NULL) {
            No* filho;
            if (raiz->esq != NULL){
                filho = raiz->esq;
            } else{
                filho = raiz->dir;
            }
            filho->pai = raiz->pai;
            free(raiz);
            return filho;
        }
        // com dois filhos
        else {
            No* sucessor = minimo(raiz->dir);
            raiz->valor = sucessor->valor;
            raiz->dir = remover(raiz->dir, sucessor->valor);
        }
    }

    return raiz;
}

void in_order(No *raiz){ //ERD
    //tem numero na esq e direita
    if(raiz != NULL){ 
        in_order(raiz -> esq);
        printf("%d ", raiz -> valor);
        in_order(raiz -> dir);
    }
}

void pre_order(No *raiz){ //RED
    //tem numero na esq e direita
    if(raiz != NULL){ 
        printf("%d ", raiz -> valor);
        pre_order(raiz -> esq);
        pre_order(raiz -> dir);
    }
}

void pos_order(No *raiz){ //EDR
    //tem numero na esq e direita
    if(raiz != NULL){ 
        pos_order(raiz -> esq);
        pos_order(raiz -> dir);
        printf("%d ", raiz -> valor);
    }
}

int main(){
    printf("Árvore Binária de busca\n");
    Arvore *tree = cria_arvore();
    tree -> raiz = inserir(tree -> raiz, 8);
    tree -> raiz = inserir(tree -> raiz, 5);
    tree -> raiz = inserir(tree -> raiz, 4);
    tree -> raiz = inserir(tree -> raiz, 2);
    tree -> raiz = inserir(tree -> raiz, 6);
    tree -> raiz = inserir(tree -> raiz, 15);
    tree -> raiz = inserir(tree -> raiz, 10);
    tree -> raiz = inserir(tree -> raiz, 9);
    tree -> raiz = inserir(tree -> raiz, 20);

    printf("Em ordem\n");
    in_order(tree -> raiz);
    printf("\n");
    printf("Pre ordem\n");
    pre_order(tree -> raiz);
    printf("\n");
    printf("Pos ordem\n");
    pos_order(tree -> raiz);
    printf("\n");

    tree->raiz = remover(tree->raiz, 5); // remove o nó com valor 5

    return 0;
}