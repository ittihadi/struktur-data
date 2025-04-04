// Preprocessors
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          data;
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void traversal(Node *head);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;

    // Contoh manual untuk membuat circular singly linked list
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));

    node1->data = 10;
    node2->data = 20;
    node3->data = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    head = node1;

    // Traversal list
    traversal(head);

    return 0;
}

// Definisi fungsi-fungsi
void traversal(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    printf("Isi Circular Singly Linked List:\n");
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(Kembali ke head)\n");
}

void judul()
{
    printf("Program Traversal Circular Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
