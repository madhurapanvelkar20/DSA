#include <stdio.h>

void bubble_sort(int arr[], int n){
    int swapped; 
    for(int i=0; i<n-1; i++){
        swapped = 0; 
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
                swapped = 1; 
            }
        }
        
        if (swapped == 0)
            break; 
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
}

int main(){
    int n; 
    printf("Enter the number of elements: "); 
    scanf("%d",&n); 
    
    int arr[100]; 
    printf("Enter the elements: "); 
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]); 
    }
    
    bubble_sort(arr, n); 
    printf("The sorted array is: "); 
    printArray(arr, n); 
    
    return 0; 
}
