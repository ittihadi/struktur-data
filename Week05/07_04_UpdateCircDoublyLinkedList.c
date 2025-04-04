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
void updateDataBerdasarkanIndeks(Node *head, int indeks, int nilaiBaru);
void traversalKeDepan(Node *head);

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

    // Update data berdasarkan indeks
    printf("\nMemperbarui data pada indeks 1 menjadi 25:\n");
    updateDataBerdasarkanIndeks(head, 1, 25);

    // Tampilkan hasil update
    traversalKeDepan(head);

    return 0;
}

// Definisi fungsi-fungsi
void updateDataBerdasarkanIndeks(Node *head, int indeks, int nilaiBaru)
{
    if (head == NULL)
    {
        printf("List kosong. Tidak ada data untuk diperbarui.\n");
        return;
    }

    Node *current = head;
    int   count   = 0;

    do
    {
        if (count == indeks)
        {
            current->data = nilaiBaru;
            printf("Data pada indeks %d berhasil diperbarui menjadi: %d\n",
                   indeks, nilaiBaru);
            return;
        }

        current = current->next;
        count++;
    } while (current != head);

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

void judul()
{
    printf("Program Perbarui Data Circular Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
