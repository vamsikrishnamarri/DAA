#include <stdio.h>
#include <limits.h>

#define INF 99999
#define V 4  // Number of vertices

// Warshall's algorithm for transitive closure
void warshall(int graph[V][V]) {
    int reach[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

    printf("Transitive Closure (Warshall):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", reach[i][j]);
        printf("\n");
    }
}

// Floyd's algorithm for all pairs shortest paths
void floyd(int graph[V][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("All Pairs Shortest Paths (Floyd):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            if (dist[i][j] == INF) printf("INF ");
            else printf("%d ", dist[i][j]);
        printf("\n");
    }
}

int main() {
    // Test Case 1: Graph with negative weights
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    printf("Test Case 1: Graph with negative weights (Floyd may not work correctly)\n");
    floyd(graph);

    // Test Case 2: Time efficiency of Warshall (cubic)
    printf("\nTest Case 2: Warshall's algorithm (O(V^3))\n");
    warshall(graph);

    return 0;
}
