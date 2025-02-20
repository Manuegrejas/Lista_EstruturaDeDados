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

void remover(Lista *lde, int valor){
    // Verifica se a lista está vazia
    if(lde -> primeira == NULL){
        printf("A lista está vazia.\n");
        return;
    }

    Celula *anterior = NULL;
    Celula *atual = lde->primeira;

    // Percorre a lista procurando o valor
    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
      }

    // Se o valor não for encontrado, exibe uma mensagem
    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    // Se o valor estiver no início da lista
    if (anterior == NULL) {
        lde->primeira = atual->proximo;  // O próximo elemento se torna o primeiro
    } else {
        anterior->proximo = atual->proximo;  // O anterior agora aponta para o próximo
    }

    // Libera a memória do elemento removido
    free(atual);
    
    // Decrementa a quantidade de elementos
    lde->qtde--;
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

  remover(lde, 50);  // Remove o número 50
  imprimir(lde);  // Lista após a remoção

  remover(lde, 100);  // Tenta remover um número que não existe
  imprimir(lde);  // Lista após a tentativa de remoção

  return 0;
}

