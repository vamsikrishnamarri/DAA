#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L);
    free(R);
}

// Merge Sort (simulating parallelization with recursive calls)
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// For descending order, sort ascending then reverse
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Generate random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

// Generate ascending array
void generateAscendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

int main() {
    srand(time(NULL));
    int n_values[] = {100, 500, 1000, 2000, 5000};
    int num_n = sizeof(n_values) / sizeof(n_values[0]);

    printf("Test Case 1: Ascending order elements\n");
    printf("n,time\n");
    for (int i = 0; i < num_n; i++) {
        int n = n_values[i];
        int *arr = (int *)malloc(n * sizeof(int));
        generateAscendingArray(arr, n);
        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d,%f\n", n, time_taken);
        free(arr);
    }

    printf("\nTest Case 2: Unsorted elements\n");
    printf("n,time\n");
    for (int i = 0; i < num_n; i++) {
        int n = n_values[i];
        int *arr = (int *)malloc(n * sizeof(int));
        generateRandomArray(arr, n);
        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d,%f\n", n, time_taken);
        free(arr);
    }

    // Sample for descending
    int sample[] = {10, 7, 8, 9, 1, 5};
    int sample_size = sizeof(sample) / sizeof(sample[0]);
    printf("\nSample Merge Sort (Descending):\n");
    printf("Original: ");
    printArray(sample, sample_size);
    mergeSort(sample, 0, sample_size - 1);
    reverseArray(sample, sample_size);
    printf("Sorted Descending: ");
    printArray(sample, sample_size);

    return 0;
}
