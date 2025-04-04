// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
int  jumlahElemenRekursif(int arr[], int n);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int arr[]   = {1, 2, 3, 4, 5};
    int panjang = sizeof(arr) / sizeof(arr[0]);

    printf("Jumlah elemen array: %d\n", jumlahElemenRekursif(arr, panjang));

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Menghitung Jumlah Elemen Array Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

int jumlahElemenRekursif(int arr[], int n)
{
    if (n == 0)
    {
        return 0;     // Base case
    }
    else
    {
        return arr[0] + jumlahElemenRekursif(arr + 1, n - 1);     // Recursive case
    }
}
