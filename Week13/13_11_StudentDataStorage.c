#include <stdio.h>
#include <string.h>

typedef struct
{
    char  NIM[10];
    char  Nama[50];
    float IPK;
} Mahasiswa;

void judul();
void tambahData(const char* nama_file);
void bacaData(const char* nama_file);
void cariMahasiswa(const char* nama_file, const char* NIM);

int main()
{
    judul();

    const char* nama_file = "Week13/mahasiswa.txt";
    int         pilihan;
    do
    {
        printf("\nMenu:\n1. Tambah Data\n2. Baca Data\n3. Cari Mahasiswa\n4. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            tambahData(nama_file);
        }
        else if (pilihan == 2)
        {
            bacaData(nama_file);
        }
        else if (pilihan == 3)
        {
            char NIM[10];
            printf("Masukkan NIM yang dicari: ");
            scanf("%s", NIM);
            cariMahasiswa(nama_file, NIM);
        }
    } while (pilihan != 4);
    return 0;
}

void judul()
{
    printf("Program Penyimpanan Data Mahasiswa\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tambahData(const char* nama_file)
{
    FILE* file = fopen(nama_file, "a");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Mahasiswa m;
    printf("Masukkan NIM: ");
    scanf("%s", m.NIM);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", m.Nama);
    printf("Masukkan IPK: ");
    scanf("%f", &m.IPK);
    fprintf(file, "%s-%s-%.2f\n", m.NIM, m.Nama, m.IPK);
    fclose(file);
    printf("Data berhasil ditambahkan.\n");
}

void bacaData(const char* nama_file)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Mahasiswa m;
    printf("Data Mahasiswa:\n");
    while (fscanf(file, "%[^-]-%[^-]-%f\n", m.NIM, m.Nama, &m.IPK) != EOF)
    {
        printf("NIM: %s, Nama: %s, IPK: %.2f\n", m.NIM, m.Nama, m.IPK);
    }
    fclose(file);
}

void cariMahasiswa(const char* nama_file, const char* NIM)
{
    FILE* file = fopen(nama_file, "r");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    Mahasiswa m;
    while (fscanf(file, "%[^-]-%[^-]-%f\n", m.NIM, m.Nama, &m.IPK) != EOF)
    {
        if (strcmp(m.NIM, NIM) == 0)
        {
            printf("Data Ditemukan: NIM: %s, Nama: %s, IPK: %.2f\n", m.NIM, m.Nama, m.IPK);
            fclose(file);
            return;
        }
    }
    printf("Data tidak ditemukan.\n");
    fclose(file);
}
