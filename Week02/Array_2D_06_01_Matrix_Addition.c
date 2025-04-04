// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();
void tampilkanMatriks(int matriks[][3], int baris, int kolom);
void jumlahkanMatriks(int matriks1[][3], int matriks2[][3], int hasil[][3], int baris, int kolom);

int main()
{
    // Tampilkan judul program
    judul();

    int matriks1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    int matriks2[2][3] = {
        {6, 5, 4},
        {3, 2, 1}};
    int hasil[2][3];

    printf("Matriks Pertama:\n");
    tampilkanMatriks(matriks1, 2, 3);

    printf("\nMatriks Kedua:\n");
    tampilkanMatriks(matriks2, 2, 3);

    jumlahkanMatriks(matriks1, matriks2, hasil, 2, 3);

    printf("\nHasil Penjumlahan Matriks:\n");
    tampilkanMatriks(hasil, 2, 3);

    return 0;
}

// Definisi fungsi-fungsi
void tampilkanMatriks(int matriks[][3], int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
            printf("%d ", matriks[i][j]);
        printf("\n");
    }
}

void jumlahkanMatriks(int matriks1[][3], int matriks2[][3], int hasil[][3], int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
    }
}

void judul()
{
    printf("Program Penjumlahan Dua Matriks\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
