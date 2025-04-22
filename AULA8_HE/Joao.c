#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct{
    int valores[LEN];
    int qtde;
} heap;

int filho_esquerdo(int pai){
    return 2 * pai + 1;
}

int filho_direito(int pai){
    return 2 * pai + 2;
}

int ultimo_pai(heap *h){
    return (h->qtde - 2) / 2;
}

int pai(int filho){
    return (filho - 1) / 2;
}

void peneirar(heap *h, int pai){
    int esq = filho_esquerdo(pai);
    int dir = filho_direito(pai);
    int maior = pai;

    if (esq < h->qtde && h->valores[esq] > h->valores[maior]){
        maior = esq;
    }
    if (dir < h->qtde && h->valores[dir] > h->valores[maior]){
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
    printf("[ ");
    for (int i = 0; i < h->qtde; i++){
        printf("%d ", h->valores[i]);
    }
    printf("]");
}

void inserir(heap *h, int valor){
    if (h->qtde == LEN) {
        printf("Heap cheia\n");
        return;
    }
    h->valores[h->qtde] = valor;
    h->qtde++;
    construir(h);
}

void remover(heap *h){
    if (h->qtde == 0) {
        printf("Heap vazia\n");
        return;
    }
    h->valores[0] = h->valores[h->qtde - 1];
    h->qtde--;
    peneirar(h, 0);
}

int main () {
    heap h;
    h.qtde = 0;
    inserir(&h, 10);
    inserir(&h, 20);
    inserir(&h, 5);
    inserir(&h, 30);
    inserir(&h, 15);
    inserir(&h, 25);

    imprimir(&h);
}