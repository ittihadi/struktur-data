// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
void updateData(int arr[], int pos, int size, int newValue);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int arr[] = {10, 20, 30, 40, 50};
    int size  = sizeof(arr) / sizeof(arr[0]);

    printf("Masukkan posisi data yang ingin diupdate (0-%d): ", size - 1);
    int pos = 0;
    scanf(" %d", &pos);

    printf("Masukkan nilai baru: ");
    int newValue = 0;
    scanf(" %d", &newValue);

    updateData(arr, pos, size, newValue);

    printf("Array setelah update:\n");
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
    printf("Program Memperbarui Data Array Satu Dimensional\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void updateData(int arr[], int pos, int size, int newValue)
{
    if (pos >= size || pos < 0)
    {
        printf("Posisi tidak valid!\n");
        return;
    }

    arr[pos] = newValue;
    printf("Data pada posisi %d telah diperbarui menjadi: %d\n", pos, arr[pos]);
}
