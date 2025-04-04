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
void tambahDiAkhir(Node **head, int data);
void tambahDiTengah(Node **head, int posisi, int data);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong

    // Tambahkan node secara manual sebagai contoh
    tambahDiAwal(&head, 30);
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);
    printf("\nSetelah menambah di awal:\n");
    traversal(head);

    // Menambah data di akhir
    tambahDiAkhir(&head, 40);
    tambahDiAkhir(&head, 50);
    printf("\nSetelah menambah di akhir:\n");
    traversal(head);

    // Menambah data di akhir
    tambahDiTengah(&head, 3, 25);
    printf("\nSetelah menambah di tengah:\n");
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

void tambahDiAwal(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head         = newNode;
}

void tambahDiAkhir(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

void tambahDiTengah(Node **head, int posisi, int data)
{
    if (posisi == 1 || posisi == 0)
        tambahDiAwal(head, data);

    Node *current = *head;
    for (int i = 1; i < posisi - 1; i++)
    {
        if (current == NULL)
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

void judul()
{
    printf("Program Menambah Data Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
