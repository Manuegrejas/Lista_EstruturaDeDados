#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
	struct Celula *anterior;
	struct Celula *proximo;
	int valor;
}Celula;

typedef struct LDDE{
	Celula *primeiro;
	int qtde;
}LDDE;

LDDE *inicializa_lista(){
	LDDE *lista = malloc(sizeof(LDDE));
	lista->primeiro = NULL;
	lista->qtde = 0;
	return lista;
}

Celula *inicializa_celula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->anterior = NULL;
	celula->proximo = NULL;
	celula->valor = valor;
	return celula;
}

void inserir(LDDE *lista, int valor){
	Celula *novo = inicializa_celula(valor);
	if(lista->qtde == 0){
		lista->primeiro = novo;
	}else{
		Celula *atual = lista->primeiro;
		Celula *anterior = NULL;
		while(atual != NULL && atual->valor <= valor){
			anterior = atual;
			atual = atual->proximo;
		}
		if(anterior == NULL && atual != NULL){
			novo->proximo = atual;
			atual->anterior = novo;
			lista->primeiro = novo;
		}else{
			if(atual == NULL && anterior != NULL){
				anterior->proximo = novo;
				novo->anterior = anterior;
			}else{
				anterior->proximo = novo;
				novo->anterior = anterior;
				novo->proximo = atual;
				atual->anterior = novo;
			}
		}
	}
	lista->qtde++;
}

void imprimir_crescente(LDDE *lista){
	Celula *atual = lista->primeiro;
	while(atual != NULL){
		printf("%d ", atual->valor);
		atual = atual->proximo;
	}
	printf("\n");
}

void imprimir_decrescente(LDDE *lista){
	Celula *atual = lista->primeiro;

    // Ir até o último elemento
    while(atual != NULL && atual->proximo != NULL){
        atual = atual->proximo;
      }

    // Imprimir a lista de trás para frente
    while(atual != NULL){
		printf("%d ", atual->valor); 
		atual = atual->anterior;
	}
	printf("\n");
}

void remover(LDDE *lista, int valor){
    Celula *atual = lista->primeiro;

    while(atual != NULL && atual->valor != valor){
        atual = atual->proximo;
    }

    if(atual == NULL){ 
        return; 
    }

    if(atual->anterior == NULL){
        lista->primeiro = atual->proximo;
        if(atual->proximo != NULL) {
            atual->proximo->anterior = NULL; 
        }
    }
    else if(atual->proximo == NULL){
        atual->anterior->proximo = NULL;
    }
    else{
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    lista->qtde--;

}

int main(void) {
  LDDE *lista = inicializa_lista();
	int in[] = {2, 3, 9, 6, 7, 4, 1, 8, 0, 5};
	int out[] = {0, 9, 1, 8, 5, 5, 6, 2, 3, 4, 7};
	int len_in = sizeof(in) / sizeof(int);
	int len_out = sizeof(out) / sizeof(int);
	for(int i = 0; i < len_in; i ++){
		inserir(lista, in[i]);
		imprimir_crescente(lista);
		imprimir_decrescente(lista);
	}
	for(int j = 0; j < len_out; j++){
		remover(lista, out[j]);
		imprimir_crescente(lista);
		imprimir_decrescente(lista);
	}
  return 0;
}