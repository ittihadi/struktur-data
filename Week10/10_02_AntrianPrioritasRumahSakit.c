#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int  priority;
} Patient;

typedef struct
{
    Patient data[100];
    int     size;
} MaxHeap;

void    judul();
void    swap(Patient *a, Patient *b);
void    upHeapify(MaxHeap *heap, int index);
void    downHeapify(MaxHeap *heap, int index);
void    insertPatient(MaxHeap *heap, char name[], int priority);
Patient servePatient(MaxHeap *heap);

int main()
{
    judul();

    MaxHeap heap;
    heap.size = 0;

    insertPatient(&heap, "Alice", 2);
    insertPatient(&heap, "Bob", 5);
    insertPatient(&heap, "Charlie", 3);

    Patient p = servePatient(&heap);
    printf("Serving patient: %s with priority %d\n", p.name, p.priority);

    return 0;
}

void judul()
{
    printf("Program Manajemen Antrian Prioritas di Rumah Sakit\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void swap(Patient *a, Patient *b)
{
    Patient temp = *a;
    *a           = *b;
    *b           = temp;
}

void upHeapify(MaxHeap *heap, int index)
{
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap->data[index].priority > heap->data[parent].priority)
    {
        swap(&heap->data[index], &heap->data[parent]);
        upHeapify(heap, parent);
    }
}

void downHeapify(MaxHeap *heap, int index)
{
    int left    = index * 2 + 1;
    int right   = index * 2 + 2;
    int largest = index;

    if (left < heap->size && heap->data[left].priority > heap->data[largest].priority)
        largest = left;
    if (right < heap->size && heap->data[right].priority > heap->data[largest].priority)
        largest = right;
    if (largest != index)
    {
        swap(&heap->data[index], &heap->data[largest]);
        downHeapify(heap, largest);
    }
}

void insertPatient(MaxHeap *heap, char name[], int priority)
{
    strcpy(heap->data[heap->size].name, name);
    heap->data[heap->size].priority = priority;
    upHeapify(heap, heap->size);
    heap->size++;
}

Patient servePatient(MaxHeap *heap)
{
    Patient top   = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    downHeapify(heap, 0);
    return top;
}
