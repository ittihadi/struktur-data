// Preprocessors
#include <stdio.h>

#define MAX 100

// Deklarasi Fungsi-fungsi
void tampilkanNilai(int arr[], int size);
void tambahNilai(int arr[], int *size, int capacity, int nilai);
void updateNilai(int arr[], int size, int pos, int nilaiBaru);
void hapusNilai(int arr[], int *size, int pos);
int  cariNilaiMin(int arr[], int size);
int  cariNilaiMax(int arr[], int size);

void judul();

int main()
{
    // Tampilkan judul
    judul();

    int nilai[MAX];
    int size      = 0;
    int pilihan   = 0;
    int nilaiBaru = 0;
    int pos       = 0;

    while (1)
    {
        printf("\nMenu Pengelolaan Nilai Siswa:\n");
        printf("1. Tampilkan Nilai\n");
        printf("2. Tambah Nilai\n");
        printf("3. Update Nilai\n");
        printf("4. Hapus Nilai\n");
        printf("5. Cari Nilai Terbesar\n");
        printf("6. Cari Nilai Terkecil\n");
        printf("7. Keluar\n");
        printf("Pilih operasi: ");
        scanf(" %d", &pilihan);

        switch (pilihan)
        {
            case 1:
                tampilkanNilai(nilai, size);
                break;
            case 2:
                printf("Masukkan nilai siswa baru: ");
                scanf(" %d", &nilaiBaru);
                tambahNilai(nilai, &size, MAX, nilaiBaru);
                break;
            case 3:
                printf("Masukkan posisi nilai yang ingin diupdate: ");
                if (size > 0)
                    printf("(1-%d)", size);
                printf(": ");

                scanf(" %d", &pos);
                printf("Masukkan nilai baru: ");
                scanf(" %d", &nilaiBaru);
                updateNilai(nilai, size, pos - 1, nilaiBaru);
                break;
            case 4:
                printf("Masukkan posisi nilai yang ingin dihapus ");
                if (size > 0)
                    printf("(1-%d)", size);
                printf(": ");

                scanf(" %d", &pos);
                hapusNilai(nilai, &size, pos - 1);
                break;
            case 5:
                if (size == 0)
                    printf("Nilai siswa kosong\n");
                else
                    printf("Nilai siswa terbesar adalah: %d\n", cariNilaiMax(nilai, size));
                break;
            case 6:
                if (size == 0)
                    printf("Nilai siswa kosong\n");
                else
                    printf("Nilai siswa terkecil adalah: %d\n", cariNilaiMin(nilai, size));
                break;
            case 7:
                return 0;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    }
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Pengelolaan Nilai Siswa\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void tampilkanNilai(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("Siswa ke-%d: %d\n", i + 1, arr[i]);
}

void tambahNilai(int arr[], int *size, int capacity, int nilai)
{
    if (*size >= capacity)
    {
        printf("Kapasitas penuh! Tidak dapat menambahkan nilai\n");
        return;
    }

    arr[*size] = nilai;
    (*size)++;
}

void updateNilai(int arr[], int size, int pos, int nilaiBaru)
{
    if (pos < 0 || pos >= size)
    {
        printf("Posisi tidak valid!\n");
        return;
    }

    arr[pos] = nilaiBaru;
}

void hapusNilai(int arr[], int *size, int pos)
{
    if (pos < 0 || pos > *size)
    {
        printf("Posisi tidak valid!\n");
        return;
    }

    for (int i = pos; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    (*size)--;
}

int cariNilaiMin(int arr[], int size)
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

int cariNilaiMax(int arr[], int size)
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
