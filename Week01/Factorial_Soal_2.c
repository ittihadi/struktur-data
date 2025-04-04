// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
int  jumlahDigitRekursif(int n);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int n = 0;

    printf("Masukkan bilangan: ");
    scanf(" %d", &n);

    printf("Jumlah digit dari %d adalah %d\n", n, jumlahDigitRekursif(n));

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Penghitung Jumlah Digit Bilangan Secara Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

int jumlahDigitRekursif(int n)
{
    if (n == 0)
        return 0;

    return (n % 10) + jumlahDigitRekursif(n / 10);
}
