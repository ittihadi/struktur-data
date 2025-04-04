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
void tambahDiPosisi(Node *head, int posisi, int data);
void traversal(Node *head);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;

    // Menambah data di awal
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);
    traversal(head);

    // Menambah data di akhir
    tambahDiAkhir(&head, 30);
    tambahDiAkhir(&head, 40);
    traversal(head);

    // Menambah data di posisi tertentu
    tambahDiPosisi(head, 3, 25);
    traversal(head);

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

void tambahDiPosisi(Node *head, int posisi, int data)
{
    if (head == NULL)
    {
        printf("List kosong. Gunakan fungsi tambahDiAwal.\n");
        return;
    }

    Node *current = head;
    for (int i = 1; i < posisi - 1; i++)
    {
        if (current->next == head)
        {
            printf("Posisi tidak valid.\n");
            return;
        }
        current = current->next;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
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
    printf("Program Tambah Data Circular Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
