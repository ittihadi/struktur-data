// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
int  hitungPangkatRekursif(int a, int b);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int a = 0;
    int b = 0;

    printf("Masukkan basis dan eksponen: ");
    scanf(" %d %d", &a, &b);

    printf("Eksponen dari %d^%d adalah %d\n", a, b, hitungPangkatRekursif(a, b));

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Penghitung Pangkat Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

int hitungPangkatRekursif(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return a * hitungPangkatRekursif(a, b - 1);
}
