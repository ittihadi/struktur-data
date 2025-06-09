#include <stdio.h>

typedef struct
{
    int  id;
    char nama[50];
    int  stok;
} Barang;

void judul();
void tambahBarang(const char* nama_file);
void bacaBarang(const char* nama_file);
void updateStok(const char* nama_file, int id_barang, int stok_baru);

int main()
{
    judul();

    const char* nama_file = "Week13/inventori.dat";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Barang\n2. Lihat Semua Barang\n3. Update Stok Barang\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahBarang(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaBarang(nama_file);
        }
        else if (pilihan == 3)
        {
            int id, stok;
            printf("Masukkan ID Barang: ");
            scanf("%d", &id);
            printf("Masukkan Stok Baru: ");
            scanf("%d", &stok);
            updateStok(nama_file, id, stok);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Inventori Barang Menggunakan File Random Access\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahBarang(const char* nama_file)
{
    FILE* file = fopen(nama_file, "ab");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Barang b;
    printf("Masukkan ID Barang: ");
    scanf("%d", &b.id);
    printf("Masukkan Nama Barang: ");
    scanf(" %49[^\n]", b.nama);
    printf("Masukkan Stok: ");
    scanf("%d", &b.stok);
    fwrite(&b, sizeof(Barang), 1, file);
    fclose(file);
    printf("Data barang berhasil ditambahkan.\n");
}

void bacaBarang(const char* nama_file)
{
    FILE* file = fopen(nama_file, "rb");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Barang b;
    printf("Data Barang:\n");
    while (fread(&b, sizeof(Barang), 1, file))
    {
        printf("ID: %d, Nama: %s, Stok: %d\n", b.id, b.nama, b.stok);
    }
    fclose(file);
}

void updateStok(const char* nama_file, int id_barang, int stok_baru)
{
    FILE* file = fopen(nama_file, "rb+");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Barang b;
    while (fread(&b, sizeof(Barang), 1, file))
    {
        if (b.id == id_barang)
        {
            b.stok = stok_baru;
            fseek(file, -sizeof(Barang), SEEK_CUR);
            fwrite(&b, sizeof(Barang), 1, file);
            fclose(file);
            printf("Stok barang dengan ID %d berhasil diperbarui.\n", id_barang);
            return;
        }
    }
    printf("Barang dengan ID %d tidak ditemukan.\n", id_barang);
    fclose(file);
}
