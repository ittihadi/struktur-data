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

    printf("Masukkan posisi baris dan kolom untuk membaca data (contoh: 1 2): ");
    int baris = 0;
    int kolom = 0;
    scanf(" %d %d", &baris, &kolom);

    hapusData(arr, baris, kolom, 2, 3);

    return 0;
}

// Definisi fungsi-fungsi
void hapusData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax)
{
    if (baris < 0 || baris >= barisMax || kolom < 0 || kolom >= kolomMax)
    {
        printf("Posisi tidak valid! Tidak dapat membaca data.\n");
        return;
    }

    printf("Data pada posisi [%d][%d]: %d.\n", baris, kolom, arr[baris][kolom]);
}

void judul()
{
    printf("Program Pembacaan Data Array 2 Dimensi\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
