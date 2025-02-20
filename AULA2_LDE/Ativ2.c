#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct Lista {
    int qtde;
    Celula *primeiro;
} Lista;

/**
 * @brief Inicializa uma nova lista encadeada.
 *
 * @return Ponteiro para a lista inicializada.
 */
Lista *inicializa_lista() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->primeiro = NULL;
    l->qtde = 0;
    return l;
}

/**
 * @brief Insere um valor na lista encadeada em ordem crescente.
 *
 * @param l Ponteiro para a lista onde o valor será inserido.
 * @param valor Valor a ser inserido na lista.
 */
void inserir(Lista *l, int valor) {
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    novo->valor = valor;
    novo->proximo = NULL;

    Celula *atual = l->primeiro;
    Celula *anterior = NULL;

    /* Encontra a posição correta para inserir o novo valor. */
    while (atual != NULL && atual->valor < valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    novo->proximo = atual;

    if (anterior == NULL) {
        l->primeiro = novo;
    } else {
        anterior->proximo = novo;
    }

    l->qtde++;
}

/**
 * @brief Remove um valor específico da lista encadeada.
 *
 * @param l Ponteiro para a lista de onde o valor será removido.
 * @param valor Valor a ser removido da lista.
 */
void remover(Lista *l, int valor) {
    Celula *atual = l->primeiro;
    Celula *anterior = NULL;
    
    // Percorre a lista procurando o valor
    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
      }

    // Se o valor não for encontrado na lista
    if (atual == NULL) {
        return; //termina a função
    } 

    // Se o valor estiver no início da lista
    if (anterior == NULL) { //atual->valor = valor
        l->primeiro = atual->proximo;  // O próximo elemento se torna o primeiro
    } 
    else {
        anterior->proximo = atual->proximo;  // O anterior agora aponta para o próximo
    }

    // Libera a memória do elemento removido
    free(atual);
    
    // Decrementa a quantidade de elementos
    l->qtde--;
}

/**
 * @brief Imprime todos os valores da lista encadeada.
 *
 * @param l Ponteiro para a lista a ser impressa.
 */
void imprimir(const Lista *l) {
    Celula *atual = l->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

/**
 * @brief Função principal para testar as operações da lista encadeada.
 *
 * @return Código de status (0 para sucesso).
 */
int main(void) {
    Lista *l = inicializa_lista();

    inserir(l, 10);
    imprimir(l);
    
    inserir(l, 20);
    inserir(l, 30);
    imprimir(l);
   
    inserir(l, 5);
    imprimir(l);

    inserir(l, 15);
    imprimir(l);
    
    remover(l, 5);
    imprimir(l);

    remover(l, 30);
    imprimir(l);

    remover(l, 15);
    imprimir(l);

    remover(l, 50);
    imprimir(l);

    remover(l, 10);
    remover(l, 20);
    imprimir(l);

    remover(l, 10);
    imprimir(l);

    return 0;
}