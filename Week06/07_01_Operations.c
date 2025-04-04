// Preprocessors
#include <stdio.h>
#define MAX 10

// Deklarasi fungsi-fungsi
void judul();
void push(int stack[], int *top, int max_size, int element);
int  pop(int stack[], int *top);
int  peek(int stack[], int top);
int  isEmpty(int top);
int  isFull(int top, int max_size);
void display(int stack[], int top);

int main()
{
    int stack[MAX];
    int top = -1;

    // Tampilkan judul program
    judul();

    int pilihan;
    int element;

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
                push(stack, &top, MAX, element);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                printf("Elemen di puncak: %d\n", peek(stack, top));
                break;
            case 4:
                display(stack, top);
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
void push(int stack[], int *top, int max_size, int element)
{
    if (*top == max_size - 1)
    {
        printf("Stack penuh.\n");
        return;
    }

    (*top)++;
    stack[*top] = element;
    printf("Elemen %d ditambahkan ke stack.\n", element);
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack kosong.\n");
        return -1;
    }

    int element = stack[*top];
    (*top)--;
    printf("Elemen %d dihapus dari stack.\n", element);
    return element;
}

int peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack kosong.\n");
        return -1;
    }

    return stack[top];
}

int isEmpty(int top)
{
    return top == -1;
}

int isFull(int top, int max_size)
{
    return top == max_size - 1;
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack kosong.\n");
        return;
    }
    printf("Isi stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

void judul()
{
    printf("Program Operasi Stack menggunakan Array\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
