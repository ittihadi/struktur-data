// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int          nomorPesanan;
    char         namaPelanggan[50];
    char         daftarMenu[100];
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahPesanan(Node **head, int nomorPesanan,
                   const char *namaPelanggan, const char *daftarMenu);
void tampilkanPesanan(Node *head);
void prosesPesanan(Node **head);
void perbaruiPesanan(Node *head, int nomorPesanan,
                     const char *namaPelanggan, const char *daftarMenu);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;
    while (1)
    {
        printf("\nMenu Sistem Pemesanan Makanan:\n");
        printf("1. Tambah Pesanan\n");
        printf("2. Tampilkan Pesanan\n");
        printf("3. Proses Pesanan\n");
        printf("4. Perbarui Pesanan\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        int pilihan;
        scanf("%d", &pilihan);

        if (pilihan == 5) break;

        int  nomorPesanan;
        char namaPelanggan[50];
        char daftarMenu[100];

        switch (pilihan)
        {
            case 1:
                printf("Masukkan Nomor Pesanan: ");
                scanf("%d", &nomorPesanan);
                printf("Masukkan Nama Pelanggan: ");
                scanf(" %49[^\n]s", namaPelanggan);
                printf("Masukkan Daftar Menu: ");
                scanf(" %99[^\n]s", daftarMenu);
                tambahPesanan(&head, nomorPesanan, namaPelanggan, daftarMenu);
                break;
            case 2:
                tampilkanPesanan(head);
                break;
            case 3:
                prosesPesanan(&head);
                break;
            case 4:
                printf("Masukkan Nomor Pesanan yang ingin Diperbarui: ");
                scanf("%d", &nomorPesanan);
                printf("Masukkan Nama Baru: ");
                scanf(" %49[^\n]s", namaPelanggan);
                printf("Masukkan Menu Baru: ");
                scanf(" %99[^\n]s", daftarMenu);
                perbaruiPesanan(head, nomorPesanan, namaPelanggan, daftarMenu);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    // Bebaskan sisa memori
    while (head != NULL)
    {
        prosesPesanan(&head);
    }

    return 0;
}

// Definisi fungsi-fungsi
void tambahPesanan(Node **head, int nomorPesanan,
                   const char *namaPelanggan, const char *daftarMenu)
{
    Node *newNode         = (Node *)malloc(sizeof(Node));
    newNode->nomorPesanan = nomorPesanan;
    strncpy(newNode->namaPelanggan, namaPelanggan, sizeof(newNode->namaPelanggan));
    strncpy(newNode->daftarMenu, daftarMenu, sizeof(newNode->daftarMenu));

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

    printf("Pesanan dengan nomor %d berhasil ditambahkan.\n", nomorPesanan);
}

void tampilkanPesanan(Node *head)
{
    if (head == NULL)
    {
        printf("Tidak ada pesanan yang aktif.\n");
        return;
    }

    Node *current = head;
    printf("Daftar pesanan:\n");
    do
    {
        printf("Nomor: %d, Nama: %s, Menu: %s\n",
               current->nomorPesanan, current->namaPelanggan, current->daftarMenu);
        current = current->next;
    } while (current != head);
}

void prosesPesanan(Node **head)
{
    if (*head == NULL)
    {
        printf("Tidak ada pesanan untuk diproses.\n");
        return;
    }

    Node *current = *head;
    if (current->next == *head)
    {
        printf("Pesanan dengan nomor %d telah diproses.\n", current->nomorPesanan);
        free(current);
        *head = NULL;
        return;
    }

    while (current->next != *head)
    {
        current = current->next;
    }

    Node *temp    = *head;
    current->next = (*head)->next;
    *head         = (*head)->next;
    printf("Pesanan dengan nomor %d telah diproses.\n", temp->nomorPesanan);
    free(temp);
}

void perbaruiPesanan(Node *head, int nomorPesanan,
                     const char *namaPelanggan, const char *daftarMenu)
{
    if (head == NULL)
    {
        printf("Tidak ada pesanan yang dapat diperbarui.\n");
        return;
    }

    Node *current = head;
    do
    {
        if (current->nomorPesanan == nomorPesanan)
        {
            strncpy(current->namaPelanggan, namaPelanggan, sizeof(current->namaPelanggan));
            strncpy(current->daftarMenu, daftarMenu, sizeof(current->daftarMenu));
            printf("Pesanan dengan nomor %d berhasil diperbarui.\n", nomorPesanan);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Pesanan dengan nomor %d tidak ditemukan.\n", nomorPesanan);
}

void judul()
{
    printf("Program Sistem Pemesanan Makanan dalam Restoran\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
