#include <stdio.h>
#include <time.h>

// Ex1: Nested loops
void ex1(int n) {
    int i, j, k = 0;
    for (i = n / 2; i <= n; i++) {
        for (j = 2; j <= n; j = j * 2) {
            k = k + n / 2;
        }
    }
    printf("Ex1 completed for n=%d, k=%d\n", n, k);
}

// Ex2: Function with loops and break
void ex2(int n) {
    if (n == 1) return;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("*");
            break;  // Only one iteration per outer loop
        }
    }
    printf("\nEx2 completed for n=%d\n", n);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start, end;
    double time_taken;

    // Time Ex1
    start = clock();
    ex1(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Ex1: %f seconds\n", time_taken);

    // Time Ex2
    start = clock();
    ex2(n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time for Ex2: %f seconds\n", time_taken);

    // Analysis
    printf("Time Complexity Analysis:\n");
    printf("Ex1: Outer loop ~ n/2, Inner loop ~ log n, Total ~ O(n log n)\n");
    printf("Ex2: Outer loop n, Inner loop 1 (due to break), Total ~ O(n)\n");

    return 0;
}
