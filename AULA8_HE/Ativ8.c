#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
  int valores[LEN];
  int qtde;
} heap;

int filho_esq(int pai) { //consegue o indice do filho esq pelo indice do pai
    int fe = 2*pai + 1;
    return fe;
}

int filho_dir(int pai) { //consegue o indice do filho dir pelo indice do pai
    int fd = 2*pai + 2;
    return fd;
}

int pai(int filho) { //consegue o indice do paio pelo indice do no
    int p = (filho - 1)/2;
    return p;
}

int ultimo_pai(heap *h) { //indice do ultimo pai
    int up = ((h->qtde)/2) - 1;
    return up;
}

void peneirar(heap *h, int pai) {
    int esq = filho_esq(pai);   // índice do filho esquerdo
    int dir = filho_dir(pai);   // índice do filho direito
    int maior = pai;    // índice do pai
    
    //(esq < h->qtde)O índice do filho esquerdo ainda está dentro da parte válida da heap?
    if (esq < h->qtde && h->valores[esq] > h->valores[maior]){ //indice
        maior = esq;
    }
    if (dir < h->qtde && h->valores[dir] > h->valores[maior]){
        maior = dir;
    }
    if (maior != pai){
        // Troca os VALORES entre os índices
        int temp = h->valores[pai];
        h->valores[pai] = h->valores[maior];
        h->valores[maior] = temp;
        peneirar(h, maior); // Continua descendo
    }
}

void mostrar(heap *h) {
    int i;
    for(i = 0; i < h->qtde; i++){
        printf("%d ",h->valores[i]);
  }
  printf("\n");
}

void construir(heap *h) {
    for (int i = ultimo_pai(h); i >= 0; i--){
        peneirar(h, i);
    }
}

void inserir(heap *h, int valor) {
    if (h->qtde == LEN) {
        printf("Heap cheia\n");
        return;
    }
    h->valores[h->qtde] = valor;
    h->qtde++;
    construir(h);
}

void remover(heap *h) {
    if (h->qtde == 0) {
        printf("Heap vazia\n");
        return;
    }
    h->valores[0] = h->valores[h->qtde - 1];
    h->qtde--;
    construir(h);
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }
  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  return 0;
}