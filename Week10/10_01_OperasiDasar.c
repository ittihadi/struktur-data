#include <stdio.h>

#define MAX_SIZE 100
typedef struct MaxHeap
{
    int data[MAX_SIZE];
    int size;
} MaxHeap;

void judul();
void showHeap(MaxHeap *heap);
void downHeapify(MaxHeap *heap, int index);
void insert(MaxHeap *heap, int value);
int  deleteRoot(MaxHeap *heap);

int main()
{
    judul();
    MaxHeap heap;
    heap.size = 0;

    printf("Menginsert 4 nilai ke dalam heap: ");
    insert(&heap, 3);
    insert(&heap, 2);
    insert(&heap, 13);
    insert(&heap, 5);

    showHeap(&heap);

    printf("Menghapus 2 nilai dari heap: ");
    deleteRoot(&heap);
    deleteRoot(&heap);

    showHeap(&heap);

    return 0;
}

void judul()
{
    printf("Program Operasi Dasar pada Heap Menggunaan Max-Heap\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void showHeap(MaxHeap *heap)
{
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->data[i]);

    printf("\n");
}

void downHeapify(MaxHeap *heap, int index)
{
    int largest = index;
    int left    = index * 2 + 1;
    int right   = index * 2 + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;

    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != index)
    {
        int temp            = heap->data[index];
        heap->data[index]   = heap->data[largest];
        heap->data[largest] = temp;
        downHeapify(heap, largest);
    }
}

void insert(MaxHeap *heap, int value)
{
    if (heap->size >= MAX_SIZE)
    {
        printf("Heap penuh!\n");
        return;
    }

    heap->data[heap->size] = value;
    int current            = heap->size;
    heap->size++;

    // Lakukan Up-Heapify
    while (current > 0 && heap->data[current] > heap->data[(current - 1) / 2])
    {
        int temp                      = heap->data[current];
        heap->data[current]           = heap->data[(current - 1) / 2];
        heap->data[(current - 1) / 2] = temp;
        current                       = (current - 1) / 2;
    }
}

int deleteRoot(MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap kosong!\n");
        return -1;
    }

    int root      = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    downHeapify(heap, 0);

    return root;
}
