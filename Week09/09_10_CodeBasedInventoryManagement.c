#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int          kode;
    char         nama[50];
    int          stok;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int kode, char *nama, int stok);
Node *insert(Node *root, int kode, char *nama, int stok);
Node *search(Node *root, int kode);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int kode);
void  inOrderTraversal(Node *root);
void  judul();

int main()
{
    judul();

    Node *root = NULL;

    // Daftarkan beberapa tiket
    root = insert(root, 3003, "Laptop", 10);
    insert(root, 3001, "Mouse", 50);
    insert(root, 3002, "Monitor", 20);
    insert(root, 3004, "Keyboard", 60);

    // Tampilkan data tiket
    printf("Stok inventori:\n");
    inOrderTraversal(root);

    // Cari produk
    int   id    = 3004;
    Node *found = search(root, id);

    if (found != NULL)
        printf("\nProduk dengan ID '%d' ditemukan, dengan nama '%s'.\n", id, found->nama);
    else
        printf("\nProduk dengan ID '%d' tidak ditemukan.\n", id);

    // Hapus produk
    int idHapus = 3002;
    if (deleteNode(root, idHapus))
        printf("\nProduk dengan ID '%d' berhasil dihapus.\n", idHapus);
    else
        printf("\nGagal menghapus produk dengan ID '%d'.\n", idHapus);

    // Tampilkan data produk setelah penghapusan
    printf("\nStok inventori setelah penghapusan:\n");
    inOrderTraversal(root);

    return 0;
}

Node *createNode(int kode, char *nama, int stok)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->kode = kode;
    strcpy(newNode->nama, nama);
    newNode->stok = stok;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int kode, char *nama, int stok)
{
    if (root == NULL)
        return createNode(kode, nama, stok);
    if (kode < root->kode)
        root->left = insert(root->left, kode, nama, stok);
    else if (kode > root->kode)
        root->right = insert(root->right, kode, nama, stok);
    return root;
}

Node *search(Node *root, int kode)
{
    if (root == NULL || root->kode == kode)
        return root;
    if (kode < root->kode)
        return search(root->left, kode);
    else
        return search(root->right, kode);
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int kode)
{
    if (root == NULL)
        return root;
    if (kode < root->kode)
        root->left = deleteNode(root->left, kode);
    else if (kode > root->kode)
        root->right = deleteNode(root->right, kode);
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
        Node *temp = findMin(root->right);
        root->kode = temp->kode;
        strcpy(root->nama, temp->nama);
        root->stok  = temp->stok;
        root->right = deleteNode(root->right, temp->kode);
    }
    return root;
}

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("Kode: %d | Nama: %s | Stok: %d\n", root->kode, root->nama, root->stok);
        inOrderTraversal(root->right);
    }
}

void judul()
{
    printf("Program Sistem Manajemen Inventaris Barang Berdasarkan Kode Barang\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
