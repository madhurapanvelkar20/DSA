#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (size >= MAX) {
        printf("Heap is full!\n");
        return;
    }

    heap[size] = value;
    int current = size;

    while (current > 0 && heap[(current - 1) / 2] < heap[current]) {
        swap(&heap[(current - 1) / 2], &heap[current]);
        current = (current - 1) / 2;
    }

    size++;
}

void deleteRoot() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return;
    }

    heap[0] = heap[size - 1];
    size--;

    int current = 0;
    while (2 * current + 1 < size) {
        int largest = current;
        int left = 2 * current + 1;
        int right = 2 * current + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest == current) {
            break;
        }

        swap(&heap[current], &heap[largest]);
        current = largest;
    }
}

void displayHeap() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(15);

    printf("Heap after insertions:\n");
    displayHeap();

    deleteRoot();
    printf("Heap after deleting the root:\n");
    displayHeap();

    return 0;
}
