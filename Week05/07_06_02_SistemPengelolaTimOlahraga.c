// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char nama[50];
    int  nomorPunggung;
    char posisi[30];

    struct Node *prev;
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahPemain(Node **head, Node **tail,
                  const char *nama, int nomorPunggung,
                  const char *posisi);
void tampilkanPemain(Node *head);
void cariPemain(Node *head, int nomorPunggung);
void hapusPemain(Node **head, Node **tail, int nomorPunggung);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;
    Node *tail = NULL;

    while (1)
    {
        printf("\nMenu Sistem Manajemen Playlist Musik:\n");
        printf("1. Tambah Pemain ke Tim\n");
        printf("2. Tampilkan Daftar Pemain\n");
        printf("3. Cari Pemain Berdasarkan Nomor Punggung\n");
        printf("4. Hapus pemain\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5) break;

        int  nomorPunggung;
        char nama[50];
        char posisi[30];
        int  indeks;

        switch (pilihan)
        {
            case 1:
                printf("Masukkan Nama Pemain Baru: ");
                scanf(" %49[^\n]s", nama);
                printf("Masukkan Nomor Punggung Pemain Baru: ");
                scanf(" %d", &nomorPunggung);
                printf("Masukkan Posisi Bermain Pemain Baru: ");
                scanf(" %29[^\n]s", posisi);
                tambahPemain(&head, &tail, nama, nomorPunggung, posisi);
                break;
            case 2:
                tampilkanPemain(head);
                break;
            case 3:
                printf("Masukkan Nomor Punggung Pemain yang ingin Dicari: ");
                scanf(" %d", &nomorPunggung);
                cariPemain(head, nomorPunggung);
                break;
            case 4:
                printf("Masukkan Nomor Punggung Pemain yang ingin Dihapus: ");
                scanf(" %d", &nomorPunggung);
                hapusPemain(&head, &tail, nomorPunggung);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    // Bebaskan sisa memori
    while (head != NULL)
    {
        hapusPemain(&head, &tail, head->nomorPunggung);
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahPemain(Node **head, Node **tail,
                  const char *nama, int nomorPunggung,
                  const char *posisi)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->nama, nama, sizeof(newNode->nama));
    strncpy(newNode->posisi, posisi, sizeof(newNode->posisi));
    newNode->nomorPunggung = nomorPunggung;
    newNode->prev          = NULL;
    newNode->next          = NULL;

    if (*head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        *head         = newNode;
        *tail         = newNode;
    }
    else
    {
        newNode->prev = *tail;
        newNode->next = *head;
        (*tail)->next = newNode;
        (*head)->prev = newNode;
        *tail         = newNode;
    }

    printf("Pemain '%s' dengan nomor punggung %d berhasil ditambahkan.\n",
           nama, nomorPunggung);
}

void tampilkanPemain(Node *head)
{
    if (head == NULL)
    {
        printf("Daftar pemain kosong.\n");
        return;
    }

    Node *current = head;
    printf("Daftar Pemain Tim:\n");
    do
    {
        printf("Nama: %s, Nomor Punggung: %d, Posisi: %s\n",
               current->nama, current->nomorPunggung, current->posisi);
        current = current->next;
    } while (current != head);
}

void cariPemain(Node *head, int nomorPunggung)
{
    if (head == NULL)
    {
        printf("Daftar pemain kosong.\n");
        return;
    }

    Node *current = head;
    do
    {
        if (current->nomorPunggung == nomorPunggung)
        {
            printf("Pemain ditemukan: Nama: %s, Nomor Punggung: %d, Posisi: %s\n",
                   current->nama, current->nomorPunggung, current->posisi);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Pemain dengan nomor punggung %d tidak ditemukan.\n", nomorPunggung);
}

void hapusPemain(Node **head, Node **tail, int nomorPunggung)
{
    if (*head == NULL)
    {
        printf("Daftar pemain kosong. Tidak ada pemain untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    do
    {
        if (current->nomorPunggung == nomorPunggung)
        {
            if (current->next == current)
            {
                *head = NULL;
                *tail = NULL;
            }
            else if (current == *head)
            {
                *head         = current->next;
                (*head)->prev = *tail;
                (*tail)->next = *head;
            }
            else if (current == *tail)
            {
                *tail         = current->prev;
                (*head)->prev = *tail;
                (*tail)->next = *head;
            }
            else
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
            }

            printf("Pemain '%s' dengan nomor punggung %d berhasil dihapus.\n",
                   current->nama, nomorPunggung);
            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Pemain dengan nomor punggung %d tidak ditemukan.\n", nomorPunggung);
}

void judul()
{
    printf("Program Sistem Pengelolaan Tim Olahraga\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
