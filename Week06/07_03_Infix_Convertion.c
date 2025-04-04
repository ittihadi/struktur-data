// Preprocessors
#include <ctype.h>
#include <stdio.h>
#define MAX 100

// Deklarasi fungsi-fungsi
void judul();
void push(char stack[], int *top, char element);
char pop(char stack[], int *top);
int  leftAssociative(char op);
int  prioritas(char op);
int  isEmpty(int top);
void konversiInfixToPostfix(char infix[], char postfix[]);

int main()
{
    char infix[MAX];
    char postfix[MAX];

    // Tampilkan judul program
    judul();

    // Ekspresi infix tanpa spasi
    printf("Masukkan ekspresi infix: ");
    scanf(" %99s", infix);

    konversiInfixToPostfix(infix, postfix);
    printf("Ekspresi postfix: %s\n", postfix);

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

// Pangkat dioperasikan dari kanan ke kiri
int leftAssociative(char op)
{
    return op != '^';
}

int prioritas(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isEmpty(int top)
{
    return top == -1;
}

void konversiInfixToPostfix(char infix[], char postfix[])
{
    char stack[MAX];
    int  top = -1;
    int  j   = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        // Langsung pindahkan angka/huruf ke output
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(stack, &top, '(');
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(top) && stack[top] != '(')
                postfix[j++] = pop(stack, &top);

            if (isEmpty(top) || stack[top] != '(')
            {
                printf("Ekspresi tidak valid, kurung tidak berpasangan.\n");
                return;
            }

            // Buang pasangan kurung
            pop(stack, &top);
        }
        else
        {
            // Jika operator di atas stack lebih diprioritaskan, masukan ke output
            // terlebih dahulu
            while (!isEmpty(top) && stack[top] != '(' &&
                   (prioritas(stack[top]) > prioritas(infix[i]) ||
                    (prioritas(stack[top]) == prioritas(infix[i]) &&
                     leftAssociative(infix[i]))))
            {
                postfix[j++] = pop(stack, &top);
            }

            push(stack, &top, infix[i]);
        }
    }

    while (!isEmpty(top))
        postfix[j++] = pop(stack, &top);

    postfix[j] = '\0';
}

void judul()
{
    printf("Program Konversi Infix ke Postfix\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
