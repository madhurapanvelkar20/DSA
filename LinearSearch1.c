#include <stdio.h>
int search(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key)
            return i; 
    }
    return -1; 
}

int main(){
    int n; 
    printf("Enter the no. of elements in the array: "); 
    scanf("%d",&n); 

    int arr[50]; 
    printf("Enter the elements of the array: "); 
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]); 
    }

    int key; 
    printf("Enter the element to be searched: "); 
    scanf("%d",&key); 

    int result = search(arr, n, key);

    (result==-1) ? printf("Element not found.") : printf("Element found at index %d",result);  
}