#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256
#define BUFFER_SIZE 4096

typedef struct HuffmanNode
{
    char                character;
    unsigned            frequency;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct
{
    unsigned      size;
    unsigned      capacity;
    HuffmanNode** array;
} MinHeap;

typedef struct
{
    char character;
    char code[MAX_TREE_HT];
} HuffmanCode;

void judul();

HuffmanNode* newNode(char character, unsigned frequency);
MinHeap*     createMinHeap(unsigned capacity);
void         swapNodes(HuffmanNode** a, HuffmanNode** b);
void         minHeapify(MinHeap* heap, int idx);
HuffmanNode* extractMin(MinHeap* heap);
void         insertMinHeap(MinHeap* heap, HuffmanNode* node);
void         buildMinHeap(MinHeap* heap);
MinHeap*     createAndBuildMinHeap(char data[], unsigned freq[], int size);
HuffmanNode* buildHuffmanTree(char data[], unsigned freq[], int size);
void         generateCodes(HuffmanNode* root, char code[], int top, HuffmanCode codeTable[]);
void         compressFile(const char* inputFile, const char* outputFile);
void         decompressFile(const char* inputFile, const char* outputFile);

int main()
{
    judul();

    int  choice;
    char inputFile[256], outputFile[256];

    printf("Huffman Coding Compression Tool\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input filename: ");
    scanf("%255s", inputFile);
    printf("Enter output filename: ");
    scanf("%255s", outputFile);

    switch (choice)
    {
        case 1:
            compressFile(inputFile, outputFile);

            // Hitung rasio kompresi
            FILE* orig = fopen(inputFile, "rb");
            FILE* comp = fopen(outputFile, "rb");
            if (orig && comp)
            {
                fseek(orig, 0, SEEK_END);
                fseek(comp, 0, SEEK_END);
                long origSize = ftell(orig);
                long compSize = ftell(comp);
                printf("Original size: %ld bytes\n", origSize);
                printf("Compressed size: %ld bytes\n", compSize);
                printf("Compression ratio: %.2f%%\n",
                       (1 - (float)compSize / origSize) * 100);
                fclose(orig);
                fclose(comp);
            }
            break;
        case 2:
            decompressFile(inputFile, outputFile);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

void judul()
{
    printf("Program Implementasi Text Compression Menggunakan Huffman Coding\n");
    printf("Nama       : Ittihadi Ramadhan\n");
    printf("NIM        : 24343038\n");
    printf("Prodi      : Informatika\n");
    printf("Matakuliah : Struktur Data\n");
    printf("\n");
}

HuffmanNode* newNode(char character, unsigned frequency)
{
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->character   = character;
    node->frequency   = frequency;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(unsigned capacity)
{
    MinHeap* heap  = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size     = 0;
    heap->capacity = capacity;
    heap->array    = (HuffmanNode**)malloc(capacity * sizeof(HuffmanNode*));
    return heap;
}

void swapNodes(HuffmanNode** a, HuffmanNode** b)
{
    HuffmanNode* temp = *a;
    *a                = *b;
    *b                = temp;
}

void minHeapify(MinHeap* heap, int idx)
{
    int smallest = idx;
    int left     = 2 * idx + 1;
    int right    = 2 * idx + 2;

    if (left < heap->size &&
        heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;

    if (right < heap->size &&
        heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx)
    {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

HuffmanNode* extractMin(MinHeap* heap)
{
    HuffmanNode* node = heap->array[0];
    heap->array[0]    = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return node;
}

void insertMinHeap(MinHeap* heap, HuffmanNode* node)
{
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency)
    {
        heap->array[i] = heap->array[(i - 1) / 2];
        i              = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void buildMinHeap(MinHeap* heap)
{
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(heap, i);
}

MinHeap* createAndBuildMinHeap(char data[], unsigned freq[], int size)
{
    MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        heap->array[i] = newNode(data[i], freq[i]);
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

HuffmanNode* buildHuffmanTree(char data[], unsigned freq[], int size)
{
    HuffmanNode *left, *right, *top;
    MinHeap*     heap = createAndBuildMinHeap(data, freq, size);

    while (heap->size != 1)
    {
        left       = extractMin(heap);
        right      = extractMin(heap);
        top        = newNode('$', left->frequency + right->frequency);
        top->left  = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}

void generateCodes(HuffmanNode* root, char code[], int top, HuffmanCode codeTable[])
{
    if (root->left)
    {
        code[top] = '0';
        generateCodes(root->left, code, top + 1, codeTable);
    }
    if (root->right)
    {
        code[top] = '1';
        generateCodes(root->right, code, top + 1, codeTable);
    }
    if (!root->left && !root->right)
    {
        code[top] = '\0';
        strcpy(codeTable[(unsigned char)root->character].code, code);
        codeTable[(unsigned char)root->character].character = root->character;
    }
}

void compressFile(const char* inputFile, const char* outputFile)
{
    FILE* in = fopen(inputFile, "rb");
    if (!in)
    {
        perror("Error opening input file");
        return;
    }

    // Hitung frekuensi karakter
    unsigned freq[256] = {0};
    char     buffer[BUFFER_SIZE];
    size_t   bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, in)))
    {
        for (size_t i = 0; i < bytesRead; ++i)
            freq[(unsigned char)buffer[i]]++;
    }
    rewind(in);

    // Bangun Huffman Tree
    char     chars[256];
    unsigned freqs[256];
    int      size = 0;
    for (int i = 0; i < 256; ++i)
    {
        if (freq[i] > 0)
        {
            chars[size] = (char)i;
            freqs[size] = freq[i];
            size++;
        }
    }
    HuffmanNode* root = buildHuffmanTree(chars, freqs, size);

    // Generate kode Huffman
    HuffmanCode codeTable[256];
    char        code[MAX_TREE_HT];
    generateCodes(root, code, 0, codeTable);

    // Tulis file terkompresi
    FILE* out = fopen(outputFile, "wb");
    if (!out)
    {
        perror("Error opening output file");
        fclose(in);
        return;
    }

    // Tulis header (tabel frekuensi)
    fwrite(freq, sizeof(unsigned), 256, out);

    // Catat panjang total data agar padding akhir nanti tidak terbaca
    unsigned long totalBits = 0;
    for (int i = 0; i < 256; i++)
        totalBits += freq[i] * strlen(codeTable[i].code);

    fwrite(&totalBits, sizeof(unsigned long), 1, out);

    // Kompresi data
    unsigned char byte     = 0;
    int           bitCount = 0;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, in)))
    {
        for (size_t i = 0; i < bytesRead; ++i)
        {
            char* huffmanCode = codeTable[(unsigned char)buffer[i]].code;
            for (int j = 0; huffmanCode[j]; ++j)
            {
                if (huffmanCode[j] == '1')
                    byte |= (1 << (7 - bitCount));
                bitCount++;
                if (bitCount == 8)
                {
                    fwrite(&byte, 1, 1, out);
                    byte     = 0;
                    bitCount = 0;
                }
            }
        }
    }

    // Tulis byte terakhir jika ada sisa bit
    if (bitCount > 0)
        fwrite(&byte, 1, 1, out);

    fclose(in);
    fclose(out);

    printf("File compressed successfully: %s\n", outputFile);
}

void decompressFile(const char* inputFile, const char* outputFile)
{
    FILE* in = fopen(inputFile, "rb");
    if (!in)
    {
        perror("Error opening input file");
        return;
    }

    // Baca header (tabel frekuensi)
    unsigned freq[256];
    if (fread(freq, sizeof(unsigned), 256, in) != 256)
    {
        perror("Error reading frequency table");
        fclose(in);
        return;
    }

    // Baca total bit count agar tidak terbaca data padding di akhir
    unsigned long totalBits;
    if (fread(&totalBits, sizeof(unsigned long), 1, in) != 1)
    {
        perror("Error reading bit count");
        fclose(in);
        return;
    }

    // Bangun Huffman Tree
    char     chars[256];
    unsigned freqs[256];
    int      size = 0;
    for (int i = 0; i < 256; ++i)
    {
        if (freq[i] > 0)
        {
            chars[size] = (char)i;
            freqs[size] = freq[i];
            size++;
        }
    }
    HuffmanNode* root = buildHuffmanTree(chars, freqs, size);

    // Buka file output
    FILE* out = fopen(outputFile, "wb");
    if (!out)
    {
        perror("Error opening output file");
        fclose(in);
        return;
    }

    // Dekompresi data
    HuffmanNode*  current = root;
    unsigned char byte;
    int           bitPos   = 7;
    unsigned long bitsRead = 0;
    while (fread(&byte, 1, 1, in))
    {
        while (bitPos >= 0 && bitsRead < totalBits)
        {
            if (byte & (1 << bitPos))
                current = current->right;
            else
                current = current->left;
            bitPos--;
            bitsRead++;

            if (!current->left && !current->right)
            {
                fwrite(&current->character, 1, 1, out);
                current = root;
            }
        }
        bitPos = 7;
    }

    fclose(in);
    fclose(out);
    printf("File decompressed successfully: %s\n", outputFile);
}
