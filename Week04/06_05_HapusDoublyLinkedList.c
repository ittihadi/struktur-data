// Preprocessors
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          data;
    struct Node *next;
    struct Node *prev;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void traversalKeBelakang(Node *tail);
void traversalKeDepan(Node *head);
void tambahDiAwal(Node **head, Node **tail, int data);
void tambahDiAkhir(Node **head, Node **tail, int data);
void hapusDataBerdasarkanIndeks(Node **head, Node **tail, int indeks);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;
    Node *tail = NULL;

    // Tambah di awal
    tambahDiAwal(&head, &tail, 20);
    tambahDiAwal(&head, &tail, 10);
    tambahDiAkhir(&head, &tail, 30);

    traversalKeDepan(head);

    // Hapus data berdasarkan indeks
    printf("\nMenghapus data pada indeks 1:\n");
    hapusDataBerdasarkanIndeks(&head, &tail, 1);

    // Tampilkan hasil penghapusan
    traversalKeDepan(head);
    traversalKeBelakang(tail);

    return 0;
}

// Definisi fungsi-fungsi
void traversalKeDepan(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    printf("Traversal ke Depan:\n");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;     // geserkan ke belakang
    }
    printf("NULL\n");
}

void traversalKeBelakang(Node *tail)
{
    if (tail == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = tail;
    printf("Traversal ke Belakang:\n");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->prev;     // geserkan ke depan
    }
    printf("NULL\n");
}

void tambahDiAwal(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;
    else
        *tail = newNode;     // Perbarui juga tail jika list kosong

    *head = newNode;
}

void tambahDiAkhir(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = *tail;
    newNode->next = NULL;

    if (*tail != NULL)
        (*tail)->next = newNode;
    else
        *head = newNode;     // Perbarui juga head jika list kosong

    *tail = newNode;
}

void hapusDataBerdasarkanIndeks(Node **head, Node **tail, int indeks)
{
    if (head == NULL)
    {
        printf("List kosong. Tidak ada data untuk dihapus.\n");
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
                    *tail = NULL;
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
            printf("Data pada indeks %d berhasil dihapus.\n", indeks);
            return;
        }

        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}

void judul()
{
    printf("Program Hapus Data Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
