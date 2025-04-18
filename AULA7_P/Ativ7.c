#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
  struct Cell *anterior;
  struct Cell *proximo;
  char valor;
} Cell;

typedef struct {
  Cell *top;
  int qtde;
} Stack;

Cell *start_cell(char valor) {
  Cell *nova = malloc(sizeof(Cell));
  nova->anterior = NULL;
  nova->proximo = NULL;
  nova->valor = valor;
  return nova;
}

Stack *start_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->qtde = 0;
  stack->top = NULL;
  return stack;
}

void push(Stack *stack, char valor) {
  Cell *nova = start_cell(valor);
  if (stack->qtde != 0) {
    nova->proximo = stack->top;
    stack->top->anterior = nova;
  }
  stack->top = nova;
  stack->qtde++;
}

char pop(Stack *stack) {
  if (stack->qtde > 0) {
    char valor = stack->top->valor;
    Cell *top = stack->top;
    stack->top = stack->top->proximo;
    if (stack->top != NULL)
      stack->top->anterior = NULL;
    stack->qtde--;
    free(top);
    return valor;
  } else {
    return 'x';
  }
}

int main(void) {
  // inicializa uma pilha
  Stack *stack = start_stack();

  // lê uma string na entrada padrão
  char expr[100];
  fgets(expr, sizeof(expr), stdin);

  
    int p = 0;
    int co = 0;
    int ch = 0;

    int verificacao = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '{'){
            if (p == 0 && co == 0){
                push(stack, expr[i]);
                ch++;
            } else {
                verificacao = 1;
                break;
            }
        } else if (expr[i] == '['){
            if (p == 0){
                push(stack, expr[i]);
                co++;
            } else {
                verificacao = 1;
                break;
            }
        } else if (expr[i] == '('){
            push(stack, expr[i]);
            p++;
        }

        if (expr[i] == '}' && p == 0 && co == 0){
            if (p == 0 && co == 0){
                char saida = pop(stack);
                    if(saida != '{'){
                        verificacao = 1;
                        break;
                    }
                ch--;
            } else {
                verificacao = 1;
                    break;
            }
        } else if (expr[i] == ']'){
            if (p == 0){
                char saida = pop(stack);
                    if(saida != '['){
                        verificacao = 1;
                        break;
                    }
                co--;
            } else {
                verificacao = 1;
                    break;
            }
        } else if (expr[i] == ')'){
            char saida = pop(stack);
                if(saida != '('){
                    verificacao = 1;
                    break;
                }
            p--;
        }
    }

    if (verificacao == 0){
        printf("correto");
    } else {
        printf("incorreto");
    }

	return 0;
}