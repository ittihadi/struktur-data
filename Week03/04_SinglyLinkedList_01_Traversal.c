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

    Node *head = NULL;     // List kosong

    // Traversal pada list kosong
    traversal(head);

    // Tambahkan node secara manual sebagai contoh
    head             = (Node *)malloc(sizeof(Node));
    head->data       = 10;
    head->next       = (Node *)malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = NULL;

    // Traversal setelah menambahkan node
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
    printf("Isi linked list:\n");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void judul()
{
    printf("Program Traversal Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
