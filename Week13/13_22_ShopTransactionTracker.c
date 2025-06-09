#include <stdio.h>
#include <string.h>

#define READ_PATTERN  "%[^-]-%[^-]-%d-%f\n"
#define WRITE_PATTERN "%s-%s-%d-%.2f\n"

typedef struct
{
    char  nomor[10];
    char  barang[50];
    int   jumlah;
    float total_harga;
} Transaksi;

void judul();
void tambahTransaksi(const char* nama_file);
void bacaTransaksi(const char* nama_file);
void cariTransaksi(const char* nama_file, const char* nomor_transaksi);

int main()
{
    judul();

    const char* nama_file = "Week13/transaksi.txt";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Transaksi\n2. Lihat Semua Transaksi\n3. Cari Transaksi\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahTransaksi(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaTransaksi(nama_file);
        }
        else if (pilihan == 3)
        {
            char nomor[10];
            printf("Masukkan Nomor Transaksi yang dicari: ");
            scanf("%s", nomor);
            cariTransaksi(nama_file, nomor);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Pencatatan Transaksi Penjualan Toko\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahTransaksi(const char* nama_file)
{
    FILE* file = fopen(nama_file, "a");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Transaksi t;
    printf("Masukkan Nomor Transaksi: ");
    scanf("%s", t.nomor);
    printf("Masukkan Nama Barang: ");
    scanf(" %[^\n]", t.barang);
    printf("Masukkan Jumlah Terjual: ");
    scanf("%d", &t.jumlah);
    printf("Masukkan Total Harga: ");
    scanf("%f", &t.total_harga);
    fprintf(file, WRITE_PATTERN, t.nomor, t.barang, t.jumlah, t.total_harga);
    fclose(file);
    printf("Data transaksi berhasil ditambahkan.\n");
}

void bacaTransaksi(const char* nama_file)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Transaksi t;
    printf("Data Transaksi:\n");
    while (fscanf(file, READ_PATTERN, t.nomor, t.barang, &t.jumlah, &t.total_harga) != EOF)
    {
        printf("Nomor: %s, Barang: %s, Jumlah: %d, Total Harga: %.2f\n", t.nomor, t.barang, t.jumlah, t.total_harga);
    }
    fclose(file);
}

void cariTransaksi(const char* nama_file, const char* nomor_transaksi)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Transaksi t;
    while (fscanf(file, READ_PATTERN, t.nomor, t.barang, &t.jumlah, &t.total_harga) != EOF)
    {
        if (strcmp(t.nomor, nomor_transaksi) == 0)
        {
            printf("Data Ditemukan: Nomor: %s, Barang: %s, Jumlah: %d, Total Harga: %.2f\n", t.nomor, t.barang, t.jumlah, t.total_harga);
            fclose(file);
            return;
        }
    }
    printf("Transaksi tidak ditemukan.\n");
    fclose(file);
}
