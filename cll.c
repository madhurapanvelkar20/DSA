#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL, *head2 = NULL;

void create(struct Node **head) {
    int data, choice;
    struct Node *newNode, *temp;
    do {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = newNode;

        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = *head;
        }
        printf("Do you want to add another node? (1-Yes / 0-No): ");
        scanf("%d", &choice);
    } while (choice == 1);
}

void insert(struct Node **head, int data, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else if (position == 1) {
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    } else {
        struct Node *temp = *head;
        for (int i = 1; i < position - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delete(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    if (position == 1) {
        if (temp->next == *head) {
            *head = NULL;
            free(temp);
        } else {
            struct Node *last = *head;
            while (last->next != *head) {
                last = last->next;
            }
            *head = temp->next;
            last->next = *head;
            free(temp);
        }
    } else {
        struct Node *prev = NULL;
        for (int i = 1; i < position && temp->next != *head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == *head && position > 1) {
            printf("Position out of bounds\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void reverse(struct Node **head) {
    if (*head == NULL || (*head)->next == *head) {
        return;
    }

    struct Node *prev = NULL, *current = *head, *next;
    struct Node *last = *head;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    last->next = prev;
    *head = prev;
}

void concatenate(struct Node **head1, struct Node **head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    if (*head2 == NULL) {
        return;
    }

    struct Node *temp1 = *head1;
    struct Node *temp2 = *head2;

    while (temp1->next != *head1) {
        temp1 = temp1->next;
    }
    while (temp2->next != *head2) {
        temp2 = temp2->next;
    }

    temp1->next = *head2;
    temp2->next = *head1;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Reverse\n");
        printf("5. Concatenate\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select List (1 or 2): ");
                int listNum;
                scanf("%d", &listNum);
                if (listNum == 1)
                    create(&head1);
                else
                    create(&head2);
                break;
            case 2:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &position);
                insert(&head1, data, position);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete(&head1, position);
                break;
            case 4:
                reverse(&head1);
                break;
            case 5:
                concatenate(&head1, &head2);
                head2 = NULL;  // Clear second list after concatenation
                break;
            case 6:
                printf("Select List to display (1 or 2): ");
                scanf("%d", &listNum);
                if (listNum == 1)
                    display(head1);
                else
                    display(head2);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
