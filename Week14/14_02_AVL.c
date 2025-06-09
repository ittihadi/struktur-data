#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode
{
    int             key;
    struct AVLNode *left;
    struct AVLNode *right;
    int             height;
} AVLNode;

void     judul();
int      height(AVLNode *node);
AVLNode *newNode(int key);
AVLNode *leftRotate(AVLNode *x);
AVLNode *rightRotate(AVLNode *y);
AVLNode *insert(AVLNode *node, int key);
void     preOrder(AVLNode *root);

int main()
{
    judul();

    AVLNode *root = NULL;
    root          = insert(root, 10);
    root          = insert(root, 20);
    root          = insert(root, 30);
    root          = insert(root, 40);
    root          = insert(root, 50);
    root          = insert(root, 25);

    printf("Preorder traversal: ");
    preOrder(root);
    return 0;
}

void judul()
{
    printf("Program Implementasi AVL Tree\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void preOrder(AVLNode *root)
{
    if (root == NULL) return;

    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int max(int a, int b) { return (a > b) ? a : b; }

int height(AVLNode *node)
{
    if (node == NULL) return 0;
    return node->height;
}

AVLNode *newNode(int key)
{
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    node->key     = key;
    node->left    = NULL;
    node->right   = NULL;
    node->height  = 1;
    return node;
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x  = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left  = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y  = x->right;
    AVLNode *T2 = y->left;

    y->left  = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *insert(AVLNode *node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = height(node->left) - height(node->right);

    // Rotasi sesuai kasus
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
