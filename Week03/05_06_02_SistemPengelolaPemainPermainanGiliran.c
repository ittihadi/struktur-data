// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int  idPemain;
    char nama[50];

    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahPemain(Node **head, int idPemain, const char *nama);
void tampilkanPemain(Node *head);
void hapusPemain(Node **head, int idPemain);
void giliranPemainBerikutnya(Node **current);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head    = NULL;
    Node *current = NULL;
    while (1)
    {
        printf("\nMenu Sistem Pemesanan Makanan:\n");
        printf("1. Tambah Pemain\n");
        printf("2. Tampilkan Pemain\n");
        printf("3. Hapus Pemain\n");
        printf("4. Giliran Pemain Berikutnya\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5) break;

        int  idPemain;
        char namaPemain[50];

        switch (pilihan)
        {
            case 1:
                printf("Masukkan ID Pemain: ");
                scanf("%d", &idPemain);
                printf("Masukkan Nama Pemain: ");
                scanf(" %49[^\n]s", namaPemain);
                tambahPemain(&head, idPemain, namaPemain);
                if (current == NULL)
                {
                    current = head;
                }
                break;
            case 2:
                tampilkanPemain(head);
                break;
            case 3:
                printf("Masukkan ID Pemain yang ingin Dihapus: ");
                scanf("%d", &idPemain);
                hapusPemain(&head, idPemain);
                break;
            case 4:
                giliranPemainBerikutnya(&current);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    // Bebaskan sisa memori
    while (head != NULL)
    {
        hapusPemain(&head, head->idPemain);
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahPemain(Node **head, int idPemain, const char *nama)
{
    Node *newNode     = (Node *)malloc(sizeof(Node));
    newNode->idPemain = idPemain;
    strncpy(newNode->nama, nama, sizeof(newNode->nama));
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head         = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }

    printf("Pemain dengan ID %d berhasil ditambahkan.\n", idPemain);
}

void tampilkanPemain(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada pemain dalam permainan.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Pemain:\n");
    do
    {
        printf("ID: %d, Nama: %s\n", current->idPemain, current->nama);
        current = current->next;
    } while (current != head);
}

void hapusPemain(Node **head, int idPemain)
{
    if (*head == NULL)
    {
        printf("Tidak ada pemain untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    Node *prev    = NULL;

    // List berukuran 1
    if (current->idPemain == idPemain && current->next == *head)
    {
        free(current);
        *head = NULL;
        printf("Pemain dengan ID %d telah dihapus.\n", idPemain);
        return;
    }

    do
    {
        if (current->idPemain == idPemain)
        {
            // List berukuran lebih besar dari 1 dan head dihapus
            if (prev == NULL)
            {
                Node *temp = *head;
                while (current->next != *head)
                {
                    current = current->next;
                }
                current->next = (*head)->next;
                *head         = (*head)->next;
                free(temp);
            }
            else
            {
                prev->next = current->next;
                free(current);
            }
            printf("Pemain dengan ID %d telah dihapus.\n", idPemain);
            return;
        }
        prev    = current;
        current = current->next;
    } while (current != *head);

    printf("Pemain dengan ID %d tidak ditemukan.\n", idPemain);
}

void giliranPemainBerikutnya(Node **current)
{
    if (*current == NULL)
    {
        printf("Tidak ada pemain dalam permainan.\n");
        return;
    }

    printf("Giliran pemain: ID %d, Nama: %s.\n", (*current)->idPemain, (*current)->nama);
    *current = (*current)->next;
}

void judul()
{
    printf("Program Sistem Pengelolaan Daftar Pemain dalam Pemain Berbasis Giliran\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
