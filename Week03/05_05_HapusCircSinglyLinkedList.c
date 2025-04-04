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
void hapusData(Node **head, int posisi);
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

    printf("\nMenghapus data pada posisi 2:\n");
    hapusData(&head, 2);

    printf("\nLinked list setelah penghapusan:\n");
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

void hapusData(Node **head, int posisi)
{
    if (head == NULL)
    {
        printf("List kosong. Tidak ada data untuk dihapus.\n");
        return;
    }

    Node *current = *head;
    Node *prev    = NULL;
    int   count   = 1;

    if (posisi == 1)
    {
        while (current->next != *head)
        {
            current = current->next;
        }

        Node *temp    = *head;
        current->next = (*head)->next;
        *head         = (*head)->next;
        free(temp);
        printf("Node pada posisi 1 berhasil dihapus.\n");
        return;
    }

    do
    {
        if (count == posisi)
        {
            prev->next = current->next;
            free(current);
            printf("Node pada posisi %d berhasil dihapus\n", posisi);
            return;
        }

        prev    = current;
        current = current->next;
        count++;
    } while (current != *head);

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
    printf("Program Hapus Data Circular Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
