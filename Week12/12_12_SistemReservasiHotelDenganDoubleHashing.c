#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 100
#define PRIME      7

typedef struct
{
    int  id;
    char guest_name[50];
    int  room;
    bool is_active;
} Reservation;

void         judul();
unsigned int hash1(int id);
unsigned int hash2(int id);
void         insert_reservation(Reservation table[], Reservation res);
Reservation* find_reservation(Reservation table[], int id);
void         cancel_reservation(Reservation table[], int id);
void         print_reservations(Reservation table[]);

int main()
{
    judul();

    Reservation reservations[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        reservations[i].id        = -1;
        reservations[i].is_active = false;
    }

    // Skenario 1: Tambah reservasi
    Reservation r1 = {1001, "John Doe", 101, true};
    Reservation r2 = {1002, "Jane Smith", 202, true};
    Reservation r3 = {1007, "Bob Johnson", 303, true};     // Akan collision dengan 1001

    insert_reservation(reservations, r1);
    insert_reservation(reservations, r2);
    insert_reservation(reservations, r3);

    // Skenario 2: Cari reservasi
    Reservation* found = find_reservation(reservations, 1007);
    if (found != NULL)
    {
        printf("\nFound Reservation: %s (Kamar %d)\n", found->guest_name, found->room);
    }

    // Skenario 3: Batalkan reservasi
    cancel_reservation(reservations, 1002);

    // Skenario 4: Tampilkan laporan
    print_reservations(reservations);

    return 0;
}

void judul()
{
    printf("Program Sistem Reservasi Hotel dengan Double Hashing\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

unsigned int hash1(int id)
{
    return id % TABLE_SIZE;
}

unsigned int hash2(int id)
{
    return PRIME - (id % PRIME);
}

void insert_reservation(Reservation table[], Reservation res)
{
    unsigned int index = hash1(res.id);
    unsigned int step  = hash2(res.id);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[index].id == -1 || !table[index].is_active)
        {
            table[index] = res;
            printf("Reservasi ID %d berhasil ditambahkan (Kamar %d)\n", res.id, res.room);
            return;
        }
        index = (index + step) % TABLE_SIZE;
    }
    printf("Error: Tabel reservasi penuh!\n");
}

Reservation* find_reservation(Reservation table[], int id)
{
    unsigned int index = hash1(id);
    unsigned int step  = hash2(id);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[index].id == id && table[index].is_active)
        {
            return &table[index];
        }
        if (table[index].id == -1)
        {
            return NULL;
        }
        index = (index + step) % TABLE_SIZE;
    }
    return NULL;
}

void cancel_reservation(Reservation table[], int id)
{
    Reservation* res = find_reservation(table, id);
    if (res != NULL)
    {
        res->is_active = false;
        printf("Reservasi ID %d dibatalkan\n", id);
    }
    else
    {
        printf("Reservasi ID %d tidak ditemukan\n", id);
    }
}

void print_reservations(Reservation table[])
{
    printf("\nDaftar Reservasi Aktif:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i].id != -1 && table[i].is_active)
        {
            printf("ID: %-5d | Tamu: %-20s | Kamar: %3d\n",
                   table[i].id, table[i].guest_name, table[i].room);
        }
    }
}
