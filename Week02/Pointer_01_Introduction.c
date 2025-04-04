// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();

int main()
{
    // Tampilkan judul program
    judul();

    int  a = 10;
    int *ptr;

    ptr = &a;

    printf("Nilai a: %d\n", a);
    printf("Alamat memori a: %p\n", ptr);
    printf("Nilai melalui pointer: %d\n", *ptr);

    return 0;
}

// Definisi fungsi-fungsi
void judul()
{
    printf("Program Pengertian Pointer\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
