#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 3
#define HASH_SIZE  100

typedef struct CacheNode
{
    char              url[256];
    char              content[1024];
    struct CacheNode *prev, *next;
} CacheNode;

typedef struct
{
    CacheNode* table[HASH_SIZE];
    CacheNode *head, *tail;
    int        count;
} LRUCache;

void         judul();
unsigned int hash_url(const char* url);
void         add_to_head(LRUCache* cache, CacheNode* node);
void         remove_node(LRUCache* cache, CacheNode* node);
void         access_url(LRUCache* cache, const char* url, const char* content);
void         print_cache(LRUCache* cache);

int main()
{
    judul();

    LRUCache cache = {0};

    // Skenario 1: Isi cache
    access_url(&cache, "example.com/page1", "<html>1</html>");
    access_url(&cache, "example.com/page2", "<html>2</html>");
    access_url(&cache, "example.com/page3", "<html>3</html>");
    print_cache(&cache);

    // Skenario 2: Akses page2 (seharusnya promote ke head)
    access_url(&cache, "example.com/page2", "<html>2</html>");
    print_cache(&cache);

    // Skenario 3: Tambah page4 (seharusnya page1 keluar)
    access_url(&cache, "example.com/page4", "<html>4</html>");
    print_cache(&cache);

    return 0;
}

void judul()
{
    printf("Program Aplikasi Cache Web Server\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

unsigned int hash_url(const char* url)
{
    unsigned long hash = 5381;
    int           c;
    while ((c = *url++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASH_SIZE;
}

void add_to_head(LRUCache* cache, CacheNode* node)
{
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head != NULL)
        cache->head->prev = node;
    cache->head = node;
    if (cache->tail == NULL)
        cache->tail = node;
}

void remove_node(LRUCache* cache, CacheNode* node)
{
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        cache->head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    else
        cache->tail = node->prev;
}

void access_url(LRUCache* cache, const char* url, const char* content)
{
    unsigned int index = hash_url(url);
    CacheNode*   node  = cache->table[index];

    // Cek apakah sudah di cache
    while (node != NULL)
    {
        if (strcmp(node->url, url) == 0)
        {
            // Update posisi ke head
            remove_node(cache, node);
            add_to_head(cache, node);
            printf("Cache HIT: %s\n", url);
            return;
        }
        node = node->next;
    }

    printf("Cache MISS: %s\n", url);

    // Jika cache penuh, hapus LRU
    if (cache->count >= CACHE_SIZE)
    {
        CacheNode*   to_remove  = cache->tail;
        unsigned int tail_index = hash_url(to_remove->url);

        // Hapus dari hash table
        CacheNode** ptr = &cache->table[tail_index];
        while (*ptr != to_remove)
        {
            ptr = &(*ptr)->next;
        }
        *ptr = to_remove->next;

        remove_node(cache, to_remove);
        free(to_remove);
        cache->count--;
    }

    // Tambahkan baru
    CacheNode* new_node = malloc(sizeof(CacheNode));
    strcpy(new_node->url, url);
    strcpy(new_node->content, content);
    new_node->next      = cache->table[index];
    cache->table[index] = new_node;
    add_to_head(cache, new_node);
    cache->count++;
}

void print_cache(LRUCache* cache)
{
    printf("\nCurrent Cache (MRU to LRU):\n");
    CacheNode* current = cache->head;
    while (current != NULL)
    {
        printf("- %s\n", current->url);
        current = current->next;
    }
}
