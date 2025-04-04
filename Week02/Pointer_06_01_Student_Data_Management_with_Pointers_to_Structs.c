// Preprocessors
#include <stdio.h>
#include <stdlib.h>

// Deklarasi fungsi-fungsi
void judul();

typedef struct
{
    int   id;
    char  nama[50];
    float nilai;
} Mahasiswa;

void tambahMahasiswa(Mahasiswa **mhs, int *jumlah, int id, const char *nama, float nilai);
void tampilkanMahasiswa(Mahasiswa **mhs, int jumlah);
void updateMahasiswa(Mahasiswa **mhs, int jumlah, int id, const char *nama, float nilai);
void hapusMahasiswa(Mahasiswa **mhs, int *jumlah, int id);

int main()
{
    // Tampilkan judul program
    judul();

    // Deklarasi variabel
    Mahasiswa *mhs[100];
    int        jumlah = 0;

    while (1)
    {
        printf("\nMenu Manajemen Data Mahasiswa:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Tampilkan Mahasiswa\n");
        printf("3. Update Mahasiswa\n");
        printf("4. Hapus Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");

        int   pilihan;
        int   id;
        char  nama[50];
        float nilai;

        scanf(" %d", &pilihan);
        if (pilihan == 5)
            break;

        switch (pilihan)
        {
            case 1:
                printf("Masukkan ID: ");
                scanf(" %d", &id);
                printf("Masukkan nama: ");
                scanf(" %49[^\n]s", nama);
                printf("Masukkan nilai: ");
                scanf(" %f", &nilai);
                tambahMahasiswa(mhs, &jumlah, id, nama, nilai);
                break;
            case 2:
                tampilkanMahasiswa(mhs, jumlah);
                break;
            case 3:
                printf("Masukkan ID mahasiswa yang ingin diupdate: ");
                scanf(" %d", &id);
                printf("Masukkan nama baru: ");
                scanf(" %49[^\n]s", nama);
                printf("Masukkan nilai baru: ");
                scanf(" %f", &nilai);
                updateMahasiswa(mhs, jumlah, id, nama, nilai);
                break;
            case 4:
                printf("Masukkan ID yang ingin dihapus: ");
                scanf(" %d", &id);
                hapusMahasiswa(mhs, &jumlah, id);
                break;
            default:
                printf("Pilhan tidak valid!");
                break;
        }
    }

    // Bebaskan memori semua mahasiswa
    for (int i = 0; i < jumlah; i++)
        free(mhs[i]);

    return 0;
}

// Definisi fungsi-fungsi
void tambahMahasiswa(Mahasiswa **mhs, int *jumlah, int id, const char *nama, float nilai)
{
    // Alokasi memori mahasiswa baru
    mhs[*jumlah] = (Mahasiswa *)malloc(sizeof(Mahasiswa));

    mhs[*jumlah]->id = id;
    snprintf(mhs[*jumlah]->nama, sizeof(mhs[*jumlah]->nama), "%s", nama);
    mhs[*jumlah]->nilai = nilai;

    (*jumlah)++;
    printf("Mahasiswa berhasil ditambahkan!\n");
}

void tampilkanMahasiswa(Mahasiswa **mhs, int jumlah)
{
    printf("Data Mahasiswa:\n");
    for (int i = 0; i < jumlah; i++)
    {
        printf("ID: %d, Nama: %s, Nilai: %.2f\n", mhs[i]->id, mhs[i]->nama, mhs[i]->nilai);
    }
}

void updateMahasiswa(Mahasiswa **mhs, int jumlah, int id, const char *nama, float nilai)
{
    for (int i = 0; i < jumlah; i++)
    {
        if (mhs[i]->id == id)
        {
            snprintf(mhs[i]->nama, sizeof(mhs[i]->nama), "%s", nama);
            mhs[i]->nilai = nilai;
            printf("Data mahasiswa dengan ID %d berhasil diperbarui!\n", id);
            return;
        }
    }
    printf("Mahasiswa dengan ID %d tidak ditemukan!\n", id);
}

void hapusMahasiswa(Mahasiswa **mhs, int *jumlah, int id)
{
    for (int i = 0; i < *jumlah; i++)
    {
        if (mhs[i]->id == id)
        {
            // Bebaskan memori mahasiswa
            free(mhs[i]);
            for (int j = i; j < *jumlah - 1; j++)
                mhs[j] = mhs[j + 1];

            (*jumlah)--;
            printf("Mahasiswa dengan ID %d berhasil dihapus!\n", id);
            return;
        }
    }
    printf("Mahasiswa dengan ID %d tidak ditemukan!\n", id);
}

void judul()
{
    printf("Program Manajemen Data Mahasiswa Menggunakan Pointer ke Struct\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
