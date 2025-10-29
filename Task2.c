#include <stdio.h>
#include <string.h>

// Function to sort and print in increasing order of asymptotic growth
void sort_functions() {
    printf("Ex2.1: Sorted functions in increasing order of asymptotic growth:\n");
    printf("4 log log n < 4 log n < n^(1/2) log^4 n < 5n < n^4 < (log n)^5 log n < n log n < n^(n^(1/5)) < 5n < 55n < (n/4)^(n/4) < n^(n/4) < 4n^4 < 44n < 55n\n");
    printf("Note: Some duplicates like 5n, 55n are listed as per input.\n\n");

    printf("Ex2.2: Order from slowest to fastest growing (assuming standard functions):\n");
    printf("64, log8 n, log2 n, 4n, n log6 n, n log2 n, 8n^2, 6n^3, 8^2 n\n\n");

    printf("Ex2.3: 6n^3, n log6 n, 4n, 8n^2, log2 n, n log2 n, log8 n, 64, 8^2 n\n");
    printf("Sorted: 64, log8 n, log2 n, 4n, n log6 n, n log2 n, 8n^2, 6n^3, 8^2 n\n");
}

int main() {
    sort_functions();
    return 0;
}
