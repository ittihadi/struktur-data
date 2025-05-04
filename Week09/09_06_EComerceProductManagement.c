#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CategoryNode
{
    char                 name[50];
    struct CategoryNode *firstChild;
    struct CategoryNode *nextSibling;
} CategoryNode;

CategoryNode *createCategory(const char *name);
void          addCategory(CategoryNode *parent, CategoryNode *newChild);
CategoryNode *findCategory(CategoryNode *root, const char *name);
void          deleteTree(CategoryNode *node);
bool          removeCategory(CategoryNode *root, const char *name);
void          displayHierarchy(CategoryNode *node, int level);
void          judul();

int main()
{
    judul();

    // Buat kategori root
    CategoryNode *root = createCategory("Produk");

    // Buat beberapa subkategori
    CategoryNode *elektronik = createCategory("Elektronik");
    CategoryNode *pakaian    = createCategory("Pakaian");
    CategoryNode *komputer   = createCategory("Komputer");
    CategoryNode *smartphone = createCategory("Smartphone");
    CategoryNode *laptop     = createCategory("Laptop");
    CategoryNode *desktop    = createCategory("Desktop");
    CategoryNode *pria       = createCategory("Pria");
    CategoryNode *wanita     = createCategory("Wanita");

    // Bangun hierarki
    addCategory(root, elektronik);
    addCategory(root, pakaian);
    addCategory(elektronik, komputer);
    addCategory(elektronik, smartphone);
    addCategory(komputer, laptop);
    addCategory(komputer, desktop);
    addCategory(pakaian, pria);
    addCategory(pakaian, wanita);

    // Tampilkan hierarki
    printf("Struktur Kategori Produk:\n");
    displayHierarchy(root, 0);

    // Cari kategori
    char          searchName[] = "Komputer";
    CategoryNode *found        = findCategory(root, searchName);

    if (found != NULL)
        printf("\nKategori '%s' ditemukan.\n", searchName);
    else
        printf("\nKategori '%s' tidak ditemukan.\n", searchName);

    // Hapus kategori
    char deleteName[] = "Komputer";
    if (removeCategory(root, deleteName))
        printf("\nKategori '%s' berhasil dihapus.\n", deleteName);
    else
        printf("\nGagal menghapus kategori '%s'.\n", deleteName);

    // Tampilkan hierarki setelah penghapusan
    printf("\nStruktur Kategori Produk setelah penghapusan:\n");
    displayHierarchy(root, 0);

    // Bersihkan memory
    deleteTree(root);

    return 0;
}

CategoryNode *createCategory(const char *name)
{
    CategoryNode *newNode = (CategoryNode *)malloc(sizeof(CategoryNode));
    strcpy(newNode->name, name);

    newNode->firstChild  = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}

void addCategory(CategoryNode *parent, CategoryNode *newChild)
{
    if (parent == NULL || newChild == NULL) return;

    // Jika parent belum memiliki child
    if (parent->firstChild == NULL)
        parent->firstChild = newChild;

    // Jika sudah ada child, tambahkan sebagai sibling terakhir
    else
    {
        CategoryNode *sibling = parent->firstChild;
        while (sibling->nextSibling != NULL)
            sibling = sibling->nextSibling;

        sibling->nextSibling = newChild;
    }
}

CategoryNode *findCategory(CategoryNode *root, const char *name)
{
    if (root == NULL) return NULL;

    // Cek current node
    if (strcmp(root->name, name) == 0)
        return root;

    // Cek children
    CategoryNode *found = findCategory(root->firstChild, name);
    if (found != NULL) return found;

    // Cek siblings
    return findCategory(root->nextSibling, name);
}

void deleteTree(CategoryNode *node)
{
    if (node == NULL) return;

    // Hapus semua children terlebih dahulu
    deleteTree(node->firstChild);

    // Hapus semua siblings
    deleteTree(node->nextSibling);

    // Baru hapus node
    free(node);
}

bool removeCategory(CategoryNode *root, const char *name)
{
    // Jangan hapus root
    if (root == NULL || strcmp(root->name, name) == 0)
        return false;

    // Cek children dari root
    CategoryNode *prev    = NULL;
    CategoryNode *current = root->firstChild;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            // Hapus node dan semua child-nya
            if (prev == NULL)
            {
                root->firstChild     = current->nextSibling;
                current->nextSibling = NULL;
            }
            else
                prev->nextSibling = current->nextSibling;

            deleteTree(current);
            return true;
        }

        // Rekursif ke child dari current node
        if (removeCategory(current, name))
            return true;

        prev    = current;
        current = current->nextSibling;
    }

    return false;
}

void displayHierarchy(CategoryNode *node, int level)
{
    if (node == NULL) return;

    // Print indentasi
    for (int i = 0; i < level; i++)
        printf("--");

    printf("%s\n", node->name);

    // Print children terlebih dahulu
    displayHierarchy(node->firstChild, level + 1);

    // Kemudian siblings
    displayHierarchy(node->nextSibling, level);
}

void judul()
{
    printf("Program Manajemen Kategori Produk E-Commerce\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
