#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula{
  int valor;
  struct Celula* proximo;
}Celula;

typedef struct {
  Celula* inicio;
}Lista;

typedef struct {
  Lista* table[tam_hash];
}Hash;

int funcaoHash(int valor) { return valor % tam_hash; }

Hash* start_hash(){
  Hash* hash = (Hash*)malloc(sizeof(Hash));
  
  for(int i = 0; i < tam_hash; i++){
    hash->table[i] = (Lista*)malloc(sizeof(Lista));
    hash->table[i]->inicio = NULL;
  }
  
  return hash;
}

Celula *start_celula(int valor) {
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->valor = valor;
  nova->proximo = NULL;
  return nova;
}

void inserir_hash(Hash* hash, int valor){
  int index = funcaoHash(valor);
  Celula* nova = start_celula(valor);
  
  if(hash->table[index]->inicio == NULL){
    hash->table[index]->inicio = nova;
  } else {
    Celula* aux = hash->table[index]->inicio;
    
    hash->table[index]->inicio = nova;
    nova->proximo = aux;
  }
}

void remover_hash(Hash* hash, int valor){
  int index = funcaoHash(valor);
  Celula* aux = hash->table[index]->inicio;
  Celula* anterior = NULL;
  
  while(aux != NULL){
    if(aux->valor == valor){
      if(anterior == NULL){
        hash->table[index]->inicio = aux->proximo;
      } else {
        anterior->proximo = aux->proximo;
      }
      free(aux);
      return;
    }
    anterior = aux;
    aux = aux->proximo;
  }
}

void imprimir(Hash* hash){
  Celula* aux;
  
  printf("---------------------\n");
  
  for(int i = 0; i < tam_hash; i++){
    printf("%d -> ", i);
    aux = hash->table[i]->inicio;
    
    while(aux != NULL){
      printf("%d ", aux->valor);
      aux = aux->proximo;
      
    }
    printf("\n");
  }
  
  printf("---------------------\n");
}

int main(void) {
  Hash* hash = start_hash();
  int valor;
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    inserir_hash(hash, valor);
  }
  imprimir(hash);
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    remover_hash(hash, valor);
  }
  imprimir(hash);
  return 0;
}