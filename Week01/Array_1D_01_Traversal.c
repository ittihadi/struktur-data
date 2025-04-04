// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
void traversalArray(int arr[], int size);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int arr[] = {10, 20, 30, 40, 50};
    int size  = sizeof(arr) / sizeof(arr[0]);

    printf("Hasil Traversal Array:\n");
    traversalArray(arr, size);

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Traversal Array Satu Dimensional\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void traversalArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Elemen ke-%d: %d\n", i, arr[i]);
    }
}
