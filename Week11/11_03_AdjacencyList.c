#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int          vertex;
    struct Node* next;
};

struct Graph
{
    int           numVertices;
    struct Node** adjLists;
};

void          judul();
struct Node*  createNode(int v);
struct Graph* createGraph(int vertices);
void          addEdge(struct Graph* graph, int src, int dest);
void          printGraph(struct Graph* graph);

int main()
{
    judul();

    struct Graph* graph = createGraph(5);

    // Contoh graf berarah
    addEdge(graph, 0, 1);     // A → B
    addEdge(graph, 0, 3);     // A → D
    addEdge(graph, 1, 2);     // B → C
    addEdge(graph, 3, 4);     // D → E
    addEdge(graph, 4, 1);     // E → B

    printGraph(graph);
    return 0;
}

void judul()
{
    printf("Program Implementasi Graf dengan Adjacency List\n");
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

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
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

void printGraph(struct Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp)
        {
            printf("%d → ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
