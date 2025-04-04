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
void traversalKeDepan(Node *head);
void tambahDiAwal(Node **head, Node **tail, int data);
void tambahDiAkhir(Node **head, Node **tail, int data);
void updateDataBerdasarkanIndeks(Node *head, int indeks, int nilaiBaru);

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

    // Update data berdasarkan indeks
    printf("\nMemperbarui data pada indeks 1 menjadi 25:\n");
    updateDataBerdasarkanIndeks(head, 1, 25);

    // Tampilkan hasil update
    traversalKeDepan(head);

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

void updateDataBerdasarkanIndeks(Node *head, int indeks, int nilaiBaru)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    int   count   = 0;

    while (current != NULL)
    {
        if (count == indeks)
        {
            current->data = nilaiBaru;
            printf("Data pada indeks %d berhasil diperbarui menjadi %d\n",
                   indeks, nilaiBaru);
            return;
        }

        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid.\n", indeks);
}

void judul()
{
    printf("Program Update Data Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
