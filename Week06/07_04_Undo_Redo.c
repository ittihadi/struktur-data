// Preprocessors
#include <stdio.h>
#include <string.h>
#define MAX 100

// Deklarasi fungsi-fungsi
void  judul();
void  push(char stack[][MAX], int *top, char element[]);
char *pop(char stack[][MAX], int *top);
int   isEmpty(int top);
void  display(char stack[][MAX], int top);

int main()
{
    char undo[MAX][MAX];
    char redo[MAX][MAX];
    int  topUndo = -1;
    int  topRedo = -1;
    int  pilihan;
    char teks[MAX];

    // Tampilkan judul program
    judul();

    do
    {
        printf("\nMenu Editor Teks:\n");
        printf("1. Tambah Teks\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Tampilkan Teks\n");
        printf("5. Keluar\n");
        printf("Pilh: ");
        scanf(" %d", &pilihan);

        switch (pilihan)
        {
            case 1:
                printf("Masukkan teks: ");
                scanf(" %[^\n]", teks);
                push(undo, &topUndo, teks);
                topRedo = -1;
                break;
            case 2:
                if (isEmpty(topUndo))
                    printf("Tidak ada operasi untuk di-undo.\n");
                else
                    push(redo, &topRedo, pop(undo, &topUndo));
                break;
            case 3:
                if (isEmpty(topRedo))
                    printf("Tidak ada operasi untuk di-redo.\n");
                else
                    push(undo, &topUndo, pop(redo, &topRedo));
                break;
            case 4:
                display(undo, topUndo);
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
void push(char stack[][MAX], int *top, char element[])
{
    if (*top == MAX - 1)
    {
        printf("Stack penuh.\n");
        return;
    }

    (*top)++;
    strncpy(stack[*top], element, sizeof(stack[*top]));
}

char *pop(char stack[][MAX], int *top)
{
    if (isEmpty(*top))
    {
        printf("Stack kosong.\n");
        return NULL;
    }

    return stack[(*top)--];
}

int isEmpty(int top)
{
    return top == -1;
}

void display(char stack[][MAX], int top)
{
    if (isEmpty(top))
    {
        printf("Tidak ada teks.\n");
        return;
    }

    printf("Teks saat ini adalah: %s\n", stack[top]);
}

void judul()
{
    printf("Program Implementasi Undo/Redo\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
