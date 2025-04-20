// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
int  fibonacci(int n);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int angka = 10;
    for (int i = 0; i < angka; i++)
    {
        printf("%d ", fibonacci(i));
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

int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
