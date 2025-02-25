#include<stdio.h> 
#include<stdlib.h>

typedef struct Lista{
  int qtde;
  struct Celula *primeira;
} Lista;

typedef struct Celula{
  int valor;
  struct Celula *proximo;
  struct Celula *anterior;
} Celula;

Lista *inicializa(){
  Lista *ldde = malloc(sizeof(Lista));
  ldde->qtde = 0;
  ldde->primeira = NULL;
  return ldde;
}

void inserir(Lista *ldde, int valor){
  Celula *novo = malloc(sizeof(Celula));
  novo->valor = valor;
  novo->proximo = NULL;
  novo->anterior = NULL;

  Celula *anterior = NULL;
  Celula *atual = ldde->primeira;

  while(atual != NULL && atual->valor < valor){
    anterior = atual;
    atual = atual->proximo;
  }

  if(atual == NULL && anterior == NULL){
    ldde->primeira = novo;
  }
  else if(atual != NULL && anterior == NULL){
    ldde->primeira = novo;
    novo->proximo = atual;
    atual->anterior = novo;
  }
  else if(atual == NULL && anterior != NULL){
    anterior->proximo = novo;
    novo->anterior = anterior;
  }
  else{
    anterior->proximo = novo;
    novo->anterior = anterior;
    atual->anterior = novo;
    novo->proximo = atual;
  }

  ldde->qtde++;
}

void remover(Lista *ldde, int valor){
  Celula *atual = ldde->primeira;

  while(atual != NULL && atual->valor != valor){
    atual = atual->proximo;
  }

  if(atual == NULL){
    printf("Valor não encontrado!\n");
    return;
  }

  // Caso 1: Remover o primeiro elemento
  if(atual->anterior == NULL){
    ldde->primeira = atual->proximo;
    if(atual->proximo != NULL) {
      atual->proximo->anterior = NULL;
    }
  }
  // Caso 2: Remover o último elemento
  else if(atual->proximo == NULL){
    atual->anterior->proximo = NULL;
  }
  // Caso 3: Remover um elemento do meio
  else{
    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;
  }

  free(atual);
  ldde->qtde--;
}

void imprimir(Lista *ldde){
  printf("[ ");
  Celula *atual = ldde->primeira;
  while(atual != NULL){
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("] - %d\n", ldde->qtde);
}

void imprimir_reverso(Lista *ldde){
  printf("[ ");
  Celula *atual = ldde->primeira;
  
  // Ir até o último elemento
  while(atual != NULL && atual->proximo != NULL){
    atual = atual->proximo;
  }

  // Imprimir a lista de trás para frente
  while(atual != NULL){
    printf("%d ", atual->valor);
    atual = atual->anterior;
  }
  printf("] - %d\n", ldde->qtde);
}

int main(){
  printf("Lista duplamente encadeada\n");

  Lista *ldde = inicializa();

  inserir(ldde, 56);
  imprimir(ldde);
  inserir(ldde, 30);
  imprimir(ldde);
  inserir(ldde, 70);
  imprimir(ldde);
  inserir(ldde, 60);
  imprimir(ldde);
  inserir(ldde, 80);
  imprimir(ldde);
  
  printf("\nRemovendo 70:\n");
  remover(ldde, 70);
  imprimir(ldde);

  printf("\nImpressão reversa:\n");
  imprimir_reverso(ldde);

  return 0;
}
