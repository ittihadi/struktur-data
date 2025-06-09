#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct Product
{
    char            barcode[13];
    char            name[50];
    int             stock;
    float           price;
    struct Product* next;
} Product;

typedef struct
{
    Product** table;
    int       size;
} Inventory;

void         judul();
unsigned int hash(const char* str);
Inventory*   create_inventory();
void         add_product(Inventory* inv, Product* p);
Product*     find_product(Inventory* inv, const char* barcode);
void         print_inventory(Inventory* inv);

int main()
{
    judul();

    Inventory* supermarket = create_inventory();

    Product p1 = {"123456789012", "Ultra Milk 1L", 50, 3.99, NULL};
    Product p2 = {"987654321098", "Roti Tawar", 30, 2.49, NULL};
    Product p3 = {"123123123123", "Indomie Goreng", 100, 1.29, NULL};

    add_product(supermarket, &p1);
    add_product(supermarket, &p2);
    add_product(supermarket, &p3);

    // Scenario 1: Pencarian produk
    Product* found = find_product(supermarket, "987654321098");
    if (found != NULL)
    {
        printf("\nFound Product: %s (Stock: %d)\n", found->name, found->stock);

        // Scenario 2: Update stok
        found->stock -= 5;
        printf("Updated stock: %d\n", found->stock);
    }

    // Scenario 3: Laporan inventaris
    printf("\nFull Inventory Report:\n");
    print_inventory(supermarket);

    return 0;
}

void judul()
{
    printf("Program Sistem Inventaris Supermarket\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

unsigned int hash(const char* str)
{
    unsigned long hash = 5381;
    int           c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % TABLE_SIZE;
}

Inventory* create_inventory()
{
    Inventory* inv = malloc(sizeof(Inventory));
    inv->size      = TABLE_SIZE;
    inv->table     = calloc(TABLE_SIZE, sizeof(Product*));
    return inv;
}

void add_product(Inventory* inv, Product* p)
{
    unsigned int index = hash(p->barcode);
    p->next            = inv->table[index];
    inv->table[index]  = p;
}

Product* find_product(Inventory* inv, const char* barcode)
{
    unsigned int index   = hash(barcode);
    Product*     current = inv->table[index];
    while (current != NULL)
    {
        if (strcmp(current->barcode, barcode) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_inventory(Inventory* inv)
{
    for (int i = 0; i < inv->size; i++)
    {
        Product* current = inv->table[i];
        while (current != NULL)
        {
            printf("Barcode: %s | Name: %-20s | Stock: %4d | Price: $%5.2f\n",
                   current->barcode, current->name, current->stock, current->price);
            current = current->next;
        }
    }
}
