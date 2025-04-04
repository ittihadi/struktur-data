// Preprocessors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char         data[100];
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void push(Node **top, char data[]);
void pop(Node **top, char *output);
void display(Node *top);
int  isEmpty(Node *top);

int main()
{
    Node *undo = NULL;
    Node *redo = NULL;

    int  pilihan;
    char data[100];
    char buffer[100];

    // Tampilkan judul program
    judul();

    do
    {
        printf("\nMenu Penyimpanan Temporer:\n");
        printf("1. Tambah Data\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Tampilkan Data\n");
        printf("5. Keluar\n");
        printf("Pilh: ");
        scanf(" %d", &pilihan);

        switch (pilihan)
        {
            case 1:
                printf("Masukkan teks: ");
                scanf(" %[^\n]", data);
                push(&undo, data);
                // Kosongkan redo
                while (redo != NULL)
                    pop(&redo, NULL);
                break;
            case 2:
                if (isEmpty(undo))
                    printf("Tidak ada operasi untuk di-undo.\n");
                else
                {
                    pop(&undo, buffer);
                    push(&redo, buffer);
                }
                break;
            case 3:
                if (isEmpty(redo))
                    printf("Tidak ada operasi untuk di-redo.\n");
                else
                {
                    pop(&redo, buffer);
                    push(&undo, buffer);
                }
                break;
            case 4:
                display(undo);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 5);

    // Bersihkan memori
    while (undo != NULL)
        pop(&undo, NULL);
    while (redo != NULL)
        pop(&redo, NULL);

    return 0;
}

// Definisi fungsi-fungsi
void push(Node **top, char data[])
{
    Node *new = (Node *)malloc(sizeof(Node));
    strncpy(new->data, data, sizeof(new->data));
    new->next = *top;
    *top      = new;
}

void pop(Node **top, char *output)
{
    if (*top == NULL)
        return;

    Node *temp = *top;
    if (output != NULL)
        strncpy(output, temp->data, sizeof(temp->data));
    *top = temp->next;
    free(temp);
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
    printf("Data dalam stack: ");
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

void judul()
{
    printf("Program Penyimpanan Data Temporer\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
