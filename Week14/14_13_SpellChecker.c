#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE   26
#define MAX_SUGGESTIONS 20
#define MAX_WORD_LENGTH 50

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool             isEndOfWord;
} TrieNode;

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

void judul();
void insert(TrieNode *root, const char *word);
bool search(TrieNode *root, const char *word);
void findAllWords(TrieNode *node, char *prefix, int length,
                  char suggestions[][MAX_WORD_LENGTH], int *count);
void generateEdits(const char *word, char edits[][MAX_WORD_LENGTH], int *editCount);
int  getSuggestions(TrieNode *root, const char *word, char suggestions[][MAX_WORD_LENGTH]);
void loadDictionary(TrieNode *root, const char *filename);

int main()
{
    judul();

    TrieNode *root = createNode();
    loadDictionary(root, "dictionary.txt");

    char input[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", input);

    if (search(root, input))
    {
        printf("\"%s\" is spelled correctly!\n", input);
    }
    else
    {
        printf("\"%s\" may be misspelled. Suggestions:\n", input);

        char suggestions[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
        int  count = getSuggestions(root, input, suggestions);

        if (count == 0)
        {
            printf("No suggestions found\n");
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                printf("%d. %s\n", i + 1, suggestions[i]);
            }
        }
    }

    return 0;
}

void judul()
{
    printf("Program Spell Checker Menggunakan Trie\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void insert(TrieNode *root, const char *word)
{
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = tolower(word[i]) - 'a';
        if (!current->children[index])
        {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(TrieNode *root, const char *word)
{
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = tolower(word[i]) - 'a';
        if (!current->children[index])
        {
            return false;
        }
        current = current->children[index];
    }
    return current != NULL && current->isEndOfWord;
}

void findAllWords(TrieNode *node, char *prefix, int length, char suggestions[][MAX_WORD_LENGTH], int *count)
{
    if (node == NULL || *count >= MAX_SUGGESTIONS) return;

    if (node->isEndOfWord)
    {
        prefix[length] = '\0';
        strcpy(suggestions[*count], prefix);
        (*count)++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != NULL)
        {
            prefix[length] = 'a' + i;
            findAllWords(node->children[i], prefix, length + 1, suggestions, count);
        }
    }
}

void generateEdits(const char *word, char edits[][MAX_WORD_LENGTH], int *editCount)
{
    char temp[MAX_WORD_LENGTH];
    int  len = strlen(word);

    // Deletes (remove one letter)
    for (int i = 0; i < len && *editCount < MAX_SUGGESTIONS; i++)
    {
        strcpy(temp, word);
        memmove(&temp[i], &temp[i + 1], len - i);
        strcpy(edits[(*editCount)++], temp);
    }

    // Transposes (swap adjacent letters)
    for (int i = 0; i < len - 1 && *editCount < MAX_SUGGESTIONS; i++)
    {
        strcpy(temp, word);
        char c      = temp[i];
        temp[i]     = temp[i + 1];
        temp[i + 1] = c;
        strcpy(edits[(*editCount)++], temp);
    }

    // Replaces (change one letter)
    for (int i = 0; i < len && *editCount < MAX_SUGGESTIONS; i++)
    {
        for (char c = 'a'; c <= 'z' && *editCount < MAX_SUGGESTIONS; c++)
        {
            if (c == word[i]) continue;
            strcpy(temp, word);
            temp[i] = c;
            strcpy(edits[(*editCount)++], temp);
        }
    }
}

int getSuggestions(TrieNode *root, const char *word, char suggestions[][MAX_WORD_LENGTH])
{
    int  count = 0;
    char prefix[MAX_WORD_LENGTH];
    int  prefixLen = 0;

    // Cari prefix yang valid
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = tolower(word[i]) - 'a';
        if (!current->children[index]) break;
        prefix[prefixLen++] = word[i];
        current             = current->children[index];
    }
    prefix[prefixLen] = '\0';

    // Cari kata dengan prefix yang sama
    if (prefixLen > 0)
    {
        findAllWords(current, prefix, prefixLen, suggestions, &count);
    }

    // Generate edits
    char edits[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
    int  editCount = 0;
    generateEdits(word, edits, &editCount);

    // Cari kata yang valid dari edits
    for (int i = 0; i < editCount && count < MAX_SUGGESTIONS; i++)
    {
        if (search(root, edits[i]))
        {
            bool exists = false;
            for (int j = 0; j < count; j++)
            {
                if (strcmp(suggestions[j], edits[i]) == 0)
                {
                    exists = true;
                    break;
                }
            }
            if (!exists)
            {
                strcpy(suggestions[count++], edits[i]);
            }
        }
    }

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
