#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for direction
#define LEFT true
#define RIGHT false

// Function to print the permutation
void printPermutation(int *perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Function to find the largest mobile element
int largestMobileElement(int *perm, bool *dir, int n) {
    int largest = -1, index = -1;
    for (int i = 0; i < n; i++) {
        int adjIndex = dir[i] == LEFT ? i - 1 : i + 1;
        if (adjIndex >= 0 && adjIndex < n && perm[i] > perm[adjIndex]) {
            if (perm[i] > largest) {
                largest = perm[i];
                index = i;
            }
        }
    }
    return index;
}

// Function to reverse the direction of elements larger than the largest mobile element
void reverseDirection(int *perm, bool *dir, int n, int largest) {
    for (int i = 0; i < n; i++) {
        if (perm[i] > largest) {
            dir[i] = !dir[i];
        }
    }
}

int main() {
    int n;
    
    printf("\tJohnson Trotter Algorithm\n");

    // Read the number of elements
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    // Initialize the permutation and directions
    int *perm = (int *)malloc(n * sizeof(int));
    bool *dir = (bool *)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT; // Initially, all elements are directed LEFT
    }

    // Print the initial permutation
    printPermutation(perm, n);

    // Generate all permutations using Johnson-Trotter algorithm
    while (true) {
        int index = largestMobileElement(perm, dir, n);
        if (index == -1) {
            break;
        }

        int adjIndex = dir[index] == LEFT ? index - 1 : index + 1;

        // Swap the mobile element with the adjacent element
        int temp = perm[index];
        perm[index] = perm[adjIndex];
        perm[adjIndex] = temp;

        // Swap the directions
        bool tempDir = dir[index];
        dir[index] = dir[adjIndex];
        dir[adjIndex] = tempDir;

        // Print the new permutation
        printPermutation(perm, n);

        // Reverse the direction of all elements larger than the largest mobile element
        reverseDirection(perm, dir, n, perm[adjIndex]);
    }

    // Free the allocated memory
    free(perm);
    free(dir);

    return 0;
}
