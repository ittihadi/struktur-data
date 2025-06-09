#include <stdio.h>
#include <string.h>

#define WRITE_PATTERN "%s-%s-%s\n"
#define READ_PATTERN  "%[^-]-%[^-]-%s\n"

typedef struct
{
    char id[10];
    char nama[50];
    char telepon[15];
} Pelanggan;

void judul();
void tambahPelanggan(const char* nama_file);
void bacaPelanggan(const char* nama_file);
void cariPelanggan(const char* nama_file, const char* id_pelanggan);

int main()
{
    judul();
    const char* nama_file = "Week13/pelanggan.txt";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Pelanggan\n2. Lihat Semua Pelanggan\n3. Cari Pelanggan\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahPelanggan(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaPelanggan(nama_file);
        }
        else if (pilihan == 3)
        {
            char id[10];
            printf("Masukkan ID Pelanggan yang dicari: ");
            scanf("%s", id);
            cariPelanggan(nama_file, id);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Manajemen Data Pelanggan pada Toko Online\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahPelanggan(const char* nama_file)
{
    FILE* file = fopen(nama_file, "a");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Pelanggan p;
    printf("Masukkan ID Pelanggan: ");
    scanf("%s", p.id);
    printf("Masukkan Nama Pelanggan: ");
    scanf(" %[^\n]", p.nama);
    printf("Masukkan Nomor Telepon: ");
    scanf("%s", p.telepon);
    fprintf(file, WRITE_PATTERN, p.id, p.nama, p.telepon);
    fclose(file);
    printf("Data pelanggan berhasil ditambahkan.\n");
}

void bacaPelanggan(const char* nama_file)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Pelanggan p;
    printf("Data Pelanggan:\n");
    while (fscanf(file, READ_PATTERN, p.id, p.nama, p.telepon) != EOF)
    {
        printf("ID: %s, Nama: %s, Telepon: %s\n", p.id, p.nama, p.telepon);
    }
    fclose(file);
}

void cariPelanggan(const char* nama_file, const char* id_pelanggan)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Pelanggan p;
    while (fscanf(file, READ_PATTERN, p.id, p.nama, p.telepon) != EOF)
    {
        if (strcmp(p.id, id_pelanggan) == 0)
        {
            printf("Data Ditemukan: ID: %s, Nama: %s, Telepon: %s\n", p.id, p.nama, p.telepon);
            fclose(file);
            return;
        }
    }
    printf("Pelanggan tidak ditemukan.\n");
    fclose(file);
}
