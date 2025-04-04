// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[64];

    struct Node *next;
    struct Node *prev;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahRiwayat(Node **head, Node **tail, const char *url);
void tampilkanRiwayat(Node *head);
void navigasiKeDepan(Node **current);
void navigasiKeBelakang(Node **current);
void hapusRiwayat(Node **head, Node **tail, int indeks);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head    = NULL;
    Node *tail    = NULL;
    Node *current = NULL;

    while (1)
    {
        printf("\nMenu Sistem Navigasi Riwayat Browser:\n");
        printf("1. Tambah Riwayat\n");
        printf("2. Tampilkan Riwayat\n");
        printf("3. Navigasi ke Depan\n");
        printf("4. Navigasi ke Belakang\n");
        printf("5. Hapus Riwayat\n");
        printf("6. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 6) break;

        char url[64];
        int  indeks;

        switch (pilihan)
        {
            case 1:
                printf("Masukkan URL Baru: ");
                scanf(" %63[^\n]s", url);
                tambahRiwayat(&head, &tail, url);
                if (current == NULL)
                {
                    current = head;
                }
                break;
            case 2:
                tampilkanRiwayat(head);
                break;
            case 3:
                navigasiKeDepan(&current);
                break;
            case 4:
                navigasiKeBelakang(&current);
                break;
            case 5:
                printf("Masukkan Indeks Riwayat yang ingin Dihapus: ");
                scanf("%d", &indeks);
                hapusRiwayat(&head, &tail, indeks);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    // Bebaskan sisa memori
    while (head != NULL)
    {
        hapusRiwayat(&head, &tail, 0);
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahRiwayat(Node **head, Node **tail, const char *url)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->data, url, sizeof(newNode->data));
    newNode->prev = *tail;
    newNode->next = NULL;

    if (*tail != NULL)
    {
        (*tail)->next = newNode;
    }
    else     // List kosong, ubah ujung awal juga
    {
        *head = newNode;
    }

    *tail = newNode;
}

void tampilkanRiwayat(Node *head)
{
    if (head == NULL)
    {
        printf("Riwayat kosong.\n");
        return;
    }

    Node *current = head;
    printf("Riwayat Browser:\n");
    while (current != NULL)
    {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void navigasiKeDepan(Node **current)
{
    if (*current == NULL)
    {
        printf("Tidak ada riwayat untuk dinavigasi.\n");
        return;
    }

    if ((*current)->next != NULL)
    {
        *current = (*current)->next;
        printf("Berpindah ke URL berikutnya: %s\n", (*current)->data);
    }
    else
    {
        printf("Sudah berada di akhir riwayat.\n");
    }
}

void navigasiKeBelakang(Node **current)
{
    if (*current == NULL)
    {
        printf("Tidak ada riwayat untuk dinavigasi.\n");
        return;
    }

    if ((*current)->prev != NULL)
    {
        *current = (*current)->prev;
        printf("Berpindah ke URL sebelumnya: %s\n", (*current)->data);
    }
    else
    {
        printf("Sudah berada di awal riwayat.\n");
    }
}

void hapusRiwayat(Node **head, Node **tail, int indeks)
{
    if (*head == NULL)
    {
        printf("Riwayat kosong. Tidak ada URL untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    int   count   = 0;

    while (current != NULL)
    {
        if (count == indeks)
        {
            if (current == *head)
            {
                *head = current->next;
                if (*head != NULL)
                {
                    (*head)->prev = NULL;
                }
                else
                {
                    *tail = NULL;     // List kosong setelah penghapusan
                }
            }
            else if (current == *tail)
            {
                *tail         = current->prev;
                (*tail)->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            free(current);
            printf("Riwayat pada indeks %d berhasil dihapus.\n", indeks);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}

void judul()
{
    printf("Program Sistem Navigasi Riwayat Browser\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
