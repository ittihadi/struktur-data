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
void tambahDiAwal(Node **head, int data);
void tambahDiAkhir(Node **head, int data);
void bacaData(Node *head, int posisi);
void traversal(Node *head);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;

    // Menambah data untuk contoh
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);
    tambahDiAkhir(&head, 30);
    traversal(head);

    printf("\nMembaca data pada posisi 2:\n");
    bacaData(head, 2);

    printf("\nMembaca data pada posisi 5:\n");
    bacaData(head, 5);

    return 0;
}

// Definisi fungsi-fungsi
void tambahDiAwal(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head         = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        newNode->next = *head;
        current->next = newNode;
        *head         = newNode;
    }
}

void tambahDiAkhir(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head         = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

void bacaData(Node *head, int posisi)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }

    Node *current = head;
    int   count   = 1;

    do
    {
        if (count == posisi)
        {
            printf("Data pada posisi %d adalah: %d\n", posisi, current->data);
            return;
        }

        current = current->next;
        count++;
    } while (current != head);

    printf("Posisi %d tidak valid.\n", posisi);
}

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
    printf("Program Baca Data Circular Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
