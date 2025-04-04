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
void bacaDataBerdasarkanIndeks(Node *head, int indeks);
void bacaDataBerdasarkanNilai(Node *head, int nilai);
void traversalKeDepan(Node *head);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong
    Node *tail = NULL;

    tambahDiAwal(&head, &tail, 20);
    tambahDiAwal(&head, &tail, 10);
    tambahDiAkhir(&head, &tail, 30);
    traversalKeDepan(head);

    // Baca data berdasarkan indeks
    printf("\nMembaca data pada indeks 1:\n");
    bacaDataBerdasarkanIndeks(head, 1);

    // Baca data berdasarkan nilai
    printf("\nMembaca data dengan nilai 30:\n");
    bacaDataBerdasarkanNilai(head, 30);

    printf("\nMembaca data dengan nilai 50:\n");
    bacaDataBerdasarkanNilai(head, 50);

    return 0;
}

// Definisi fungsi-fungsi
void bacaDataBerdasarkanIndeks(Node *head, int indeks)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    int   count   = 0;

    do
    {
        if (count == indeks)
        {
            printf("Data pada indeks %d adalah: %d\n", indeks, current->data);
            return;
        }

        current = current->next;
        count++;
    } while (current != head);

    printf("Indeks %d tidak valid.\n", indeks);
}

void bacaDataBerdasarkanNilai(Node *head, int nilai)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;

    do
    {
        if (current->data == nilai)
        {
            printf("Data ditemukan: %d\n", current->data);
            return;
        }

        current = current->next;
    } while (current != head);

    printf("Data %d tidak ditemukan.\n", nilai);
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
    printf("Program Baca Data Circular Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
