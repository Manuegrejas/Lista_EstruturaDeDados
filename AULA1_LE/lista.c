 #include <stdio.h>

#define LEN 10  //define variavel estática de tamanho do vetor

typedef struct{ //construir uma struct
    int valor[LEN];//vetor de tamanho 10
    int n; //numero de elementos
} lista;

int is_full(lista *l){
    return l->n == 10;
    //ou if(l->n == 10){
    // return 1;
    //}else{
    //return 0;}
}

int is_empty(lista *l){
    return l->n == 0; 
}

//busca o indice idx em que valor de ser inserida
int get_idx(lista *l, int valor){
    int idx = 0;
    while(idx < l->n && valor > l->valor[idx]){
        idx++;
    }
    return idx;
}

// desloca para a direita todos os elementos iniciando do indice <idx>
void mover(lista*l, int idx){
    int i;
    for(i = l->n; i > idx; i--)
        l->valor[i] = l->valor[i-1];
}

//funcao do tipo int pois void não retornaria nenhum valor (aqui fala se está cheio ou nao)
// insere <value> na lista <l>
int inserir(lista *l, int valor){ //variavel valor do tipo int e variavel l do tipo lista
    if(is_full(l)){
        return 0;
    }

    int idx = 0; //indice
    if(!is_empty(l)){
        idx = get_idx(l, valor); //recebe a posicao que estaria o valor (aqui seria 1 para o valor 35)
        mover(l, idx); //deslocar todos os numeros para colocar o numero 35
    }
    l->valor[idx] = valor;
    l->n++;
    return 1;
}

void mostrar(lista *l){
    int i;
    for(i = 0; i < l->n; i++){
        printf("%d ",l->valor[i]);
    }
    printf("\n");
}

int main(){
    lista l;
    l.n = 0; //acessando o item n da lista (l)
    inserir(&l, 30); //& passa pro ponteiro
    mostrar(&l);
    inserir(&l, 40);
    mostrar(&l);
    inserir(&l, 55);
    mostrar(&l);
    inserir(&l, 35);
    mostrar(&l);
    inserir(&l, 48);
    mostrar(&l);
    inserir(&l, 21);
    mostrar(&l);
}