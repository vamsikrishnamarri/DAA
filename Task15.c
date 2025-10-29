#include <stdio.h>
#include <limits.h>

#define V 6

int graph[V][V] = {
    {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}
};

int bfs(int rGraph[V][V], int s, int t, int parent[]) {
    int visited[V] = {0};
    visited[s] = 1;
    int queue[V], front = 0, rear = 0;
    queue[rear++] = s;
    parent[s] = -1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (visited[v] == 0 && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
                if (v == t) return 1;
            }
        }
    }
    return 0;
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = (path_flow < rGraph[u][v]) ? path_flow : rGraph[u][v];
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
        printf("Augmenting path found with flow: %d\n", path_flow);
        printf("Updated residual graph:\n");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                printf("%d ", rGraph[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return max_flow;
}

int main() {
    printf("Test Case 1: Augmenting path exists\n");
    int max_flow = fordFulkerson(graph, 0, 5);
    printf("Max Flow: %d\n", max_flow);

    printf("Test Case 2: Updated residual capacity\n");
    printf("Residual graph after Ford-Fulkerson:\n");
    // Residual is updated in the function

    return 0;
}
