#include <stdio.h>
#include <string.h>

typedef struct
{
    char  judul[100];
    float rating;
} Film;

typedef struct
{
    Film data[5];
    int  size;
} MaxHeap;

void judul();
void swap(Film *a, Film *b);
void upHeapify(MaxHeap *heap, int i);
void downHeapify(MaxHeap *heap, int i);
void insertFilm(MaxHeap *heap, char *judul, float rating);
void displayRekomendasi(MaxHeap heap);

int main()
{
    judul();

    MaxHeap heap = {.size = 0};

    insertFilm(&heap, "Interstellar", 9.1);
    insertFilm(&heap, "Parasite", 8.6);
    insertFilm(&heap, "The Godfather", 9.3);
    insertFilm(&heap, "Inception", 8.8);
    insertFilm(&heap, "Avengers: Endgame", 8.4);
    insertFilm(&heap, "Joker", 8.9);     // Akan menggantikan film rating terendah

    displayRekomendasi(heap);

    return 0;
}

void judul()
{
    printf("Program Rekomendasi Film Berdasarkan Rating Tertinggi\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

void swap(Film *a, Film *b)
{
    Film temp = *a;
    *a        = *b;
    *b        = temp;
}

void upHeapify(MaxHeap *heap, int i)
{
    int parent = (i - 1) / 2;
    if (i && heap->data[i].rating > heap->data[parent].rating)
    {
        swap(&heap->data[i], &heap->data[parent]);
        upHeapify(heap, parent);
    }
}

void downHeapify(MaxHeap *heap, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2;
    int largest = i;
    if (left < heap->size && heap->data[left].rating > heap->data[largest].rating)
        largest = left;
    if (right < heap->size && heap->data[right].rating > heap->data[largest].rating)
        largest = right;
    if (largest != i)
    {
        swap(&heap->data[i], &heap->data[largest]);
        downHeapify(heap, largest);
    }
}

void insertFilm(MaxHeap *heap, char *judul, float rating)
{
    if (heap->size < 5)
    {
        strcpy(heap->data[heap->size].judul, judul);
        heap->data[heap->size].rating = rating;
        upHeapify(heap, heap->size);
        heap->size++;
    }
    else
    {
        if (rating > heap->data[heap->size - 1].rating)
        {
            strcpy(heap->data[heap->size - 1].judul, judul);
            heap->data[heap->size - 1].rating = rating;
            downHeapify(heap, 0);
        }
    }
}

void displayRekomendasi(MaxHeap heap)
{
    printf("Daftar Rekomendasi Film (Top 5):\n");
    for (int i = 0; i < heap.size; i++)
    {
        printf("%s - Rating: %.1f\n", heap.data[i].judul, heap.data[i].rating);
    }
}
