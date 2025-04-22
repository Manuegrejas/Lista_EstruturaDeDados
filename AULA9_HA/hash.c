#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct Celula{
    int valor;
    struct Celula* proximo; //esse célula chama a própria célula
} Celula;

typedef struct {
    int qtde;
    Celula* inicio; //essa chama a célula e não a lista, por isso não tem nome em cima
} Lista;

typedef struct{
 Lista* table[LEN];
} Hash;

void inserir(Hash* hash, int valor){
    Celula* nova = malloc(sizeof(Celula));
    nova -> valor = valor;
    nova -> proximo = NULL;
    int pos = valor % LEN; //descobrir a posição da célula
    if (hash -> table[pos] -> inicio == NULL){
        //sem colisão
        hash -> table[pos] -> inicio = nova;
    } else{
        //colisão
        nova -> proximo = hash -> table[pos] -> inicio;
        hash -> table[pos] -> inicio = nova;
    }

    hash -> table[pos] -> qtde++;
}

Hash* inicializa(){
    Hash* hash = malloc(sizeof(Hash));
    int i;
    for(i = 0; i < LEN; i++){
        Lista* lista = malloc(sizeof(Lista));
        lista -> inicio = NULL;
        lista -> qtde = 0;
        hash -> table[i] = lista;
    }
    return hash;
}

int buscar(Hash* hash, int valor){
    int i;
    for(i = 0; i < LEN; i++){
        Celula* atual = hash -> table[i] -> inicio;
        while(atual != NULL && atual -> valor != valor){
            atual = atual -> proximo;
        }
    if(atual == NULL){
        printf("Valor não encontrado");
        return -1;
    } else{
        printf("Valor encontrado");
        return; 
    }

   free(atual);
}

int remover(Hash* hash, int valor){
    for(i = 0; i < LEN; i++){
        Celula* atual = hash -> table[i] -> inicio;
        Celula* anterior = NULL;
        while(atual != NULL){
            printf("%d ", atual -> valor);
            atual = atual -> proximo;
        }
    }
}

void imprimir(Hash* hash){
    int i;
    for(i = 0; i < LEN; i++){
        Celula* atual = hash -> table[i] -> inicio;
        while(atual != NULL){
            printf("%d ", atual -> valor);
            atual = atual -> proximo;
        }
        printf("\n");
    }
}

int main(){
    printf("tabela hash\n");
    Hash* hash = inicializa();
    inserir(hash, 3);
    inserir(hash, 5);
    inserir(hash, 45);
    inserir(hash, 55);
    imprimir(hash);

    return 0;
}