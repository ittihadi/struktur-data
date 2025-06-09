#include <stdio.h>
#include <string.h>

#define READ_PATTERN  "%[^-]-%[^-]-%[^\n]\n"
#define WRITE_PATTERN "%s-%s-%s\n"

typedef struct
{
    char kode[10];
    char judul[100];
    char penulis[50];
} Buku;

void judul();
void tambahBuku(const char* nama_file);
void bacaBuku(const char* nama_file);
void cariBuku(const char* nama_file, const char* kode_buku);

int main()
{
    judul();

    const char* nama_file = "Week13/buku.txt";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Buku\n2. Lihat Semua Buku\n3. Cari Buku\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahBuku(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaBuku(nama_file);
        }
        else if (pilihan == 3)
        {
            char kode[10];
            printf("Masukkan Kode Buku yang dicari: ");
            scanf("%s", kode);
            cariBuku(nama_file, kode);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Pencatatan Data Buku Perpustakaan\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahBuku(const char* nama_file)
{
    FILE* file = fopen(nama_file, "a");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Buku b;
    printf("Masukkan Kode Buku: ");
    scanf("%s", b.kode);
    printf("Masukkan Judul Buku: ");
    scanf(" %[^\n]", b.judul);
    printf("Masukkan Nama Penulis: ");
    scanf(" %[^\n]", b.penulis);
    fprintf(file, WRITE_PATTERN, b.kode, b.judul, b.penulis);
    fclose(file);
    printf("Data buku berhasil ditambahkan.\n");
}

void bacaBuku(const char* nama_file)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Buku b;
    printf("Data Buku:\n");
    while (fscanf(file, READ_PATTERN, b.kode, b.judul, b.penulis) != EOF)
    {
        printf("Kode: %s, Judul: %s, Penulis: %s\n", b.kode, b.judul, b.penulis);
    }
    fclose(file);
}

void cariBuku(const char* nama_file, const char* kode_buku)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Buku b;
    while (fscanf(file, READ_PATTERN, b.kode, b.judul, b.penulis) != EOF)
    {
        if (strcmp(b.kode, kode_buku) == 0)
        {
            printf("Data Ditemukan: Kode: %s, Judul: %s, Penulis: %s\n", b.kode, b.judul, b.penulis);
            fclose(file);
            return;
        }
    }
    printf("Buku tidak ditemukan.\n");
    fclose(file);
}
