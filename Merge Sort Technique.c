#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)

    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main()
{
  int numTests;

  printf("\tMerge Sort Technique for Sorting elements...");

  printf("\nEnter the number of test cases: ");
  scanf("%d", &numTests);

  for (int t = 0; t < numTests; t++)
  {
    int N;
    printf("\nEnter the number of elements for test case %d: ", t + 1);
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < N; i++)
    {
      scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    mergeSort(arr, 0, N - 1);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array for test case %d:\n", t + 1);
    for (int i = 0; i < N; i++)
    {
      printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken to sort %d elements: %f seconds\n", N, cpu_time_used);

    free(arr);
  }

  return 0;
}
