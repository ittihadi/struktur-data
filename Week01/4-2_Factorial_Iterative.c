// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
int  faktorial(int n);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int angka = 5;
    printf("Faktorial dari %d adalah %d\n", angka, faktorial(angka));

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Faktorial Iteratif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

int faktorial(int n)
{
    int hasil = 1;
    for (int i = 1; i <= n; i++)
    {
        hasil *= i;
    }

    return hasil;
}
