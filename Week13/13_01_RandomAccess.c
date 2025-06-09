#include <stdio.h>

void judul();
void updateData(const char* nama_file, long posisi, int data_baru);

int main()
{
    judul();

    const char* nama_file = "Week13/data.bin";
    updateData(nama_file, 2, 42);      // Update data pada posisi ke-2
    updateData(nama_file, 0, 210);     // Update data pada posisi ke-0
    return 0;
}

void judul()
{
    printf("Program Random Access File\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void updateData(const char* nama_file, long posisi, int data_baru)
{
    FILE* file = fopen(nama_file, "w+");
    if (!file)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    fseek(file, posisi * sizeof(int), SEEK_SET);
    fwrite(&data_baru, sizeof(int), 1, file);
    fclose(file);
    printf("Data berhasil diperbarui.\n");
}
