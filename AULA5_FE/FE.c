#include <stdio.h>
#define LEN 5

typedef struct{
    int qtde; //quantidade de elementos
    char data[LEN]; //vetor circular com os elementos
    int head; //indice
    int tail; //indice
}Fila;

void inicializa(Fila *fila){
    fila -> qtde = 0;
    fila -> head = 0;
    fila -> tail = 0;
}

int esta_vazio(Fila *fila){
    if (fila -> tail == fila -> head){
        return 1;
    } else{
        return 0;
    }
}

int esta_cheia(Fila *fila){
    if ((fila -> tail + 1) % LEN == fila -> head){ //%LEN (resto) pois de 5 teria que ir para 0 pois é um vetor circular
        return 1;
    } else{
        return 0;
    }  
}

void inserir(Fila *fila, char valor){
    if (esta_cheia(fila)){
       printf("fila cheia\n");
        return; //sai da função
    }
    fila -> data[fila -> tail] = valor;
    fila -> tail = (fila -> tail + 1) % LEN;
    fila -> qtde++;
}

//int pois vai retornar o valor que foi tirado
char remover(Fila *fila){ //SEMPRE REMOVE O PRIMEIRO
    if (esta_vazio(fila)){
        printf("fila vazia");
        return -1;
    }
    char valor = fila -> data[fila -> head]; //guardando na variavel valor 
    fila -> head = (fila -> head + 1) % LEN;
    fila -> qtde--;
    return valor;
}

void imprimir(Fila *fila){
    printf("[ ");
    int i;
    for (i = fila -> head; i < fila -> tail; i++){
        printf("%c ", fila -> data[i]);
    }
    printf("]\n");
}

int main(){
    printf("Fila Estática\n");

    Fila fila; //cria a fila
    inicializa(&fila); //endereço da lista
    inserir(&fila, 'a');
    imprimir(&fila);
    inserir(&fila, 'b');
    imprimir(&fila);
    char valor = remover(&fila);
    printf("%c \n", valor);
    imprimir(&fila);
    return 0;
}