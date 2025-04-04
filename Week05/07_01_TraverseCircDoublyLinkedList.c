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
void traversalKeDepan(Node *head);
void traversalKeBelakang(Node *tail);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong
    Node *tail = NULL;

    // Contoh manual untuk Circular Doubly Linked List
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->prev = node3;
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = node1;

    head = node1;
    tail = node3;

    // Traversal ke depan dan ke belakang
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
    printf("Program Traversal Circular Doubly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
