#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
};

// Comparator function for qsort
int compare(const void *a, const void *b) {
    double r1 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    double r2 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *arr = malloc(n * sizeof(struct Item));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("\nItem %d - Weight: ", i + 1);
        scanf("%d", &arr[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &arr[i].value);
    }

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, arr, n);

    printf("\nMaximum value in Knapsack = %.2f\n", maxValue);

    free(arr); // Free dynamically allocated memory

    return 0;
}
