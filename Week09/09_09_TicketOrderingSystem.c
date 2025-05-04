#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int  ID;
    char nama[50];
    char kategori[30];

    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int ID, char *nama, char *kategori);
Node *insert(Node *root, int ID, char *nama, char *kategori);
Node *search(Node *root, int ID);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int ID);
void  inOrderTraversal(Node *root);
void  judul();

int main()
{
    judul();

    Node *root = NULL;

    // Daftarkan beberapa tiket
    root = insert(root, 2003, "Rina", "VIP");
    insert(root, 2001, "Ari", "Reguler");
    insert(root, 2004, "Nina", "VIP");
    insert(root, 2002, "Budi", "Reguler");

    // Tampilkan data tiket
    printf("Tiket terdaftar:\n");
    inOrderTraversal(root);

    // Cari tiket
    int   id    = 2004;
    Node *found = search(root, id);

    if (found != NULL)
        printf("\nTiket dengan ID '%d' ditemukan, atas nama '%s'.\n", id, found->nama);
    else
        printf("\nTiket dengan ID '%d' tidak ditemukan.\n", id);

    // Hapus tiket
    int idHapus = 2003;
    if (deleteNode(root, idHapus))
        printf("\nTiket dengan ID '%d' berhasil dihapus.\n", idHapus);
    else
        printf("\nGagal menghapus tiket dengan ID '%d'.\n", idHapus);

    // Tampilkan data tiket setelah penghapusan
    printf("\nTiket terdaftar setelah penghapusan:\n");
    inOrderTraversal(root);

    return 0;
}

Node *createNode(int ID, char *nama, char *kategori)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->ID   = ID;
    strcpy(newNode->nama, nama);
    strcpy(newNode->kategori, kategori);

    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int ID, char *nama, char *kategori)
{
    if (root == NULL)
        return createNode(ID, nama, kategori);

    if (ID < root->ID)
        root->left = insert(root->left, ID, nama, kategori);
    else if (ID > root->ID)
        root->right = insert(root->right, ID, nama, kategori);

    return root;
}

Node *search(Node *root, int ID)
{
    if (root == NULL || root->ID == ID)
        return root;

    if (ID < root->ID)
        return search(root->left, ID);
    else
        return search(root->right, ID);
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int ID)
{
    if (root == NULL)
        return root;

    if (ID < root->ID)
        root->left = deleteNode(root->left, ID);
    else if (ID > root->ID)
        root->right = deleteNode(root->right, ID);
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
        root->ID   = temp->ID;
        strcpy(root->nama, temp->nama);
        strcpy(root->kategori, temp->kategori);
        root->right = deleteNode(root->right, temp->ID);
    }

    return root;
}

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("ID: %d | Nama: %s | Kategori: %s\n", root->ID, root->nama, root->kategori);
        inOrderTraversal(root->right);
    }
}

void judul()
{
    printf("Program Sistem Pemesanan Tiket Konser Berdasarkan ID Pemesanan\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
