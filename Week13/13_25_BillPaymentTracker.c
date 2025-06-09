#include <stdio.h>
#include <string.h>

typedef struct
{
    char  id[10];
    char  nama[50];
    float jumlah_tagihan;
    char  tanggal[15];
} Pembayaran;

void judul();
void tambahPembayaran(const char* nama_file);
void bacaPembayaran(const char* nama_file);
void cariPembayaran(const char* nama_file, const char* id_pembayaran);

int main()
{
    judul();

    const char* nama_file = "Week13/pembayaran.txt";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Pembayaran\n2. Lihat Semua Pembayaran\n3. Cari Pembayaran\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahPembayaran(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaPembayaran(nama_file);
        }
        else if (pilihan == 3)
        {
            char id[10];
            printf("Masukkan ID Pembayaran yang dicari: ");
            scanf("%s", id);
            cariPembayaran(nama_file, id);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Pencatatan Data Pembayaran Tagihan\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahPembayaran(const char* nama_file)
{
    FILE* file = fopen(nama_file, "a");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Pembayaran p;
    printf("Masukkan ID Pembayaran: ");
    scanf("%s", p.id);
    printf("Masukkan Nama Pelanggan: ");
    scanf(" %[^\n]", p.nama);
    printf("Masukkan Jumlah Tagihan: ");
    scanf("%f", &p.jumlah_tagihan);
    printf("Masukkan Tanggal Pembayaran (DD/MM/YYYY): ");
    scanf("%s", p.tanggal);
    fprintf(file, "%s %s %.2f %s\n", p.id, p.nama, p.jumlah_tagihan, p.tanggal);
    fclose(file);
    printf("Data pembayaran berhasil ditambahkan.\n");
}

void bacaPembayaran(const char* nama_file)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Pembayaran p;
    printf("Data Pembayaran:\n");
    while (fscanf(file, "%s %s %f %s", p.id, p.nama, &p.jumlah_tagihan, p.tanggal) != EOF)
    {
        printf("ID: %s, Nama: %s, Jumlah Tagihan: %.2f, Tanggal: %s\n", p.id, p.nama, p.jumlah_tagihan, p.tanggal);
    }
    fclose(file);
}

void cariPembayaran(const char* nama_file, const char* id_pembayaran)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Pembayaran p;
    while (fscanf(file, "%s %s %f %s", p.id, p.nama, &p.jumlah_tagihan, p.tanggal) != EOF)
    {
        if (strcmp(p.id, id_pembayaran) == 0)
        {
            printf("Data Ditemukan: ID: %s, Nama: %s, Jumlah Tagihan: %.2f, Tanggal: %s\n", p.id, p.nama, p.jumlah_tagihan, p.tanggal);
            fclose(file);
            return;
        }
    }
    printf("Data tidak ditemukan.\n");
    fclose(file);
}
