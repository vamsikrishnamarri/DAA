#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};

struct Edge edges[E] = {
    {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
};

int parent[V];

int find(int i) {
    if (parent[i] == i) return i;
    return find(parent[i]);
}

void unionSets(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    parent[xset] = yset;
}

int compare(const void *a, const void *b) {
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->weight - e2->weight;
}

void kruskalMST() {
    qsort(edges, E, sizeof(edges[0]), compare);
    for (int i = 0; i < V; i++) parent[i] = i;
    struct Edge result[V-1];
    int e = 0, i = 0;
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(next.src);
        int y = find(next.dest);
        if (x != y) {
            result[e++] = next;
            unionSets(x, y);
        }
    }
    printf("MST Edges (Kruskal):\n");
    for (int j = 0; j < e; j++)
        printf("%d - %d : %d\n", result[j].src, result[j].dest, result[j].weight);
}

void kruskalMaxST() {
    qsort(edges, E, sizeof(edges[0]), compare);
    for (int i = 0; i < V; i++) parent[i] = i;
    struct Edge result[V-1];
    int e = 0, i = E-1;
    while (e < V - 1 && i >= 0) {
        struct Edge next = edges[i--];
        int x = find(next.src);
        int y = find(next.dest);
        if (x != y) {
            result[e++] = next;
            unionSets(x, y);
        }
    }
    printf("Max ST Edges (Kruskal):\n");
    for (int j = 0; j < e; j++)
        printf("%d - %d : %d\n", result[j].src, result[j].dest, result[j].weight);
}

int main() {
    printf("Test Case 1: Same weight edges (select first in sorted order)\n");
    kruskalMST();

    printf("\nTest Case 2: Maximum Spanning Tree\n");
    kruskalMaxST();

    return 0;
}
