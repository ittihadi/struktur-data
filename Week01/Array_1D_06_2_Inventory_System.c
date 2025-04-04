// Preprocessors
#include <stdio.h>

#define MAX 100

// Deklarasi Fungsi-fungsi
void tampilkanBarang(int arr[], int size);
void tambahBarang(int arr[], int *size, int capacity, int hargaBaru);
void perbaruiBarang(int arr[], int size, int pos, int hargaBaru);
void hapusBarang(int arr[], int *size, int pos);
int  cariHargaTerendah(int arr[], int size);
int  cariHargaTertinggi(int arr[], int size);

void judul();

int main()
{
    // Tampilkan judul
    judul();

    int harga[MAX] = {0};
    int size       = 0;
    int pilihan    = 0;
    int hargaBaru  = 0;
    int pos        = 0;

    while (1)
    {
        printf("\nMenu Sistem Inventori Barang:\n");
        printf("1. Tampilkan Daftar Harga\n");
        printf("2. Tambah Harga Barang Baru\n");
        printf("3. Perbarui Harga Barang\n");
        printf("4. Hapus Data Barang\n");
        printf("5. Cari Harga Tertinggi\n");
        printf("6. Cari Harga Terendah\n");
        printf("7. Keluar\n");
        printf("Pilih operasi: ");
        scanf(" %d", &pilihan);

        switch (pilihan)
        {
            case 1:
                tampilkanBarang(harga, size);
                break;
            case 2:
                printf("Masukkan harga barang baru: Rp");
                scanf(" %d", &hargaBaru);
                tambahBarang(harga, &size, MAX, hargaBaru);
                break;
            case 3:
                printf("Masukkan posisi barang yang ingin diupdate: ");
                scanf(" %d", &pos);
                printf("Masukkan harga baru: Rp");
                scanf(" %d", &hargaBaru);
                perbaruiBarang(harga, size, pos - 1, hargaBaru);
                break;
            case 4:
                printf("Masukkan posisi barang yang ingin dihapus: ");
                scanf(" %d", &pos);
                hapusBarang(harga, &size, pos - 1);
                break;
            case 5:
                if (size > 0)
                    printf("Harga tertinggi adalah: Rp%d\n", cariHargaTertinggi(harga, size));
                else
                    printf("Inventori kosong\n");
                break;
            case 6:
                if (size > 0)
                    printf("Harga terendah adalah: Rp%d\n", cariHargaTerendah(harga, size));
                else
                    printf("Inventori kosong\n");
                break;
            case 7:
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    }
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Sistem Inventori Barang\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tampilkanBarang(int arr[], int size)
{
    if (size == 0)
    {
        printf("Inventori kosong\n");
        return;
    }

    for (int i = 0; i < size; i++)
        printf("Barang ke-%d: Rp%d\n", i + 1, arr[i]);
}

void tambahBarang(int arr[], int *size, int capacity, int hargaBaru)
{
    if (*size >= capacity)
    {
        printf("Kapasitas inventori penuh! Tidak dapat menambahkan barang\n");
        return;
    }

    arr[*size] = hargaBaru;
    (*size)++;
    printf("Barang berhasil ditambahkan\n");
}

void perbaruiBarang(int arr[], int size, int pos, int hargaBaru)
{
    if (pos < 0 || pos >= size)
    {
        printf("Posisi tidak valid!\n");
        return;
    }

    arr[pos] = hargaBaru;
    printf("Harga barang ke-%d telah diperbarui menjadi Rp%d\n", pos + 1, arr[pos]);
}

void hapusBarang(int arr[], int *size, int pos)
{
    if (pos < 0 || pos >= *size)
    {
        printf("Posisi tidak valid!\n");
        return;
    }

    for (int i = pos; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
    printf("Barang ke-%d berhasil dihapus\n", pos + 1);
}

int cariHargaTerendah(int arr[], int size)
{
    if (size == 0)
        return 0;

    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int cariHargaTertinggi(int arr[], int size)
{
    if (size == 0)
        return 0;

    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
