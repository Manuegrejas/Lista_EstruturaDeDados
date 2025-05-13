#include <stdio.h>

#define V 6 //6 vertices
#define E 12 //12 arestas (vais e volta)

int get_index(char x){ //tabela ascii
    return x - 97;
}

void inicia_arestas(int arestas[V][V]){//inicializa matriz toda em zero
    for(int i = 0; i< V; i++){
        for(int j = 0; j< V; j++){
            arestas[i][j] = 0;
        }
    }
}

void cria_arestas(int arestas[V][V], int v, int u){
    arestas[v][u] = 1;
}

void mostra_arestas(int arestas[V][V]){
    for(int i = 0; i< V; i++){
        for(int j = 0; j< V; j++){
            printf("%d ", arestas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mostra_adjacentes(int arestas[V][V], char v){
    int c = get_index(v);
    for(int i = 0; i< V; i++){
        if(arestas[c][i] == 1){
            printf("%c -> %c\n", v, i + 97);
        }
    }
}

void mostra_distancias(int arestas[V][V], char origem){
    int fila[V], visitado[V], distancia[V];
    int inicio, fim;
    int origem_idx = get_index(origem);
    
    for(int i = 0; i < V; i++) {
        fila[i] = 0;
        visitado[i] = 0;
        distancia[i] = -1;
    }

    inicio = 0;
    fim = 0;
    fila[fim++] = origem_idx;
    visitado[origem_idx] = 1;
    distancia[origem_idx] = 0;

    while(inicio < fim){
        int atual = fila[inicio++];
        for(int i = 0; i < V; i++){
            if(arestas[atual][i] == 1 && !visitado[i]){
                fila[fim++] = i;
                visitado[i] = 1;
                distancia[i] = distancia[atual] + 1;
            }
        }
    }

    for(int i = 0; i < V; i++){
        printf("%d ", distancia[i]);
    }
    printf("\n");
}

void mostra_todas_distancias(int arestas[V][V]){
    printf("Matriz de Distâncias:\n");
    for(char v = 'a'; v < 'a' + V; v++){
        mostra_distancias(arestas, v);
    }
}

int main(){
    printf("\nGrafo\n");

    int matriz[V][V]; //cria matriz

    inicia_arestas(matriz);

    //nao orientado
    cria_arestas(matriz, get_index('a'), get_index('b')); //vai
    cria_arestas(matriz, get_index('b'), get_index('a')); //volta

    cria_arestas(matriz, get_index('b'), get_index('c')); //vai
    cria_arestas(matriz, get_index('c'), get_index('b')); //volta

    cria_arestas(matriz, get_index('b'), get_index('f')); //vai
    cria_arestas(matriz, get_index('f'), get_index('b')); //volta

    cria_arestas(matriz, get_index('f'), get_index('e')); //vai
    cria_arestas(matriz, get_index('e'), get_index('f')); //volta

    cria_arestas(matriz, get_index('e'), get_index('a')); //vai
    cria_arestas(matriz, get_index('a'), get_index('e')); //volta

    cria_arestas(matriz, get_index('a'), get_index('d')); //vai
    cria_arestas(matriz, get_index('d'), get_index('a')); //volta

    mostra_arestas(matriz);

    mostra_adjacentes(matriz, 'a');
    mostra_adjacentes(matriz, 'b');
    mostra_adjacentes(matriz, 'c');
    mostra_adjacentes(matriz, 'd');
    mostra_adjacentes(matriz, 'e');
    mostra_adjacentes(matriz, 'f');

    return 0;
}