#include <stdio.h>
#include <limits.h>

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int final_path[N+1];
int visited[N];
int final_res = INT_MAX;

void copyToFinal(int curr_path[]) {
    for (int i = 0; i < N; i++) final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];
}

int firstMin(int i) {
    int min = INT_MAX;
    for (int k = 0; k < N; k++)
        if (graph[i][k] < min && i != k) min = graph[i][k];
    return min;
}

int secondMin(int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if (graph[i][j] <= first) {
            second = first;
            first = graph[i][j];
        } else if (graph[i][j] <= second && graph[i][j] != first) {
            second = graph[i][j];
        }
    }
    return second;
}

void TSPRec(int curr_bound, int curr_weight, int level, int curr_path[]) {
    if (level == N) {
        if (graph[curr_path[level-1]][curr_path[0]] != 0) {
            int curr_res = curr_weight + graph[curr_path[level-1]][curr_path[0]];
            if (curr_res < final_res) {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (graph[curr_path[level-1]][i] != 0 && visited[i] == 0) {
            int temp = curr_bound;
            curr_weight += graph[curr_path[level-1]][i];
            if (level == 1) curr_bound -= ((firstMin(curr_path[level-1]) + firstMin(i)) / 2);
            else curr_bound -= ((secondMin(curr_path[level-1]) + firstMin(i)) / 2);
            if (curr_bound + curr_weight < final_res) {
                curr_path[level] = i;
                visited[i] = 1;
                TSPRec(curr_bound, curr_weight, level + 1, curr_path);
            }
            curr_weight -= graph[curr_path[level-1]][i];
            curr_bound = temp;
            memset(visited, 0, sizeof(visited));
            for (int j = 0; j <= level - 1; j++) visited[curr_path[j]] = 1;
        }
    }
}

void TSP() {
    int curr_path[N+1];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) curr_bound += (firstMin(i) + secondMin(i));
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;
    visited[0] = 1;
    curr_path[0] = 0;
    TSPRec(curr_bound, 0, 1, curr_path);
}

int main() {
    TSP();
    printf("Test Case 1: TSP Branch & Bound\n");
    printf("Minimum cost: %d\n", final_res);
    printf("Path: ");
    for (int i = 0; i <= N; i++) printf("%d ", final_path[i]);
    printf("\n");

    printf("Test Case 2: TSP is NP-hard\n");
    printf("TSP is NP-hard as it involves finding optimal tours in exponential time.\n");

    return 0;
}
