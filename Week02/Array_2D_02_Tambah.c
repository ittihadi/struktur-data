// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();
void tambahData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int data);

int main()
{
    // Tampilkan judul program
    judul();

    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("Array sebelum penambahan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    int baris = 1;
    int kolom = 2;
    int data  = 10;

    tambahData(arr, baris, kolom, 2, 3, data);
    printf("Array setelah penambahan:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahData(int arr[][3], int baris, int kolom, int barisMax, int kolomMax, int data)
{
    if (baris < 0 || baris >= barisMax || kolom < 0 || kolom >= kolomMax)
    {
        printf("Posisi tidak valid! Tidak dapat menambahkan data.\n");
        return;
    }

    arr[baris][kolom] = data;
    printf("Data berhasil ditambahkan di posisi [%d][%d].\n", baris, kolom);
}

void judul()
{
    printf("Program Penambahan Data Array 2 Dimensi\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
