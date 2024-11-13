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
    if (!newNode) {
        printf("Memory allocation failed for TreeNode.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct ListNode* createListNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        printf("Memory allocation failed for ListNode.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* bstToSortedList(struct Node* root, struct ListNode* prev) {
    if (root == NULL) {
        return prev; 
    }

    prev = bstToSortedList(root->left, prev);

    struct ListNode* newListNode = createListNode(root->data);
    if (prev != NULL) {
        prev->next = newListNode;
    }
    prev = newListNode; 
    return bstToSortedList(root->right, prev);
}

struct ListNode* convertBSTToSortedList(struct Node* root) {
    struct ListNode dummy; 
    dummy.next = NULL;
    bstToSortedList(root, &dummy);
    return dummy.next;
}

void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* root = NULL;

    root = createTreeNode(50);
    root->left = createTreeNode(30);
    root->right = createTreeNode(70);
    root->left->left = createTreeNode(20);
    root->left->right = createTreeNode(40);
    root->right->left = createTreeNode(60);
    root->right->right = createTreeNode(80);

    struct ListNode* sortedList = convertBSTToSortedList(root);

    printf("Sorted Linked List: ");
    printLinkedList(sortedList);

    return 0;
}


