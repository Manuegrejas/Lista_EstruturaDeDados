#include<stdio.h>
#include<stdlib.h>

typedef struct Lista{
  int qtde;
  struct Celula *primeira;
}Lista;

typedef struct Celula{
  int valor;
  struct Celula *proximo;
}Celula;

Lista *inicializa(){
  Lista *lde = malloc(sizeof(Lista));
  lde->qtde = 0;
  lde->primeira = NULL;
  return lde;
}

void inserir(Lista *lde, int valor){
  Celula *novo = malloc(sizeof(Celula));
  novo->valor = valor;
  novo->proximo = NULL;

  Celula *anterior = NULL;
  Celula *atual = lde->primeira;

  while(atual != NULL && atual->valor < valor){
    anterior = atual;
    atual = atual->proximo;
  }

  if (anterior == NULL){  
    // insere no inicio da lista
    novo->proximo = lde->primeira;
    lde->primeira = novo;
  }
  else{
    // insere meio ou fim da lista
    anterior->proximo = novo;
    novo->proximo = atual;
  }
  lde->qtde++;
}

void imprimir(Lista *lde){
  printf("[ ");
  Celula *atual = lde->primeira;
  while(atual != NULL){
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("] - %d\n", lde->qtde);
}

int main(){
  printf("LDE = Lista Dinamicamente Encadeada\n");

  Lista *lde = inicializa(); 
  inserir(lde,56);
  imprimir(lde);
  inserir(lde,50);
  imprimir(lde);
  inserir(lde,30);
  imprimir(lde);
  inserir(lde,52);
  imprimir(lde);
  inserir(lde,70);
  imprimir(lde);

  
  return 0;
}
