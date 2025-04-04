// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();
void hapusData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax);

int main()
{
    // Tampilkan judul program
    judul();

    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Array sebelum penghapusan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    printf("\nMasukkan posisi baris dan kolom untuk penghapusan (contoh: 1 2): ");
    int baris = 0;
    int kolom = 0;
    scanf(" %d %d", &baris, &kolom);

    hapusData(arr, baris, kolom, 2, 3);

    printf("Array setelah penghapusan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}

// Definisi fungsi-fungsi
void hapusData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax)
{
    if (baris < 0 || baris >= barisMax || kolom < 0 || kolom >= kolomMax)
    {
        printf("Posisi tidak valid! Tidak dapat menghapus data.\n");
        return;
    }

    arr[baris][kolom] = 0;
    printf("Data pada posisi [%d][%d] telah dihapus.\n", baris, kolom);
}

void judul()
{
    printf("Program Hapus Data Array 2 Dimensi\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
