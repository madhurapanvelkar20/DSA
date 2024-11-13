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

struct Node* createnode_t(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct ListNode* createnode_l(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* BSTToList(struct Node* root) {
    if (root == NULL) return NULL;

    struct ListNode* leftList = BSTToList(root->left);

    struct ListNode* newNode = createnode_l(root->data);

    if (leftList == NULL) {
        leftList = newNode;
    } else {
        struct ListNode* temp = leftList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    struct ListNode* rightList = BSTToList(root->right);

    newNode->next = rightList;

    return leftList;
}

struct ListNode* mergeSortedLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode* result;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }
    return result;
}

struct Node* sortedListToBST(struct ListNode** head, int n) {
    if (n <= 0) return NULL;

    struct Node* left = sortedListToBST(head, n / 2);

    struct Node* root = createnode_t((*head)->data);

    *head = (*head)->next;

    root->left = left;
    root->right = sortedListToBST(head, n - n / 2 - 1);

    return root;
}

struct Node* sortedListTo_BST(struct ListNode* head, int n) {
    return sortedListToBST(&head, n);
}

struct Node* mergeBSTs(struct Node* root1, struct Node* root2) {
    struct ListNode* list1 = BSTToList(root1);
    struct ListNode* list2 = BSTToList(root2);

    struct ListNode* mergedList = mergeSortedLists(list1, list2);

    int n = 0;
    struct ListNode* temp = mergedList;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    return sortedListTo_BST(mergedList, n);
}

int main() {
    struct Node* root1 = createnode_t(10);
    root1->left = createnode_t(5);
    root1->right = createnode_t(15);

    struct Node* root2 = createnode_t(20);
    root2->left = createnode_t(17);
    root2->right = createnode_t(25);

    struct Node* mergedBST = mergeBSTs(root1, root2);

    return 0;
}

