// Preprocessors
#include <stdio.h>

// Deklarasi Fungsi-fungsi
void hanoi(int n, char asal, char tujuan, char bantuan);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    int n = 4;
    printf("Penyelesaian menara hanoi dengan %d cakram adalah:\n", n);
    hanoi(n, 'A', 'C', 'B');

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Menara Hanoi Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void hanoi(int n, char asal, char tujuan, char bantuan)
{
    // Base case
    if (n == 1)
    {
        printf("Pindahkan cakram 1 dari %c ke %c\n", asal, tujuan);
        return;
    }

    // Recursive case
    // Pindahkan cakram di atas ke tiang bantu
    hanoi(n - 1, asal, bantuan, tujuan);
    // Pindahkan cakram ini ke tujuan
    printf("Pindahkan cakram %d dari %c ke %c\n", n, asal, tujuan);
    // Pindahkan cakram di atas ke tujuan
    hanoi(n - 1, bantuan, tujuan, asal);
}
