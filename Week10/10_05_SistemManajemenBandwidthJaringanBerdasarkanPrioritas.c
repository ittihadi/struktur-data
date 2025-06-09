#include <stdio.h>
#include <string.h>

typedef struct
{
    int  id;
    char nama[50];
    int  prioritas;
} Pengguna;

typedef struct
{
    Pengguna data[100];
    int      size;
} MaxHeap;

void     judul();
void     swap(Pengguna *a, Pengguna *b);
void     upHeapify(MaxHeap *heap, int i);
void     downHeapify(MaxHeap *heap, int i);
void     insertUser(MaxHeap *heap, int id, char *nama, int prioritas);
Pengguna serveUser(MaxHeap *heap);
void     tampilkanPengguna(MaxHeap heap);

int main()
{
    judul();

    MaxHeap heap;
    heap.size = 0;

    insertUser(&heap, 1, "Direktur", 3);
    insertUser(&heap, 2, "Manajer IT", 2);
    insertUser(&heap, 3, "Staf Administrasi", 1);
    insertUser(&heap, 4, "Manager Finance", 2);

    tampilkanPengguna(heap);

    Pengguna served = serveUser(&heap);
    printf("\nAkses Bandwidth diberikan ke: %s (Prioritas %d)\n", served.nama, served.prioritas);

    return 0;
}

void judul()
{
    printf("Program Sistem Manajemen Bandwidth Jaringan Berdasarkan Prioritas Pengguna\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void swap(Pengguna *a, Pengguna *b)
{
    Pengguna temp = *a;
    *a            = *b;
    *b            = temp;
}

void upHeapify(MaxHeap *heap, int i)
{
    if (i == 0) return;
    int parent = (i - 1) / 2;
    if (heap->data[i].prioritas > heap->data[parent].prioritas)
    {
        swap(&heap->data[i], &heap->data[parent]);
        upHeapify(heap, parent);
    }
}

void downHeapify(MaxHeap *heap, int i)
{
    int left    = i * 2 + 1;
    int right   = i * 2 + 2;
    int largest = i;

    if (left < heap->size && heap->data[left].prioritas > heap->data[largest].prioritas)
        largest = left;
    if (right < heap->size && heap->data[right].prioritas > heap->data[largest].prioritas)
        largest = right;

    if (largest != i)
    {
        swap(&heap->data[i], &heap->data[largest]);
        downHeapify(heap, largest);
    }
}

void insertUser(MaxHeap *heap, int id, char *nama, int prioritas)
{
    Pengguna p;
    p.id = id;
    strcpy(p.nama, nama);
    p.prioritas = prioritas;

    heap->data[heap->size] = p;
    upHeapify(heap, heap->size);
    heap->size++;
}

Pengguna serveUser(MaxHeap *heap)
{
    Pengguna top  = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    downHeapify(heap, 0);
    return top;
}

void tampilkanPengguna(MaxHeap heap)
{
    printf("Antrian Pengguna Akses Jaringan:\n");
    for (int i = 0; i < heap.size; i++)
    {
        printf("ID: %d | Nama: %s | Prioritas: %d\n", heap.data[i].id, heap.data[i].nama, heap.data[i].prioritas);
    }
}
