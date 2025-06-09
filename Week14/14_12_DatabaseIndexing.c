#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDER    3
#define MAX_KEYS (ORDER - 1)

typedef struct BPlusTreeNode
{
    bool                  is_leaf;
    int                   keys[MAX_KEYS];
    void                 *pointers[ORDER];
    int                   num_keys;
    struct BPlusTreeNode *next;
} BPlusTreeNode;

typedef struct
{
    int  key;
    char value[50];
} Record;

void           judul();
BPlusTreeNode *createNewNode(bool is_leaf);
void           insertNonFull(BPlusTreeNode *node, int key, void *value);
BPlusTreeNode *insert(BPlusTreeNode *root, int key, void *value);
Record        *search(BPlusTreeNode *root, int key);
void           rangeQuery(BPlusTreeNode *root, int start_key, int end_key);
void           splitChild(BPlusTreeNode *parent, int index, BPlusTreeNode *child);

int main()
{
    judul();

    BPlusTreeNode *root = NULL;

    // Sample records
    Record records[] = {
        {101, "John"},
        {205, "Alice"},
        {307, "Bob"},
        {150, "Charlie"},
        {250, "David"},
        {300, "Eve"}};

    // Insert records
    for (int i = 0; i < sizeof(records) / sizeof(Record); i++)
    {
        Record *record = (Record *)malloc(sizeof(Record));
        record->key    = records[i].key;
        strcpy(record->value, records[i].value);
        root = insert(root, record->key, record);
    }

    // Test search
    int     search_key = 205;
    Record *result     = search(root, search_key);
    if (result != NULL)
    {
        printf("Search result for key %d: %s\n", search_key, result->value);
    }
    else
    {
        printf("Record with key %d not found\n", search_key);
    }

    // Test range query
    rangeQuery(root, 200, 300);

    // Test range query semua
    printf("\n");
    rangeQuery(root, 100, 400);

    return 0;
}

void judul()
{
    printf("Program Database Indexing Menggunakan B+ Tree\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

BPlusTreeNode *createNewNode(bool is_leaf)
{
    BPlusTreeNode *node = (BPlusTreeNode *)malloc(sizeof(BPlusTreeNode));
    node->is_leaf       = is_leaf;
    node->num_keys      = 0;
    node->next          = NULL;
    return node;
}

void insertNonFull(BPlusTreeNode *node, int key, void *value)
{
    int i = node->num_keys - 1;

    if (node->is_leaf)
    {
        while (i >= 0 && key < node->keys[i])
        {
            node->keys[i + 1]     = node->keys[i];
            node->pointers[i + 1] = node->pointers[i];
            i--;
        }
        node->keys[i + 1]     = key;
        node->pointers[i + 1] = value;
        node->num_keys++;
    }
    else
    {
        while (i >= 0 && key < node->keys[i])
            i--;
        i++;

        BPlusTreeNode *child = node->pointers[i];
        if (child->num_keys == MAX_KEYS)
        {
            splitChild(node, i, child);

            if (key > node->keys[i])
                i++;

            child = node->pointers[i];
        }
        insertNonFull(child, key, value);
    }
}

BPlusTreeNode *insert(BPlusTreeNode *root, int key, void *value)
{
    if (root == NULL)
    {
        root              = createNewNode(true);
        root->keys[0]     = key;
        root->pointers[0] = value;
        root->num_keys    = 1;
        return root;
    }

    if (root->num_keys == MAX_KEYS)
    {
        BPlusTreeNode *new_root = createNewNode(false);
        new_root->pointers[0]   = root;
        splitChild(new_root, 0, root);
        insertNonFull(new_root, key, value);
        return new_root;
    }
    else
    {
        insertNonFull(root, key, value);
        return root;
    }
}

Record *search(BPlusTreeNode *root, int key)
{
    BPlusTreeNode *node = root;
    while (node != NULL && !node->is_leaf)
    {
        int i = 0;
        while (i < node->num_keys && key >= node->keys[i])
            i++;
        node = node->pointers[i];
    }

    if (node != NULL)
    {
        for (int i = 0; i < node->num_keys; i++)
        {
            if (node->keys[i] == key)
                return (Record *)node->pointers[i];
        }
    }
    return NULL;
}

void rangeQuery(BPlusTreeNode *root, int start_key, int end_key)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    BPlusTreeNode *node = root;
    while (node != NULL && !node->is_leaf)
    {
        int i = 0;
        while (i < node->num_keys && start_key >= node->keys[i])
            i++;
        node = node->pointers[i];
    }

    printf("Records in range %d to %d:\n", start_key, end_key);
    bool found = false;
    while (node != NULL)
    {
        for (int i = 0; i < node->num_keys; i++)
        {
            if (node->keys[i] >= start_key && node->keys[i] <= end_key)
            {
                Record *record = (Record *)node->pointers[i];
                printf("Key: %d, Value: %s\n", record->key, record->value);
                found = true;
            }
        }
        node = node->next;
    }

    if (!found)
    {
        printf("No records found in this range\n");
    }
}

void splitChild(BPlusTreeNode *parent, int index, BPlusTreeNode *child)
{
    int mid = MAX_KEYS / 2;

    BPlusTreeNode *new_child = createNewNode(child->is_leaf);
    new_child->num_keys      = child->num_keys - mid;

    if (child->is_leaf)
    {
        for (int i = 0; i < new_child->num_keys; i++)
        {
            new_child->keys[i]     = child->keys[mid + i];
            new_child->pointers[i] = child->pointers[mid + i];
        }
        child->num_keys = mid;

        new_child->next = child->next;
        child->next     = new_child;

        for (int i = parent->num_keys; i > index; i--)
        {
            parent->keys[i]         = parent->keys[i - 1];
            parent->pointers[i + 1] = parent->pointers[i];
        }

        parent->keys[index]         = new_child->keys[0];
        parent->pointers[index + 1] = new_child;
        parent->num_keys++;
    }
    else
    {
        for (int i = 0; i < child->num_keys - mid - 1; i++)
        {
            new_child->keys[i]     = child->keys[mid + i + 1];
            new_child->pointers[i] = child->pointers[mid + i + 1];
        }
        new_child->pointers[child->num_keys - mid - 1] = child->pointers[child->num_keys];

        new_child->num_keys = child->num_keys - mid - 1;
        int mid_key         = child->keys[mid];

        child->num_keys = mid;

        for (int i = parent->num_keys; i > index; i--)
        {
            parent->keys[i]         = parent->keys[i + 1];
            parent->pointers[i + 1] = parent->pointers[i];
        }

        parent->keys[index]         = mid_key;
        parent->pointers[index + 1] = new_child;
        parent->num_keys++;
    }
}
