//Write a C program to represent directed and undirected graphs using adjacency

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

void addEdge(Graph *graph, int src, int dest, int isDirected) {
    graph->matrix[src][dest] = 1;
    if (!isDirected) {
        graph->matrix[dest][src] = 1;
    }
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}

int main() {
    int vertices, edges, isDirected;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest, isDirected);
    }

    printf("Adjacency Matrix:\n");
    printGraph(graph);

    freeGraph(graph);
    return 0;
}
