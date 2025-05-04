#include <stdint.h>
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
Node *findMin(Node *node);
Node *deleteNode(Node *root, int key);

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

    deleteNode(root, 20);
    deleteNode(root, 70);

    printf("In-order traversal tree setelah penghapusan 20 dan 70: ");
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

Node *findMin(Node *node)
{
    while (node->left != NULL)
        node = node->left;

    return node;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Successor
        Node *temp  = findMin(root->right);
        root->data  = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void judul()
{
    printf("Program Menghapus Node pada Tree Binary Search\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
