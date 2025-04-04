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
void updateData(Node *head, int indeks, int nilaiBaru);

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
    updateData(head, 1, 25);

    printf("\nLinked list setelah update:\n");
    traversal(head);

    printf("\nMemperbarui data pada indeks 5:\n");
    updateData(head, 5, 40);     // Indeks tidak valid

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

void updateData(Node *head, int indeks, int nilaiBaru)
{
    int   count   = 0;
    Node *current = head;

    while (current != NULL)
    {
        if (count == indeks)
        {
            current->data = nilaiBaru;
            printf("Data pada indeks %d berhasil diperbarui menjadi %d.\n",
                   indeks, nilaiBaru);
            return;
        }
        current = current->next;
        count++;
    }
    printf("Indeks %d tidak valid. Tidak dapat memperbarui data.\n", indeks);
}

void judul()
{
    printf("Program Memperbarui Data Singly Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
