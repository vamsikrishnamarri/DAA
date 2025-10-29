#include <stdio.h>
#include <stdlib.h>

#define V 6

void topologicalSortUtil(int v, int visited[], int stack[], int *stackIndex, int adj[V][V]) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i, visited, stack, stackIndex, adj);
        }
    }
    stack[(*stackIndex)++] = v;
}

void topologicalSort(int adj[V][V]) {
    int visited[V] = {0};
    int stack[V], stackIndex = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack, &stackIndex, adj);
        }
    }
    printf("Topological Order: ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void topologicalSortBFS(int adj[V][V]) {
    int indegree[V] = {0};
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) indegree[j]++;
        }
    }
    int queue[V], front = 0, rear = 0;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }
    int count = 0;
    printf("Topological Order (BFS): ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int i = 0; i < V; i++) {
            if (adj[u][i]) {
                indegree[i]--;
                if (indegree[i] == 0) queue[rear++] = i;
            }
        }
        count++;
    }
    if (count != V) printf("Cycle detected!\n");
    else printf("\n");
}

int main() {
    int adj[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    printf("Test Case 1: DAG\n");
    topologicalSort(adj);

    printf("\nTest Case 2: BFS Topological Sort\n");
    topologicalSortBFS(adj);

    return 0;
}
