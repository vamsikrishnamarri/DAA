#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function with random pivot
int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    printf("Test Case 1: Random pivot, random elements\n");
    printf("n,time\n");
    for (int i = 0; i < num_n; i++) {
        int n = n_values[i];
        int *arr = (int *)malloc(n * sizeof(int));
        generateRandomArray(arr, n);
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d,%f\n", n, time_taken);
        free(arr);
    }

    printf("\nTest Case 2: Ascending order elements\n");
    printf("n,time\n");
    for (int i = 0; i < num_n; i++) {
        int n = n_values[i];
        int *arr = (int *)malloc(n * sizeof(int));
        generateAscendingArray(arr, n);
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d,%f\n", n, time_taken);
        free(arr);
    }

    // Sample run for verification
    int sample[] = {10, 7, 8, 9, 1, 5};
    int sample_size = sizeof(sample) / sizeof(sample[0]);
    printf("\nSample Quick Sort:\n");
    printf("Original: ");
    printArray(sample, sample_size);
    quickSort(sample, 0, sample_size - 1);
    printf("Sorted: ");
    printArray(sample, sample_size);

    return 0;
}
