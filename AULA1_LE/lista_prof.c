#include <stdio.h>

#define LEN 10

typedef struct{
  int values[LEN];
  int n;
} list;

//verifica se a lista esta cheia
int is_full(list *l){
  return l->n == 10;
}

// verifica se a lista esta vazia
int is_empty(list *l){
  return l->n == 0;
}

// busca o indice <idx> em que <value> deve ser inserida
int get_idx(list *l, int value){
  int idx = 0;
  while(idx < l->n && value > l->values[idx]){
    idx++;
  }
  return idx;
}

// desloca para a direita todos os elementos iniciando do indice <idx>
void move(list *l, int idx){
  int i;
  for(i = l->n; i > idx; i--)
    l->values[i] = l->values[i-1];
}

// insere <value> na lista <l>
int insert(list *l, int value){
  if(is_full(l)) return 0;

  int idx = 0;
  if (!is_empty(l)){
    idx = get_idx(l, value);
    move(l, idx);
  }
  l->values[idx] = value;
  l->n++;
  return 1;
}

// mostra todos os elementos inseridos na lista
void show(list *l){
  int i;
  for(i = 0; i < l->n; i++){
    printf("%d ",l->values[i]);
  }
  printf("\n");
}

int main(){
  list l;
  l.n = 0;
  insert(&l, 30); 
  show(&l);
  insert(&l, 40); 
  show(&l);
  insert(&l, 55); 
  show(&l);
  insert(&l, 35); 
  show(&l);
  insert(&l, 48); 
  show(&l);
  insert(&l, 21); 
  show(&l);
}
