// Preprocessors
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          data;
    struct Node *prev;
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void tambahDiAwal(Node **head, Node **tail, int data);
void tambahDiAkhir(Node **head, Node **tail, int data);
void hapusDataBerdasarkanIndeks(Node **head, Node **tail, int indeks);
void traversalKeDepan(Node *head);
void traversalKeBelakang(Node *tail);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong
    Node *tail = NULL;

    // Tambah data
    tambahDiAwal(&head, &tail, 20);
    tambahDiAwal(&head, &tail, 10);
    tambahDiAkhir(&head, &tail, 30);
    traversalKeDepan(head);

    // Hapus data berdasarkan indeks
    printf("\nMenghapus data pada indeks 1:\n");
    hapusDataBerdasarkanIndeks(&head, &tail, 1);

    // Tampilkan hasil hapus
    traversalKeDepan(head);
    traversalKeBelakang(tail);

    return 0;
}

// Definisi fungsi-fungsi
void hapusDataBerdasarkanIndeks(Node **head, Node **tail, int indeks)
{
    if (*head == NULL)
    {
        printf("List kosong. Tidak ada data untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    int   count   = 0;

    do
    {
        if (count == indeks)
        {
            if (current == *head)
            {
                *head         = current->next;
                (*head)->prev = *tail;
                (*tail)->prev = *head;
            }
            else if (current == *tail)
            {
                *tail         = current->prev;
                (*head)->next = *head;
                (*tail)->prev = *tail;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            printf("Node pada indeks %d berhasil dihapus.\n", indeks);
            free(current);
            return;
        }

        current = current->next;
        count++;
    } while (current != *head);

    printf("Indeks %d tidak valid.\n", indeks);
}

void tambahDiAwal(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

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
        (*head)->prev = newNode;
        (*tail)->next = newNode;
        *head         = newNode;
    }

    printf("Node dengan data %d berhasil ditambahkan di awal.\n", data);
}

void tambahDiAkhir(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

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
        (*head)->prev = newNode;
        (*tail)->next = newNode;
        *tail         = newNode;
    }

    printf("Node dengan data %d berhasil ditambahkan di akhir.\n", data);
}

void traversalKeDepan(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    printf("Traversal ke Depan:\n");
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(Kembali ke head)\n");
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
    do
    {
        printf("%d -> ", current->data);
        current = current->prev;
    } while (current != tail);
    printf("(Kembali ke tail)\n");
}

void judul()
{
    printf("Program Hapus Data Circular Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
