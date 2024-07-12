#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main() {
    int V;

    printf("\t Dijkstra's Algorithm for Shortest Path\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    if (V <= 0 || V > MAX) {
        printf("Invalid number of vertices. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    if (src < 0 || src >= V) {
        printf("Invalid source vertex. Please enter a number between 0 and %d.\n", V - 1);
        return 1;
    }

    dijkstra(graph, V, src);

    return 0;
}
