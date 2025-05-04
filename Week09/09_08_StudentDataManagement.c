#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int          NIM;
    char         Nama[50];
    char         Jurusan[50];
    struct Node *Left;
    struct Node *Right;
} Node;

Node *createNode(int NIM, char *Nama, char *Jurusan);
Node *insert(Node *root, int NIM, char *Nama, char *Jurusan);
Node *search(Node *root, int NIM);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int NIM);
void  inOrderTraversal(Node *root);
void  judul();

int main()
{
    judul();

    Node *root = NULL;

    // Daftar beberapa mahasiswa
    root = insert(root, 102, "Andi", "Informatika");
    insert(root, 101, "Budi", "Sistem Informasi");
    insert(root, 104, "Citra", "Teknik Komputer");
    insert(root, 103, "Dina", "Teknik Informatika");

    // Tampilkan data mahasiswa
    printf("Data Mahasiswa:\n");
    inOrderTraversal(root);

    // Cari mahasiswa
    int   nim   = 101;
    Node *found = search(root, nim);

    if (found != NULL)
        printf("\nMahasiswa dengan NIM '%d' ditemukan, bernama '%s'.\n", nim, found->Nama);
    else
        printf("\nMahasiswa dengan NIM '%d' tidak ditemukan.\n", nim);

    // Hapus mahasiswa
    int nimHapus = 102;
    if (deleteNode(root, nimHapus))
        printf("\nMahasiswa dengan NIM '%d' berhasil dihapus.\n", nimHapus);
    else
        printf("\nGagal menghapus mahasiswa dengan NIM '%d'.\n", nimHapus);

    // Tampilkan data mahasiswa setelah penghapusan
    printf("\nData mahasiswa setelah penghapusan:\n");
    inOrderTraversal(root);

    return 0;
}

Node *createNode(int NIM, char *Nama, char *Jurusan)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->NIM  = NIM;
    strcpy(newNode->Nama, Nama);
    strcpy(newNode->Jurusan, Jurusan);
    newNode->Left = newNode->Right = NULL;
    return newNode;
}

Node *insert(Node *root, int NIM, char *Nama, char *Jurusan)
{
    if (root == NULL)
        return createNode(NIM, Nama, Jurusan);
    if (NIM < root->NIM)
        root->Left = insert(root->Left, NIM, Nama, Jurusan);
    else if (NIM > root->NIM)
        root->Right = insert(root->Right, NIM, Nama, Jurusan);
    return root;
}

Node *search(Node *root, int NIM)
{
    if (root == NULL || root->NIM == NIM)
        return root;
    if (NIM < root->NIM)
        return search(root->Left, NIM);
    else
        return search(root->Right, NIM);
}

Node *findMin(Node *root)
{
    while (root->Left != NULL)
        root = root->Left;
    return root;
}

Node *deleteNode(Node *root, int NIM)
{
    if (root == NULL)
        return root;
    if (NIM < root->NIM)
        root->Left = deleteNode(root->Left, NIM);
    else if (NIM > root->NIM)
        root->Right = deleteNode(root->Right, NIM);
    else
    {
        if (root->Left == NULL)
        {
            Node *temp = root->Right;
            free(root);
            return temp;
        }
        else if (root->Right == NULL)
        {
            Node *temp = root->Left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->Right);
        root->NIM  = temp->NIM;
        strcpy(root->Nama, temp->Nama);
        strcpy(root->Jurusan, temp->Jurusan);
        root->Right = deleteNode(root->Right, temp->NIM);
    }
    return root;
}

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->Left);
        printf("NIM: %d | Nama: %s | Jurusan: %s\n", root->NIM, root->Nama, root->Jurusan);
        inOrderTraversal(root->Right);
    }
}

void judul()
{
    printf("Program Manajemen Data Mahasiswa\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
