// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
int  pangkat(int a, int b);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int basis = 2, eksponen = 3;
    printf("%d^%d = %d\n", basis, eksponen, pangkat(basis, eksponen));

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Eksponen Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

int pangkat(int a, int b)
{
    if (b == 0) return 1;             // Base Case
    return a * pangkat(a, b - 1);     // Recursive Case
}
