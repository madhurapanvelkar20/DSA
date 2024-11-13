#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterElement(struct Node* head, int data, int element) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != element) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteStart(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void deleteAfterElement(struct Node* head, int element) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != element) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Element not found or no node to delete after it\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* mergedHead = NULL;
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeSortedLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeSortedLists(head1, head2->next);
    }
    return mergedHead;
}

// Test the implementation
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Creating linked list 1
    insertLast(&head1, 10);
    insertLast(&head1, 20);
    insertLast(&head1, 30);

    printf("List 1: ");
    display(head1);

    // Inserting at start
    insertStart(&head1, 5);
    printf("After inserting at start: ");
    display(head1);
    insertLast(&head1, 40);
    printf("After inserting at end: ");
    display(head1);
    insertAtPosition(&head1, 25, 4);
    printf("After inserting at position 4: ");
    display(head1);
    insertAfterElement(head1, 35, 30);
    printf("After inserting after element 30: ");
    display(head1);
    deleteStart(&head1);
    printf("After deleting from start: ");
    display(head1);
    deleteEnd(&head1);
    printf("After deleting from end: ");
    display(head1);
    deleteAtPosition(&head1, 3);
    printf("After deleting at position 3: ");
    display(head1);
    deleteAfterElement(head1, 20);
    printf("After deleting after element 20: ");
    display(head1);
    reverseList(&head1);
    printf("After reversing: ");
    display(head1);
    insertLast(&head2, 15);
    insertLast(&head2, 25);
    insertLast(&head2, 35);

    printf("List 2: ");
    display(head2);
    concatLists(&head1, head2);
    printf("After concatenation: ");
    display(head1);

    struct Node* mergedHead = mergeSortedLists(head1, head2);
    printf("Merged list: ");
    display(mergedHead);

    return 0;
}
