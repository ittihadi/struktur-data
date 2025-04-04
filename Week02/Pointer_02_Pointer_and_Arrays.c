// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();

int main()
{
    // Tampilkan judul program
    judul();

    int  arr[] = {10, 20, 30, 40, 50};
    int *ptr   = arr;

    printf("Mengakses elemen array melalui pointer:\n");
    for (int i = 0; i < 5; i++)
        printf("Elemen ke-%d: %d\n", i, *(ptr + i));

    return 0;
}

// Definisi fungsi-fungsi
void judul()
{
    printf("Program Pointer dan Array\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
