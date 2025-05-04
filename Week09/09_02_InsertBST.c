#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int          data;
    struct Node *left;
    struct Node *right;
} Node;

void  judul();
Node *createNode(int data);
Node *insertNode(Node *node, int data);
void  inOrder(Node *node);

int main()
{
    judul();

    Node *root = NULL;
    root       = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("In-order traversal tree: ");
    inOrder(root);
    printf("\n");

    return 0;
}

Node *createNode(int data)
{
    Node *newNode  = (Node *)malloc(sizeof(Node));
    newNode->data  = data;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);

    return node;
}

void inOrder(Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

void judul()
{
    printf("Program Menambah Node pada Tree Binary Search\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
