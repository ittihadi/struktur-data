#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

struct Node
{
    int          vertex;
    struct Node* next;
};

struct Graph
{
    int           numVertices;
    struct Node** adjLists;
    int*          visited;
};

void          judul();
struct Node*  createNode(int v);
struct Graph* createGraph(int vertices);
void          addEdge(struct Graph* graph, int src, int dest);
void          BFS(struct Graph* graph, int startVertex);

int main()
{
    judul();

    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);     // 0 -- 1
    addEdge(graph, 0, 2);     // 0 -- 2
    addEdge(graph, 1, 3);     // 1 -- 3
    addEdge(graph, 2, 3);     // 2 -- 3

    BFS(graph, 0);     // Mulai BFS dari vertex 0
    return 0;
}

void judul()
{
    printf("Program Breadth-First Search\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void BFS(struct Graph* graph, int startVertex)
{
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++]               = startVertex;

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("Visited %d\n", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                queue[rear++]             = adjVertex;
            }
            temp = temp->next;
        }
    }
}

struct Node* createNode(int v)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex      = v;
    newNode->next        = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices  = vertices;
    graph->adjLists     = malloc(vertices * sizeof(struct Node*));
    graph->visited      = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i]  = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Tambah edge dari src ke dest
    struct Node* newNode = createNode(dest);
    newNode->next        = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
