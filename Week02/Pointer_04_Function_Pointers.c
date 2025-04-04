// Preprocessors
#include <stdio.h>

// Deklarasi fungsi-fungsi
void judul();
void cetakPesan(const char *pesan);

int main()
{
    // Tampilkan judul program
    judul();

    // Pointer ke fungsi
    void (*ptrFunc)(const char *) = cetakPesan;

    // Pemanggilan fungsi
    ptrFunc("Halo, ini dipanggil melalui pointer ke fungsi!");

    return 0;
}

// Definisi fungsi-fungsi
void cetakPesan(const char *pesan)
{
    printf("%s\n", pesan);
}

void judul()
{
    printf("Program Pointer ke Fungsi\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
