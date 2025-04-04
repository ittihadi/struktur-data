// Preprocessors
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Deklarasi Fungsi-fungsi
bool isPalindromeRekursif(char str[], int start, int end);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    char str[]   = "radar";
    int  panjang = strlen(str);

    if (isPalindromeRekursif(str, 0, panjang - 1))
    {
        printf("String %s adalah palindrom.\n", str);
    }
    else
    {
        printf("String %s bukan palindrom.\n", str);
    }

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Pemeriksa Palindrom Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

bool isPalindromeRekursif(char str[], int start, int end)
{
    if (start >= end)
        return true;     // Base case
    else if (str[start] != str[end])
        return false;     // Karakter pertama dan terakhir beda
    else
        return isPalindromeRekursif(str, start + 1, end - 1);     // Recursive case
}
