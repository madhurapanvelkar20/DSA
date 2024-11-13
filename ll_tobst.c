#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

struct Node* createTreeNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct ListNode* createListNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow; 
}

struct Node* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* mid = findMiddle(head);
    struct Node* root = createTreeNode(mid->data);

    if (head == mid) {
        return root;
    }

    struct ListNode* leftList = head;
    struct ListNode* rightList = mid->next;
    
    mid->next = NULL;
    
    root->left = sortedListToBST(leftList);
    root->right = sortedListToBST(rightList);

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
    struct ListNode* head = createListNode(1);
    head->next = createListNode(2);
    head->next->next = createListNode(3);
    head->next->next->next = createListNode(4);
    head->next->next->next->next = createListNode(5);
    head->next->next->next->next->next = createListNode(6);
    head->next->next->next->next->next->next = createListNode(7);

    struct Node* root = sortedListToBST(head);

    printf("In-order Traversal of the constructed BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
