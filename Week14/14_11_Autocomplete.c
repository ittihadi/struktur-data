#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE   26
#define MAX_SUGGESTIONS 100
#define MAX_WORD_LENGTH 50

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool             isEndOfWord;
} TrieNode;

void      judul();
TrieNode *createNode();
void      insert(TrieNode *root, const char *word);
void      collectWords(TrieNode *node, char *currentPrefix, int length,
                       char suggestions[][MAX_WORD_LENGTH], int *count);
int       autocomplete(TrieNode *root, const char *prefix, char suggestions[][MAX_WORD_LENGTH]);
void      loadDictionary(TrieNode *root, const char *filename);

int main()
{
    judul();

    TrieNode *root = createNode();

    // Insert dictionary
    loadDictionary(root, "dictionary.txt");

    char prefix[MAX_WORD_LENGTH];
    printf("Enter prefix: ");
    scanf("%s", prefix);

    char suggestions[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
    int  count = autocomplete(root, prefix, suggestions);

    if (count == 0)
    {
        printf("No suggestions found for prefix '%s'\n", prefix);
    }
    else
    {
        printf("Suggestions for '%s':\n", prefix);
        for (int i = 0; i < count; i++)
        {
            printf("%d. %s\n", i + 1, suggestions[i]);
        }
    }

    return 0;
}

void judul()
{
    printf("Program Autocomplete Menggunakan Trie\n");
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
    {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *word)
{
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        if (!current->children[index])
        {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void collectWords(TrieNode *node, char *currentPrefix, int length, char suggestions[][MAX_WORD_LENGTH], int *count)
{
    if (node == NULL || *count >= MAX_SUGGESTIONS) return;

    if (node->isEndOfWord)
    {
        currentPrefix[length] = '\0';
        strcpy(suggestions[*count], currentPrefix);
        (*count)++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != NULL)
        {
            currentPrefix[length] = 'a' + i;
            collectWords(node->children[i], currentPrefix, length + 1, suggestions, count);
        }
    }
}

int autocomplete(TrieNode *root, const char *prefix, char suggestions[][MAX_WORD_LENGTH])
{
    TrieNode *current = root;
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        int index = prefix[i] - 'a';
        if (!current->children[index])
        {
            return 0;
        }
        current = current->children[index];
    }

    char currentPrefix[MAX_WORD_LENGTH];
    strcpy(currentPrefix, prefix);
    int count = 0;
    collectWords(current, currentPrefix, strlen(prefix), suggestions, &count);
    return count;
}

void loadDictionary(TrieNode *root, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary file\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF)
    {
        insert(root, word);
    }

    fclose(file);
}
