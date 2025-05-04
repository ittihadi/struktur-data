#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FileSystemNode
{
    char name[100];
    bool isFolder;

    struct FileSystemNode *firstChild;
    struct FileSystemNode *nextSibling;
} FileSystemNode;

FileSystemNode *createNode(const char *name, bool isFolder);
void            addNode(FileSystemNode *parent, FileSystemNode *newNode);
FileSystemNode *searchNode(FileSystemNode *root, const char *name);
void            deleteTree(FileSystemNode *node);
bool            removeNode(FileSystemNode *root, const char *name);
void            displayStructure(FileSystemNode *node, int level);
void            judul();

int main()
{
    judul();

    // Buat root
    FileSystemNode *root = createNode("C:", true);

    // Buat beberapa folder dan file
    FileSystemNode *documents = createNode("Documents", true);
    FileSystemNode *downloads = createNode("Downloads", true);
    FileSystemNode *notes     = createNode("notes.txt", false);
    FileSystemNode *image     = createNode("image.jpg", false);

    // Bangun struktur
    addNode(root, documents);
    addNode(root, downloads);
    addNode(documents, notes);
    addNode(downloads, image);

    // Tampilkan struktur
    printf("Struktur File System:\n");
    displayStructure(root, 0);

    // Cari file
    char            searchName[] = "notes.txt";
    FileSystemNode *found        = searchNode(root, searchName);

    if (found != NULL)
        printf("\nFile '%s' ditemukan.\n", searchName);
    else
        printf("\nFile '%s' tidak ditemukan.\n", searchName);

    // Hapus folder
    char deleteName[] = "Downloads";
    if (removeNode(root, deleteName))
        printf("\nFolder '%s' berhasil dihapus.\n", deleteName);
    else
        printf("\nGagal menghapus folder '%s'.\n", deleteName);

    // Tampilkan struktur setelah penghapusan
    printf("\nStruktur setelah penghapusan:\n");
    displayStructure(root, 0);

    // Bersihkan memory
    deleteTree(root);

    return 0;
}
FileSystemNode *createNode(const char *name, bool isFolder)
{
    FileSystemNode *newNode = (FileSystemNode *)malloc(sizeof(FileSystemNode));
    strcpy(newNode->name, name);
    newNode->isFolder    = isFolder;
    newNode->firstChild  = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addNode(FileSystemNode *parent, FileSystemNode *newNode)
{
    if (parent == NULL || newNode == NULL || !parent->isFolder) return;

    if (parent->firstChild == NULL)
        parent->firstChild = newNode;
    else
    {
        FileSystemNode *current = parent->firstChild;
        while (current->nextSibling != NULL)
            current = current->nextSibling;

        current->nextSibling = newNode;
    }
}

FileSystemNode *searchNode(FileSystemNode *root, const char *name)
{
    if (root == NULL) return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    // Cari children juga
    FileSystemNode *found = searchNode(root->firstChild, name);
    if (found != NULL) return found;

    return searchNode(root->nextSibling, name);
}

void deleteTree(FileSystemNode *node)
{
    if (node == NULL) return;

    deleteTree(node->firstChild);
    deleteTree(node->nextSibling);
    free(node);
}

bool removeNode(FileSystemNode *root, const char *name)
{
    if (root == NULL) return false;

    FileSystemNode *prev    = NULL;
    FileSystemNode *current = root->firstChild;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (prev == NULL)
                root->firstChild = current->nextSibling;
            else
                prev->nextSibling = current->nextSibling;

            deleteTree(current);
            return true;
        }

        // Cari child juga
        if (removeNode(current, name))
            return true;

        prev    = current;
        current = current->nextSibling;
    }

    return false;
}

void displayStructure(FileSystemNode *node, int level)
{
    if (node == NULL) return;

    for (int i = 0; i < level; i++) printf("  ");
    printf("[%s] %s\n", node->isFolder ? "Folder" : "File", node->name);

    displayStructure(node->firstChild, level + 1);
    displayStructure(node->nextSibling, level);
}

void judul()
{
    printf("Program Sistem Penelusuran File dan Folder\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}
