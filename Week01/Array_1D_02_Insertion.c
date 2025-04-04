// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
void tambahData(int arr[], int *size, int capacity, int data, int pos);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int arr[10]  = {10, 20, 30, 40, 50};
    int size     = 5;
    int capacity = 10;

    printf("Sebelum penambahan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");
    printf("Menambahkan elemen 25 di posisi 2\n");
    tambahData(arr, &size, capacity, 25, 2);

    printf("Setelah menambahkan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Penambahan Data Array Satu Dimensional\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahData(int arr[], int *size, int capacity, int data, int pos)
{
    if (*size >= capacity)
    {
        printf("Array penuh, tidak dapat menambahkan data\n");
        return;
    }

    for (int i = *size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = data;
    (*size)++;
}
