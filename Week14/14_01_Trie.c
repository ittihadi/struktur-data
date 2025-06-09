#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool             isEndOfWord;
} TrieNode;

void      judul();
TrieNode *createNode();
void      insert(TrieNode *root, const char *word);
bool      search(TrieNode *root, const char *word);

int main()
{
    judul();

    TrieNode *root = createNode();
    insert(root, "algorithm");
    insert(root, "data");
    insert(root, "structure");

    printf("Search 'data': %s\n", search(root, "data") ? "Found" : "Not Found");
    printf("Search 'tree': %s\n", search(root, "tree") ? "Found" : "Not Found");
    return 0;
}

void judul()
{
    printf("Program Implementasi Trie\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

TrieNode *createNode()
{
    TrieNode *node    = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode *root, const char *word)
{
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (!current->children[index])
            current->children[index] = createNode();
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(TrieNode *root, const char *word)
{
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (!current->children[index])
            return false;
        current = current->children[index];
    }
    return (current != NULL && current->isEndOfWord);
}
