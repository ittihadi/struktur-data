// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();
void traversalArray(int arr[][3], int baris, int kolom);

int main()
{
    // Tampilkan judul program
    judul();

    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Hasil Traversal Array 2 Dimensi:\n");
    traversalArray(arr, 2, 3);

    return 0;
}

// Definisi fungsi-fungsi
void traversalArray(int arr[][3], int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void judul()
{
    printf("Program Traversal Array 2 Dimensi\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
