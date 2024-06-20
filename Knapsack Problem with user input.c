#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        K[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int result = K[n][W];

    // Free allocated memory
    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);

    // K[n][W] holds the result
    return result;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items\n");
        return 1;
    }

    int *val = (int *)malloc(n * sizeof(int));
    int *wt = (int *)malloc(n * sizeof(int));

    if (val == NULL || wt == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        if (scanf("%d", &val[i]) != 1) {
            printf("Invalid input\n");
            free(val);
            free(wt);
            return 1;
        }
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        if (scanf("%d", &wt[i]) != 1) {
            printf("Invalid input\n");
            free(val);
            free(wt);
            return 1;
        }
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    if (scanf("%d", &W) != 1 || W < 0) {
        printf("Invalid weight capacity\n");
        free(val);
        free(wt);
        return 1;
    }

    printf("Maximum value in Knapsack = %d\n", knapSack(W, wt, val, n));

    // Free allocated memory
    free(val);
    free(wt);

    return 0;
}
