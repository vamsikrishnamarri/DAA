#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] < min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], sptSet[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = 0;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Shortest paths from %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("%d -> %d : %d\n", src, i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 0},
        {0, 0, 7, 0, 9},
        {0, 0, 0, 9, 0}
    };

    printf("Test Case 1: Negative weights (Dijkstra fails)\n");
    int negGraph[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, -8, 0, 0},
        {0, -8, 0, 7, 0},
        {0, 0, 7, 0, 9},
        {0, 0, 0, 9, 0}
    };
    dijkstra(negGraph, 0);

    printf("\nTest Case 2: Positive weights (Dijkstra works)\n");
    dijkstra(graph, 0);

    return 0;
}
