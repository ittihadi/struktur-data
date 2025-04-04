// Preprocessors
#include <stdio.h>
#include <string.h>
#define MAX 100

// Deklarasi fungsi-fungsi
void judul();
void push(char stack[], int *top, char element);
char pop(char stack[], int *top);
int  isEmpty(int top);
int  validasiKurung(char ekspresi[]);

int main()
{
    char ekspresi[MAX];

    // Tampilkan judul program
    judul();

    printf("Masukkan ekspresi matematika: ");
    scanf("%99[^\n]s", ekspresi);

    if (validasiKurung(ekspresi))
        printf("Ekspresi valid.\n");
    else
        printf("Ekspresi tidak valid.\n");

    return 0;
}

// Definisi fungsi-fungsi
void push(char stack[], int *top, char element)
{
    if (*top == MAX - 1)
    {
        printf("Stack penuh.\n");
        return;
    }

    (*top)++;
    stack[*top] = element;
}

char pop(char stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack kosong.\n");
        return '\0';
    }

    int element = stack[*top];
    (*top)--;
    return element;
}

int isEmpty(int top)
{
    return top == -1;
}

int validasiKurung(char ekspresi[])
{
    char stack[MAX];
    int  top = -1;

    for (int i = 0; i < strlen(ekspresi); i++)
    {
        if (ekspresi[i] == '(')
        {
            push(stack, &top, '(');
        }
        else if (ekspresi[i] == ')')
        {
            if (isEmpty(top))
                return 0;

            pop(stack, &top);
        }
    }

    return isEmpty(top);
}

void judul()
{
    printf("Program Validasi Kurung Ekspresi Matematika\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
