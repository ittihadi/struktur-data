// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
void hapusData(int arr[], int *size, int pos);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int arr[] = {10, 20, 30, 40, 50};
    int size  = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum penghapusan:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Masukkan posisi data yang ingin dihapus (0-%d): ", size - 1);
    int pos = 0;
    scanf(" %d", &pos);

    hapusData(arr, &size, pos);

    printf("Array setelah penghapusan:\n");
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
    printf("Program Menghapus Data Array Satu Dimensional\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void hapusData(int arr[], int *size, int pos)
{
    if (pos < 0 || pos >= *size)
    {
        printf("Posisi tidak valid, tidak dapat menghapus data\n");
        return;
    }

    for (int i = pos; i < *size; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Elemen pada posisi %d telah dihapus\n", pos);
}
