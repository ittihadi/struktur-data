#include <stdbool.h>
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
bool          isDAGUtil(struct Graph* graph, int v, bool visited[], bool recStack[]);
bool          isDAG(struct Graph* graph);
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

    printf("Graf berarah (1):\n");
    printGraph(graph);
    printf("Graf ini %s\n", isDAG(graph) ? "tidak bersiklus" : "bersiklus");

    // Buat graf siklik
    struct Graph* graph2 = createGraph(5);

    // Contoh graf berarah
    addEdge(graph2, 0, 1);     // A → B
    addEdge(graph2, 0, 3);     // A → D
    addEdge(graph2, 1, 2);     // B → C
    addEdge(graph2, 3, 4);     // D → E
    addEdge(graph2, 4, 1);     // E → B
    addEdge(graph2, 1, 0);     // E → B

    printf("\n");
    printf("Graf berarah (2):\n");
    printGraph(graph2);
    printf("Graf ini %s\n", isDAG(graph2) ? "tidak bersiklus" : "bersiklus");

    return 0;
}

void judul()
{
    printf("Program Deteksi DAG dengan Topological Sort\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

bool isDAGUtil(struct Graph* graph, int v, bool visited[], bool recStack[])
{
    if (!visited[v])
    {
        visited[v]  = true;
        recStack[v] = true;

        struct Node* adj = graph->adjLists[v];
        while (adj)
        {
            if (!visited[adj->vertex] && isDAGUtil(graph, adj->vertex, visited, recStack))
                return true;
            else if (recStack[adj->vertex])
                return true;
            adj = adj->next;
        }
    }
    recStack[v] = false;
    return false;
}

bool isDAG(struct Graph* graph)
{
    bool* visited  = malloc(graph->numVertices * sizeof(bool));
    bool* recStack = malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i]  = false;
        recStack[i] = false;
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (isDAGUtil(graph, i, visited, recStack))
            return false;     // Bukan DAG jika ada siklus
    }
    return true;
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
