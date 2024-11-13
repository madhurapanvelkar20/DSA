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

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void printnodes_dis_k(struct Node* root, int k) {
    if (root == NULL || k < 0) {
        return;
    }

    if (k == 0) {
        printf("%d ", root->data);
        return;
    }

    printnodes_dis_k(root->left, k - 1);
    printnodes_dis_k(root->right, k - 1);
}

int find_print_nodes(struct Node* root, struct Node* target, int k) {
    if (root == NULL) {
        return -1; 
    }

    if (root == target) {
        printnodes_dis_k(root, k);
        return 0; 
    }

    int leftDistance = find_print_nodes(root->left, target, k);

    if (leftDistance != -1) {
        if (leftDistance + 1 == k) {
            printf("%d ", root->data);
        } else {
            printnodes_dis_k(root->right, k - leftDistance - 2);
        }
        return leftDistance + 1; 
    }

    int rightDistance = find_print_nodes(root->right, target, k);

    if (rightDistance != -1) {
        if (rightDistance + 1 == k) {
            printf("%d ", root->data);
        } else {
            printnodes_dis_k(root->left, k - rightDistance - 2);
        }
        return rightDistance + 1; 
    }

    return -1; 
}

void printnodes_dis_kth(struct Node* root, struct Node* target, int k) {
    find_print_nodes(root, target, k);
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    struct Node* target = root->left->right; 
    int k = 2; 

    printf("Nodes at distance %d from node %d: ", k, target->data);
    printnodes_dis_kth(root, target, k);
    printf("\n");

    return 0;
}
