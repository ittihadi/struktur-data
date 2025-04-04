// Preprocessors
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          nomorKursi;
    bool         tersedia;     // True: kursi tersedia; False: kursi sudah dipesan
    struct Node *prev;
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahKursi(Node **head, Node **tail, int nomorKursi);
void tampilkanKursi(Node *head);
void pilihKursi(Node *head, int nomorKursi);
void hapusKursi(Node **head, Node **tail, int nomorKursi);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;
    Node *tail = NULL;

    while (1)
    {
        printf("\nMenu Sistem Manajemen Playlist Musik:\n");
        printf("1. Tambah Kursi ke Daftar\n");
        printf("2. Tampilkan Daftar Kursi\n");
        printf("3. Pilih Kursi dan Pesan\n");
        printf("4. Hapus Kursi dari Daftar\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5) break;

        int nomorKursi;
        int indeks;

        switch (pilihan)
        {
            case 1:
                printf("Masukkan Nomor Kursi Baru: ");
                scanf(" %d", &nomorKursi);
                tambahKursi(&head, &tail, nomorKursi);
                break;
            case 2:
                tampilkanKursi(head);
                break;
            case 3:
                printf("Masukkan Nomor Kursi yang Dipilih: ");
                scanf(" %d", &nomorKursi);
                pilihKursi(head, nomorKursi);
                break;
            case 4:
                printf("Masukkan Nomor Kursi yang ingin Dihapus: ");
                scanf(" %d", &nomorKursi);
                hapusKursi(&head, &tail, nomorKursi);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    // Bebaskan sisa memori
    while (head != NULL)
    {
        hapusKursi(&head, &tail, head->nomorKursi);
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahKursi(Node **head, Node **tail, int nomorKursi)
{
    Node *newNode       = (Node *)malloc(sizeof(Node));
    newNode->nomorKursi = nomorKursi;
    newNode->tersedia   = true;     // Semua kursi baru dianggap tersedia
    newNode->prev       = NULL;
    newNode->next       = NULL;

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

    printf("Kursi %d berhasil ditambahkan.\n", nomorKursi);
}

void tampilkanKursi(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada kursi yang tersedia.\n");
        return;
    }

    Node *current = head;
    printf("Daftar kursi:\n");
    do
    {
        printf("Kursi %d [%s]\n",
               current->nomorKursi,
               current->tersedia ? "Tersedia" : "Sudah Dipesan");
        current = current->next;
    } while (current != head);
}

void pilihKursi(Node *head, int nomorKursi)
{
    if (head == NULL)
    {
        printf("Tidak ada kursi untuk dipilih.\n");
        return;
    }

    Node *current = head;
    do
    {
        if (current->nomorKursi == nomorKursi)
        {
            if (current->tersedia)
            {
                printf("Kursi %d berhasil dipilih.\n", nomorKursi);
                current->tersedia = false;
            }
            else
            {
                printf("Kuris %d sudah dipesan.\n", nomorKursi);
            }
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Kursi %d tidak ditemukan.\n", nomorKursi);
}

void hapusKursi(Node **head, Node **tail, int nomorKursi)
{
    if (*head == NULL)
    {
        printf("Tidak ada kursi untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    do
    {
        if (current->nomorKursi == nomorKursi)
        {
            if (current->next == current)
            {
                // Jika hanya ada satu elemen dalam list
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

            printf("Kursi %d berhasil dihapus.\n", nomorKursi);
            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Kursi %d tidak ditemukan.\n", nomorKursi);
}

void judul()
{
    printf("Program Sistem Pemesanan Tiket Bioskop\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
