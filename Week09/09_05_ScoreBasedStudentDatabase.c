#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa
{
    int   nim;
    char  nama[50];
    float nilai;

    struct Mahasiswa *left;
    struct Mahasiswa *right;
} Mahasiswa;

Mahasiswa *createNode(int nim, const char *nama, float nilai);
Mahasiswa *insert(Mahasiswa *root, int nim, const char *nama, float nilai);
Mahasiswa *search(Mahasiswa *root, float nilai);
Mahasiswa *findMin(Mahasiswa *node);
Mahasiswa *deleteNode(Mahasiswa *root, float nilai);
void       preOrder(Mahasiswa *root);
void       inOrder(Mahasiswa *root);
void       postOrder(Mahasiswa *root);
void       judul();

int main()
{
    judul();

    Mahasiswa *root = NULL;
    root            = insert(root, 101, "Andi", 85.5);
    root            = insert(root, 102, "Budi", 90.0);
    root            = insert(root, 103, "Citra", 75.0);
    root            = insert(root, 104, "Dewi", 80.0);

    printf("In-order Traversal:\n");
    inOrder(root);

    printf("\nPre-order Traversal:\n");
    preOrder(root);

    printf("\nPost-order Traversal:\n");
    postOrder(root);

    float      cariNilai = 80.0;
    Mahasiswa *hasil     = search(root, cariNilai);
    if (hasil != NULL)
        printf("\nMahasiswa dengan nilai %.2f ditemukan: %s\n", cariNilai, hasil->nama);
    else
        printf("\nMahasiswa dengan nilai %.2f tidak ditemukan.\n", cariNilai);

    float hapusNilai = 75.0;
    root             = deleteNode(root, hapusNilai);
    printf("\nSetelah menghapus mahasiswa dengan nilai %.2f:\n", hapusNilai);
    inOrder(root);

    return 0;
}

Mahasiswa *createNode(int nim, const char *nama, float nilai)
{
    Mahasiswa *newMahasiswa = (Mahasiswa *)malloc(sizeof(Mahasiswa));
    newMahasiswa->nim       = nim;
    newMahasiswa->nilai     = nilai;
    strcpy(newMahasiswa->nama, nama);

    newMahasiswa->left  = NULL;
    newMahasiswa->right = NULL;
    return newMahasiswa;
}

Mahasiswa *insert(Mahasiswa *root, int nim, const char *nama, float nilai)
{
    if (root == NULL) return createNode(nim, nama, nilai);
    if (nilai < root->nilai)
        root->left = insert(root->left, nim, nama, nilai);
    else
        root->right = insert(root->right, nim, nama, nilai);

    return root;
}

Mahasiswa *search(Mahasiswa *root, float nilai)
{
    if (root == NULL || root->nilai == nilai)
        return root;

    if (nilai < root->nilai)
        return search(root->left, nilai);
    else
        return search(root->right, nilai);
}

Mahasiswa *findMin(Mahasiswa *node)
{
    while (node->left != NULL)
        node = node->left;

    return node;
}

Mahasiswa *deleteNode(Mahasiswa *root, float nilai)
{
    if (root == NULL) return root;

    if (nilai < root->nilai)
        root->left = deleteNode(root->left, nilai);
    else if (nilai > root->nilai)
        root->right = deleteNode(root->right, nilai);
    else
    {
        if (root->left == NULL)
        {
            Mahasiswa *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Mahasiswa *temp = root->left;
            free(root);
            return temp;
        }

        Mahasiswa *temp = findMin(root->right);
        root->nilai     = temp->nilai;
        root->nim       = temp->nim;
        strcpy(root->nama, temp->nama);

        root->right = deleteNode(root->right, temp->nilai);
    }
    return root;
}

void preOrder(Mahasiswa *root)
{
    if (root != NULL)
    {
        printf("NIM: %d, Nama: %s, Nilai: %.2f\n", root->nim, root->nama, root->nilai);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Mahasiswa *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("NIM: %d, Nama: %s, Nilai: %.2f\n", root->nim, root->nama, root->nilai);
        inOrder(root->right);
    }
}

void postOrder(Mahasiswa *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("NIM: %d, Nama: %s, Nilai: %.2f\n", root->nim, root->nama, root->nilai);
    }
}

void judul()
{
    printf("Program Penyimpan Data Mahasiswa diurut dari Nilai\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
