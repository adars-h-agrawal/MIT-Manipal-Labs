//Write a C program to implement Depth First Search (DFS)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **matrix;
    int vertices;
} Graph;

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->matrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->matrix[i] = (int *)calloc(vertices, sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
}

void dfsUtil(Graph *graph, int vertex, int *visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[vertex][i] && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

void dfs(Graph *graph, int start) {
    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    printf("DFS Traversal: ");
    dfsUtil(graph, start, visited);
    printf("\n");
    free(visited);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);
    dfs(graph, start);

    for (int i = 0; i < graph->vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);

    return 0;
}
