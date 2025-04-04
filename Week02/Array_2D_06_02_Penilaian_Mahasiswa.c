// Preprocessors
#include <stdio.h>

#define MAX_MHS   10
#define MAX_MAPEL 5

// Deklarasi fungsi-fungsi
void tampilkanNilai(int nilai[][MAX_MAPEL], int jumlahMahasiswa, int jumlahMapel);
void tambahNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel, int nilaiBaru);
void bacaNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel);
void updateNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel, int nilaiBaru);
void hapusNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel);
void hitungRataRata(int nilai[][MAX_MAPEL], int jumlahMahasiswa, int jumlahMapel);
void judul();

int main()
{
    // Tampilkan judul program
    judul();

    int nilai[MAX_MHS][MAX_MAPEL] = {0};
    int jumlahMahasiswa           = 3;
    int jumlahMapel               = 4;

    while (1)
    {
        printf("\nMenu Sistem Penilaian Mahasiswa:\n");
        printf("1. Tampilkan Nilai\n");
        printf("2. Tambahkan Nilai\n");
        printf("3. Baca Nilai\n");
        printf("4. Update Nilai\n");
        printf("5. Hapus Nilai\n");
        printf("6. Hitung Rata-Rata Nilai\n");
        printf("7. Keluar\n");
        printf("Pilih Operasi: ");
        int pilihan;
        scanf(" %d", &pilihan);

        if (pilihan == 7)
            break;

        int mahasiswa;
        int mapel;
        int nilaiBaru;

        switch (pilihan)
        {
            case 1:
                tampilkanNilai(nilai, jumlahMahasiswa, jumlahMapel);
                break;
            case 2:
                printf("Masukkan Mahasiswa (0-%d) dan Mata Pelajaran (0-%d): ", jumlahMahasiswa - 1, jumlahMapel - 1);
                scanf(" %d %d", &mahasiswa, &mapel);
                printf("Masukkan nilai baru: ");
                scanf(" %d", &nilaiBaru);
                tambahNilai(nilai, mahasiswa, mapel, jumlahMahasiswa, jumlahMapel, nilaiBaru);
                break;
            case 3:
                printf("Masukkan Mahasiswa (0-%d) dan Mata Pelajaran (0-%d): ", jumlahMahasiswa - 1, jumlahMapel - 1);
                scanf(" %d %d", &mahasiswa, &mapel);
                bacaNilai(nilai, mahasiswa, mapel, jumlahMahasiswa, jumlahMapel);
                break;
            case 4:
                printf("Masukkan Mahasiswa (0-%d) dan Mata Pelajaran (0-%d): ", jumlahMahasiswa - 1, jumlahMapel - 1);
                scanf(" %d %d", &mahasiswa, &mapel);
                printf("Masukkan nilai baru: ");
                scanf(" %d", &nilaiBaru);
                updateNilai(nilai, mahasiswa, mapel, jumlahMahasiswa, jumlahMapel, nilaiBaru);
                break;
            case 5:
                printf("Masukkan Mahasiswa (0-%d) dan Mata Pelajaran (0-%d): ", jumlahMahasiswa - 1, jumlahMapel - 1);
                scanf(" %d %d", &mahasiswa, &mapel);
                hapusNilai(nilai, mahasiswa, mapel, jumlahMahasiswa, jumlahMapel);
                break;
            case 6:
                hitungRataRata(nilai, jumlahMahasiswa, jumlahMapel);
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    }

    return 0;
}

// Definisi fungsi-fungsi
void tampilkanNilai(int nilai[][MAX_MAPEL], int jumlahMahasiswa, int jumlahMapel)
{
    printf("Nilai Mahasiswa:\n");
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        printf("Mahasiswa ke-%d: ", i);
        for (int j = 0; j < jumlahMapel; j++)
            printf("%d ", nilai[i][j]);
        printf("\n");
    }
}

void tambahNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel, int nilaiBaru)
{
    if (mahasiswa < 0 || mahasiswa >= jumlahMahasiswa || mapel < 0 || mapel >= jumlahMapel)
    {
        printf("Posisi tidak valid! Tidak dapat menambahkan nilai.\n");
        return;
    }

    nilai[mahasiswa][mapel] = nilaiBaru;
    printf("Nilai berhasil ditambahkan untuk Mahasiswa ke-%d pada Mata Pelajaran ke-%d.\n",
           mahasiswa + 1, mapel + 1);
}

void bacaNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel)
{
    if (mahasiswa < 0 || mahasiswa >= jumlahMahasiswa || mapel < 0 || mapel >= jumlahMapel)
    {
        printf("Posisi tidak valid! Tidak dapat membaca nilai.\n");
        return;
    }

    printf("Nilai Mahasiswa ke-%d pada Mata Pelajaran ke-%d adalah: %d", mahasiswa + 1, mapel + 1, nilai[mahasiswa][mapel]);
}

void updateNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel, int nilaiBaru)
{
    if (mahasiswa < 0 || mahasiswa >= jumlahMahasiswa || mapel < 0 || mapel >= jumlahMapel)
    {
        printf("Posisi tidak valid! Tidak dapat memperbarui nilai.\n");
        return;
    }

    nilai[mahasiswa][mapel] = nilaiBaru;
    printf("Nilai Mahasiswa ke-%d pada Mata Pelajaran ke-%d telah diperbarui menjadi %d.\n",
           mahasiswa + 1, mapel + 1, nilaiBaru);
}

void hapusNilai(int nilai[][MAX_MAPEL], int mahasiswa, int mapel, int jumlahMahasiswa, int jumlahMapel)
{
    if (mahasiswa < 0 || mahasiswa >= jumlahMahasiswa || mapel < 0 || mapel >= jumlahMapel)
    {
        printf("Posisi tidak valid! Tidak dapat menghapus nilai.\n");
        return;
    }

    nilai[mahasiswa][mapel] = 0;
    printf("Nilai Mahasiswa ke-%d pada Mata Pelajaran ke-%d telah dihapus.\n",
           mahasiswa + 1, mapel + 1);
}

void hitungRataRata(int nilai[][MAX_MAPEL], int jumlahMahasiswa, int jumlahMapel)
{
    printf("Rata-rata Nilai Mahasiswa:\n");
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        int total = 0;
        for (int j = 0; j < jumlahMapel; j++)
            total += nilai[i][j];

        printf("Mahasiswa ke-%d: %.2f\n", i + 1, (float)total / jumlahMapel);
    }

    printf("Rata-rata per Mata Pelajaran:\n");
    for (int j = 0; j < jumlahMapel; j++)
    {
        int total = 0;
        for (int i = 0; i < jumlahMahasiswa; i++)
            total += nilai[i][j];

        printf("Mata Pelajaran ke-%d: %.2f\n", j + 1, (float)total / jumlahMahasiswa);
    }
}

void judul()
{
    printf("Program Sistem Penilaian Siswa\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
