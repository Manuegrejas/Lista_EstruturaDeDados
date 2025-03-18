#include <stdio.h>

#define LEN 100

typedef struct {
  char data[LEN];
  int head;
  int tail;
  int qtde;
} Queue;

void enqueue(Queue *queue, char caracter) {
    if (queue->tail < LEN) {
      queue->data[queue->tail++] = caracter;
      queue->qtde++;
    } 
}

int dequeue(Queue *queue) {
    if (queue->tail > queue->head) {
      queue->qtde--;
      return queue->data[queue->head++];
    } else {
      return -1;
    }
}

void show(Queue *queue) {
    for (int i = queue->head; i < queue->tail; i++) {
        printf("%c", queue->data[i]);
    }
}

void start_queue(Queue *queue) {
    queue->tail = 0;
    queue->head = 0;
    queue->qtde = 0;
}

int main(void) {
    char s[LEN];
    char v;

    fgets(s, sizeof(s), stdin);

    Queue queue;
    Queue queue2;

    start_queue(&queue);
    start_queue(&queue2);

    for (int i = 0; s[i] != '\0'; i++) {
        enqueue(&queue, s[i]);
    }

    int verificacao = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        v = dequeue(&queue);
        if (v == '('){
            enqueue(&queue2, s[i]);
        }
        if (v == ')'){
            v = dequeue(&queue2);
            if (v == -1){
                verificacao = 1;
                printf("incorreto\n");
                break;
            }
        }

        show(&queue);
     
    }

    if (queue2.qtde == 0 && verificacao == 0){
        printf("correto\n");
    }
    if(queue2.qtde != 0 && verificacao == 0){
        printf("incorreto\n");
    }
        
    return 0;
}
