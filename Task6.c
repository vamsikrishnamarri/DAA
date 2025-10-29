#include <stdio.h>

#define MAX 100

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i-1] <= w) dp[i][w] = (val[i-1] + dp[i-1][w - wt[i-1]] > dp[i-1][w]) ? val[i-1] + dp[i-1][w - wt[i-1]] : dp[i-1][w];
            else dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);

    printf("0/1 Knapsack DP Result: %d\n", knapsack(W, wt, val, n));

    // Test Case 1: Non-decreasing in row
    printf("\nTest Case 1: Row sequences are non-decreasing\n");
    int dp[MAX][MAX];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i-1] <= w) dp[i][w] = (val[i-1] + dp[i-1][w - wt[i-1]] > dp[i-1][w]) ? val[i-1] + dp[i-1][w - wt[i-1]] : dp[i-1][w];
            else dp[i][w] = dp[i-1][w];
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }

    // Test Case 2: Non-decreasing in column
    printf("\nTest Case 2: Column sequences are non-decreasing\n");
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i <= n; i++) {
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }

    return 0;
}
