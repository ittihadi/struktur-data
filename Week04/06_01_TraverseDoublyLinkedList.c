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

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;
    Node *tail = NULL;

    // Membuat doubly linked list
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));

    node1->data = 10;
    node1->prev = NULL;
    node1->next = node2;

    node2->data = 20;
    node2->prev = node1;
    node2->next = node3;

    node3->data = 30;
    node3->prev = node2;
    node3->next = NULL;

    head = node1;
    tail = node3;

    // Traverse doubly linked list
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

void judul()
{
    printf("Program Traversal Doubly Linked List ke Depan dan ke Belakang\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
