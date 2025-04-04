// Preprocessors
#include <stdio.h>
#include <stdlib.h>

// Deklarasi fungsi-fungsi
void judul();
typedef struct
{
    int  id;
    char nama[50];
} Barang;

int main()
{
    // Tampilkan judul program
    judul();

    // Alokasi memori
    Barang *mhs = (Barang *)malloc(sizeof(Barang));

    mhs->id = 1;
    snprintf(mhs->nama, sizeof(mhs->nama), "John Doe");

    printf("ID: %d\n", mhs->id);
    printf("Nama: %s\n", mhs->nama);

    // Bebaskan memori
    free(mhs);

    return 0;
}

// Definisi fungsi-fungsi
void judul()
{
    printf("Program Pointer ke Struct\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
