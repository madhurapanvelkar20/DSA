#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data; 
    struct Node* left;
    struct Node* right; 
};

struct Node* createNode(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct Node* insertNode(struct Node* root, int data){
    if(root==NULL){
        return createNode(data); 
    }

    if(data < root->data){
        root->left = insertNode(root->left, data); 
    }
    else if (data > root->data){
        root->right = insertNode(root->right, data); 
    }

    return root;
}

int search(struct Node* root, int key){
    if(root==NULL){
        return 0; 
    }
    if(root->data == key){
        return 1; 
    }
    if(key > root->data){
        return search(root->right, key); 
    }
    else{
        return search(root->left, key); 
    }
}

int checkBST(struct Node* root){
    static struct Node* prev = NULL; 
    if(root!=NULL){
        if(!checkBST(root->left)){
            return 0; 
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0; 
        }
        prev = root; 
        return checkBST(root->right); 
    }
    else{
        return 1; 
    }
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* findMax(struct Node* node){
    struct Node* current = node; 
    while(current && current->right != NULL){
        current = current->right; 
    }
    return current; 
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d->",root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    printf("%d->",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root){
    if(root==NULL){
        return; 
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d->",root->data);
}

void printMinValue(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    struct Node* minNode = findMin(root);
    printf("The minimum value in the BST is: %d\n", minNode->data);
}

void printMaxValue(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    struct Node* maxNode = findMax(root);
    printf("The maximum value in the BST is: %d\n", maxNode->data);
}

int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

void printlevel(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printlevel(root->left, level - 1);
        printlevel(root->right, level - 1);
    }
}

void leveltraversal(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printlevel(root, i);
    }
}

int countnodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}

int find_height(struct Node* root) {
    if (root == NULL) {
        return -1;  
    }

    int height_left = find_height(root->left);
    int height_right = find_height(root->right);

    return (height_left > height_right ? height_left : height_right) + 1;
}

int height_balanced(struct Node* root) {
    if (root == NULL) {
        return 1; 
    }

    int height_left = height(root->left);
    int height_right = height(root->right);

    if (abs(height_left - height_right) > 1) {
        return 0; 
    }

    return height_balanced(root->left) && height_balanced(root->right);
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

void k_smallest(struct Node* root, int* count, int k, int* result) {
    if (root == NULL || *count >= k) {
        return;
    }

    k_smallest(root->left, count, k, result);

    (*count)++;

    if (*count == k) {
        *result = root->data;
        return;
    }

    k_smallest(root->right, count, k, result);
}

int kthsmallest(struct Node* root, int k) {
    int count = 0;
    int result = -1;  

    k_smallest(root, &count, k, &result);

    if (count < k) {
        printf("The tree does not have %d elements.\n", k);
        return -1; 
    }

    return result;
}

void k_largest(struct Node* root, int* count, int k, int* result) {
    if (root == NULL || *count >= k) {
        return;
    }

    k_largest(root->right, count, k, result);
    (*count)++;

    if (*count == k) {
        *result = root->data;
        return;
    }

    k_largest(root->left, count, k, result);
}

int kthlargest(struct Node* root, int k) {
    int count = 0;
    int result = -1;  

    k_largest(root, &count, k, &result);

    if (count < k) {
        printf("The tree does not have %d elements.\n", k);
        return -1; 
    }

    return result;
}

int main(){
    struct Node* root = NULL;
    root = insertNode(root, 54);
    root = insertNode(root, 21);
    root = insertNode(root, 78);
    root = insertNode(root, 2);
    root = insertNode(root, 34);
    root = insertNode(root, 95);

    printf("Level Order Traversal of the BST: \n");
    levelOrderTraversal(root);
    printf("\n"); 

    printf("Total number of nodes in the BST: %d\n", countNodes(root));

    printf("Height of the BST: %d\n", findHeight(root));

    if (isHeightBalanced(root)) {
        printf("The tree is height-balanced.\n");
    } else {
        printf("The tree is not height-balanced.\n");
    }

    int n1 = 54, n2 = 2;
    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
    } else {
        printf("LCA does not exist.\n");
    }

    int k = 4;
    int result = kthSmallest(root, k);

    if (result != -1) {
        printf("The %d-th smallest element is %d\n", k, result);
    }

    int k1 = 2;
    int result1 = kthLargest(root, k1);

    if (result1 != -1) {
        printf("The %d-th largest element is %d\n", k1, result1);
    }

    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n"); 

    printf("Is this tree BST: %d ",isBST(root)); 
    printf("\n");

    printf("Pre-order traversal of the BST: "); 
    preorderTraversal(root); 
    printf("\n");

    printf("Post-order traversal of the BST: "); 
    postorderTraversal(root); 
    printf("\n"); 


    printMinValue(root); 
    printMaxValue(root); 

    printf("After deleting 21: \n");
    root = deleteNode(root, 21);

    printf("In-order traversal of BST: "); 
    inorderTraversal(root); 
    printf("\n"); 

    if(search(root, 5)){
        printf("5 is present in the tree."); 
    }
    else{
        printf("5 is not present in the tree."); 
    }
    
    return 0; 
}