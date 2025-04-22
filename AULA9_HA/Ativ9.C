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

Hash* start_hash(){
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    int i;
    for(i = 0; i < tam_hash; i++){
        Lista* lista = (Lista*)malloc(sizeof(Lista));
        lista -> inicio = NULL;
        hash -> table[i] = lista;
    }
    return hash;
}

void inserir_hash(Hash* hash, int valor){
    int pos = valor % tam_hash; //descobrir a posição da célula
    Lista *lista = hash -> table[pos];
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova -> valor = valor;
    nova -> proximo = NULL;

    if (lista -> inicio == NULL){
        lista -> inicio = nova;
    } else{
        nova -> proximo = lista -> inicio;
        lista -> inicio = nova;
    }
}

void remover_hash(Hash* hash, int valor){
    int pos = valor % tam_hash; //descobrir a posição da célula
    int i;
    for(i = 0; i < tam_hash; i++){
        Celula* atual = hash -> table[i] -> inicio;
        Celula* anterior = NULL;
        while(atual != NULL){
            if(atual -> valor == valor){  
                if(anterior == NULL){ //primeiro da lista
                    hash -> table[pos]-> inicio = atual->proximo;
                } else{ //meio da lista
                    anterior->proximo = atual->proximo;
                }
                free(atual);
                return;
            } else{
                anterior = atual;
                atual = atual -> proximo;
            }
        }
    }
}

void imprimir(Hash* hash){
    printf("---------------------\n");
    int i;
    for(i = 0; i < tam_hash; i++){
        printf("%d -> ", i);
        Celula *atual = hash -> table[i] -> inicio;
        while(atual != NULL){
            printf("%d ", atual -> valor);
            atual = atual -> proximo;
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