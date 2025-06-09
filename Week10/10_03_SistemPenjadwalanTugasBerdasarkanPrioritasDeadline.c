#include <stdio.h>
#include <string.h>

typedef struct
{
    int  id;
    char nama[100];
    int  prioritas;
} Task;

typedef struct
{
    Task data[100];
    int  size;
} MaxHeap;

void judul();
void swapTask(Task *a, Task *b);
void upHeapify(MaxHeap *heap, int i);
void downHeapify(MaxHeap *heap, int i);
void insertTask(MaxHeap *heap, int id, char *nama, int prioritas);
Task executeTask(MaxHeap *heap);
void displayTasks(MaxHeap heap);

int main()
{
    judul();

    MaxHeap heap;
    heap.size = 0;

    insertTask(&heap, 101, "Fix bug login", 4);
    insertTask(&heap, 102, "Deploy aplikasi", 5);
    insertTask(&heap, 103, "Review UI", 2);

    printf("Tugas dalam antrian:\n");
    displayTasks(heap);

    Task next = executeTask(&heap);
    printf("\nTugas yang dieksekusi: %s\n", next.nama);

    return 0;
}

void judul()
{
    printf("Program Penjadwalan Tugas Berdasarkan Prioritas Deadline\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void swapTask(Task *a, Task *b)
{
    Task temp = *a;
    *a        = *b;
    *b        = temp;
}

void upHeapify(MaxHeap *heap, int i)
{
    int parent = (i - 1) / 2;
    if (i && heap->data[i].prioritas > heap->data[parent].prioritas)
    {
        swapTask(&heap->data[i], &heap->data[parent]);
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
        swapTask(&heap->data[i], &heap->data[largest]);
        downHeapify(heap, largest);
    }
}

void insertTask(MaxHeap *heap, int id, char *nama, int prioritas)
{
    Task t;
    t.id = id;
    strcpy(t.nama, nama);
    t.prioritas            = prioritas;
    heap->data[heap->size] = t;
    upHeapify(heap, heap->size);
    heap->size++;
}

Task executeTask(MaxHeap *heap)
{
    Task top      = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    downHeapify(heap, 0);
    return top;
}

void displayTasks(MaxHeap heap)
{
    for (int i = 0; i < heap.size; i++)
    {
        printf("ID: %d | Tugas: %s | Prioritas: %d\n", heap.data[i].id, heap.data[i].nama, heap.data[i].prioritas);
    }
}
