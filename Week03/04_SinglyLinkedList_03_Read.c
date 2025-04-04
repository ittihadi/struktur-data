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
void tambahDiAwal(Node **head, int data);
void bacaData(Node *head, int indeks);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong

    // Tambahkan node secara manual sebagai contoh
    tambahDiAwal(&head, 30);
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);

    printf("Linked list:\n");
    traversal(head);

    printf("\nMembaca data pada indeks 1:\n");
    bacaData(head, 1);     // Membaca node kedua

    printf("\nMembaca data pada indeks 5:\n");
    bacaData(head, 5);     // Indeks tidak valid

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

void tambahDiAwal(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head         = newNode;
}

void bacaData(Node *head, int indeks)
{
    int   count   = 0;
    Node *current = head;
    while (current != NULL)
    {
        if (count == indeks)
        {
            printf("Data pada indeks %d adalah: %d\n", indeks, current->data);
            return;
        }
        current = current->next;
        count++;
    }

    printf("Indeks %d tidak valid. List terlalu pendek.\n", indeks);
}

void judul()
{
    printf("Program Membaca Data Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
