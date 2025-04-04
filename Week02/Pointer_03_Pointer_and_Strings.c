// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();

int main()
{
    // Tampilkan judul program
    judul();

    char  str[] = "Halo, Dunia!";
    char *ptr   = str;

    printf("String: %s\n", str);
    printf("Traversal string menggunakan pointer:\n");
    while (*ptr != '\0')
    {
        printf("%c ", *ptr);
        ptr++;
    }
    printf("\n");
    return 0;
}

// Definisi fungsi-fungsi
void judul()
{
    printf("Program Pointer dan String\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
