// Preprocessors
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int          x;
    int          y;
    struct Node *next;
} Node;

// Deklarasi fungsi-fungsi
void judul();
void push(Node **top, int x, int y);
void pop(Node **top);
int  isEmpty(Node *top);
void displayPath(Node *top);
int  isSafe(int maze[][MAX], int visited[][MAX], int x, int y, int n, int m);
int  backtrackingLabirin(int maze[][MAX], int n, int m,
                         int startX, int startY, int endX, int endY);

int main()
{
    // Tampilkan judul program
    judul();

    int maze[MAX][MAX];
    int n, m;
    int startX, startY;
    int endX, endY;

    printf("Masukkan ukuran labirin (n m): ");
    scanf("%d %d", &n, &m);

    printf("Masukkan labirin (1 untuk jalan, 0 untuk penghalang):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maze[i][j]);

    printf("Masukkan posisi awal (x y): ");
    scanf("%d %d", &startX, &startY);

    printf("Masukkan posisi tujuan (x y): ");
    scanf("%d %d", &endX, &endY);

    if (!backtrackingLabirin(maze, n, m, startX, startY, endX, endY))
        printf("Tidak ada jalur yang dapat ditemukan.\n");

    return 0;
}

// Definisi fungsi-fungsi
void push(Node **top, int x, int y)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->x    = x;
    new->y    = y;
    new->next = *top;
    *top      = new;
}

void pop(Node **top)
{
    if (*top == NULL)
        return;

    Node *temp = *top;
    *top       = temp->next;
    free(temp);
}

int isEmpty(Node *top)
{
    return top == NULL;
}

void displayPath(Node *top)
{
    if (isEmpty(top))
    {
        printf("Tidak ada jalur.\n");
        return;
    }

    printf("Jalur: ");
    Node *current = top;

    while (current != NULL)
    {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }

    printf("\n");
}

int isSafe(int maze[][MAX], int visited[][MAX], int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1 && visited[x][y] == 0);
}

int backtrackingLabirin(int maze[][MAX], int n, int m,
                        int startX, int startY, int endX, int endY)
{
    int   visited[MAX][MAX] = {0};
    Node *stack             = NULL;

    // Mulai dari posisi awal
    push(&stack, startX, startY);
    visited[startX][startY] = 1;

    // Gerakan { atas, bawah, kiri, kanan }
    int row[] = {-1, 1, 0, 0};
    int col[] = {0, 0, -1, 1};

    while (!isEmpty(stack))
    {
        int x = stack->x;
        int y = stack->y;

        // Cek jika sampai tujuan
        if (x == endX && y == endY)
        {
            displayPath(stack);
            return 1;
        }

        int found = 0;

        // Coba semua arah
        for (int i = 0; i < 4; i++)
        {
            int newX = x + row[i];
            int newY = y + col[i];

            if (isSafe(maze, visited, newX, newY, n, m))
            {
                push(&stack, newX, newY);
                visited[newX][newY] = 1;
                found               = 1;
                break;
            }
        }

        // Jika buntu, mundur ke node sebelumnya
        if (!found)
        {
            pop(&stack);
        }
    }

    printf("Jalur tidak ditemukan.\n");
    return 0;
}

void judul()
{
    printf("Program Simulasi Backtracking\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
