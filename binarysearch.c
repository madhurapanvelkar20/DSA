#include <stdio.h>

int BinarySearch(int arr[], int size, int x){
int low = 0, high = size-1;

    while(low<=high) {
    int mid = (low+high)/2; 
    
    if (arr[mid]==x){
        return mid; 
    }
    else if (arr[mid]>x){
        high = mid-1; 
    }
    else {
        low = mid+1; 
    }
}
return -1; 
}

int main(){
int n,x; 

    printf("Enter the size of the array: ");
    scanf("%d", &n); 
    
    int arr[n];
    printf("Enter the elements of the array: ");
    
    int i; 
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]); 
    }
    
    printf("Enter the element to be searched: "); 
    scanf("%d", &x);
    
    int result = BinarySearch(arr, n, x); 
    
    if (result == -1){
        printf("Element not found."); 
    }
    else{
        printf("The element %d is found at the index %d", x, result); 
    }
    
    return 0; 
}

