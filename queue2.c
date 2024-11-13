#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void enqueue(int);
void dequeue();
int isEmpty();
int isFull();
void display();

// Define the front and rear pointers for the queue
struct Node* front = NULL;
struct Node* rear = NULL;

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                if (isFull()) {
                    printf("Queue is full!\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to enqueue an element to the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue is full (memory allocation failed).\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    printf("%d dequeued from the queue.\n", temp->data);
    free(temp);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to check if the queue is full (based on memory availability)
int isFull() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1; // Memory allocation failed, so the queue is full
    }
    free(temp);
    return 0; // Memory is available, so the queue is not full
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
