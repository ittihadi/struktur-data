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
void hapusData(Node **head, int indeks);

int main()
{
    // Tampilkan judul program
    judul();

    Node *head = NULL;     // List kosong

    // Tambahkan node secara manual sebagai contoh
    tambahDiAwal(&head, 30);
    tambahDiAwal(&head, 20);
    tambahDiAwal(&head, 10);

    printf("Linked list sebelum update:\n");
    traversal(head);

    printf("\nMemperbarui data pada indeks 1:\n");
    hapusData(&head, 1);

    printf("\nLinked list setelah update:\n");
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

void hapusData(Node **head, int indeks)
{
    if (*head == NULL)
    {
        printf("List kosong. Tidak ada yang dapat dihapus.\n");
        return;
    }

    Node *current = *head;
    if (indeks == 0)
    {
        *head = current->next;
        free(current);
        printf("Node pada indeks 0 berhasil dihapus.\n");
        return;
    }

    Node *prev  = NULL;
    int   count = 0;

    while (current != NULL && count != indeks)
    {
        prev    = current;
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        printf("Indeks %d tidak valid. Tidak dapat menghapus data.\n", indeks);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Node pada indeks %d berhasil dihapus.\n", indeks);
}

void judul()
{
    printf("Program Menghapus Data Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
