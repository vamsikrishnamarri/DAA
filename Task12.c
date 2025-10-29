#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int set[] = {1, 2, 5, 6, 8};
int n = 5;
int d = 9;
int found = 0;

void printSubset(int subset[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", subset[i]);
        if (i < size - 1) printf(",");
    }
    printf("}\n");
}

void subsetSum(int index, int currentSum, int subset[], int subsetSize) {
    if (currentSum == d) {
        printSubset(subset, subsetSize);
        found = 1;
        return;
    }
    if (index == n || currentSum > d) return;
    subset[subsetSize] = set[index];
    subsetSum(index + 1, currentSum + set[index], subset, subsetSize + 1);
    subsetSum(index + 1, currentSum, subset, subsetSize);
}

void generatePowerSet() {
    printf("Power Set:\n");
    int total = 1 << n;
    for (int i = 0; i < total; i++) {
        printf("{");
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d", set[j]);
                sum += set[j];
                if (j < n - 1 && (i & (1 << (j + 1)))) printf(",");
            }
        }
        printf("} sum=%d\n", sum);
    }
}

int main() {
    int subset[MAX];

    printf("Test Case 1: Subset Sum with inequalities\n");
    subsetSum(0, 0, subset, 0);
    if (!found) printf("No solution\n");

    printf("\nTest Case 2: Power Set\n");
    generatePowerSet();

    return 0;
}
