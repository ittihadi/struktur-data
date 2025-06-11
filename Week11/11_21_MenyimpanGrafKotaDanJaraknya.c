#include <limits.h>
#include <stdio.h>
#define V 4

void judul();
void printPath(int parent[], int j);
void dijkstra(int graph[V][V], int src);

int main()
{
    judul();

    int graph[V][V] = {
        {0, 50, 30, 0},
        {0, 0, 0, 70},
        {0, 20, 0, 0},
        {0, 0, 20, 0}};
    dijkstra(graph, 0);     // Mulai dari kota 0 (Jakarta)
    return 0;
}

void judul()
{
    printf("Program Menyimpan Graf Kota dan Jaraknya\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1) return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V], parent[V], visited[V];
    for (int i = 0; i < V; i++)
    {
        dist[i]    = INT_MAX;
        visited[i] = 0;
        parent[i]  = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u, min = INT_MAX;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], u = v;
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v]   = dist[u] + graph[u][v];
            }
    }
    // Cetak hasil
    printf("Kota\tJarak\tRute\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\t%d", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}
