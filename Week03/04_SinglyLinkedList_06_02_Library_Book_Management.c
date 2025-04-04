// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char         kode[10];
    char         judul[100];
    char         penulis[50];
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahBuku(Node **head, const char *kode, const char *judul, const char *penulis);
void tampilkanBuku(Node *head);
void hapusBuku(Node **head, const char *kode);
void cariBuku(Node *head, const char *kode);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong
    while (1)
    {
        printf("\nMenu Pengelola Data Buku:\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Cari Buku\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5) break;

        char kode[10];
        char judul[100];
        char penulis[50];

        switch (pilihan)
        {
            case 1:
                printf("Masukkan Kode Buku: ");
                scanf(" %9[^\n]s", kode);
                printf("Masukkan Judul Buku: ");
                scanf(" %99[^\n]s", judul);
                printf("Masukkan Penulis Buku: ");
                scanf(" %49[^\n]s", penulis);
                tambahBuku(&head, kode, judul, penulis);
                break;
            case 2:
                tampilkanBuku(head);
                break;
            case 3:
                printf("Masukkan Kode Buku yang ingin Dihapus: ");
                scanf(" %9[^\n]s", kode);
                hapusBuku(&head, kode);
                break;
            case 4:
                printf("Masukkan Kode Buku yang ingin Dicari: ");
                scanf(" %9[^\n]s", kode);
                cariBuku(head, kode);
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    // Bebaskan memori sisa
    while (head != NULL)
    {
        Node *temp = head;
        head       = head->next;
        free(temp);
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahBuku(Node **head, const char *kode, const char *judul, const char *penulis)
{
    // Alokasi node antrian baru dan isi data
    Node *newNode = (Node *)malloc(sizeof(Node));
    snprintf(newNode->kode, sizeof(newNode->kode), "%s", kode);
    snprintf(newNode->judul, sizeof(newNode->judul), "%s", judul);
    snprintf(newNode->penulis, sizeof(newNode->penulis), "%s", penulis);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        // Traversal ke akhir list
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Pasang Buku baru di akhir list
        current->next = newNode;
    }

    printf("Buku dengan kode %s berhasil ditambahkan.\n", kode);
}

void tampilkanBuku(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada buku dalam daftar.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Buku:\n");
    while (current != NULL)
    {
        printf("Kode: %s, Judul: %s, Penulis: %s\n",
               current->kode, current->judul, current->penulis);
        current = current->next;
    }
}

void hapusBuku(Node **head, const char *kode)
{
    if (*head == NULL)
    {
        printf("Tidak ada buku dalam daftar untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    Node *prev    = NULL;

    if (strcmp(current->kode, kode) == 0)
    {
        *head = current->next;
        free(current);
        printf("Buku dengan kode %s berhasil dihapus.\n", kode);
        return;
    }

    while (current != NULL && strcmp(current->kode, kode) != 0)
    {
        prev    = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Buku dengan kode %s tidak ditemukan.\n", kode);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Buku dengan kode %s berhasil dihapus.\n", kode);
}

void cariBuku(Node *head, const char *kode)
{
    Node *current = head;

    while (current != NULL)
    {
        if (strcmp(current->kode, kode) == 0)
        {
            printf("Buku ditemukan! Kode: %s, Judul: %s, Penulis: %s\n",
                   current->kode, current->judul, current->penulis);
            return;
        }
        current = current->next;
    }
    printf("Buku dengan kode %s tidak ditemukan.\n", kode);
}

void judul()
{
    printf("Program Pengelolaan Data Buku di Perpustakaan\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
