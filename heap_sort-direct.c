#include <stdio.h>

void heap_const(int a[], int n);
void heap_adj(int a[], int n);
void heap_sort(int a[], int n);

void heap_const(int a[], int n) {
    int i, j, k, item;
    for (k = 1; k < n; k++) {
        item = a[k];
        i = k;
        j = (i - 1) / 2;
        while (i > 0 && item > a[j]) {
            a[i] = a[j];
            i = j;
            j = (i - 1) / 2;
        }
        a[i] = item;
    }
}

void heap_adj(int a[], int n) {
    int i, j, item;
    j = 0;
    item = a[j];
    i = 2 * j + 1;
    while (i <= n - 1) {
        if (i < n - 1 && a[i] < a[i + 1]) {
            i++;
        }
        if (item < a[i]) {
            a[j] = a[i];
            j = i;
            i = 2 * j + 1;
        } else {
            break;
        }
    }
    a[j] = item;
}

void heap_sort(int a[], int n) {
    int i, t;
    heap_const(a, n);
    for (i = n - 1; i > 0; i--) {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        heap_adj(a, i);
    }
}

int main() {
    int i, n;
    printf("\t Heap Sort Implementation...\n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    heap_sort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
