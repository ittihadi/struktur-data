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
void          DFS(struct Graph* graph, int vertex);

int main()
{
    judul();

    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);     // 0 -- 1
    addEdge(graph, 0, 2);     // 0 -- 2
    addEdge(graph, 1, 3);     // 1 -- 3

    DFS(graph, 0);     // Mulai DFS dari vertex 0
    return 0;
}

void judul()
{
    printf("Program Depth First Search dengan Adjacency List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
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

    // Untuk graf tidak berarah, tambah edge dari dest ke src
    newNode               = createNode(src);
    newNode->next         = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex)
{
    struct Node* adjList   = graph->adjLists[vertex];
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    while (adjList != NULL)
    {
        int connectedVertex = adjList->vertex;
        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        adjList = adjList->next;
    }
}
