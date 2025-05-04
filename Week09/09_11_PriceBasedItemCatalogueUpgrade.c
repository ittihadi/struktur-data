#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produk
{
    int  id;
    char nama[50];
    int  harga;

    struct Produk *left;
    struct Produk *right;
} Produk;

void    judul();
Produk *createProduk(int id, const char *nama, int harga);
Produk *insertProduk(Produk *root, int id, const char *nama, int harga);
Produk *search(Produk *root, int id);
void    update(Produk *root, int id, int hargaBaru);
void    inOrderProduk(Produk *root);

int main()
{
    judul();

    Produk *katalog = NULL;
    katalog         = insertProduk(katalog, 101, "Mouse", 150000);
    katalog         = insertProduk(katalog, 102, "Keyboard", 300000);
    katalog         = insertProduk(katalog, 103, "Monitor", 1500000);
    katalog         = insertProduk(katalog, 104, "Headset", 450000);
    katalog         = insertProduk(katalog, 105, "Case", 1000000);
    katalog         = insertProduk(katalog, 106, "SSD", 600000);

    printf("Daftar Harga Produk:\n");
    inOrderProduk(katalog);

    // Cari produk
    int     id    = 102;
    Produk *found = search(katalog, id);

    if (found != NULL)
        printf("\nProduk dengan ID '%d' ditemukan, dengan harga '%d'.\n", id, found->harga);
    else
        printf("\nProduk dengan ID '%d' tidak ditemukan.\n", id);

    // Perbarui produk
    int idUpdate    = 105;
    int hargaUpdate = 1200000;
    update(katalog, idUpdate, hargaUpdate);

    // Tampilkan data produk setelah pembaruan
    printf("Daftar Harga Produk Setelah Pembaruan Harga:\n");
    inOrderProduk(katalog);
    return 0;
}

Produk *createProduk(int id, const char *nama, int harga)
{
    Produk *newProduk = (Produk *)malloc(sizeof(Produk));
    newProduk->id     = id;
    newProduk->harga  = harga;
    strcpy(newProduk->nama, nama);

    newProduk->left  = NULL;
    newProduk->right = NULL;
    return newProduk;
}

Produk *insertProduk(Produk *root, int id, const char *nama, int harga)
{
    if (root == NULL) return createProduk(id, nama, harga);

    if (id < root->id)
        root->left = insertProduk(root->left, id, nama, harga);
    else
        root->right = insertProduk(root->right, id, nama, harga);

    return root;
}

Produk *search(Produk *root, int id)
{
    if (root == NULL || root->id == id)
        return root;
    if (id < root->id)
        return search(root->left, id);
    else
        return search(root->right, id);
}

void update(Produk *root, int id, int hargaBaru)
{
    if (root == NULL) return;

    if (root->id == id)
    {
        root->harga = hargaBaru;
        return;
    }

    if (id < root->id)
        update(root->left, id, hargaBaru);
    else
        update(root->right, id, hargaBaru);
}

void inOrderProduk(Produk *root)
{
    if (root != NULL)
    {
        inOrderProduk(root->left);
        printf("ID: %d, Nama: %s, Harga: %d\n", root->id, root->nama, root->harga);
        inOrderProduk(root->right);
    }
}

void judul()
{
    printf("Program Katalog Produk Berdasarkan Harga Extra\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
