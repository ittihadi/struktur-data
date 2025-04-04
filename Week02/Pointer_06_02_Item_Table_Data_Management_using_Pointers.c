// Preprocessors
#include <stdio.h>
#include <stdlib.h>

// Deklarasi fungsi-fungsi
void judul();

typedef struct
{
    int   id;
    char  nama[50];
    float harga;
} Barang;

void tambahBarang(Barang **barang, int *jumlah, int id, const char *nama, float harga);
void tampilkanBarang(Barang **barang, int jumlah);
void updateBarang(Barang **barang, int jumlah, int id, const char *nama, float harga);
void hapusBarang(Barang **barang, int *jumlah, int id);

int main()
{
    // Tampilkan judul program
    judul();

    // Deklarasi variabel
    Barang *barang[100];
    int     jumlah = 0;

    while (1)
    {
        printf("\nMenu Pengelolaan Tabel Data Barang:\n");
        printf("1. Tambah Barang\n");
        printf("2. Tampilkan Barang\n");
        printf("3. Update Barang\n");
        printf("4. Hapus Barang\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");

        int   pilihan;
        int   id;
        char  nama[50];
        float harga;

        scanf(" %d", &pilihan);
        if (pilihan == 5)
            break;

        switch (pilihan)
        {
            case 1:
                printf("Masukkan ID Barang: ");
                scanf(" %d", &id);
                printf("Masukkan Nama Barang: ");
                scanf(" %49[^\n]s", nama);
                printf("Masukkan Nilai Barang: ");
                scanf(" %f", &harga);
                tambahBarang(barang, &jumlah, id, nama, harga);
                break;
            case 2:
                tampilkanBarang(barang, jumlah);
                break;
            case 3:
                printf("Masukkan ID barang yang ingin diupdate: ");
                scanf(" %d", &id);
                printf("Masukkan nama baru barang: ");
                scanf(" %49[^\n]s", nama);
                printf("Masukkan harga baru barang: ");
                scanf(" %f", &harga);
                updateBarang(barang, jumlah, id, nama, harga);
                break;
            case 4:
                printf("Masukkan ID barang yang ingin dihapus: ");
                scanf(" %d", &id);
                hapusBarang(barang, &jumlah, id);
                break;
            default:
                printf("Pilhan tidak valid!");
                break;
        }
    }

    // Bebaskan memori semua barang
    for (int i = 0; i < jumlah; i++)
        free(barang[i]);

    return 0;
}

// Definisi fungsi-fungsi
void tambahBarang(Barang **barang, int *jumlah, int id, const char *nama, float harga)
{
    // Alokasi memori barang baru
    barang[*jumlah] = (Barang *)malloc(sizeof(Barang));

    barang[*jumlah]->id = id;
    snprintf(barang[*jumlah]->nama, sizeof(barang[*jumlah]->nama), "%s", nama);
    barang[*jumlah]->harga = harga;

    (*jumlah)++;
    printf("Barang berhasil ditambahkan!\n");
}

void tampilkanBarang(Barang **barang, int jumlah)
{
    printf("Data Barang:\n");
    for (int i = 0; i < jumlah; i++)
    {
        printf("ID: %d, Nama: %s, Harga: %.2f\n", barang[i]->id, barang[i]->nama, barang[i]->harga);
    }
}

void updateBarang(Barang **barang, int jumlah, int id, const char *nama, float harga)
{
    for (int i = 0; i < jumlah; i++)
    {
        if (barang[i]->id == id)
        {
            snprintf(barang[i]->nama, sizeof(barang[i]->nama), "%s", nama);
            barang[i]->harga = harga;
            printf("Data barang dengan ID %d berhasil diperbarui!\n", id);
            return;
        }
    }
    printf("Barang dengan ID %d tidak ditemukan!\n", id);
}

void hapusBarang(Barang **barang, int *jumlah, int id)
{
    for (int i = 0; i < *jumlah; i++)
    {
        if (barang[i]->id == id)
        {
            // Bebaskan memori barang
            free(barang[i]);
            for (int j = i; j < *jumlah - 1; j++)
                barang[j] = barang[j + 1];

            (*jumlah)--;
            printf("Barang dengan ID %d berhasil dihapus!\n", id);
            return;
        }
    }
    printf("Barang dengan ID %d tidak ditemukan!\n", id);
}

void judul()
{
    printf("Program Pengelolaan Tabel Data Barang Menggunakan Pointer\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
