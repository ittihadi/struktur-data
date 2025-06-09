#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE       1000
#define FINGERPRINT_SIZE 65     // SHA-256 = 64 chars + null

typedef struct
{
    char fingerprint[FINGERPRINT_SIZE];
    char doc_name[50];
} DocEntry;

void         judul();
unsigned int hash(const char* fp);
void         check_plagiarism(DocEntry table[], const char* doc_name, const char* fingerprint);
void         generate_fingerprint(const char* text, char* fingerprint);

int main()
{
    judul();

    DocEntry fingerprint_table[TABLE_SIZE] = {0};

    // Skenario 1: Tambah dokumen
    char doc1_fp[FINGERPRINT_SIZE], doc2_fp[FINGERPRINT_SIZE];
    generate_fingerprint("This is document one content", doc1_fp);
    generate_fingerprint("This is document two content", doc2_fp);

    check_plagiarism(fingerprint_table, "doc1.txt", doc1_fp);
    check_plagiarism(fingerprint_table, "doc2.txt", doc2_fp);

    // Skenario 2: Cek dokumen mirip
    char doc3_fp[FINGERPRINT_SIZE];
    generate_fingerprint("This is document one content", doc3_fp);     // Konten sama dengan doc1

    printf("\nMemeriksa dokumen baru...\n");
    check_plagiarism(fingerprint_table, "doc3_copy.txt", doc3_fp);

    // Skenario 3: Cek dokumen berbeda
    char doc4_fp[FINGERPRINT_SIZE];
    generate_fingerprint("Completely different content", doc4_fp);

    printf("\nMemeriksa dokumen baru...\n");
    check_plagiarism(fingerprint_table, "doc4.txt", doc4_fp);

    return 0;
}

void judul()
{
    printf("Program Sistem Deteksi Plagiarisme Dokumen\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

unsigned int hash(const char* fp)
{
    unsigned long hash_val = 0;
    for (int i = 0; i < 8; i++)
    {
        hash_val = (hash_val << 4) + fp[i];
    }
    return hash_val % TABLE_SIZE;
}

void check_plagiarism(DocEntry table[], const char* doc_name, const char* fingerprint)
{
    unsigned int index          = hash(fingerprint);
    int          original_index = index;

    do
    {
        // Jika slot kosong
        if (table[index].fingerprint[0] == '\0')
        {
            strcpy(table[index].fingerprint, fingerprint);
            strcpy(table[index].doc_name, doc_name);
            printf("Dokumen %s ditambahkan ke sistem\n", doc_name);
            return;
        }

        // Jika ditemukan fingerprint sama
        if (strcmp(table[index].fingerprint, fingerprint) == 0)
        {
            printf("PERINGATAN: %s mirip dengan %s (Kemiripan 100%%)\n",
                   doc_name, table[index].doc_name);
            return;
        }

        index = (index + 1) % TABLE_SIZE;
    } while (index != original_index);

    printf("Error: Tabel fingerprint penuh!\n");
}

void generate_fingerprint(const char* text, char* fingerprint)
{
    // Simulasi SHA-256 (dalam implementasi nyata gunakan OpenSSL)
    unsigned long hash = 5381;
    int           c;
    int           i = 0;
    while ((c = *text++) && i < 64)
    {
        hash             = ((hash << 5) + hash) + c;
        fingerprint[i++] = (hash % 26) + 'a';     // Convert to a-z
    }
    fingerprint[64] = '\0';
}
