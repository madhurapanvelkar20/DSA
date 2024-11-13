#include <stdio.h>
#include <stdbool.h>

void optimizedSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        bool isSorted = true;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            if (arr[j - 1] > arr[j]) {
                isSorted = false;
            }
        }

        if (isSorted) {
            return;
        }
         if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);  
    }
    printf("\n");

    optimizedSelectionSort(arr, n); 
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]); 
    }

    return 0; 
} 
