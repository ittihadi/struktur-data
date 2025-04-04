// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char judul[100];
    char artis[100];

    struct Node *next;
    struct Node *prev;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahLagu(Node **head, Node **tail, const char *judul, const char *artis);
void tampilkanPlaylist(Node *head);
void navigasiKeLaguBerikutnya(Node **current);
void navigasiKeLaguSebelumnya(Node **current);
void hapusLagu(Node **head, Node **tail, int indeks);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head    = NULL;
    Node *tail    = NULL;
    Node *current = NULL;

    while (1)
    {
        printf("\nMenu Sistem Manajemen Playlist Musik:\n");
        printf("1. Tambah Lagu\n");
        printf("2. Tampilkan Playlist\n");
        printf("3. Navigasi ke Lagu Berikutnya\n");
        printf("4. Navigasi ke Lagu Sebelumnya\n");
        printf("5. Hapus Lagu dari Playlist\n");
        printf("6. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 6) break;

        char judul[100];
        char artis[100];
        int  indeks;

        switch (pilihan)
        {
            case 1:
                printf("Masukkan Judul Lagu Baru: ");
                scanf(" %99[^\n]s", judul);
                printf("Masukkan Artis Lagu Baru: ");
                scanf(" %99[^\n]s", artis);
                tambahLagu(&head, &tail, judul, artis);
                if (current == NULL)
                {
                    current = head;
                }
                break;
            case 2:
                tampilkanPlaylist(head);
                break;
            case 3:
                navigasiKeLaguBerikutnya(&current);
                break;
            case 4:
                navigasiKeLaguSebelumnya(&current);
                break;
            case 5:
                printf("Masukkan Indeks Lagu yang ingin Dihapus: ");
                scanf("%d", &indeks);
                hapusLagu(&head, &tail, indeks);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    // Bebaskan sisa memori
    while (head != NULL)
    {
        hapusLagu(&head, &tail, 0);
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahLagu(Node **head, Node **tail, const char *judul, const char *artis)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->judul, judul, sizeof(newNode->judul));
    strncpy(newNode->artis, artis, sizeof(newNode->artis));
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
    printf("Lagu '%s' oleh '%s' berhasil ditambahkan ke playlist.\n", judul, artis);
}

void tampilkanPlaylist(Node *head)
{
    if (head == NULL)
    {
        printf("Playlist kosong.\n");
        return;
    }

    Node *current = head;
    printf("Playlist Musik:\n");
    while (current != NULL)
    {
        printf("Lagu: '%s', Artis: '%s'\n", current->judul, current->artis);
        current = current->next;
    }
}

void navigasiKeLaguBerikutnya(Node **current)
{
    if (*current == NULL)
    {
        printf("Playlist kosong.\n");
        return;
    }

    if ((*current)->next != NULL)
    {
        *current = (*current)->next;
        printf("Sekarang memutar lagu: '%s' oleh '%s'.\n",
               (*current)->judul, (*current)->artis);
    }
    else
    {
        printf("Sudah berada di akhir playlist.\n");
    }
}

void navigasiKeLaguSebelumnya(Node **current)
{
    if (*current == NULL)
    {
        printf("Playlist kosong.\n");
        return;
    }

    if ((*current)->prev != NULL)
    {
        *current = (*current)->prev;
        printf("Sekarang memutar lagu: '%s' oleh '%s'.\n",
               (*current)->judul, (*current)->artis);
    }
    else
    {
        printf("Sudah berada di awal playlist.\n");
    }
}

void hapusLagu(Node **head, Node **tail, int indeks)
{
    if (*head == NULL)
    {
        printf("Playlist kosong. Tidak ada lagu untuk dihapus.\n");
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

            printf("Lagu '%s' oleh '%s' berhasil dihapus.\n",
                   current->judul, current->artis);
            free(current);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}

void judul()
{
    printf("Program Sistem Manajemen Playlist Musik\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
