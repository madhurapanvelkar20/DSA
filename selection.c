#include <stdio.h>

void selection_sort(int arr[], int n){
    int min, temp; 
    for(int i=0; i<n-1; i++){
        min=i; 
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
            min=j; 
        }
    }
        temp = arr[i];
        arr[i] = arr[min]; 
        arr[min] = temp; 
    }
}

int main(){
    int n; 
    printf("Enter number of elements: "); 
    scanf("%d",&n); 
    
    int arr[100]; 
    printf("Enter the elements: "); 
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]); 
    }
    
    printf("Original Array: "); 
    for(int i=0; i<n; i++){
        printf("%4d", arr[i]); 
    }
    printf("\n"); 
    
    selection_sort(arr,n); 
    
    printf("Sorted array: "); 
    for(int i=0; i<n; i++){
        printf("%4d", arr[i]); 
    }
}
