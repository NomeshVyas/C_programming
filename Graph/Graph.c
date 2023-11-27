#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50

struct graph{
    int v; // No. of vertices
    int adj[MAX_VERTICES][MAX_VERTICES];
};

struct graph* createGraph(int v){
    struct graph* g = malloc(sizeof(struct graph));
    g->v = v;
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            g->adj[i][j] = 0;
    
    return g;
}

void Graph_addEdge(struct graph* g, int i, int j){
    g->adj[i][j] = 1;
}

void Graph_BSF(struct graph* g, int s){
    int visited[MAX_VERTICES];
    for (int i = 0; i < g->v; i++)
        visited[i] = 0;
    
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while(front != rear){
        s = queue[front++];
        printf("%d\t", s);

        for(int adj = 0; adj < g->v; adj++)
            if(g->adj[s][adj] && !visited[adj]){
                visited[adj] = 1;
                queue[rear++] = adj;
            }
    }
}

int main(){
    struct graph* g = createGraph(4);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 2);
    Graph_addEdge(g, 1, 2);
    Graph_addEdge(g, 2, 0);
    Graph_addEdge(g, 2, 3);
    Graph_addEdge(g, 3, 3);

    printf("\nBFS of given Graph: \n");
    Graph_BSF(g, 2);
    free(g);
    return 0;
}

