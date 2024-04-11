#include <stdio.h>
#define v 4
#define INF 99999

void printSolution(int dist[][v]){
    printf("All Route Shortest Path :- \n");
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(dist[i][j]==INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int dist[][v]){
    int i, j, k;
    for(k=0; k<v; k++)
        for(i=0; i<v; i++)
            for(j=0; j<v; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    printSolution(dist);
}

int main(){
    int graph[v][v] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 3},
        {INF, INF, INF, 0} 
    };
    floydWarshall(graph);

    return 0;
}

