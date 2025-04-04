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
void traversalKeDepan(Node *head);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong
    Node *tail = NULL;

    tambahDiAwal(&head, &tail, 20);
    tambahDiAwal(&head, &tail, 10);
    traversalKeDepan(head);

    tambahDiAkhir(&head, &tail, 30);
    tambahDiAkhir(&head, &tail, 40);
    traversalKeDepan(head);

    return 0;
}

// Definisi fungsi-fungsi
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
    printf("Program Tambah Data Circular Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
