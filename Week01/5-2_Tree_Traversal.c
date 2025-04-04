// Preprocessors
#include <stdio.h>

// Deklarasi struct
struct TreeNode
{
    int data;

    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

// Deklarasi Fungsi-fungsi
void preorder(TreeNode *root);
void judul();

int main()
{
    // Tampilkan judul
    judul();

    TreeNode leaf1 = (TreeNode){.data = 2, .left = NULL, .right = NULL};
    TreeNode leaf2 = (TreeNode){.data = 3, .left = NULL, .right = NULL};
    TreeNode root  = (TreeNode){.data = 1, .left = &leaf1, .right = &leaf2};

    printf("Traversal Tree dengan 3 node:\n");
    preorder(&root);

    return 0;
}

// Definisi Fungsi-fungsi
void judul()
{
    printf("Program Traversal Tree Rekursif\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void preorder(TreeNode *root)
{
    // Base case
    if (root == NULL) return;

    // Recursive case
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
