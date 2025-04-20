// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();
void updateData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int nilaiBaru);

int main()
{
    // Tampilkan judul program
    judul();

    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Array sebelum pembaruan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    printf("Masukkan posisi baris dan kolom untuk diupdate (contoh: 1 2): ");
    int baris     = 0;
    int kolom     = 0;
    int nilaiBaru = 0;
    scanf(" %d %d", &baris, &kolom);
    printf("Masukkan nilai baru: ");
    scanf(" %d", &nilaiBaru);

    updateData(arr, baris, kolom, 2, 3, nilaiBaru);

    printf("Array setelah pembaruan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}

// Definisi fungsi-fungsi
void updateData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int nilaiBaru)
{
    if (baris < 0 || baris >= barisMax || kolom < 0 || kolom >= kolomMax)
    {
        printf("Posisi tidak valid! Tidak dapat memperbarui data.\n");
        return;
    }

    arr[baris][kolom] = nilaiBaru;
    printf("Data pada posisi [%d][%d] telah diperbarui menjadi: %d.\n", baris, kolom, nilaiBaru);
}

void judul()
{
    printf("Program Update Data Array 2 Dimensi\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
