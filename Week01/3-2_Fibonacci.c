// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
int  pangkat(int n);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int angka = 10;
    for (int i = 0; i < angka; i++)
    {
        printf("%d ", pangkat(i));
    }

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Fibonacci Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

int pangkat(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return pangkat(n - 1) + pangkat(n - 2);
}
