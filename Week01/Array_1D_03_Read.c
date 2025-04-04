// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
void bacaData(int arr[], int pos, int size);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int arr[] = {10, 20, 30, 40, 50};
    int size  = sizeof(arr) / sizeof(arr[0]);

    printf("Masukkan posisi data yang ingin dibaca (0-%d): ", size - 1);
    int pos = 0;
    scanf(" %d", &pos);

    bacaData(arr, pos, size);

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Membaca Data Array Satu Dimensional\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void bacaData(int arr[], int pos, int size)
{
    if (pos >= size || pos < 0)
    {
        printf("Posisi tidak valid!\n");
        return;
    }

    printf("Data pada posisi %d adalah: %d\n", pos, arr[pos]);
}
