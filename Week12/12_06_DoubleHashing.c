#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct
{
    int  key;
    char value[50];
} HashEntry;

void        judul();
void        init_hash_table(HashEntry *hash_table);
void        insert_double(HashEntry *hash_table, int key, const char *value);
const char *search_double(HashEntry *hash_table, int key);
int         hash_division(int key, int table_size);
int         hash2(int key);

int main()
{
    judul();
    HashEntry hash_table[TABLE_SIZE];

    init_hash_table(hash_table);

    int key = 12512;
    printf("Memasukkan data dengan key %d\n", key);
    insert_double(hash_table, key, "Halo!");
    printf("\n");

    int key2 = 9202;
    printf("Memasukkan data dengan key %d\n", key2);
    insert_double(hash_table, key2, "Hai!");
    printf("\n");

    printf("Mengakses data dengan key %d\n", key);
    const char *res = search_double(hash_table, key);

    if (res == NULL)
        printf("Data tidak ditemukan\n");
    else
        printf("Data ditemukan: %s\n", res);

    printf("Mengakses data dengan key %d\n", key2);
    res = search_double(hash_table, key2);

    if (res == NULL)
        printf("Data tidak ditemukan\n");
    else
        printf("Data ditemukan: %s\n", res);

    return 0;
}

void judul()
{
    printf("Program Implementasi Penanganan Kolisi dengan Double Hashing\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

int hash_division(int key, int table_size)
{
    return key % table_size;
}

void init_hash_table(HashEntry *hash_table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i].key = -1;     // Menandakan slot kosong
    }
}

void insert_double(HashEntry *hash_table, int key, const char *value)
{
    int index          = hash_division(key, TABLE_SIZE);
    int original_index = index;
    int i              = 1;
    int step           = hash2(key);

    while (hash_table[index].key != -1 && hash_table[index].key != key)
    {
        index = (original_index + i * step) % TABLE_SIZE;
        i++;
        if (i > TABLE_SIZE)
        {
            printf("Tabel penuh!\n");
            return;
        }
    }

    hash_table[index].key = key;
    strcpy(hash_table[index].value, value);
}

const char *search_double(HashEntry *hash_table, int key)
{
    int index          = hash_division(key, TABLE_SIZE);
    int original_index = index;
    int i              = 1;
    int step           = hash2(key);

    while (hash_table[index].key != -1)
    {
        if (hash_table[index].key == key)
        {
            return hash_table[index].value;
        }
        index = (original_index + i * step) % TABLE_SIZE;
        i++;
        if (i > TABLE_SIZE)
        {
            break;
        }
    }

    return NULL;
}

int hash2(int key)
{
    return 7 - (key % 7);
}
