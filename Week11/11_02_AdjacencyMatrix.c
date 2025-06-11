#include <stdio.h>
#define V 3     // Jumlah vertex

void judul();
void printMatrix(int matrix[V][V]);

int main()
{
    judul();

    // Inisialisasi matriks (0 = tidak ada edge)
    int adjMatrix[V][V] = {
        {0, 1, 1},     // A terhubung ke B dan C
        {1, 0, 1},     // B terhubung ke A dan C
        {1, 1, 0}      // C terhubung ke A dan B
    };

    printMatrix(adjMatrix);
    return 0;
}

void judul()
{
    printf("Program Implementasi Graf dengan Adjacency Matrix\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void printMatrix(int matrix[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
