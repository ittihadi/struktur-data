// Preprocessors
#include <stdio.h>
#include <string.h>

// Deklarasi Fungsi-fungsi
void balikStringRekursif(char str[], int start, int end);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    char str[128]   = {0};
    char str_2[128] = {0};
    int  len        = 0;

    printf("Masukkan teks: ");
    scanf(" %127[^\n]", str);
    strcpy(str_2, str);
    len = strlen(str);

    balikStringRekursif(str_2, 0, len - 1);
    printf("Kebalikan dari string %s adalah %s\n", str, str_2);

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Pembalik String Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void balikStringRekursif(char str[], int start, int end)
{
    if (start >= end)
        return;

    char tmp   = str[start];
    str[start] = str[end];
    str[end]   = tmp;

    balikStringRekursif(str, start + 1, end - 1);
}
