//Write a C program to represent directed and undirected graphs using adjacency list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct {
    Node **list;
    int vertices;
} Graph;

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->list = (Node **)malloc(vertices * sizeof(Node *));
    for (int i = 0; i < vertices; i++) {
        graph->list[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest, int isDirected) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->list[src];
    graph->list[src] = newNode;

    if (!isDirected) {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->vertex = src;
        newNode->next = graph->list[dest];
        graph->list[dest] = newNode;
    }
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: ", i);
        Node *temp = graph->list[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node *temp = graph->list[i];
        while (temp) {
            Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->list);
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

    printf("Adjacency List:\n");
    printGraph(graph);

    freeGraph(graph);
    return 0;
}
