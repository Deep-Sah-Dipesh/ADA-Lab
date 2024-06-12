#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int indegree[MAX];
int V;

void initGraph() {
    int i, j;
    for (i = 0; i < V; i++) {
        indegree[i] = 0;
        for (j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    indegree[dest]++;
}

void topologicalSort() {
    int i, j, count = 0;
    int result[MAX]; // Array to store the final topological order
    int step = 1; // Step counter

    while (count < V) {
        int removed = 0;
        for (i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                printf("Step %d: %d\n", step++, i);
                result[count++] = i;
                removed = 1;
                indegree[i] = -1; // Mark as removed
                for (j = 0; j < V; j++) {
                    if (adjMatrix[i][j] == 1) {
                        indegree[j]--;
                    }
                }
            }
        }
        if (!removed) {
            printf("Graph contains cycle or it's not a DAG (Directed Acyclic Graph).\n");
            return;
        }
    }

    printf("Final sorted path: ");
    for (i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    initGraph();
    int E;
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter edges in the format (source destination): \n");
    int i, src, dest;
    for (i = 0; i < E; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Step-wise Removal and Topological Sorting:\n");
    topologicalSort();
    return 0;
}
