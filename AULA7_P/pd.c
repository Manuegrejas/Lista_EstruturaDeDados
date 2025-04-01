#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{ //tipo de dado composta por outros dados
    char valor; 
    struct Celula *proximo; //FAZENDO REFERENCIA PARA ELE MESMO (POR ISSO USA STRUCT)
    struct Celula *anterior;
}Celula;

typedef struct Stack{ //tipo de dado composta por outros dados
    int qtd;
    Celula *topo; //FAZENDO REFERENCIA PARA OUTRO
}Stack;

Stack *inicializa(){ //retorna uma stack
    Stack *stack = malloc(sizeof(Stack));
    stack -> qtd = 0;
    stack -> topo = NULL;
    return stack;
}

Celula *inicializa_celula(char valor){
    Celula *celula = malloc(sizeof(Celula));
    celula -> proximo = NULL;
    celula -> anterior = NULL;
    celula -> valor = valor;

    return celula;
}

void push(Stack *stack, char valor){
    Celula *nova = inicializa_celula(valor); //cria uma celula
    if (stack -> qtd != 0){
        //tem elemento na pilha
        nova -> anterior = stack -> topo;
        stack -> topo -> proximo = nova;
    }
    stack -> topo = nova;
    stack -> qtd++;
}

char pop(Stack *stack){
    if(stack -> qtd == 0){
        return '$';
    }
    char valor = stack -> topo -> valor;
    Celula *aux = stack -> topo;
    stack -> topo = stack -> topo -> anterior;
    //stack -> topo -> proximo = NULL; //funciona se o topo for diferente de nulo
    if(stack -> topo != NULL){
        stack -> topo -> proximo = NULL; 
    }
    free(aux);
    stack -> qtd--;
    return valor;
}

void imprimir(Stack *stack){
    printf("[ ");
    Celula *atual = stack -> topo;
    while(atual != NULL){
        printf("%c ", atual -> valor);
        atual = atual -> anterior;
    }

    printf("]\n");
}

int main(){
    printf("Pilha dinamica\n");

    Stack *stack = inicializa();
    push(stack, 'm');
    push(stack, 'a');
    push(stack, 'n');
    push(stack, 'u');
    push(stack, 'e');
    push(stack, 'l');
    push(stack, 'l');
    push(stack, 'a');
    imprimir(stack);
    char valor = pop(stack);
    printf("%c \n", valor);
    imprimir(stack);
    valor = pop(stack);
    printf("%c \n", valor);
    imprimir(stack);
    valor = pop(stack);
    printf("%c \n", valor);
    imprimir(stack);
    valor = pop(stack);
    printf("%c \n", valor);
    imprimir(stack);
    return 0;
}