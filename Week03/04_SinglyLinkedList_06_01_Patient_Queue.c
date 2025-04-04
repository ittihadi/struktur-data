// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int          nomorAntrian;
    char         nama[50];
    char         keluhan[100];
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahPasien(Node **head, int nomorAntrian, const char *nama, const char *keluhan);
void tampilkanAntrian(Node *head);
void layaniPasien(Node **head);
void cariPasien(Node *head, int nomorAntrian);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong
    while (1)
    {
        printf("\nMenu Sistem Antrian Pasien:\n");
        printf("1. Tambah Pasien\n");
        printf("2. Tampilkan Antrian\n");
        printf("3. Layani Pasien\n");
        printf("4. Cari Pasien\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5) break;

        int  nomorAntrian;
        char nama[50];
        char keluhan[100];

        switch (pilihan)
        {
            case 1:
                printf("Masukkan Nomor Antrian: ");
                scanf("%d", &nomorAntrian);
                printf("Masukkan Nama Pasien: ");
                scanf(" %49[^\n]s", nama);
                printf("Masukkan Keluhan: ");
                scanf(" %99[^\n]s", keluhan);
                tambahPasien(&head, nomorAntrian, nama, keluhan);
                break;
            case 2:
                tampilkanAntrian(head);
                break;
            case 3:
                layaniPasien(&head);
                break;
            case 4:
                printf("Masukkan Nomor Antrian: ");
                scanf("%d", &nomorAntrian);
                cariPasien(head, nomorAntrian);
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
void tambahPasien(Node **head, int nomorAntrian, const char *nama, const char *keluhan)
{
    // Alokasi node antrian baru dan isi data
    Node *newNode         = (Node *)malloc(sizeof(Node));
    newNode->nomorAntrian = nomorAntrian;
    snprintf(newNode->nama, sizeof(newNode->nama), "%s", nama);
    snprintf(newNode->keluhan, sizeof(newNode->keluhan), "%s", keluhan);
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
        // Pasang pasien baru di akhir list
        current->next = newNode;
    }

    printf("Pasien dengan nomor antrian %d berhasil ditambahkan.\n", nomorAntrian);
}

void tampilkanAntrian(Node *head)
{
    if (head == NULL)
    {
        printf("Antrian kosong\n");
        return;
    }

    Node *current = head;
    printf("Daftar Antrian Pasien:\n");
    while (current != NULL)
    {
        printf("Nomor Antrian: %d, Nama: %s, Keluhan: %s\n",
               current->nomorAntrian, current->nama, current->keluhan);
        current = current->next;
    }
}

void layaniPasien(Node **head)
{
    if (*head == NULL)
    {
        printf("Antrian kosong. Tidak ada pasien yang dapat dilayani.\n");
        return;
    }

    Node *temp = *head;
    printf("Melayani pasien dengan nomor antrian %d, Nama: %s, Keluhan: %s\n",
           temp->nomorAntrian, temp->nama, temp->keluhan);

    *head = (*head)->next;
    free(temp);
}

void cariPasien(Node *head, int nomorAntrian)
{
    Node *current = head;

    while (current != NULL)
    {
        if (current->nomorAntrian == nomorAntrian)
        {
            printf("Pasien ditemukan. Nomor Antrian: %d, Nama: %s, Keluhan: %s\n",
                   current->nomorAntrian, current->nama, current->keluhan);
            return;
        }
        current = current->next;
    }
    printf("Pasien dengan nomor antrian %d tidak ditemukan.\n", nomorAntrian);
}

void judul()
{
    printf("Program Sistem Antrian Pasien di Rumah Sakit\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
