#include <stdio.h>

void bubble_sort(int arr[], int n){
    if (n==1){
        return; 
    }
    for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i]; 
                arr[i] = arr[i+1]; 
                arr[i+1] = temp; 
            }
        }
        bubble_sort(arr, n-1); 
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
