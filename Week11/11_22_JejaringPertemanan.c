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
void          DFS(struct Graph* graph, int vertex, int component[], int compID);
void          findConnectedComponents(struct Graph* graph);

int main()
{
    judul();

    struct Graph* graph = createGraph(10);     // 10 user: 0=Alice, 1=Bob, dst.
    addEdge(graph, 0, 1);                      // Alice -- Bob
    addEdge(graph, 1, 2);                      // Bob -- Charlie
    addEdge(graph, 0, 3);                      // Alice -- David
    addEdge(graph, 1, 4);                      // Bob -- Eve
    // Group teman kedua
    addEdge(graph, 5, 7);     // Thomas -- Adam
    addEdge(graph, 8, 6);     // Zeke -- Antonio
    addEdge(graph, 9, 8);     // Alfred -- Zeke
    addEdge(graph, 5, 9);     // Thomas -- Alfred

    findConnectedComponents(graph);
    return 0;
}

void judul()
{
    printf("Program Jejaring Pertemanan\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void DFS(struct Graph* graph, int vertex, int component[], int compID)
{
    graph->visited[vertex] = 1;
    component[vertex]      = compID;

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList)
    {
        int connectedVertex = adjList->vertex;
        if (!graph->visited[connectedVertex])
        {
            DFS(graph, connectedVertex, component, compID);
        }
        adjList = adjList->next;
    }
}

void findConnectedComponents(struct Graph* graph)
{
    int component[MAX_VERTICES] = {0};
    int compID                  = 0;

    for (int v = 0; v < graph->numVertices; v++)
    {
        if (!graph->visited[v])
        {
            compID++;
            DFS(graph, v, component, compID);
        }
    }

    // Cetak hasil
    printf("Kelompok Teman:\n");
    for (int id = 1; id <= compID; id++)
    {
        printf("Kelompok %d: ", id);
        for (int v = 0; v < graph->numVertices; v++)
        {
            if (component[v] == id) printf("%d ", v);
        }
        printf("\n");
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
