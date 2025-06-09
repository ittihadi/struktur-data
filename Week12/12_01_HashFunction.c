#include <stdio.h>

void          judul();
int           hash_division(int key, int table_size);
unsigned long hash_string(const char *str);

int main()
{
    judul();
    // Contoh penggunaan
    int key        = 12345;
    int table_size = 100;
    printf("Hash divisi dari %d: %d\n", key, hash_division(key, table_size));

    const char *text = "Hello";
    printf("Hash string '%s': %lu\n", text, hash_string(text));

    return 0;
}

void judul()
{
    printf("Program Implementasi Fungsi Hash\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

// 1. Fungsi Hash Divisi untuk integer
int hash_division(int key, int table_size)
{
    return key % table_size;
}

// 2. Fungsi Hash untuk string (djb2)
unsigned long hash_string(const char *str)
{
    unsigned long hash = 5381;
    int           c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;     // hash * 33 + c
    return hash;
}
