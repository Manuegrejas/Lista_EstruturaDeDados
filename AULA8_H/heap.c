#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct{
    int valores[LEN];
    int qtd;
} heap;

void peneirar(heap *h, int pai){ //struct que tem o vetor e o indice
    int fe = filho_esquerdo(pai);
    int fd = filho_direito(pai);
    if(fe != 0){
        if(h->valores[pai] < h->valores[fe]){

        }
    }else{
        return;
    }
}

void contruir(heap *h){
    
}

int filho_esquerdo(int pai){
    int fe = 2*pai + 1;
    return fe;
}

int filho_direito(int pai){
    int fd = 2*pai + 2;
    return fd;
}

int ultimo_pai(heap *h){
    int up = ((h->qtd)/2) - 1;
    return up;
}

int pai(int filho){
    int p = (filho - 1)/2;
    return p;
}

void imprimir(heap *h){
    int i;
    for(i = 0; i < h->qtd; i++){
        printf("%d ",h->valores[i]);
  }
  printf("\n");
}

void inserir(heap *h, int valor){

}

void remover(heap *h){

}

int main(){

}