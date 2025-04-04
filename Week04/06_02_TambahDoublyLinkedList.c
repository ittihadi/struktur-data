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
void traversalKeBelakang(Node *tail);
void tambahDiAwal(Node **head, Node **tail, int data);
void tambahDiAkhir(Node **head, Node **tail, int data);
void tambahDiIndeks(Node **head, Node **tail, int data, int indeks);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;
    Node *tail = NULL;

    // Tambah di awal
    tambahDiAwal(&head, &tail, 20);
    tambahDiAwal(&head, &tail, 10);
    traversalKeDepan(head);
    traversalKeBelakang(tail);

    // Tambah di akhir
    tambahDiAkhir(&head, &tail, 30);
    tambahDiAkhir(&head, &tail, 40);
    traversalKeDepan(head);
    traversalKeBelakang(tail);

    // Tambah di indeks
    tambahDiIndeks(&head, &tail, 15, 1);
    tambahDiIndeks(&head, &tail, 35, 4);
    tambahDiIndeks(&head, &tail, 50, 6);
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

void tambahDiIndeks(Node **head, Node **tail, int data, int indeks)
{
    if (*head == NULL || indeks == 0)
    {
        tambahDiAwal(head, tail, data);
    }
    else
    {
        Node *curr = *head;
        Node *next = curr->next;

        for (int i = 0; i < indeks - 1; i++)
        {
            if (next == NULL)
            {
                printf("Indeks %d tidak valid\n", indeks);
                return;
            }

            curr = next;
            next = curr->next;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = curr;
        newNode->next = next;

        // Jika next kosong, maka ini akhir list, perbarui tail
        if (next == NULL)
            *tail = newNode;
        else
            next->prev = newNode;

        curr->next = newNode;
    }
}

void judul()
{
    printf("Program Tambah Data Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
