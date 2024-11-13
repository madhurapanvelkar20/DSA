#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* converttoBST(int arr[], int low, int high) {
    if (low > high) {
        return NULL;
    }

    int mid = (low + high) / 2;
    struct Node* root = createNode(arr[mid]);

    root->left = converttoBST(arr, low, mid - 1);
    root->right = converttoBST(arr, mid + 1, high);

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = converttoBST(arr, 0, n - 1);

    printf("In-order Traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
