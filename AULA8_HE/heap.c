#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct{
    int valores[LEN];
    int qtd;
} heap;


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

void peneirar(heap *h, int pai){ //struct que tem o vetor e o indice
    int esq = filho_esquerdo(pai);
    int dir = filho_direito(pai);
    int maior = pai;
    
    if (esq < h->qtd && h->valores[esq] > h->valores[maior]){
        maior = esq;
    }
    if (dir < h->qtd && h->valores[dir] > h->valores[maior]){
        maior = dir;
    }
    if (maior != pai){
        int temp = h->valores[pai];
        h->valores[pai] = h->valores[maior];
        h->valores[maior] = temp;
        peneirar(h, maior);
    }
}

void construir(heap *h){
    for (int i = ultimo_pai(h); i >= 0; i--){
        peneirar(h, i);
    }
}

void imprimir(heap *h){
    int i;
    printf("[ ");
    for(i = 0; i < h->qtd; i++){
        printf("%d ",h->valores[i]);
  }
  printf("]\n");
}

void inserir(heap *h, int valor){
    if (h->qtd == LEN) {
        printf("Heap cheia\n");
        return;
    }
    h->valores[h->qtd] = valor;
    h->qtd++;
    construir(h);
}

void remover(heap *h){
    if (h->qtd == 0) {
        printf("Heap vazia\n");
        return;
    }
    h->valores[0] = h->valores[h->qtd - 1];
    h->qtd--;
    peneirar(h, 0);
}

int main(){
    heap h;
    h.qtd = 0;
    inserir(&h, 10);
    inserir(&h, 20);
    inserir(&h, 5);
    inserir(&h, 30);
    inserir(&h, 15);
    inserir(&h, 25);

    imprimir(&h);
    
    remover(&h);

    imprimir(&h);
}
