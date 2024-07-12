#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int **graph, int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print the MST for a graph
void primMST(int **graph, int V) {
    int *parent = (int *)malloc(V * sizeof(int));
    int *key = (int *)malloc(V * sizeof(int));
    bool *mstSet = (bool *)malloc(V * sizeof(bool));

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in the MST
    key[0] = 0;
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in the MST
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, V);

    // Free allocated memory
    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    int V;

    printf("\t Prim's Algorithm for MST\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Dynamic allocation of adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Construct and print the MST
    primMST(graph, V);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
