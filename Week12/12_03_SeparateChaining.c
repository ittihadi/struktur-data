#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashEntry
{
    int               key;
    char              value[50];
    struct HashEntry *next;
} HashEntry;

void        judul();
void        init_hash_table(HashEntry *hash_table[]);
void        insert_chaining(HashEntry *hash_table[], int key, const char *value);
const char *search_chaining(HashEntry *hash_table[], int key);
int         hash_division(int key, int table_size);

int main()
{
    judul();
    HashEntry *hash_table[TABLE_SIZE];

    init_hash_table(hash_table);

    int key = 12512;
    printf("Memasukkan data dengan key %d\n", key);
    insert_chaining(hash_table, key, "Halo!");
    printf("\n");

    int key2 = 11202;     // Key akan kolisi

    printf("Memasukkan data dengan key %d\n", key);
    insert_chaining(hash_table, key2, "Hai!");
    printf("\n");

    printf("Mengakses data dengan key %d\n", key);
    const char *res = search_chaining(hash_table, key);

    if (res == NULL)
        printf("Data tidak ditemukan\n");
    else
        printf("Data ditemukan: %s\n", res);

    printf("Mengakses data dengan key %d\n", key2);

    res = search_chaining(hash_table, key2);
    if (res == NULL)
        printf("Data tidak ditemukan\n");
    else
        printf("Data ditemukan: %s\n", res);

    return 0;
}

void judul()
{
    printf("Program Implementasi Penanganan Kolisi dengan Separate Chaining\n");
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

void init_hash_table(HashEntry *hash_table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void insert_chaining(HashEntry *hash_table[], int key, const char *value)
{
    int        index    = hash_division(key, TABLE_SIZE);
    HashEntry *new_node = malloc(sizeof(HashEntry));
    new_node->key       = key;
    strcpy(new_node->value, value);
    new_node->next    = hash_table[index];
    hash_table[index] = new_node;
}

const char *search_chaining(HashEntry *hash_table[], int key)
{
    int        index   = hash_division(key, TABLE_SIZE);
    HashEntry *current = hash_table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}
