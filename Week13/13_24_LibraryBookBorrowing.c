#include <stdio.h>
#include <string.h>

#define WRITE_PATTERN "%s-%s-%s-%s\n"
#define READ_PATTERN  "%[^-]-%[^-]-%[^-]-%s\n"

typedef struct
{
    char id[10];
    char nama[50];
    char judul_buku[100];
    char tanggal[15];
} Peminjaman;

void judul();
void tambahPeminjaman(const char* nama_file);
void bacaPeminjaman(const char* nama_file);
void cariPeminjaman(const char* nama_file, const char* id_peminjaman);

int main()
{
    judul();

    const char* nama_file = "Week13/peminjaman.txt";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Peminjaman\n2. Lihat Semua Peminjaman\n3. Cari Peminjaman\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahPeminjaman(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaPeminjaman(nama_file);
        }
        else if (pilihan == 3)
        {
            char id[10];
            printf("Masukkan ID Peminjaman yang dicari: ");
            scanf("%s", id);
            cariPeminjaman(nama_file, id);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Pencatatan Data Peminjaman Buku Perpustakaan\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahPeminjaman(const char* nama_file)
{
    FILE* file = fopen(nama_file, "a");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Peminjaman p;
    printf("Masukkan ID Peminjaman: ");
    scanf("%s", p.id);
    printf("Masukkan Nama Peminjam: ");
    scanf(" %[^\n]", p.nama);
    printf("Masukkan Judul Buku: ");
    scanf(" %[^\n]", p.judul_buku);
    printf("Masukkan Tanggal Peminjaman (DD/MM/YYYY): ");
    scanf("%s", p.tanggal);
    fprintf(file, WRITE_PATTERN, p.id, p.nama, p.judul_buku, p.tanggal);
    fclose(file);
    printf("Data peminjaman berhasil ditambahkan.\n");
}

void bacaPeminjaman(const char* nama_file)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Peminjaman p;
    printf("Data Peminjaman:\n");
    while (fscanf(file, READ_PATTERN, p.id, p.nama, p.judul_buku, p.tanggal) != EOF)
    {
        printf("ID: %s, Nama: %s, Judul Buku: %s, Tanggal: %s\n", p.id, p.nama, p.judul_buku, p.tanggal);
    }
    fclose(file);
}

void cariPeminjaman(const char* nama_file, const char* id_peminjaman)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Peminjaman p;
    while (fscanf(file, READ_PATTERN, p.id, p.nama, p.judul_buku, p.tanggal) != EOF)
    {
        if (strcmp(p.id, id_peminjaman) == 0)
        {
            printf("Data Ditemukan: ID: %s, Nama: %s, Judul Buku: %s, Tanggal: %s\n", p.id, p.nama, p.judul_buku, p.tanggal);
            fclose(file);
            return;
        }
    }
    printf("Data tidak ditemukan.\n");
    fclose(file);
}
