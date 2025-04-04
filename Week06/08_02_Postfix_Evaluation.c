// Preprocessors
#include <ctype.h>
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
int  evaluasiPostfix(char ekspresi[]);

int main()
{
    char ekspresi[100];

    // Tampilkan judul program
    judul();

    printf("Masukkan ekspresi postfix: ");
    scanf(" %99s", ekspresi);

    int hasil = evaluasiPostfix(ekspresi);
    printf("Hasil evaluasi: %d\n", hasil);

    return 0;
}

// Definisi fungsi-fungsi
void push(Node **top, int element)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = element;
    new->next = *top;
    *top      = new;
}

int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack kosong.\n");
        return -1;
    }

    Node *temp    = *top;
    int   element = temp->data;
    *top          = temp->next;
    free(temp);
    return element;
}

int evaluasiPostfix(char ekspresi[])
{
    Node *top = NULL;
    for (int i = 0; ekspresi[i] != '\0'; i++)
    {
        if (isdigit(ekspresi[i]))
            push(&top, ekspresi[i] - '0');
        else
        {
            int op2 = pop(&top);
            int op1 = pop(&top);
            int hasil;

            switch (ekspresi[i])
            {
                case '+':
                    hasil = op1 + op2;
                    break;
                case '-':
                    hasil = op1 - op2;
                    break;
                case '*':
                    hasil = op1 * op2;
                    break;
                case '/':
                    hasil = op1 / op2;
                    break;
                default:
                    printf("Operator %c tidak valid\n", ekspresi[i]);
                    return -1;
            }
            push(&top, hasil);
        }
    }
    return pop(&top);
}

void judul()
{
    printf("Program Evaluasi Ekspresi Postfix\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
