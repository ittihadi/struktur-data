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
void push(Node **top, int element);
int  pop(Node **top);
int  peek(Node *top);
int  isEmpty(Node *top);
void display(Node *top);

int main()
{
    Node *top = NULL;
    int   pilihan;
    int   element;

    // Tampilkan judul program
    judul();

    do
    {
        printf("\nMenu Stack:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf(" %d", &pilihan);

        switch (pilihan)
        {
            case 1:
                printf("Masukkan elemen: ");
                scanf(" %d", &element);
                push(&top, element);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                printf("Elemen di puncak: %d\n", peek(top));
                break;
            case 4:
                display(top);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 5);

    return 0;
}

// Definisi fungsi-fungsi
void push(Node **top, int element)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = element;
    new->next = *top;
    *top      = new;

    printf("Elemen %d ditambahkan ke stack.\n", element);
}

int pop(Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack kosong.\n");
        return -1;
    }

    Node *temp    = *top;
    int   element = temp->data;
    *top          = temp->next;
    free(temp);

    printf("Elemen %d dihapus dari stack.\n", element);
    return element;
}

int peek(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack kosong.\n");
        return -1;
    }

    return top->data;
}

int isEmpty(Node *top)
{
    return top == NULL;
}

void display(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack kosong.\n");
        return;
    }

    Node *current = top;
    printf("Isi stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void judul()
{
    printf("Program Operasi Stack menggunakan Linked List\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
