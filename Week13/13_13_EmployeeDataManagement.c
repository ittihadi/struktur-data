#include <stdio.h>

typedef struct
{
    int   id;
    char  nama[50];
    float gaji;
} Karyawan;

void judul();
void tambahKaryawan(const char* nama_file);
void bacaKaryawan(const char* nama_file);
void cariKaryawan(const char* nama_file, int id_karyawan);

int main()
{
    judul();

    const char* nama_file = "Week13/karyawan.txt";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Karyawan\n2. Lihat Semua Karyawan\n3. Cari Karyawan\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahKaryawan(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaKaryawan(nama_file);
        }
        else if (pilihan == 3)
        {
            int id;
            printf("Masukkan ID Karyawan yang dicari: ");
            scanf("%d", &id);
            cariKaryawan(nama_file, id);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Manajemen Data Karyawan dengan File Sequential\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahKaryawan(const char* nama_file)
{
    FILE* file = fopen(nama_file, "a");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Karyawan k;
    printf("Masukkan ID Karyawan: ");
    scanf("%d", &k.id);
    printf("Masukkan Nama Karyawan: ");
    scanf(" %[^\n]", k.nama);
    printf("Masukkan Gaji Karyawan: ");
    scanf("%f", &k.gaji);
    fprintf(file, "%d-%s-%.2f\n", k.id, k.nama, k.gaji);
    fclose(file);
    printf("Data karyawan berhasil ditambahkan.\n");
}

void bacaKaryawan(const char* nama_file)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Karyawan k;
    printf("Data Karyawan:\n");
    while (fscanf(file, "%d-%[^-]-%f", &k.id, k.nama, &k.gaji) != EOF)
    {
        printf("ID: %d, Nama: %s, Gaji: %.2f\n", k.id, k.nama, k.gaji);
    }
    fclose(file);
}

void cariKaryawan(const char* nama_file, int id_karyawan)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Karyawan k;
    while (fscanf(file, "%d-%[^-]-%f", &k.id, k.nama, &k.gaji) != EOF)
    {
        if (k.id == id_karyawan)
        {
            printf("Data Ditemukan: ID: %d, Nama: %s, Gaji: %.2f\n", k.id, k.nama, k.gaji);
            fclose(file);
            return;
        }
    }
    printf("Data tidak ditemukan.\n");
    fclose(file);
}
