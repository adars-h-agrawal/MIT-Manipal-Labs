//Write a C program to implement Breadth First Search (BFS)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **matrix;
    int vertices;
} Graph;

typedef struct {
    int *items;
    int front, rear, size;
} Queue;

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

Queue *createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->items = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == q->size - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int value = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return value;
}

void bfs(Graph *graph, int start) {
    int *visited = (int *)calloc(graph->vertices, sizeof(int));
    Queue *q = createQueue(graph->vertices);

    visited[start] = 1;
    enqueue(q, start);

    printf("BFS Traversal: ");
    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[current][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    free(visited);
    free(q->items);
    free(q);
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
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);
    bfs(graph, start);

    for (int i = 0; i < graph->vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);

    return 0;
}
